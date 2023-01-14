MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x00040000  /* FLASH size 256KB */
    RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 0x00007000  /* RAM size 32KB */
}

SECTIONS
{
    /* Pointer to the top of the stack, which runs from high (0x20007FFF) to low (0x20000000) */
    PROVIDE(_stack_ptr = ORIGIN(RAM) + LENGTH(RAM));

    /* 
     * Code section
     * Contains executable code and constants
     */
    .text :
    {
        _text = .;              /* Marks the beginning of the .text segment */
        KEEP(*(.vector_table))  /* Vector table (defined in startup.c) */
        *(.text*)
        . = ALIGN(4);
        *(.rodata*)             /* Read-only data (constants go here) */
        _text_end = .;          /* Marks the end of the .text segment */
    } > FLASH

    /*
     * Data section
     * Contains initialized variables which are copied to RAM upon RESET (defined in startup.c)
     */
    .data : 
    {
        . = ALIGN(4);
        _data = .;      /* Marks the beginning of the .data segment */
        *(.data*)
        *(vtable*)
        _data_end = .;  /* Marks the end of the .data segment */
    } > RAM AT > FLASH  /* Puts the .data segment directly after the .text section in FLASH */

    /* 
     * Uninitialized data section
     * Contains uninitialized variables which are initialized to 0 upon RESET
     * (defined in startup.c)
     */
    .bss :
    {
        _bss = .;      /* Marks the beginning of the .bss segment */
        __bss_start__ = .;
        *(.bss*)
        . = ALIGN(4);
        *(COMMON)
        . = ALIGN(4);
        _bss_end = .;  /* Marks the end of the .bss segment */
        __bss_end__ = .;
    } > RAM
}
