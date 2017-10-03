#ifndef nrf_millis_h
#define nrf_millis_h

#include <stdint.h>

//void setCurrentTick(uint32_t t);
//uint32_t millis(void);
uint32_t compareMillis(uint32_t previousMillis, uint32_t currentMillis);
//uint32_t millisPassed(uint32_t localMillis);

#endif
