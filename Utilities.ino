#include "Utilities.h"

void staticResizeStrip(int delta) {

  if (delta == 0) return;

  if (staticLedWidth == 0) staticLedWidth = (stripIsEven) ? 2 * delta : delta;
  else staticLedWidth += 2 * delta;
  
  if (staticLedWidth < 0) staticLedWidth = 0; 
  else if (ledNumLimit < staticLedWidth) staticLedWidth = ledNumLimit;
  else ;  

  SON("Strip width: " + String(staticLedWidth));
}

void staticPositionStrip(int delta) {

  if (delta == 0) return;

  staticLedPosition += delta * speed;
  
  if (staticLedPosition < 0) staticLedPosition = 0; 
  else if (ledNumLimit < staticLedPosition) staticLedPosition = ledNumLimit;
  else ;  

  adjustSpeed();

}

void staticSetHue(int delta) {

  if (delta == 0) return;

  int newValue = vHue + delta * speed;
  
  if (newValue < 0) vHue = 0; 
  else if (255 < newValue) vHue = 255;
  else vHue = newValue;  

  adjustSpeed();

}

void staticSetSaturation(int delta) {

  if (delta == 0) return;

  int newValue = vSaturation + delta * speed;
  
  if (newValue < 0) vSaturation = 0; 
  else if (255 < newValue) vSaturation = 255;
  else vSaturation = newValue;  

  adjustSpeed();

}

void staticSetValue(int delta) {

  if (delta == 0) return;

  int newValue = vValue + delta * speed;
  
  if (newValue < 0) vValue = 0; 
  else if (255 < newValue) vValue = 255;
  else vValue = newValue;  

  adjustSpeed();

}

void adjustSpeed() {
  
  if (++nSpeed == SPEED_INTERVAL) {
    if (speed < 16) speed *= 2;
    nSpeed = 0;
  }
  
}

bool isEven(int value) { return (value == (value / 2) * 2); }

void printModeStatus() {
  switch (mode) {
    case MODE_STATIC:           SO("MODE_STATIC           - "); break;
    case MODE_ENTERING_DYNAMIC: SO("MODE_ENTERING_DYNAMIC - "); break;
    case MODE_DYNAMIC:          SO("MODE_DYNAMIC          - "); break;
    case MODE_ENTERING_STATIC:  SO("MODE_ENTERING_STATIC  - "); break;
  }
  switch (currentStatus) {
    case STATUS_WORKING:          SO("STATUS_WORKING          - "); break;
    case STATUS_ENTERING_SETTING: SO("STATUS_ENTERING_SETTING - "); break;
    case STATUS_SETTING:          SO("STATUS_SETTING          - "); break;
  }
  switch (lastKey) {
    case KEY_SHRINK:     SON("SHRINK"); break;
    case KEY_ENLARGE:    SON("ENLARGE"); break; 
    case KEY_MOVE_LEFT:  SON("MOVE LEFT"); break;
    case KEY_MOVE_RIGHT: SON("MOVE RIGHT"); break;
    case KEY_HUE_LEFT:   SON("HUE LEFT"); break;
    case KEY_HUE_RIGHT:  SON("HUE RIGHT"); break; 
    case KEY_DESATURATE: SON("DESATURATE"); break;
    case KEY_SATURATE:   SON("SATURATE"); break;
    case KEY_BRIGHTER:   SON("BRIGHTER"); break;
    case KEY_DARKER:     SON("DARKER"); break;
    case KEY_ALL_LEDS:   SON("ALL LEDS"); break;
    case KEY_CENTER:     SON("CENTER"); break;
    case KEY_FULL_COLOR: SON("FULL COLOR"); break;
    case KEY_WHITE:      SON("WHITE"); break;
    case KEY_OFF:        SON("OFF"); break;
    case KEY_RED:        SON("RED"); break;
    case KEY_GREEN:      SON("GREEN"); break;
    case KEY_BLUE:       SON("BLUE"); break;
    case KEY_YELLOW:     SON("YELLOW"); break;
    case KEY_CYAN:       SON("CYAN"); break;
    case KEY_MAGENTA:    SON("MAGENTA"); break;
    default:             Serial.println(lastKey, HEX);
  }
}
