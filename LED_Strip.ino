// LED_Strip
//
// Ciao Ale !!!

#define INFRAROSSO
//#define WIFI

#define PROGRAM_NAME "LED_Strip"
#define VERSION "1.0"

#include "common.h"
#include "Utilities.h"
#include "Effetto_Corsa.h"
#include "Effetto_Sfumature.h"
#include "Effetto_Onde.h"
      
#include <IRremote.h>
#include "IR_Codes.h"

extern HardwareSerial Serial;


int mode = MODE_STATIC;
int currentStatus = STATUS_WORKING;
bool updateNeeded;

int staticLedWidth = NUM_LEDS_START;
int staticLedPosition = NUM_LEDS_START / 2 + 1;

int ledNumLimit = NUM_LEDS_START;
int delayCycles = DELAY_CYCLES;

int switchLeftRight = -1;   // 1 = primo pixel a sx,  -1 = primo pixel a dx

int speed = 1;
int nSpeed = 0;

Pix currentPix;

uint8_t vHue = 0;
uint8_t vSaturation = 0;
uint8_t vValue = 255;

Pix pix[MAX_PIXELS];

int currentAnimation = 1;
long animationCounter = 0;
int animationDirection = 1;

bool stripIsEven = isEven(ledNumLimit);

DEVICE_MANAGER dm(pix);
Onda onde[] = {
  Onda(pix, 1, 0),
  Onda(pix, 2, 120),
  Onda(pix, 3, 240)
};

Effetto_Corsa ec(pix, 10, 0, 1);
Effetto_Sfumature es(pix, 1);
Effetto_Onde eo(onde, 3, pix, 1);

void setup() {

  Serial.begin(250000);
  while (!Serial) ;

  SON((String) PROGRAM_NAME + " " + VERSION);

  _SETUP_();

}

void loop() {

  _LOOP_(); 
  dm.draw();

}
