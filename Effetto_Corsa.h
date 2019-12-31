#ifndef EFFETTO_CORSA_H
#define EFFETTO_CORSA_H

#include "common.h"
#include "Effetto.h"

class Effetto_Corsa: public Effetto {

  private:
  /*
  int posizione;
  int speed;
  int verso = 1;
  Pix *pix;
  */
  int ampiezza;

  public:
  Effetto_Corsa();
  Effetto_Corsa(Pix *pix, int ampiezza, int posizione, int speed);

  void update();
  void manageSubCommand(long key);
  
};

#endif
