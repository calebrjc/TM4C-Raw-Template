#include <stdint.h>

#include <tm4c123gh6pm.h>

#define DELAY_CYCLES 2000000

void delay(volatile uint32_t delay_cycles) {
    for (uint32_t i = 0; i < delay_cycles; i++) {}
}

int main(void) {
    SYSCTL_RCGC2_R |= 0x00000020;     // 1) activate clock for Port F
    (void)SYSCTL_RCGC2_R;             // allow time for clock to start
    GPIO_PORTF_LOCK_R  = 0x4C4F434B;  // 2) unlock GPIO Port F
    GPIO_PORTF_CR_R    = 0x1F;        // allow changes to PF4-0
    GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog on PF
    GPIO_PORTF_PCTL_R  = 0x00000000;  // 4) PCTL GPIO on PF4-0
    GPIO_PORTF_DIR_R   = 0x0E;        // 5) PF4,PF0 in, PF3-1 out
    GPIO_PORTF_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
    GPIO_PORTF_PUR_R   = 0x11;        // enable pull-up on PF0 and PF4
    GPIO_PORTF_DEN_R   = 0x1F;        // 7) enable digital I/O on PF4-0

    while (1) {
        GPIO_PORTF_DATA_R ^= 0x02;
        delay(DELAY_CYCLES);
    }
}
