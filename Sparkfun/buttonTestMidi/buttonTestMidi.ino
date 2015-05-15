#include <SPI.h>
#include "buttonPad.cpp";

// See http://www.vlsi.fi/fileadmin/datasheets/vs1053.pdf Pg 31
#define VS1053_BANK_DEFAULT 0x00
#define VS1053_BANK_DRUMS1 0x78
#define VS1053_BANK_DRUMS2 0x7F
#define VS1053_BANK_MELODY 0x79

// See http://www.vlsi.fi/fileadmin/datasheets/vs1053.pdf Pg 32 for more!
#define VS1053_GM1_OCARINA 80

#define MIDI_NOTE_ON  0x90
#define MIDI_NOTE_OFF 0x80
#define MIDI_CHAN_MSG 0xB0
#define MIDI_CHAN_BANK 0x00
#define MIDI_CHAN_VOLUME 0x07
#define MIDI_CHAN_PROGRAM 0xC0

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
  Serial.begin(31250);
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

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// Functions
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void midiSetInstrument(uint8_t chan, uint8_t inst) {
  if (chan > 15) return;
  inst --; // page 32 has instruments starting with 1 not 0 :(
  if (inst > 127) return;
  
  Serial.write(MIDI_CHAN_PROGRAM | chan);  
  Serial.write(inst);
}


void midiSetChannelVolume(uint8_t chan, uint8_t vol) {
  if (chan > 15) return;
  if (vol > 127) return;
  
  Serial.write(MIDI_CHAN_MSG | chan);
  Serial.write(MIDI_CHAN_VOLUME);
  Serial.write(vol);
}

void midiSetChannelBank(uint8_t chan, uint8_t bank) {
  if (chan > 15) return;
  if (bank > 127) return;
  
  Serial.write(MIDI_CHAN_MSG | chan);
  Serial.write((uint8_t)MIDI_CHAN_BANK);
  Serial.write(bank);
}

void midiNoteOn(uint8_t chan, uint8_t n, uint8_t vel) {
  if (chan > 15) return;
  if (n > 127) return;
  if (vel > 127) return;
  
  Serial.write(MIDI_NOTE_ON | chan);
  Serial.write(n);
  Serial.write(vel);
}

void midiNoteOff(uint8_t chan, uint8_t n, uint8_t vel) {
  if (chan > 15) return;
  if (n > 127) return;
  if (vel > 127) return;
  
  Serial.write(MIDI_NOTE_OFF | chan);
  Serial.write(n);
  Serial.write(vel);
}
