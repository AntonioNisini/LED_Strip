#ifndef UTILITIES_H
#define UTILITIES_H

extern bool IcanDraw(); // da definire in Infrarosso / WiFi / ...

void staticResizeStrip(int delta);
void staticPositionStrip(int delta);
void staticSetHue(int delta);
void staticSetSaturation(int delta);
void staticSetValue(int delta);
void adjustSpeed();

bool isEven(int value);

void printModeStatus();

#endif
