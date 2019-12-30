#ifndef EFFETTO_ONDE_H
#define EFFETTO_ONDE_H

#include "common.h"
#include "Effetto.h"

#define SPEED_DIVIDER  10
#define AMPIEZZA        1


/**************
 * Classe Onda
 **************/

class Onda : public Attuatore {

  private:
  int ampiezza;
  Pix color;


  public:
  Onda(Pix *pix);
  Onda(Pix *pix, int ampiezza, uint16_t hue);
  Onda(Pix *pix, int ampiezza, uint16_t hue, int posizione, int verso, int speed);

  void setHue(uint16_t hue);

  void update();
  void draw();
};



/**********************
 * Classe Effetto_Onde
 **********************/

class Effetto_Onde : public Effetto {

  private:
  int speedDivider;
  int ampiezza;
  int nOnde;
  Onda *onde;


  public:
  Effetto_Onde();
  Effetto_Onde(Onda *onde, int nOnde, Pix *pix, int speed);

  void update();
  void manageSubCommand(long key);  
};

#endif