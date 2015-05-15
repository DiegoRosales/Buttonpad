#include "buttonPad.h"

inline buttonPad::buttonPad(){
  for(int i=0; i<16; i++){
    for(int j=0; j<3; j++){
      colorMatrix[i][j] = 0;  
    }
  }
}

inline void buttonPad::setColor(char x, char rgb, char color){
  for(int i=0; i<4; i++){
    for(int j = 0; j < 16; j++){
      if(rgb == i && (x == j)){
        mySPITransmit(color);
      }else{
        mySPITransmit(0x00);
      }  
    }  
  }
}

inline void buttonPad::setColorMatrix(char x, char rgb, char color){
  colorMatrix[x][rgb] = color;  
}

inline short int buttonPad::sendColorMatrix(){
  pressedButtons = 0x00;
  for(int i=0; i<4; i++){
    for(int j = 0; j < 16; j++){
      if(i<3) mySPITransmit(colorMatrix[j][i]);
      else{ 
          pressedButtons |= mySPITransmitReceive(0x00);          
          if(j<15) pressedButtons <<= 1;
      }
    }  
  }
  return pressedButtons;
}

inline void buttonPad::clearColorMatrix(){
  for(int i=0; i<16; i++){
    for(int j=0; j<3; j++){
      colorMatrix[i][j] = 0;  
    }
  }
}
  
