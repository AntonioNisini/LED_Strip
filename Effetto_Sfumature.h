#ifndef EFFETTO_SFUMATURE_H
#define EFFETTO_SFUMATURE_H

#include "common.h"
#include "Effetto.h"

#define SPEED_DIVIDER 10

class Effetto_Sfumature: public Effetto {

  private:
  int speedDivider;
  int ampiezza;

  public:
  Effetto_Sfumature();
  Effetto_Sfumature(Pix *pix, int speed);

  void update();
  void manageSubCommand(long key);
  
};

#endif
