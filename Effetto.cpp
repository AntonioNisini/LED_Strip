#include "Effetto.h"


/*******************
 * Classe Attuatore
 ******************/
 
// int Attuatore::minimo;
// int Attuatore::massimo;

Attuatore::Attuatore() {
  this->posizione = POSIZIONE;
  this->verso = VERSO;
  this->speed = SPEED;
}
Attuatore::Attuatore(Pix *pix) {
  this->posizione = POSIZIONE;
  this->verso = VERSO;
  this->speed = SPEED;
  this->pix = pix;
}
Attuatore::Attuatore(Pix *pix, int posizione, int verso, int speed) {
  this->posizione = posizione;
  this->verso = verso;
  this->speed = speed;
  this->pix = pix;
}

void Attuatore::backAndForth(int extra) {
  this->posizione += this->verso;
  if ((this->posizione < 0 - extra) || (this->posizione > MAX_PIXELS + extra)) {
    this->verso *= -1;
    this->posizione += 2 * this->verso;
  }
}

void Attuatore::backAndForth(int low, int high) {
  //SO(String(low) + "," + String(high) + ":" + String(this->posizione) + "," + String(this->verso) + " ");
  this->posizione += this->verso;
  if ((this->posizione < low) || (this->posizione > high)) {
    this->verso *= -1;
    this->posizione += 2 * this->verso;
  }
  SON(String(this->posizione) + "." + String(this->verso));
}

boolean Attuatore::posizioneValida(int posizione) {
  SO("p");
  return (((posizione < 0) || (posizione >= MAX_PIXELS)) ? false : true);
}



/**************
 * Effetto
 **************/

Effetto::Effetto() {}
Effetto::Effetto(Pix *pix, int posizione, int speed) {
  this->posizione = posizione;
  this->speed = speed;
  this->pix = pix;
}

void Effetto::update() {
  this->posizione += this->verso * this->speed;
  if ((this->posizione > MAX_PIXELS) || (this->posizione < 0)) {
    this->verso *= -1;
    this->posizione += 2 * this->verso * this->speed;
  }
  
  for (int i = 0; i < MAX_PIXELS; i++) {
    int value = (i == this->posizione) ? 1: 0;
    this->pix[i].setRGB(value, value, value);
    this->pix[i].RGB2HSV();
  }
}

void Effetto::manageSubCommand(long key) {
  
  string s = "";
  switch (key) {
    case KEY_RED:           this->color.setRGB(255,   0,   0); this->color.RGB2HSV(); break;
    case KEY_GREEN:         this->color.setRGB(  0, 255,   0); this->color.RGB2HSV(); break;
    case KEY_BLUE:          this->color.setRGB(  0,   0, 255); this->color.RGB2HSV(); break;
    case KEY_YELLOW:        this->color.setRGB(255, 255,   0); this->color.RGB2HSV(); break;
    case KEY_CYAN:          this->color.setRGB(  0, 255, 255); this->color.RGB2HSV(); break;
    case KEY_MAGENTA:       this->color.setRGB(255,   0, 255); this->color.RGB2HSV(); break;
    case KEY_WHITE:         this->color.setRGB(255, 255, 255); this->color.RGB2HSV(); break;
    default: SON("CODE not found: " + String(key, HEX));
  }
  SON(PIX2STRING(this->color));
}

void Effetto::fill(uint8_t r, uint8_t g, uint8_t b) {
  this->fill(0, MAX_PIXELS, r, g, b);
}

void Effetto::fill(int start, int end, uint8_t r, uint8_t g, uint8_t b) {   // end excluded
  for (int i = start; i < end; i++) {
    this->pix[i].r = r;
    this->pix[i].g = g;
    this->pix[i].b = b;
    this->pix[i].RGB2HSV();
  }
}

bool Effetto::posizioneValida(int posizione) {
  return (((posizione < 0) || (posizione >= MAX_PIXELS)) ? false : true);
}



/**************************
 * Classe EffettoAttuatori
 *************************/

EffettoAttuatori::EffettoAttuatori() {}
EffettoAttuatori::EffettoAttuatori(Attuatore *attuatori, int nAttuatori, Pix *pix, int posizione, int speed) : Effetto(pix, posizione, speed) {
  this->nAttuatori = nAttuatori;
  this->attuatori = attuatori;
}
