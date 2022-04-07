//
// Created by maoz on 03.09.2018.
//

#ifndef R1_COMMON_H
#define R1_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>

void delay(int waitTicks);
void delayMicroseconds(uint32_t delay);
void initHSE();

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif //R1_COMMON_H
