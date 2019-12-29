#ifndef COMMON_H
  #define COMMON_H
  
  #define ARDUINO_IDE
  #define LED_STRIP
  #define REMOTE_4x6

  #define MAX_PIXELS          20
  #define NUM_PIXELS_START    20
  
  #ifdef LED_STRIP
    #define DEVICE_MANAGER LED_Controller
    #define DEVICE_MANAGER_H "LED_Controller.h"
    #define MAX_LEDS MAX_PIXELS
    #define NUM_LEDS_START NUM_PIXELS_START
  #else
    #define DEVICE_MANAGER TFT_Manager
    #define DEVICE_MANAGER_H "TFT_Manager.h"
    #define MAX_DOTS MAX_PIXELS
    #define MAX_DOTS_START NUM_PIXELS_START
  #endif

  //#include DEVICE_MANAGER_H
  
  
  #define SO_ENABLED
  
  #ifdef SO_ENABLED
    #ifdef ARDUINO_IDE
      #define string String
      #define SO(x) Serial.print(x) 
      #define SON(x) Serial.println(x) 
      #define SOF(x, y) Serial.print(x, y) 
      #define SONF(x, y) Serial.println(x, y) 
    #else
      #define String string
      #define SO(x) cout << x
      #define SON(x) cout << x << endl
      #define SOF(x, y) cout << x << 
      #define SONF(x, y) cout << x << endl 
    #endif
  #else
    #define SO(x) // dummy 
    #define SON(x) // dummy 
    #define SOF(x, y) // dummy 
    #define SONF(x, y) // dummy 
  #endif

  #define IR_PIN   4
  #define LED_PIN  8
  
  #define MODE_STATIC             0
  #define MODE_DYNAMIC            1
  #define MODE_ENTERING_DYNAMIC   2
  #define MODE_ENTERING_STATIC    3
  
  #define STATUS_UNCHANGED        0
  #define STATUS_CHANGED          1
  #define SERIAL_ENABLED       true
  
  #define STATUS_WORKING          0
  #define STATUS_ENTERING_SETTING 1
  #define STATUS_SETTING          2

  #define SPEED_INTERVAL         10

  #define NUMERO_EFFETTI          2

  #define DELAY_CYCLES           50

  extern int ledNumLimit;
  extern int delayCycles;

#endif

#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)

#ifndef PIX
#define PIX

  #include <Arduino.h>
  
  typedef struct Pix {
    union {
      struct {
        union {
          uint8_t r;
          uint8_t red;
        };
        union {
          uint8_t g;
          uint8_t green;
        };
        union {
          uint8_t b;
          uint8_t blue;
        };
      };
      uint8_t rawRGB[3];
    };
    union {
      struct {
        union {
          uint16_t h;
          uint16_t hue;
        };
        union {
          uint8_t s;
          uint8_t saturation;
        };
        union {
          uint8_t v;
          uint8_t value;
        };
      };
      uint8_t rawHSV[3];
    };

    inline void setRGB(uint8_t nr, uint8_t ng, uint8_t nb) __attribute__((always_inline)) {
      r = nr;
      g = ng;
      b = nb;
    }

    inline void setRGB(Pix pix) __attribute__((always_inline)) {
      r = pix.r;
      g = pix.g;
      b = pix.b;
    }

    inline void setHSV(uint8_t nh, uint8_t ns, uint8_t nv) __attribute__((always_inline)) {
      h = nh;
      s = ns;
      v = nv;
    }

    inline void setHSV(Pix pix) __attribute__((always_inline)) {
      h = pix.h;
      s = pix.s;
      v = pix.v;
    }

    void RGB2HSV() {
      float nr, ng, nb, nh, ns, nv;
      nr = r; ng = g; nb = b; 
      RGBtoHSV(nr, ng, nb, nh, ns, nv);
      h = nh; s = 255 * ns; v = nv;
    }
    
    void RGBtoHSV(float& fR, float& fG, float fB, float& fH, float& fS, float& fV) {
      float fCMax = max(max(fR, fG), fB);
      float fCMin = min(min(fR, fG), fB);
      float fDelta = fCMax - fCMin;
      
      if(fDelta > 0) {
        if(fCMax == fR) {
          fH = 60 * (fmod(((fG - fB) / fDelta), 6));
        } else if(fCMax == fG) {
          fH = 60 * (((fB - fR) / fDelta) + 2);
        } else if(fCMax == fB) {
          fH = 60 * (((fR - fG) / fDelta) + 4);
        }
        
        if(fCMax > 0) {
          fS = fDelta / fCMax;
        } else {
          fS = 0;
        }
        
        fV = fCMax;
      } else {
        fH = 0;
        fS = 0;
        fV = fCMax;
      }
      
      if(fH < 0) {
        fH = 360 + fH;
      }
    }

    void HSV2RGB() {
      float nh = h;
      float ns = 1.0 * s / 255;
      float nv = 1.0 * v / 255;
      // Serial.println("CHSV: (" + String(h) + ", " + String(s) + ", " + String(v) + ")");
      float nr, ng, nb;
      HSVtoRGB(nr, ng, nb, nh, ns, nv);
      // Serial.println("CRGB1: (" + String(r) + ", " + String(g) + ", " + String(b) + ")");
      r = 255 * nr;
      g = 255 * ng;
      b = 255 * nb;
      // printCRGB(color);
    }
    
    void HSVtoRGB(float& fR, float& fG, float& fB, float& fH, float& fS, float& fV) {
      float fC = fV * fS; // Chroma
      float fHPrime = fmod(fH / 60.0, 6);
      float fX = fC * (1 - fabs(fmod(fHPrime, 2) - 1));
      float fM = fV - fC;
      
      if(0 <= fHPrime && fHPrime < 1) {
        fR = fC;
        fG = fX;
        fB = 0;
      } else if(1 <= fHPrime && fHPrime < 2) {
        fR = fX;
        fG = fC;
        fB = 0;
      } else if(2 <= fHPrime && fHPrime < 3) {
        fR = 0;
        fG = fC;
        fB = fX;
      } else if(3 <= fHPrime && fHPrime < 4) {
        fR = 0;
        fG = fX;
        fB = fC;
      } else if(4 <= fHPrime && fHPrime < 5) {
        fR = fX;
        fG = 0;
        fB = fC;
      } else if(5 <= fHPrime && fHPrime < 6) {
        fR = fC;
        fG = 0;
        fB = fX;
      } else {
        fR = 0;
        fG = 0;
        fB = 0;
      }
      
      fR += fM;
      fG += fM;
      fB += fM;
    }
  };

  #define PIX2STRING(pix) "(" + String(pix.r) + "," + String(pix.g) + "," + String(pix.b) + ")(" + String(pix.h) + "," + String(pix.s) + "," + String(pix.v) + ")"
#endif
