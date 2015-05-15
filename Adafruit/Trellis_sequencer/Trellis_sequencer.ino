#include <Wire.h>
#include "Adafruit_Trellis.h"
#include "T_Seq.h"
#include "TimerOne.h"
#include <SoftwareSerial.h>

T_Sequencer mSequencer;

void setup() {
  Serial.begin(115200);
  Serial.println("Trellis Sequencer Test");
  //pinMode(2, INPUT);
  mSequencer.begin();
  //mSequencer.record();
  //mSequencer.play();
  //mSequencer.recordPlay();
  //mSequencer.drumMachine();
  Serial.println("Done!!");

}

void loop(){
  mSequencer.clearLEDS();
  mSequencer.drumMachine();
  Serial.println("===============MAIN MENU===============");
  Serial.println("Select option");
  Serial.println("1 - Drum pad");
  Serial.println("2 - Sequencer");
  while(!Serial.available());
  if(Serial.available()){
    int sel = Serial.parseInt();
    Serial.read();
    switch(sel){
      case 1:
        mSequencer.drumMachine();
        break;
      case 2:
        mSequencer.recordPlay();
        break;
    }
    Serial.read();
  }
}

