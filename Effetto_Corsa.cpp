#include "Effetto_Corsa.h"

Effetto_Corsa::Effetto_Corsa() : Effetto() {
  this->color.setRGB(255, 255, 255);
  this->color.setHSV(  0,   0, 255);
}
Effetto_Corsa::Effetto_Corsa(Pix *pix, int ampiezza, int posizione, int speed) : Effetto(pix, posizione, speed) {
  this->ampiezza = ampiezza;
  this->color.setRGB(255, 255, 255);
  this->color.setHSV(  0,   0, 255);
}

void Effetto_Corsa::update() {
  this->posizione += this->verso * this->speed;
  if ((this->posizione > MAX_PIXELS + this->ampiezza) || (this->posizione < -this->ampiezza - 1)) {
    this->verso *= -1;
    this->posizione = (this->verso > 0) ? -2: MAX_PIXELS + 1;
  }

  //SON(this->posizione);
  
  this->fill(0, 0, 0);
  int gap = 255 / this->ampiezza;
  int pos = this->posizione;
  int value = 255;
  while (value > 0) {
    if (this->posizioneValida(pos)) {   
      // SO(String(value) + " "); 
      this->pix[pos].setRGB(this->color);                                   // SO(PIX2STRING(this->pix[pos]) + " ");
      this->pix[pos].RGB2HSV();                                             // SO(PIX2STRING(this->pix[pos]) + " ");
      this->pix[pos].value = value;                                         // SO(PIX2STRING(this->pix[pos]) + " ");
      this->pix[pos].HSV2RGB();                                             // SON(PIX2STRING(this->pix[pos]) + "\n");
      //SON(PIX2STRING(this->color) + PIX2STRING(this->pix[pos]));
    }
    pos -= this->verso;
    value -= gap;
  }
}

void Effetto_Corsa::manageSubCommand(long key)  {
  Effetto::manageSubCommand(key);
}

