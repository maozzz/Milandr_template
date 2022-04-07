#include "MDR32Fx.h"
#include "common.h"

volatile uint16_t w;

int main(void) {
    initHSE();
    // Тактирование порта С
    MDR_RST_CLK->PER_CLOCK |= (1 << RST_CLK_PER_CLOCK_PCLK_EN_PORTC_Pos);

    MDR_PORTC->OE |= (1 << 0);
    MDR_PORTC->FUNC &= ~PORT_FUNC_MODE10_Msk | 0b00;
    MDR_PORTC->PWR |= (0x1 << PORT_PWR0_Pos);
    MDR_PORTC->ANALOG |= (1 << 0);

    while (1) {
        if (MDR_PORTC->RXTX & 0x1)
            MDR_PORTC->RXTX &= ~((uint16_t) 0x1);
        else
            MDR_PORTC->RXTX |= 0x01;
        delay(8000000);
    }
}

#ifdef __cplusplus
extern "C" {
#endif

void SysTick_Handler(void) {
}

void Default_Handler(void) {
    asm("nop");
}

void WWDG_IRQHandler(void) {
    asm("nop");
}

#ifdef __cplusplus
} // extern "C" block end
#endif