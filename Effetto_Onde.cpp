#include "Effetto_Onde.h"

/**************
 * Classe Onda
 **************/

Onda::Onda(Pix *pix) : Onda(pix, AMPIEZZA, POTENZA, 0) {}
Onda::Onda(Pix *pix, int ampiezza, int potenza, uint16_t hue) : Onda(pix, ampiezza, potenza, hue, POSIZIONE, VERSO, SPEED) {}
Onda::Onda(Pix *pix, int ampiezza, int potenza, uint16_t hue, int posizione, int verso, int speed) : Attuatore(pix, posizione,verso, speed) {
  this->ampiezza = ampiezza;
  this->potenza = potenza;
  //this->fattore = 1;
  this->delta = potenza / ampiezza;
  this->baseHue = hue;
  this->color.setHSV(hue, 255, potenza);
  this->color.HSV2RGB(); 
}

void Onda::setHue(uint16_t hue) { 
  switch (hue) {
    case HUE_MIXED: this->color.saturation = 255; this->color.hue = baseHue; break;
    case HUE_BW:    this->color.saturation =   0; this->color.hue = baseHue; break;
    default:        this->color.saturation = 255; this->color.hue =     hue;
  }
  this->color.HSV2RGB(); 
  //SON(String("Onda: ") + PIX2STRING(this->color));
}

void Onda::update() {
  //SO("u");
  this->backAndForth(-this->ampiezza, MAX_PIXELS + this->ampiezza);
}

void Onda::draw() {
  //SO("d(" + String(this->ampiezza) + ") ");
  Pix deltaPix; 
  deltaPix.setHSV(this->color);
  deltaPix.value = this->potenza;
  //deltaPix.value = this->fattore * this->potenza;
  deltaPix.HSV2RGB();
  for (int i = 0; i < this->ampiezza; i++) {
    if (this->posizioneValida(this->posizione + i)) {
      this->pix[this->posizione + i].addRGB(deltaPix);
      this->pix[this->posizione + i].RGB2HSV();
      //SON(PIX2STRING(this->pix[this->posizione + i]));
    }
    if (this->posizioneValida(this->posizione - i)) {
      this->pix[this->posizione - i].addRGB(deltaPix);
      this->pix[this->posizione - i].RGB2HSV();
      //SON(PIX2STRING(this->pix[this->posizione + i]));
    }
    deltaPix.value -= this->delta;
    //deltaPix.value -= this->fattore * this->delta;
    deltaPix.HSV2RGB();
  }
}



/**********************
 * Classe Effetto_Onde
 **********************/

Effetto_Onde::Effetto_Onde() : Effetto() {
  this->color.setRGB(255,   0,   0);
  this->color.setHSV(  0, 255, 255);
  speedDivider = 0;
  this->fattore = 1;
  this->hue = HUE_MIXED;
}
Effetto_Onde::Effetto_Onde(Onda *onde, int nOnde, Pix *pix, int speed) : Effetto(pix, 0, speed) {
  this->nOnde = nOnde;
  this->onde = onde;
  this->ampiezza = ampiezza;
  this->fattore = 1;
  this->color.setRGB(255,   0,   0);
  this->color.setHSV(  0, 255, 255);
}

void Effetto_Onde::update() {
  //SON("fill(" + String(this->nOnde) + ") ");
  this->fill(0, 0 , 0);
  for (int i = 0; i < this->nOnde; i++) {
    SO(String("A:") + String(i));
    this->onde[i].update();
    this->onde[i].draw();
  }
  for (int i = 0; i < MAX_PIXELS; i++) {
    this->pix[i].value = this->fattore * this->pix[i].value;
    this->pix[i].HSV2RGB();
  }
}

void Effetto_Onde::aggiornaOnde() { 
  Serial.println(String("F: ") + this->fattore); 
  for (int i = 0; i < this->nOnde; i++) {
    //this->onde[i].fattore = this->fattore;
    this->onde[i].setHue(this->hue); 
  }
}

void Effetto_Onde::manageSubCommand(long key) {
  bool needUpdate = true;
  switch (key) {
    case KEY_RED:      this->hue =         0; break;
    case KEY_YELLOW:   this->hue =        60; break;
    case KEY_GREEN:    this->hue =       120; break;
    case KEY_CYAN:     this->hue =       180; break;
    case KEY_BLUE:     this->hue =       240; break;
    case KEY_MAGENTA:  this->hue =       300; break;
    case KEY_WHITE:    this->hue =    HUE_BW; break;
    case KEY_MIXED:    this->hue = HUE_MIXED; break;
    
    case KEY_BRIGHTER: if (this->fattore < 1 - DELTA_FATTORE) this->fattore += DELTA_FATTORE; else this->fattore = 1; break;
    case KEY_DARKER:   if (this->fattore >     DELTA_FATTORE) this->fattore -= DELTA_FATTORE; else this->fattore = 0; break;
    
    default: Serial.println("CODE not found: " + String(key, HEX)); needUpdate = false;
  }
  if (needUpdate) aggiornaOnde();
}
