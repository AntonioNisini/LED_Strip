#ifndef EFFETTO_ONDE_H
#define EFFETTO_ONDE_H

#include "common.h"
#include "Effetto.h"

#define SPEED_DIVIDER  10
#define AMPIEZZA        1

class Onda {

  private:
  int posizione;
  int speed;
  int verso = 1;
  int ampiezza;
  Pix color;
  Pix *pix;

  public:
  Onda();
  Onda(Pix *pix);
  Onda(Pix *pix, int ampiezza, uint16_t hue);
  Onda(Pix *pix, int ampiezza, uint16_t hue, int posizione, int verso, int speed);

  void setHue(uint16_t hue);
  
  void backAndForth(int extra);
  void backAndForth(int low, int high);
  bool posizioneValida(int posizione);

  void update();
  void draw();

};

class Effetto_Onde : public Effetto {

  private:
  //int posizione;
  //int speed;
  //int verso = 1;
  int speedDivider;
  int ampiezza;
  //Pix color;
  //Pix *pix;
  int nOnde;
  Onda *onde;



  public:
  Effetto_Onde();
  Effetto_Onde(Onda *onde, int nOnde, Pix *pix, int speed);

  void update();
  void manageSubCommand(long key);

  //void fill(uint8_t r, uint8_t g, uint8_t b);
  //oid fill(int start, int end, uint8_t r, uint8_t g, uint8_t b);  // end excluded
  
};

#endif