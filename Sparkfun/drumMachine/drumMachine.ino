#include <SPI.h>
#include <SoftwareSerial.h>
#include "buttonPad.cpp";
#include "myMidi.h"
#include "Sequencer.h"
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// Global variables
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

const int slaveCS = 10;
char color = 0;
bool temp = false;
buttonPad mButtonPad;

unsigned short int pressedButtonsLast = 0x00;
unsigned short int pressedButtons = 0x00;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// Setup
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void setup() {
  Serial.begin(115200);
  midiBegin();
  pinMode(slaveCS, OUTPUT);
  
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  delay(10);
  digitalWrite(9, HIGH);
  delay(10);
  
  midiSetChannelBank(0, VS1053_BANK_DRUMS1);
  midiSetInstrument(0, VS1053_GM1_OCARINA);
  midiSetChannelVolume(0, 127);
  
  mySPIBegin();
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// Loop
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void loop() {
  if(Serial.available()){
    if(Serial.read() == 1)
      SeqTest();  
  }
  digitalWrite(slaveCS, HIGH);
  pressedButtons = mButtonPad.sendColorMatrix();
  delayMicroseconds(200);
  pressedButtons &= mButtonPad.sendColorMatrix();

  

  //mButtonPad.clearColorMatrix();
  digitalWrite(slaveCS, LOW);
  short int index = 1;
  for(int i=0; i<16; i++){
    int note = 35+i;
    if((((1<<i)&pressedButtons) == 0) && (((1<<i)&pressedButtonsLast) != 0)){
      temp = true;
      midiNoteOn(0, note, 127);
      mButtonPad.setColorMatrix(15-i, i%3, 255);
    }else if((((1<<i)&pressedButtons) != 0) && (((1<<i)&pressedButtonsLast) == 0)){
      mButtonPad.setColorMatrix(15-i, i%3, 0x00);
      midiNoteOff(0, note, 127);
    } 
  }
  if(temp){
    temp = false;  
  }
  pressedButtonsLast = pressedButtons; 
}


