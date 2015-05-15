#ifndef BUTTONPAD_H
#define BUTTONPAD_H

#include "mySPI.h"

class buttonPad{

  char colorMatrix[16][3];
  unsigned short int pressedButtons;
  
public:
  buttonPad();
  void setColor(char x, char rgb, char color);
  void setColorMatrix(char x, char rgb, char color);
  short int sendColorMatrix();
  void clearColorMatrix();
  
};

#endif
