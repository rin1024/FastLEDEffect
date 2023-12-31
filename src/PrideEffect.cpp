/**
 * PrideEffect
 *
 * カラフルな粒がくるくる回転(というか移動)する
 */
#include "PrideEffect.h"

/** 
 * This function draws rainbows with an ever-changing,
 * widely-varying set of parameters.
 */
void PrideEffect::loop() {
  uint8_t sat8 = beatsin88( 87, 220, 250);
  uint8_t brightdepth = 255;//beatsin88( 341, 96, 224);
  uint16_t brightnessthetainc16 = beatsin88( 203, (25 * 256), (40 * 256));
  uint8_t msmultiplier = beatsin88(147, 23, 60);

  uint16_t hue16 = sHue16;//gHue * 256;
  uint16_t hueinc16 = beatsin88(113, 1, 3000); // 個別の色変える場合のパラメータ?
  
  uint16_t ms = millis();
  uint16_t deltams = ms - sLastMillis;
  sLastMillis  = ms;
  sPseudotime += deltams * msmultiplier; // コメントアウトすると動きゆっくりになる
  sHue16 += deltams * beatsin88( 400, 5,9);
  uint16_t brightnesstheta16 = sPseudotime;
  
  for( uint16_t i = 0 ; i < numLeds; i++) {
    hue16 += hueinc16;
    uint8_t hue8 = hue16 / 256;

    brightnesstheta16  += brightnessthetainc16;
    uint16_t b16 = sin16( brightnesstheta16  ) + 32768;

    uint16_t bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
    uint8_t bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
    bri8 += (255 - brightdepth);
    
    CRGB newcolor = CHSV(hue8, sat8, bri8);
    
    uint16_t pixelnumber = i;
    pixelnumber = (numLeds - 1) - pixelnumber;
    
    // nblend( CRGB& existing, const CRGB& overlay, fract8 amountOfOverlay )
    nblend(leds[pixelnumber], newcolor, 64);

    // brightness対応用にblackとblendをかける
    leds[pixelnumber] = blend(CRGB::Black, leds[pixelnumber], getBrightness());
  }
}
