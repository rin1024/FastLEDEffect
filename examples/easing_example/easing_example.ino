// 
#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
FASTLED_USING_NAMESPACE
#include "EasingEffect.h"

#define __COMPILE_DATE__ __DATE__ " " __TIME__
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define DATA_PIN    3
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS    100

CRGB leds[NUM_LEDS];

EasingEffect effect;

void setup() {
  Serial.begin(115200);
  delay(3000); // 3 second delay for recovery

  char buff[50];
  sprintf(buff, "[%s] %s", __COMPILE_DATE__, __FILENAME__);
  Serial.println(buff);

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip);

  effect.setup(leds, NUM_LEDS);
}

void loop() {
  effect.loop();
  FastLED.show();  
}
