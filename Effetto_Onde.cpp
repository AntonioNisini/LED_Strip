#include "Effetto_Onde.h"

Onda::Onda() {
  this->posizione = POSIZIONE;
  this->verso = VERSO;
  this->speed = SPEED;
  this->ampiezza = AMPIEZZA;
  this->color.setHSV(0, 255, 255);
  this->color.HSV2RGB(); 
}
Onda::Onda(Pix *pix) {
  this->posizione = POSIZIONE;
  this->verso = VERSO;
  this->speed = SPEED;
  this->ampiezza = AMPIEZZA;
  this->pix = pix;
  this->color.setHSV(0, 255, 255);
  this->color.HSV2RGB(); 
}
Onda::Onda(Pix *pix, int ampiezza, uint16_t hue) {
  this->posizione = POSIZIONE;
  this->verso = VERSO;
  this->speed = SPEED;
  this->ampiezza = ampiezza;
  this->pix = pix;
  this->color.setHSV(hue, 255, 255);
  this->color.HSV2RGB(); 
}
Onda::Onda(Pix *pix, int ampiezza, uint16_t hue, int posizione, int verso, int speed) {
  this->ampiezza = ampiezza;
  this->color.setHSV(hue, 255, 255);
  this->color.HSV2RGB(); 
}

void Onda::setHue(uint16_t hue) { 
  this->color.hue = hue;
  this->color.HSV2RGB(); 
  SON(String("Onda: ") + PIX2STRING(this->color));
}

void Onda::update() {
  SO("u");
  this->backAndForth(-this->ampiezza, MAX_PIXELS);
  //Attuatore::update();
}

void Onda::draw() {
  //SO("d(" + String(this->ampiezza) + ") ");
  for (int i = 0; i < this->ampiezza; i++) {
    //SO(String(this->posizione + i));
    if (this->posizioneValida(this->posizione + i)) {
      //SON(PIX2STRING(this->pix[this->posizione + i]) + "\n+\n" + PIX2STRING(this->color) + "\n=");
      this->pix[this->posizione + i].addRGB(this->color);
      //SON(PIX2STRING(this->pix[this->posizione + i]));
      this->pix[this->posizione + i].RGB2HSV();
      //Serial.print(String(this->pix[this->posizione + i].h) + "," + String(this->pix[this->posizione + i].s) + "," + String(this->pix[this->posizione + i].v));
      //SON(PIX2STRING(this->pix[this->posizione + i]));
    }
  }
  
  //Attuatore::draw();
}

void Onda::backAndForth(int extra) {
  this->posizione += this->verso;
  if ((this->posizione < 0 - extra) || (this->posizione > MAX_PIXELS + extra)) {
    this->verso *= -1;
    this->posizione += 2 * this->verso;
  }
}

void Onda::backAndForth(int low, int high) {
  //SO(String(low) + "," + String(high) + ":" + String(this->posizione) + "," + String(this->verso) + " ");
  this->posizione += this->verso;
  if ((this->posizione < low) || (this->posizione > high)) {
    this->verso *= -1;
    this->posizione += 2 * this->verso;
  }
  SON(String(this->posizione) + "." + String(this->verso));
}

boolean Onda::posizioneValida(int posizione) {
  //SO("p");
  return (((posizione < 0) || (posizione >= MAX_PIXELS)) ? false : true);
}






Effetto_Onde::Effetto_Onde() : Effetto() {
  this->color.setRGB(255,   0,   0);
  this->color.setHSV(  0, 255, 255);
  speedDivider = 0;
}
Effetto_Onde::Effetto_Onde(Onda *onde, int nOnde, Pix *pix, int speed) : Effetto(pix, 0, speed) {
  this->nOnde = nOnde;
  this->onde = onde;
  this->ampiezza = ampiezza;
  //this->pix = pix;
  this->color.setRGB(255,   0,   0);
  this->color.setHSV(  0, 255, 255);
}

void Effetto_Onde::update() {
  SON("fill(" + String(this->nOnde) + ") ");
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