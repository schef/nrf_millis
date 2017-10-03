#include <stdio.h>
#include "nrf_millis.h"

//uint32_t tick = 0;
//
//void setCurrentTick(uint32_t t)
//{
//  tick = t;
//}
//
//uint32_t millis(void)
//{
//  return(tick / 32.768);
//}

#define OVERFLOW ((uint32_t)(0xFFFFFFFF/32.768))
uint32_t compareMillis(uint32_t previousMillis, uint32_t currentMillis)
{
  if(currentMillis < previousMillis) return(currentMillis + OVERFLOW + 1 - previousMillis);
  return(currentMillis - previousMillis);
}

//uint32_t millisPassed(uint32_t previousMillis)
//{
//  uint32_t currentMillis = millis();
//  if(currentMillis < previousMillis)
//  {
//    uint32_t overflow = 0xffffffff - previousMillis;
//    previousMillis += overflow;
//    currentMillis += overflow;
//  }
//  return(currentMillis - previousMillis);
//}
