//
// Created by maoz on 03.09.2018.
//

#include <stdint.h>
#include <MDR32Fx.h>
#include "common.h"


#ifdef __cplusplus
extern "C" {
#endif

void delay(int waitTicks) {
    int w8 = waitTicks / 18;
    volatile int i;
    for (i = 0; i < w8; i++) {
        asm("nop");
    }
}


/**
 * Инициализация тактирования на внешнем кварцевом резонаторе.
 */
void initHSE() {
    // HSE BYP режим осциллятора
    MDR_RST_CLK->HS_CONTROL &= ~RST_CLK_HS_CONTROL_HSE_BYP;
    // HSE ON включен
    MDR_RST_CLK->HS_CONTROL |= RST_CLK_HS_CONTROL_HSE_ON;
    // ожидаем готовности
    while (!(MDR_RST_CLK->CLOCK_STATUS & RST_CLK_CLOCK_STATUS_HSE_RDY));
}

#ifdef __cplusplus
} // extern "C" block end
#endif