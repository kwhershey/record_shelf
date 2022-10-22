#include "FastLED.h"

// fast led constants
#define LED_PIN    2     // change to your data pin
//#define BUTTON_PIN 30 
#define COLOR_ORDER GRB      // if colors are mismatched; change this
#define NUM_LEDS    300       // change to the number of LEDs in your strip
#define BRIGHTNESS 32
#define LED_TYPE    WS2812B

CRGB leds[NUM_LEDS];
int startIndex=0;

void setup()
{
  delay(3000);
  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
    FastLED.clear();
    for(int i=0;i<NUM_LEDS;i++){
      leds[i].setHSV(startIndex,255,255);
      
    }
    FastLED.show();
    delay(30);

    startIndex=(startIndex+1)%255;
}
