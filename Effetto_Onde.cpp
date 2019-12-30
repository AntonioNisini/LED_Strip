#include "Effetto_Onde.h"

/**************
 * Classe Onda
 **************/

Onda::Onda(Pix *pix) : Onda(pix, AMPIEZZA, 0) {}
Onda::Onda(Pix *pix, int ampiezza, uint16_t hue) : Onda(pix, ampiezza, hue, POSIZIONE, VERSO, SPEED) {}
Onda::Onda(Pix *pix, int ampiezza, uint16_t hue, int posizione, int verso, int speed) : Attuatore(pix, posizione,verso, speed) {
  this->ampiezza = ampiezza;
  this->color.setHSV(hue, 255, 255);
  this->color.HSV2RGB(); 
}

void Onda::setHue(uint16_t hue) { 
  this->color.hue = hue;
  this->color.HSV2RGB(); 
  //SON(String("Onda: ") + PIX2STRING(this->color));
}

void Onda::update() {
  //SO("u");
  this->backAndForth(-this->ampiezza, MAX_PIXELS);
}

void Onda::draw() {
  //SO("d(" + String(this->ampiezza) + ") ");
  for (int i = 0; i < this->ampiezza; i++) {
    if (this->posizioneValida(this->posizione + i)) {
      this->pix[this->posizione + i].addRGB(this->color);
      this->pix[this->posizione + i].RGB2HSV();
      //SON(PIX2STRING(this->pix[this->posizione + i]));
    }
  }
}



/**********************
 * Classe Effetto_Onde
 **********************/

Effetto_Onde::Effetto_Onde() : Effetto() {
  this->color.setRGB(255,   0,   0);
  this->color.setHSV(  0, 255, 255);
  speedDivider = 0;
}
Effetto_Onde::Effetto_Onde(Onda *onde, int nOnde, Pix *pix, int speed) : Effetto(pix, 0, speed) {
  this->nOnde = nOnde;
  this->onde = onde;
  this->ampiezza = ampiezza;
  this->color.setRGB(255,   0,   0);
  this->color.setHSV(  0, 255, 255);
}

void Effetto_Onde::update() {
  //SON("fill(" + String(this->nOnde) + ") ");
  this->fill(0, 0 , 0);
  for (int i = 0; i < this->nOnde; i++) {
    Serial.print(String("A:") + String(i));
    this->onde[i].update();
    this->onde[i].draw();
  }
}

void Effetto_Onde::manageSubCommand(long key) {
  switch (key) {
    case KEY_SLOW_DOWN:     if (this->speed >   1) this->speed--; break;
    case KEY_SPEED_UP:      if (this->speed < 255) this->speed++; break;
    default: SON("CODE not found: " + String(key, HEX));
  }
  SON("Speed: " + String(this->speed));
}