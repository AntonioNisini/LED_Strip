#ifdef INFRAROSSO

//#define IR_TEST

#ifdef ARDUINO_IDE
#include <IRremote.h>
#include "IR_Codes.h"

IRrecv ir(IR_PIN);
decode_results results;

#define KEY_PRESS_TIME_FOR_SETTING  5000
#define KEY_TIME_ABORT_SETTING      1000

#define KEY_PRESS_TIME_FOR_MODE     2000
#define KEY_TIME_ABORT_MODE         1000

long lastKey = 0;

long initial_SHRINK_pressTime = 0; 
long last_SHRINK_pressTime = 0; 

long last_OFF_pressTime = 0;
long initial_OFF_pressTime = 0; 
#endif

Effetto *getAnimation(int idx) {
  Effetto *e;
    
  int cAnimation = 1;
  if (idx == cAnimation++) e = &ec;
  else if (idx == cAnimation++) e = &es; 
  else e = 0;
  return e;  
}

void performDynamic() {
  //SO("\n0");

  Effetto *e = getAnimation(currentAnimation);
  
  updateNeeded = true;
  if (ir.decode(&results)) {
    SO("a");
    //Serial.println(results.value, HEX);
    ir.resume(); 

    if (results.value != KEY_REPEAT) {
      SO("b");
      lastKey = results.value;
    }
    //serialPrintlnModeStatus();

    switch (lastKey) {
      case KEY_PREVIOUS_ANIMATION:
        SO("c");     
        if (--currentAnimation == 0) currentAnimation = NUMERO_EFFETTI;   
        animationCounter = 0;
        animationDirection = 1;
        SON("KEY_PREVIOUS_AMINATION: " + String(currentAnimation));
        break;
      case KEY_NEXT_ANIMATION:
        SO("d");     
        if (++currentAnimation > NUMERO_EFFETTI) currentAnimation = 1;   
        animationCounter = 0;
        animationDirection = 1;
        SON("KEY_NEXT_ANIMATION: " + String(currentAnimation));
        break;
      case KEY_EXIT_DYNAMIC:
        SO("e");  
        animationCounter = 0;
        animationDirection = 1;
        SON("EXIT DYNAMIC");
        initial_OFF_pressTime = 0;
        last_OFF_pressTime = 0; 
        mode = MODE_STATIC;
        dm.stripBlink(6, 50);
        return;  
        break;
 
      default: 
        SO("f"); 
        if (e != 0) e->manageSubCommand(lastKey);
        else updateNeeded = false;
    }
    if (updateNeeded) {
      SO("g");
      dm.stripOFF(0, MAX_LEDS);
      dm.stripFullON();
      dm.draw();
    }
  }
  
  e = getAnimation(currentAnimation);
  if (e != 0) {
    e->update();
    //SON(e->toString()); 
  }
}

void setLedCount() {

  if (ir.decode(&results)) {
    //Serial.println(results.value, HEX);
    ir.resume(); 

    if (results.value != KEY_REPEAT) lastKey = results.value;
    
    updateNeeded = true;
    switch (lastKey) {
      case KEY_LESS_LEDS:     
        SON("LESS LEDS");
        if (ledNumLimit > 1) ledNumLimit--;   
        break;
      case KEY_MORE_LEDS:     
        SON("MORE LEDS");
        if (ledNumLimit < MAX_LEDS) ledNumLimit++; 
        break;
      case KEY_EXIT_SETTING:  SON("EXIT SETTING");
        initial_SHRINK_pressTime = 0;
        last_SHRINK_pressTime = 0;
        currentStatus = STATUS_WORKING;
        dm.stripBlink();
        // settingLedCount = false;
        return;  
        break;
 
      default: updateNeeded = false;
    }
    staticLedWidth = ledNumLimit; 
    if (updateNeeded) {
      dm.stripOFF();
      dm.stripFullON(0, ledNumLimit);
      dm.draw();
    }
  }
  delay(100);
}
/*
void manageMode() {
    
  long mil = millis();
  SON(String(mil) + " " + String(last_OFF_pressTime) + " " + String(initial_OFF_pressTime));

  if (mode == MODE_STATIC) {        
    SON("OFF"); vValue = 0;
    initial_OFF_pressTime = mil; 
    mode = MODE_ENTERING_DYNAMIC;
  } 
  else if (mode == MODE_ENTERING_DYNAMIC) {
    if (mil < last_OFF_pressTime) {
      initial_OFF_pressTime = mil; 
    }
    if (mil - last_OFF_pressTime > KEY_TIME_ABORT_MODE) {
      initial_OFF_pressTime = 0;
      mode = MODE_STATIC;
    } else {
      if (mil - initial_OFF_pressTime > KEY_PRESS_TIME_FOR_MODE) {
        mode = MODE_DYNAMIC;
        dm.stripBlink(6, 50);
        dm.stripOFF();
        dm.draw();
      }
      else { 
        SON("WAITING FOR ENTERING DYNAMIC");
      }
    }
  } 
  else if (mode == MODE_DYNAMIC) {
    //serialPrintln("STATUS_SETTING");
    SON("SHOULDN'T BE HERE");
  }
  last_OFF_pressTime = mil;
}
*/
void manageSetting() {
    
  long mil = millis();
  SON(String(mil) + " " + String(last_SHRINK_pressTime) + " " + String(initial_SHRINK_pressTime));

  if (currentStatus == STATUS_WORKING) { 
    SON("SHRINK"); speed =  1; staticResizeStrip( -1 );
    // serialPrintln("STATUS_WORKING");
    initial_SHRINK_pressTime = mil; 
    currentStatus = STATUS_ENTERING_SETTING;
  } 
  else if (currentStatus == STATUS_ENTERING_SETTING) {
    SON("SHRINK"); speed =  1; staticResizeStrip( -1 );
    // serialPrint("STATUS_ENTERING_SETTING");
    if (mil < last_SHRINK_pressTime) {
      initial_SHRINK_pressTime = mil; 
    }
    if (mil - last_SHRINK_pressTime > KEY_TIME_ABORT_SETTING) {
      initial_SHRINK_pressTime = 0;
      currentStatus = STATUS_WORKING;
    } else {
      if (mil - initial_SHRINK_pressTime > KEY_PRESS_TIME_FOR_SETTING) {
        currentStatus = STATUS_SETTING;
        dm.stripBlink();
        staticLedWidth = ledNumLimit; 
        dm.stripOFF();
        dm.stripFullON();
        dm.draw();
      }
      else { 
        SON("WAITING FOR ENTERING SETTING");
      }
    }
  } 
  else if (currentStatus == STATUS_SETTING) {
    //serialPrintln("STATUS_SETTING");
    SON("SHOULDN'T BE HERE");
  }
  last_SHRINK_pressTime = mil;
}

void loopStatic() {

#ifndef IR_TEST
  if (currentStatus == STATUS_SETTING) {
    // SON("STATUS_SETTING");
    setLedCount();
    return;
  }
  if (ir.decode(&results)) {
    SONF(results.value, HEX);
    ir.resume(); 

    if (results.value != KEY_REPEAT) lastKey = results.value;
    printModeStatus();

    if (lastKey != KEY_SHRINK) {
      initial_SHRINK_pressTime = 0;
      last_SHRINK_pressTime = 0;
      currentStatus = STATUS_WORKING;
    }
    
    updateNeeded = true;
    switch (lastKey) {
      case KEY_SHRINK:        manageSetting();                                                                  break;
        
      case KEY_ENLARGE:       SON("ENLARGE");      speed =  1;    staticResizeStrip(               1 );         break; 
      case KEY_MOVE_LEFT:     SON("MOVE LEFT");    speed =  1;    staticPositionStrip(-switchLeftRight );       break;
      case KEY_MOVE_RIGHT:    SON("MOVE RIGHT");   speed =  1;    staticPositionStrip( switchLeftRight );       break;
      
      case KEY_HUE_LEFT:      SON("HUE LEFT");     speed =  4;    staticSetHue(                -1 );            break;
      case KEY_HUE_RIGHT:     SON("HUE RIGHT");    speed =  4;    staticSetHue(                 1 );            break; 

      case KEY_DESATURATE:    SON("DESATURATE");   speed = 16;    staticSetSaturation(         -1 );            break;
      case KEY_SATURATE:      SON("SATURATE");     speed = 16;    staticSetSaturation(          1 );            break;
      case KEY_BRIGHTER:      SON("BRIGHTER");     speed =  8;    staticSetValue(              -1 );            break;
      case KEY_DARKER:        SON("DARKER");       speed =  8;    staticSetValue(               1 );            break;
      
      case KEY_ALL_LEDS:      SON("ALL LEDS");     staticLedWidth = ledNumLimit;                                break;
      
      case KEY_CENTER:        SON("CENTER");       staticLedPosition = ledNumLimit / 2 + 1;                     break;
      
      case KEY_FULL_COLOR:    SON("FULL COLOR");   vSaturation = 255;                                           break;
      case KEY_WHITE:         SON("WHITE");        vSaturation =   0; vValue = 255;                             break;

      //case KEY_ON:            manageMode();                                                                   break;
      case KEY_ENTER_DYNAMIC: 
        mode = MODE_DYNAMIC;
        dm.stripBlink(6, 50);
        dm.stripOFF();
        dm.draw();
        break;
      case KEY_OFF:           SON("OFF");          vSaturation =   0; vValue = 0;                               break;
 
      case KEY_RED:           currentPix.red = 255; currentPix.green =   0; currentPix.blue =   0; vHue =   0;  break;
      case KEY_GREEN:         currentPix.red =   0; currentPix.green = 255; currentPix.blue =   0; vHue =  85;  break;
      case KEY_BLUE:          currentPix.red =   0; currentPix.green =   0; currentPix.blue = 255; vHue = 170;  break;
      case KEY_YELLOW:        currentPix.red = 255; currentPix.green = 255; currentPix.blue =   0; vHue =  43;  break;
      case KEY_CYAN:          currentPix.red =   0; currentPix.green = 255; currentPix.blue = 255; vHue = 128;  break;
      case KEY_MAGENTA:       currentPix.red = 255; currentPix.green =   0; currentPix.blue = 255; vHue = 213;  break;
 
      default: updateNeeded = false; SO("CODE not found: "); SONF(results.value, HEX);
    }
    if (updateNeeded) {
      //digitalWrite(ctrlLed, !digitalRead(ctrlLed));
      switch (lastKey) {
        case KEY_RED:
        case KEY_GREEN:
        case KEY_BLUE:
        case KEY_YELLOW:
        case KEY_CYAN:  
        case KEY_MAGENTA:  dm.setStripRangeCentered(currentPix, staticLedPosition, staticLedWidth); vSaturation = 255; vValue = 255; break; 
  
        default:           dm.setStripRangeCenteredHSV(currentPix, staticLedPosition, staticLedWidth, vHue, vSaturation, vValue);
      } 
    }
  }
  delay(100);
#else
  if (ir.decode(&results)) {
    SONF(results.value, HEX);
    ir.resume(); 

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
  delay(100);
#endif

}

void loopDynamic() {
  
  dm.draw();

  performDynamic();
  //ec.update();
  return;

}

void _SETUP_() {

  SON("INFRAROSSO");
  ir.enableIRIn();
  
}

void _LOOP_() {

  switch (mode) {
    case MODE_STATIC:  loopStatic();  break;
    case MODE_DYNAMIC: loopDynamic(); break;
  }
  
}

bool IcanDraw() {
  return ir.isIdle();
}
#endif
