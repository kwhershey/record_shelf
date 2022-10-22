#include "FastLED.h"

// fast led constants
#define LED_PIN    2     // change to your data pin
//#define BUTTON_PIN 30 
#define COLOR_ORDER GRB      // if colors are mismatched; change this
#define NUM_LEDS    241       // change to the number of LEDs in your strip
#define BRIGHTNESS 32
#define LED_TYPE    WS2812B

CRGB leds[NUM_LEDS];
int startIndex=0;
int sections[13] = {0,21,53,74,80,101,118,134,160,172,194,223,240};
int offsets[12] = {0,200,40,160,0,20,180,40,212,140,50,200};
void setup()
{
  delay(3000);
  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

}

void loop()
{
    
    for(int br=0;br<512;br++){
      FastLED.clear();
      for(int i=0;i<12;i++){
        for(int j=sections[i];j<sections[i+1];j++){

            leds[j].setHSV(15,255,abs((br+offsets[i])%505-254));

        }
      }
    
      FastLED.show();
      delay(1);
    }


    startIndex=(startIndex+1)%255;
}
