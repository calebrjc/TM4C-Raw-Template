cmake_minimum_required(VERSION 3.12)
project(TM4C-Raw-Template C CXX ASM)

# CONFIGURATION ------------------------------------------------------------------------------------
set(DEVICE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/device)

# Include directories
set(INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${DEVICE_DIR}/include
    ${DEVICE_DIR}/startup
)

# Source files
set(SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
    ${DEVICE_DIR}/startup/startup.c
)

# Project definitions
set(DEFS)

# MCU-specific compilation options (used for both compiling and linking)
set(MCU_OPTIONS
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -mthumb
)

# Compilation options that are not MCU specific
set(COMPILE_OPTIONS
    ${MCU_OPTIONS}
    -ggdb
    -Os
    -MD
    -ffunction-sections
    -fdata-sections
    -Wall
    --pedantic-errors
)

# Linking options that are not MCU specific
set(LINK_OPTIONS
    ${MCU_OPTIONS}
    -Wl,-T ${CMAKE_CURRENT_SOURCE_DIR}/device/TM4C123GH6PM.ld
    --entry Reset_Handler
    -Wl,--gc-sections
)

# INTERNALS ----------------------------------------------------------------------------------------

add_executable(${PROJECT_NAME} ${SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${INCLUDE_DIRS}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    ${DEFS}
)

target_compile_options(${PROJECT_NAME} PRIVATE
    ${COMPILE_OPTIONS}
)

target_link_options(${PROJECT_NAME} PRIVATE
    ${LINK_OPTIONS}
)

# CUSTOM -------------------------------------------------------------------------------------------

# Run objcopy post-build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND 
  ${CMAKE_OBJCOPY} -O binary ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX_C}
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.bin
)

# Add objcopy output to clean target
set_property(
    TARGET ${PROJECT_NAME}
    APPEND
    PROPERTY ADDITIONAL_CLEAN_FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.bin
)

# Make flashing the MCU convenient with a custom "flash" target
add_custom_target(flash DEPENDS ${PROJECT_NAME} COMMAND
    lmflash ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.bin)
