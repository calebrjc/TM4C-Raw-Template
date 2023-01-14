// File: startup.c
// Author: Caleb Johnson-Cantrell

#include "startup.h"

void Default_Handler(void) {
    while (1) {
        // Loop forever
    }
}

void Reset_Handler(void) {
    uint32_t *src, *dest;

    // Copy the .data section into RAM
    src = &_text_end;
    for (dest = &_data; dest < &_data_end; dest++, src++) {
        *dest = *src;
    }

    // Zero out the .bss section
    for (dest = &_bss; dest < &_bss_end; dest++) {
        *dest = 0;
    }

    /* your program's main() called */
    main();
}

// The vector table
//
// The prepended annotation specifies that this table should be plalced at the `.vector_table`
// marker in the linker script
__attribute__((section(".vector_table"))) const VectorTableEntry vectors[] = {
    {.ptr = &_stack_ptr},        //    0  Initial stack pointer
    {Reset_Handler},             //    1  Reset routine
    {NMI_Handler},               //    2  Non-Maskable Interrupt handler
    {HardFault_Handler},         //    3  Hard Fault Handler
    {MemManageFault_Handler},    //    4  MPU fault Handler
    {BusFault_Handler},          //    5  Bus Fault Handler
    {UsageFault_Handler},        //    6  Usage Fault Handler
    {0},                         //    7  Reserved
    {0},                         //    8  Reserved
    {0},                         //    9  Reserved
    {0},                         //   10  Reserved
    {SVC_Handler},               //   11  SuperVisor Call Handler
    {DebugMonitor_Handler},      //   12  Debug Monitor Handler
    {0},                         //   13  Reserved
    {PendSV_Handler},            //   14  Pendeable Interrupt-Driven Request Handler
    {SysTick_Handler},           //   15  SysTick Timer handler
    {GPIOPortA_ISR},             //   16  GPIO Port A
    {GPIOPortB_ISR},             //   17  GPIO Port B
    {GPIOPortC_ISR},             //   18  GPIO Port C
    {GPIOPortD_ISR},             //   19  GPIO Port D
    {GPIOPortE_ISR},             //   20  GPIO Port C
    {UART0_ISR},                 //   21  UART0
    {UART1_ISR},                 //   22  UART1
    {SPI0_ISR},                  //   23  SPI0
    {I2C0_ISR},                  //   24  I2C0
    {PWM0Fault_ISR},             //   25  PWM0 Fault
    {PWM0Generator0_ISR},        //   26  PWM0 Generator 0
    {PWM0Generator1_ISR},        //   27  PWM0 Generator 1
    {PWM0Generator2_ISR},        //   28  PWM0 Generator 2
    {QEI0_ISR},                  //   29  Quadrature Encoder 0
    {ADC0Sequence0_ISR},         //   30  ADC0 Sequence 0
    {ADC0Sequence1_ISR},         //   31  ADC0 Sequence 1
    {ADC0Sequence2_ISR},         //   32  ADC0 Sequence 2
    {ADC0Sequence3_ISR},         //   33  ADC0 Sequence 3
    {WatchDogTimer_ISR},         //   34  WatchDog Timer
    {Timer0A_ISR},               //   35  Timer0 Subtimer A
    {Timer0B_ISR},               //   36  Timer0 Subtimer B
    {Timer1A_ISR},               //   37  Timer1 Subtimer A
    {Timer1B_ISR},               //   38  Timer1 Subtimer B
    {Timer2A_ISR},               //   39  Timer2 Subtimer A
    {Timer2B_ISR},               //   40  Timer2 Subtimer B
    {AnalogComparator0_ISR},     //   41  Analog Comparator 0
    {AnalogComparator1_ISR},     //   42  Analog Comparator 1
    {0},                         //   43  Analog Comparator 2
    {SystemCtrl_ISR},            //   44  System Control (PLL, OSC, BO)
    {FlashCtrl_ISR},             //   45  FLASH Control
    {GPIOPortF_ISR},             //   46  GPIO Port F
    {0},                         //   47  Reserved
    {0},                         //   48  Reserved
    {UART2_ISR},                 //   49  UART2
    {SPI1_ISR},                  //   50  SPI1
    {Timer3A_ISR},               //   51  Timer3 Subtimer A
    {Timer3B_ISR},               //   52  Timer3 Subtimer B
    {I2C1_ISR},                  //   53  I2C1
    {QEI1_ISR},                  //   54  Quadrature Encoder 1
    {CAN0_ISR},                  //   55  CAN0
    {CAN1_ISR},                  //   56  CAN1
    {0},                         //   57  Reserved
    {0},                         //   58  Reserved
    {Hibernation_ISR},           //   59  Hibernation
    {USB0_ISR},                  //   60  USB0
    {PWM0Generator3_ISR},        //   61  PWM0 Generator 3
    {UDMASoftware_ISR},          //   62  uDMA Software Transfer
    {UDMAError_ISR},             //   63  uDMA Error
    {ADC1Sequence0_ISR},         //   64  ADC1 Sequence 0
    {ADC1Sequence1_ISR},         //   65  ADC1 Sequence 1
    {ADC1Sequence2_ISR},         //   66  ADC1 Sequence 2
    {ADC1Sequence3_ISR},         //   67  ADC1 Sequence 3
    {0},                         //   68  Reserved
    {0},                         //   69  Reserved
    {0},                         //   70  GPIO Port J
    {0},                         //   71  GPIO Port K
    {0},                         //   72  GPIO Port L
    {SPI2_ISR},                  //   73  SPI2
    {SPI3_ISR},                  //   74  SPI3
    {UART3_ISR},                 //   75  UART3
    {UART4_ISR},                 //   76  UART4
    {UART5_ISR},                 //   77  UART5
    {UART6_ISR},                 //   78  UART6
    {UART7_ISR},                 //   79  UART7
    {0},                         //   80  Reserved
    {0},                         //   81  Reserved
    {0},                         //   82  Reserved
    {0},                         //   83  Reserved
    {I2C2_ISR},                  //   84  I2C2
    {I2C3_ISR},                  //   85  I2C3
    {Timer4A_ISR},               //   86  Timer4 Subtimer A
    {Timer4B_ISR},               //   87  Timer4 Subtimer B
    {0},                         //   88  Reserved
    {0},                         //   89  Reserved
    {0},                         //   90  Reserved
    {0},                         //   91  Reserved
    {0},                         //   92  Reserved
    {0},                         //   93  Reserved
    {0},                         //   94  Reserved
    {0},                         //   95  Reserved
    {0},                         //   96  Reserved
    {0},                         //   97  Reserved
    {0},                         //   98  Reserved
    {0},                         //   99  Reserved
    {0},                         //  100  Reserved
    {0},                         //  101  Reserved
    {0},                         //  102  Reserved
    {0},                         //  103  Reserved
    {0},                         //  104  Reserved
    {0},                         //  105  Reserved
    {0},                         //  106  Reserved
    {Timer5A_ISR},               //  107  Timer5 Subtimer A
    {Timer5B_ISR},               //  108  Timer5 Subtimer B
    {WideTimer0A_ISR},           //  109  WideTimer0 Subtimer A
    {WideTimer0B_ISR},           //  110  WideTimer0 Subtimer B
    {WideTimer1A_ISR},           //  111  WideTimer1 Subtimer A
    {WideTimer1B_ISR},           //  112  WideTimer1 Subtimer B
    {WideTimer2A_ISR},           //  113  WideTimer2 Subtimer A
    {WideTimer2B_ISR},           //  114  WideTimer2 Subtimer B
    {WideTimer3A_ISR},           //  115  WideTimer3 Subtimer A
    {WideTimer3B_ISR},           //  116  WideTimer3 Subtimer B
    {WideTimer4A_ISR},           //  117  WideTimer4 Subtimer A
    {WideTimer4B_ISR},           //  118  WideTimer4 Subtimer B
    {WideTimer5A_ISR},           //  119  WideTimer5 Subtimer A
    {WideTimer5B_ISR},           //  120  WideTimer6 Subtimer B
    {SystemException_ISR},       //  121  FPU
    {0},                         //  122  Reserved
    {0},                         //  123  Reserved
    {0},                         //  124  Reserved
    {0},                         //  125  Reserved
    {0},                         //  126  Reserved
    {0},                         //  127  Reserved
    {0},                         //  128  Reserved
    {0},                         //  129  Reserved
    {0},                         //  130  Reserved
    {0},                         //  131  Reserved
    {0},                         //  132  Reserved
    {0},                         //  133  Reserved
    {0},                         //  134  Reserved
    {0},                         //  135  Reserved
    {0},                         //  136  Reserved
    {0},                         //  137  Reserved
    {0},                         //  138  Reserved
    {0},                         //  139  Reserved
    {0},                         //  140  Reserved
    {0},                         //  141  Reserved
    {0},                         //  142  Reserved
    {0},                         //  143  Reserved
    {0},                         //  144  Reserved
    {0},                         //  145  Reserved
    {0},                         //  146  Reserved
    {0},                         //  147  Reserved
    {0},                         //  148  Reserved
    {PWM1Generator0_ISR},        //  149  PWM1 Generator 0
    {PWM1Generator1_ISR},        //  150  PWM1 Generator 1
    {PWM1Generator2_ISR},        //  151  PWM1 Generator 2
    {PWM1Generator3_ISR},        //  152  PWM1 Generator 3
    {PWM1Fault_ISR},             //  153  PWM1 Fault
};
