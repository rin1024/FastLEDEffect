/**
   FastLEDEffect
*/
#ifndef FAST_LED_EFFECT_H
#define FAST_LED_EFFECT_H

/*******************************************
   include
 *******************************************/
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <avr/pgmspace.h>
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <FastLED.h>

/*******************************************
   const
 *******************************************/
#define TEST_INTERVAL  1000
#define TEST_BRIGHTNESS 255

/**************************************************************************************
   class definition
 **************************************************************************************/
class FastLEDEffect {
  public:
    FastLEDEffect();
    ~FastLEDEffect();

    void setup(CRGB *_leds, uint16_t _numLeds = 5);
    void loop();
    void lazyLoop();

    uint16_t getBrightness();
    void setBrightness(uint16_t _brightness);

  protected:
    CRGB *leds; // CRGBSet
    uint16_t numLeds;

    uint8_t testIndex;
    uint32_t testTimer;

    uint16_t brightness;

    void setAndShowColor(CRGB _color);    
};

#endif
