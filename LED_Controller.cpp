#include "LED_Controller.h"

LED_Controller::LED_Controller(Pix *pix) {
  this->pix = pix;
  FastLED.addLeds<WS2811, LED_PIN, BRG>(this->leds, MAX_LEDS);
  
}

void LED_Controller::stripOFF() {
  this->stripOFF(0, MAX_LEDS);
}
void LED_Controller::stripOFF(int start, int end) { // end excluded
  for (int i = start; i < end; i++) this->pix[i].setRGB(0, 0, 0); 
}

void LED_Controller::stripFullON() {
  this->stripFullON(0, MAX_LEDS);
}
void LED_Controller::stripFullON(int start, int end) { // end excluded
  for (int i = start; i < end; i++) this->pix[i].setRGB(255, 255, 255);
}

void LED_Controller::stripBlink() { stripBlink(3, 200); }
void LED_Controller::stripBlink(int count, int dly) {
  for (int i = 0; i < count; i++) {
    this->stripFullON();
    this->draw();
    delay(dly);
    this->stripOFF();
    this->draw();
    delay(dly);
  }
}

void LED_Controller::setStripRangeCentered(Pix &pix, int position, int width) {

  int pos, lowLimit, upLimit;
  
  lowLimit = position - width / 2 - ((stripIsEven()) ? 0 : 1);
  if (width == 0) upLimit =  lowLimit;
  else  upLimit =  position + width / 2;
  
  stripOFF();
  int minim = ledNumLimit;
  int maxim = 0;
  for (int i = lowLimit; i < upLimit; i++) {
    pos = (i < ledNumLimit) ? ((i < 0) ? i + ledNumLimit : i) : i - ledNumLimit;
    if (minim > pos) minim = pos;
    if (maxim < pos) maxim = pos;
    if (i < width / 2 + position) this->pix[pos].setRGB(pix);
    else this->pix[pos].setRGB(0, 0, 0);
  }
  
}

void LED_Controller::setStripRangeCenteredHSV(Pix &pix, int position, int width, byte hue, byte saturation, byte value) {
  this->HSV2RGB(pix, hue, saturation, value);
  this->setStripRangeCentered(pix, position, width);
}

void LED_Controller::HSV2RGB(Pix &pix, byte hue, byte saturation, byte value) {
  float h = 360.0 * hue / 255;
  float s = 1.0 * saturation / 255;
  float v = 1.0 * value / 255;
  // Serial.println("CHSV: (" + String(h) + ", " + String(s) + ", " + String(v) + ")");
  float r, g, b;
  this->HSVtoRGB(r, g, b, h, s, v);
  // Serial.println("CRGB1: (" + String(r) + ", " + String(g) + ", " + String(b) + ")");
  pix.r = 255 * r;
  pix.g = 255 * g;
  pix.b = 255 * b;
  // printCRGB(color);
}

void LED_Controller::HSVtoRGB(float& fR, float& fG, float& fB, float& fH, float& fS, float& fV) {
  float fC = fV * fS; // Chroma
  float fHPrime = fmod(fH / 60.0, 6);
  float fX = fC * (1 - fabs(fmod(fHPrime, 2) - 1));
  float fM = fV - fC;
  
  if(0 <= fHPrime && fHPrime < 1) {
    fR = fC;
    fG = fX;
    fB = 0;
  } else if(1 <= fHPrime && fHPrime < 2) {
    fR = fX;
    fG = fC;
    fB = 0;
  } else if(2 <= fHPrime && fHPrime < 3) {
    fR = 0;
    fG = fC;
    fB = fX;
  } else if(3 <= fHPrime && fHPrime < 4) {
    fR = 0;
    fG = fX;
    fB = fC;
  } else if(4 <= fHPrime && fHPrime < 5) {
    fR = fX;
    fG = 0;
    fB = fC;
  } else if(5 <= fHPrime && fHPrime < 6) {
    fR = fC;
    fG = 0;
    fB = fX;
  } else {
    fR = 0;
    fG = 0;
    fB = 0;
  }
  
  fR += fM;
  fG += fM;
  fB += fM;
}

void LED_Controller::draw() {
  this->draw(DELAY_CYCLES);  
}

void LED_Controller::draw(int delayCycles) {
  
  for (int i = 0; i <  MAX_LEDS; i++) {
    this->leds[i].r = this->pix[i].r;
    this->leds[i].g = this->pix[i].g;
    this->leds[i].b = this->pix[i].b; 
  }

  if (!IcanDraw()) {
    SO("*");
    return;
  }
  
  FastLED.show();
  delay(delayCycles);
}

void LED_Controller::update() {

  SON("LED_Controller->update()");
  
}

bool LED_Controller::stripIsEven() { return (ledNumLimit == (ledNumLimit / 2) * 2); }
