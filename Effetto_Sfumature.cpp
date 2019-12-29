#include "Effetto_Sfumature.h"

Effetto_Sfumature::Effetto_Sfumature() : Effetto() {
  this->color.setRGB(255,   0,   0);
  this->color.setHSV(  0, 255, 255);
  speedDivider = 0;
}
Effetto_Sfumature::Effetto_Sfumature(Pix *pix, int speed) : Effetto(pix, 0, speed) {
  this->ampiezza = ampiezza;
  this->color.setRGB(255,   0,   0);
  this->color.setHSV(  0, 255, 255);
}

void Effetto_Sfumature::update() {
  if (this->speedDivider++ > this->speed) {
    this->speedDivider = 0;
    this->color.h++;
    this->color.HSV2RGB();
    for (int i = 0; i < MAX_PIXELS; i++) this->pix[i].setRGB(this->color);
  }
}

void Effetto_Sfumature::manageSubCommand(long key) {
  switch (key) {
    case KEY_SLOW_DOWN:     if (this->speed >   1) this->speed--; break;
    case KEY_SPEED_UP:      if (this->speed < 255) this->speed++; break;
    default: SON("CODE not found: " + String(key, HEX));
  }
  SON("Speed: " + String(this->speed));
}
