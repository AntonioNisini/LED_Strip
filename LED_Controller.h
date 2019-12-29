#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include "common.h"

#ifdef ARDUINO_IDE
#include <Arduino.h>
#include "FastLED.h"

extern int ledNumLimit;
extern bool IcanDraw();
#endif

class LED_Controller {

  private:
  Pix *pix;
  CRGB leds[MAX_LEDS];

  void HSV2RGB(Pix &pix, byte hue, byte saturation, byte value);
  void HSVtoRGB(float& fR, float& fG, float& fB, float& fH, float& fS, float& fV);

  public:
  LED_Controller(Pix *pix);

  void stripOFF();
  void stripOFF(int start, int end); // end excluded
  void stripFullON();
  void stripFullON(int start, int end); // end excluded
  void stripBlink();
  void stripBlink(int count, int dly);

  void setStripRangeCentered(Pix &pix, int position, int width);
  void setStripRangeCenteredHSV(Pix &pix, int position, int width, byte hue, byte saturation, byte value);
  void update();
  void draw();
  void draw(int delayCycles);
  
  bool stripIsEven();
  
};

#endif
