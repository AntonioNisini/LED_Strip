// LED_Strip
//
// Ciao Ale !!!
#include "common.h"
#define REMOTE_4x6
      
#include <IRremote.h>
#include "codes.h"

extern HardwareSerial Serial;

int led = LED_BUILTIN;
IRrecv ir(4);
decode_results results;
int cnt = 0;
long tmb = 0;

long lastKey = 0;

void setup() {

  Serial.begin(250000);
  while (!Serial) ;
  Serial.println("ciao");

  pinMode(led, OUTPUT);
  
  ir.enableIRIn(); // Start the receiver

}

void loop() {
  if (ir.decode(&results)) {
    if (cnt == 0) tmb = micros();
    if (cnt++ == 100) {
      Serial.println(micros() - tmb);
      cnt = 0;
    }
    SOF(results.value, HEX);
    SO(" \t");
    ir.resume();
    showCode();
    //digitalWrite(ctrlLed, HIGH);
    delay(25);
    //digitalWrite(ctrlLed, LOW);
  }
  bool x = ir.isIdle();
}

void showCode() {

  if (results.value != KEY_REPEAT) lastKey = results.value;

  switch (lastKey) {
    case KEY_SHRINK:        SON("SHRINK");            break;
      
    case KEY_ENLARGE:       SON("ENLARGE");           break; 
    case KEY_MOVE_LEFT:     SON("MOVE LEFT");         break;
    case KEY_MOVE_RIGHT:    SON("MOVE RIGHT");        break;
    
    case KEY_HUE_LEFT:      SON("HUE LEFT");          break;
    case KEY_HUE_RIGHT:     SON("HUE RIGHT");         break; 

    case KEY_DESATURATE:    SON("DESATURATE");        break;
    case KEY_SATURATE:      SON("SATURATE");          break;
    case KEY_BRIGHTER:      SON("BRIGHTER");          break;
    case KEY_DARKER:        SON("DARKER");            break;
    
    case KEY_ALL_LEDS:      SON("ALL LEDS");          break;
    
    case KEY_EXIT_SETTING:  SON("FLASH");             break;
    case KEY_FADE:          SON("FADE");              break;
    case KEY_CENTER:        SON("CENTER");            break;
    
    case KEY_FULL_COLOR:    SON("FULL COLOR");        break;
    case KEY_WHITE:         SON("WHITE");             break;

    case KEY_ON:            SON("ON");                break;
    case KEY_OFF:           SON("OFF");               break;

    case KEY_RED:           SON("RED");               break;
    case KEY_GREEN:         SON("GREEN");             break;
    case KEY_BLUE:          SON("BLUE");              break;
    case KEY_YELLOW:        SON("YELLOW");            break;
    case KEY_CYAN:          SON("CYAN");              break;
    case KEY_MAGENTA:       SON("MAGENTA");           break;

    default: SO("CODE not found: "); SONF(results.value, HEX);
  }
}
