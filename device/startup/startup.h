// File: startup.h
// Author: Caleb Johnson-Cantrell

#include <stdint.h>

// All ISRs and handler functions are of this type
typedef void (*HandlerFunction)(void);

// Defines a type for the vector table (avoids a lot of casting)
typedef union {
    HandlerFunction handler_func;  // all ISRs use this type
    void *ptr;                     // pointer to top of the stack
} VectorTableEntry;

// Program entry point
extern int main(void);

// Stack pointer
extern uint32_t _stack_ptr;

// Start marker for the .text section
extern uint32_t _text;

// End marker for the .text section
extern uint32_t _text_end;

// Start marker for the .data section
extern uint32_t _data;

// End marker for the .data section
extern uint32_t _data_end;

// Start marker for the .bss section
extern uint32_t _bss;

// End marker for the .bss section
extern uint32_t _bss_end;

/**
 * The following section defines handler and ISR prototypes to be overriden when the user wants to
 * provide a handler for certain functionality.
 * 
 * NOTE(Caleb): Prototype names don't follow my normal naming conventions in order to follow normal
 * conventions for these functions.
 */

// Aliases a function prototype to default_handler if the function is not defined
#define OPTIONAL_OVERRIDE __attribute__((weak, alias("Default_Handler")))

// Default ISR/handler function which only freezes the processor with a tight infinite loop
void Default_Handler(void);

// Handles the processor's reset routine
void Reset_Handler(void);

OPTIONAL_OVERRIDE void NMI_Handler(void);
OPTIONAL_OVERRIDE void SVC_Handler(void);
OPTIONAL_OVERRIDE void DebugMonitor_Handler(void);
OPTIONAL_OVERRIDE void PendSV_Handler(void);
OPTIONAL_OVERRIDE void SysTick_Handler(void);

OPTIONAL_OVERRIDE void HardFault_Handler(void);
OPTIONAL_OVERRIDE void MemManageFault_Handler(void);
OPTIONAL_OVERRIDE void BusFault_Handler(void);
OPTIONAL_OVERRIDE void UsageFault_Handler(void);

OPTIONAL_OVERRIDE void ADC0Sequence0_ISR(void);
OPTIONAL_OVERRIDE void ADC0Sequence1_ISR(void);
OPTIONAL_OVERRIDE void ADC0Sequence2_ISR(void);
OPTIONAL_OVERRIDE void ADC0Sequence3_ISR(void);

OPTIONAL_OVERRIDE void ADC1Sequence0_ISR(void);
OPTIONAL_OVERRIDE void ADC1Sequence1_ISR(void);
OPTIONAL_OVERRIDE void ADC1Sequence2_ISR(void);
OPTIONAL_OVERRIDE void ADC1Sequence3_ISR(void);

OPTIONAL_OVERRIDE void AnalogComparator0_ISR(void);
OPTIONAL_OVERRIDE void AnalogComparator1_ISR(void);


OPTIONAL_OVERRIDE void SystemCtrl_ISR(void);
OPTIONAL_OVERRIDE void FlashCtrl_ISR(void);

OPTIONAL_OVERRIDE void CAN0_ISR(void);
OPTIONAL_OVERRIDE void CAN1_ISR(void);

OPTIONAL_OVERRIDE void GPIOPortA_ISR(void);
OPTIONAL_OVERRIDE void GPIOPortB_ISR(void);
OPTIONAL_OVERRIDE void GPIOPortC_ISR(void);
OPTIONAL_OVERRIDE void GPIOPortD_ISR(void);
OPTIONAL_OVERRIDE void GPIOPortE_ISR(void);
OPTIONAL_OVERRIDE void GPIOPortF_ISR(void);

OPTIONAL_OVERRIDE void Hibernation_ISR(void);

OPTIONAL_OVERRIDE void I2C0_ISR(void);
OPTIONAL_OVERRIDE void I2C1_ISR(void);
OPTIONAL_OVERRIDE void I2C2_ISR(void);
OPTIONAL_OVERRIDE void I2C3_ISR(void);

OPTIONAL_OVERRIDE void PWM0Fault_ISR(void);
OPTIONAL_OVERRIDE void PWM0Generator0_ISR(void);
OPTIONAL_OVERRIDE void PWM0Generator1_ISR(void);
OPTIONAL_OVERRIDE void PWM0Generator2_ISR(void);
OPTIONAL_OVERRIDE void PWM0Generator3_ISR(void);

OPTIONAL_OVERRIDE void PWM1Fault_ISR(void);
OPTIONAL_OVERRIDE void PWM1Generator0_ISR(void);
OPTIONAL_OVERRIDE void PWM1Generator1_ISR(void);
OPTIONAL_OVERRIDE void PWM1Generator2_ISR(void);
OPTIONAL_OVERRIDE void PWM1Generator3_ISR(void);

OPTIONAL_OVERRIDE void QEI0_ISR(void);
OPTIONAL_OVERRIDE void QEI1_ISR(void);

OPTIONAL_OVERRIDE void SPI0_ISR(void);
OPTIONAL_OVERRIDE void SPI1_ISR(void);
OPTIONAL_OVERRIDE void SPI2_ISR(void);
OPTIONAL_OVERRIDE void SPI3_ISR(void);

OPTIONAL_OVERRIDE void SystemException_ISR(void);

OPTIONAL_OVERRIDE void Timer0A_ISR(void);
OPTIONAL_OVERRIDE void Timer0B_ISR(void);

OPTIONAL_OVERRIDE void Timer1A_ISR(void);
OPTIONAL_OVERRIDE void Timer1B_ISR(void);

OPTIONAL_OVERRIDE void Timer2A_ISR(void);
OPTIONAL_OVERRIDE void Timer2B_ISR(void);

OPTIONAL_OVERRIDE void Timer3A_ISR(void);
OPTIONAL_OVERRIDE void Timer3B_ISR(void);

OPTIONAL_OVERRIDE void Timer4A_ISR(void);
OPTIONAL_OVERRIDE void Timer4B_ISR(void);

OPTIONAL_OVERRIDE void Timer5A_ISR(void);
OPTIONAL_OVERRIDE void Timer5B_ISR(void);

OPTIONAL_OVERRIDE void WideTimer0A_ISR(void);
OPTIONAL_OVERRIDE void WideTimer0B_ISR(void);

OPTIONAL_OVERRIDE void WideTimer1A_ISR(void);
OPTIONAL_OVERRIDE void WideTimer1B_ISR(void);

OPTIONAL_OVERRIDE void WideTimer2A_ISR(void);
OPTIONAL_OVERRIDE void WideTimer2B_ISR(void);

OPTIONAL_OVERRIDE void WideTimer3A_ISR(void);
OPTIONAL_OVERRIDE void WideTimer3B_ISR(void);

OPTIONAL_OVERRIDE void WideTimer4A_ISR(void);
OPTIONAL_OVERRIDE void WideTimer4B_ISR(void);

OPTIONAL_OVERRIDE void WideTimer5A_ISR(void);
OPTIONAL_OVERRIDE void WideTimer5B_ISR(void);

OPTIONAL_OVERRIDE void UART0_ISR(void);
OPTIONAL_OVERRIDE void UART1_ISR(void);
OPTIONAL_OVERRIDE void UART2_ISR(void);
OPTIONAL_OVERRIDE void UART3_ISR(void);
OPTIONAL_OVERRIDE void UART4_ISR(void);
OPTIONAL_OVERRIDE void UART5_ISR(void);
OPTIONAL_OVERRIDE void UART6_ISR(void);
OPTIONAL_OVERRIDE void UART7_ISR(void);


OPTIONAL_OVERRIDE void UDMASoftware_ISR(void);
OPTIONAL_OVERRIDE void UDMAError_ISR(void);

OPTIONAL_OVERRIDE void USB0_ISR(void);

OPTIONAL_OVERRIDE void WatchDogTimer_ISR(void);
