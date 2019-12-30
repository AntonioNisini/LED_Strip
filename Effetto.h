#ifndef EFFETTO_H
#define EFFETTO_H

#include "common.h"
#include "IR_Codes.h"


#define SX_DX           1
#define DX_SX          -1
#define VERSO       SX_DX

#define POSIZIONE       0
#define SPEED           1
#define COLOR_CYCLE  1000

/*******************
 * Classe Attuatore
 ******************/

class Attuatore {

  protected:
  int posizione;
  int speed;
  int verso = 1;
  Pix *pix;

  public:
  //static int minimo, massimo;
  Attuatore();
  Attuatore(Pix *pix);
  Attuatore(Pix *pix, int posizione, int verso, int speed);
  
  void backAndForth(int extra);
  void backAndForth(int low, int high);
  bool posizioneValida(int posizione);

  virtual void update() = 0;
  virtual void draw() = 0;

};



/*******************
 * Classe Effetto
 ******************/

class Effetto {

  protected:
  int posizione;
  int speed;
  int verso = 1;
  Pix color;
  Pix *pix;

  bool posizioneValida(int posizione);
  
  public:
  Effetto();
  Effetto(Pix *pix, int posizione, int speed);

  virtual void update();
  virtual void manageSubCommand(long key) = 0;
  void fill(uint8_t r, uint8_t g, uint8_t b);
  void fill(int start, int end, uint8_t r, uint8_t g, uint8_t b);  // end excluded
  
};



/**************************
 * Classe EffettoAttuatori
 *************************/

class EffettoAttuatori : public Effetto {

  protected:
  int nAttuatori;
  Attuatore *attuatori;
  
  public:
  EffettoAttuatori();
  EffettoAttuatori(Attuatore *attuatori, int nAttuatori, Pix *pix, int posizione, int speed);

  virtual void update();
  virtual void manageSubCommand(long key) = 0;
  
};

#endif
