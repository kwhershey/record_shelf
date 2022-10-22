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

void setup()
{
  delay(3000);
  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

}

void loop()
{
    
    for(int br=0;br<225;br++){
      FastLED.clear();
      for(int i=0;i<12;i++){
        for(int j=sections[i];j<sections[i+1];j++){
          if(i%2==0){
            leds[j].setHSV(15,255,br+25);
          }
          else{
            leds[j].setHSV(15,255,256-br);
          }
        }
      }
    
      FastLED.show();
      delay(1);
    }
    for(int br=0;br<225;br++){
      FastLED.clear();
      for(int i=0;i<12;i++){
        for(int j=sections[i];j<sections[i+1];j++){
          if(i%2==0){
            leds[j].setHSV(15,255,255-br);
          }
          else{
            leds[j].setHSV(15,255,br+25);
          }
        }
      }
    
      FastLED.show();
      delay(1);
    }

    startIndex=(startIndex+1)%255;
}
