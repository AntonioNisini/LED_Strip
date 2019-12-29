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
      
#include <IRremote.h>
#include "IR_Codes.h"

extern HardwareSerial Serial;

int led = LED_BUILTIN;
IRrecv ir(4);
decode_results results;
int cnt = 0;
long tmb = 0;

long lastKey = 0;

#include "Infrarosso.ino"

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
