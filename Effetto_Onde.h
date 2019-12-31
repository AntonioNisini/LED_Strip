#ifndef EFFETTO_ONDE_H
#define EFFETTO_ONDE_H

#include "common.h"
#include "Effetto.h"

#define SPEED_DIVIDER  10
#define AMPIEZZA        1
#define POTENZA       255
#define DELTA_FATTORE 0.1
#define HUE_BW        500
#define HUE_MIXED    1000


/**************
 * Classe Onda
 **************/

class Onda : public Attuatore {

  private:
  int ampiezza;
  int potenza;
  //float fattore;
  uint16_t baseHue;
  Pix color;
  uint8_t delta;

  public:
  Onda(Pix *pix);
  Onda(Pix *pix, int ampiezza, int potenza, uint16_t hue);
  Onda(Pix *pix, int ampiezza, int potenza, uint16_t hue, int posizione, int verso, int speed);

  void setHue(uint16_t hue);

  void update();
  void draw();

  friend class Effetto_Onde;
};



/**********************
 * Classe Effetto_Onde
 **********************/

class Effetto_Onde : public Effetto {

  private:
  int speedDivider;
  int ampiezza;
  float fattore;
  uint16_t hue;
  int nOnde;
  Onda *onde;

  void aggiornaOnde();

  public:
  Effetto_Onde();
  Effetto_Onde(Onda *onde, int nOnde, Pix *pix, int speed);

  void update();
  void manageSubCommand(long key);  
};

#endif
