#include <SPI.h>
#include "buttonPad.cpp";

const int slaveCS = 10;
char color = 0;
buttonPad mButtonPad;

unsigned short int pressedButtonsLast = 0x00;
unsigned short int pressedButtons = 0x00;
void setup() {
  Serial.begin(115200);
  pinMode(slaveCS, OUTPUT);
  mySPIBegin();
}

bool temp = false;

void loop() {
  digitalWrite(slaveCS, HIGH);
  pressedButtons = mButtonPad.sendColorMatrix();
  delayMicroseconds(500);
  pressedButtons &= mButtonPad.sendColorMatrix();
  

  //mButtonPad.clearColorMatrix();
  digitalWrite(slaveCS, LOW);
  short int index = 1;
  for(int i=0; i<16; i++){
    int note = 56-i;
    if((((1<<i)&pressedButtons) == 0) && (((1<<i)&pressedButtonsLast) != 0)){
      temp = true;
      noteOn(0x90, note, 0x55);
      mButtonPad.setColorMatrix(15-i, i%3, 255);
    }else if((((1<<i)&pressedButtons) != 0) && (((1<<i)&pressedButtonsLast) == 0)){
      mButtonPad.setColorMatrix(15-i, i%3, 0x00);
      noteOn(0x80, note, 0x00);
    } 
  }
  if(temp){
    temp = false;  
  }
  pressedButtonsLast = pressedButtons; 
}

void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
