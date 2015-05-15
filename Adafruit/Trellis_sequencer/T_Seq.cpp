#include "T_Seq.h"

static unsigned long counter = 0;
static SoftwareSerial VS1053_MIDI(0, 2);

void timerCallback(){
  counter++;
  // Serial.println("interrupted!");
}


void T_Sequencer::begin(){

  // Reset the MIDI Module
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  delay(10);
  digitalWrite(9, HIGH);
  delay(10);

  VS1053_MIDI.begin(31250);

  // Set channel and instrument
  midiSetChannelBank(0, VS1053_BANK_DRUMS1);
  midiSetInstrument(0, 34);
  midiSetChannelVolume(0, 127);

  // Initialize button pad
  trellis =  Adafruit_Trellis();
  trellis.begin(0x70);

  // Initialize sequence
  sequence = 0;
  for(uint8_t i=0; i<8; i++){
    seqTracks[i].pattern = 0;
    seqTracks[i].instrument = i+40;
    for(uint8_t j=0; j<numKeys; j++){
      seqTracks[i].velocity[j] = 127;
    }
  }
  // light up all the LEDs in order
  for (uint8_t i=0; i<numKeys; i++) {
    trellis.setLED(i);
    trellis.writeDisplay();    
    delay(50);
  }
  // then turn them off
  for (uint8_t i=0; i<numKeys; i++) {
    trellis.clrLED(i);
    trellis.writeDisplay();    
    delay(50);
  }
  trellis.readSwitches();
}

void T_Sequencer::record(){
  Serial.println("Recording...");
  while(Serial.available() == 0){

    delay(30);
    if(trellis.readSwitches()){
      Serial.println("Trellis!");
      for(uint8_t i=0; i<numKeys; i++){
        if (trellis.justPressed(i)){
          sequence ^= 1<<i;
          Serial.println(sequence, BIN);
          if (trellis.isLED(i)){
            trellis.clrLED(i);
            Serial.println(sequence, BIN);
          }
          else{
            trellis.setLED(i);            
            Serial.println(sequence, BIN);
          }
        }
      }
      trellis.writeDisplay();
    }
  }
}

void T_Sequencer::play(){
  Serial.println("Playing...");
  while(Serial.available()){
    Serial.read();
  }

  while(Serial.available() == 0){
    delay(30);
    Serial.println(sequence, BIN);
    for(uint8_t i=0; i<numKeys; i++){
      if (((1<<i)&sequence) != 0){
        trellis.setLED(i);      
        trellis.writeDisplay();  
        delay(500);    
        trellis.clrLED(i);
        trellis.writeDisplay();
        //delay(500);        
      }
      else{
        trellis.setLED(i);      
        trellis.writeDisplay();  
        delay(80);    
        trellis.clrLED(i);
        trellis.writeDisplay();
        delay(420);    
      }
    }
  }
}

void T_Sequencer::recordPlay(){
  Serial.println("-----SEQUENCER-----");
  Timer1.initialize(6000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt( timerCallback ); // attach the service routine here
  unsigned long x = 0;
  unsigned long N = 40;
  unsigned long M = 10;
  unsigned char k = 1;
  midiSetChannelBank(0, VS1053_BANK_DRUMS1);
  midiSetInstrument(0, 35);
  midiSetChannelVolume(0, 127);

  seqTracks[0].instrument = 42;  
  seqTracks[0].pattern = 0xFFFF;

  seqTracks[1].instrument = 36;
  seqTracks[1].pattern = 0x1111;

  seqTracks[2].instrument = 50;
  seqTracks[2].pattern = 0x4444;

  seqTracks[3].instrument = 38;
  seqTracks[3].pattern = 0x4444;
  //sequence = seqTracks[1].pattern;
  loadTrack(k);
  while(1){
    for(uint8_t i=0; i<numKeys; i++){
      tracksNoteOn(i);
      if (((1<<i)&seqTracks[k].pattern) != 0){
        trellis.clrLED(i);      
        trellis.writeDisplay();  
        while(counter < M)
        { 
          delay(30); 
          updateSequence(k); 
        }
        counter = 0;
        trellis.setLED(i);
        trellis.writeDisplay();
        while(counter < (N-M))
        { 
          delay(30); 
          updateSequence(k); 
        }     
        counter = 0;  
      }
      else{
        trellis.setLED(i);      
        trellis.writeDisplay();  
        while(counter < M)
        { 
          delay(30); 
          updateSequence(k); 
        }
        counter = 0;
        trellis.clrLED(i);
        trellis.writeDisplay();
        while(counter < (N-M))
        { 
          delay(30); 
          updateSequence(k); 
        }  
        counter = 0;        
      }
      tracksNoteOff(i);
      if(Serial.available()){
        char command = Serial.read();
        
        // Change track
        if(command == 't'){
          k = Serial.parseInt()%8;
          Serial.print("Display track ");
          Serial.println(k);
          loadTrack(k);
          Serial.read();
          
        // Clear all tracks
        }else if(command == 'c'){
          Serial.println("Clearing patterns");
          for(uint8_t j=0; j<8; j++){
            seqTracks[j].pattern = 0x0000;
          }
          k = 0; i=0; loadTrack(k);
          Serial.read();
        // Exit sequencer mode
        }else if(command == 'i'){
          unsigned int inst = Serial.parseInt();
          seqTracks[k].instrument = inst;
          Serial.print("Change instrument to ");
          Serial.println(inst);
        }else if(command == 'e'){
          Serial.println("Exit sequencer...");
          Timer1.stop();
          clearLEDS();
          return;
        }      
      } 
    }   
  }
}

void T_Sequencer::tracksNoteOn(unsigned int i){
  unsigned int comp = (1<<i);
  for(int j=0; j<8; j++){
    if((comp & seqTracks[j].pattern) != 0)
      midiNoteOn(0, seqTracks[j].instrument, seqTracks[j].velocity[i]);
  }
}

void T_Sequencer::tracksNoteOff(unsigned int i){
  unsigned int comp = (1<<i);
  for(int j=0; j<8; j++){
    if((comp & seqTracks[j].pattern) != 0)
      midiNoteOff(0, seqTracks[j].instrument, seqTracks[j].velocity[i]);
  }
}

void T_Sequencer::updateSequence(unsigned int k){
  //Serial.println("updateSequence");
  if(trellis.readSwitches()){
    for(uint8_t i=0; i<numKeys; i++){
      if (trellis.justPressed(i)){
        seqTracks[k].pattern ^= 1<<i;
        //Serial.println(sequence, BIN);
        if (trellis.isLED(i)){
          trellis.clrLED(i);
          //Serial.println(sequence, BIN);
        }
        else{
          trellis.setLED(i);            
          //Serial.println(sequence, BIN);
        }
      }
    }
    trellis.writeDisplay();
  }
}

void T_Sequencer::loadTrack(unsigned char k){
  for(uint8_t i=0; i<16; i++){
    if(((1<<i)&seqTracks[k].pattern) != 0)
      trellis.setLED(i);
    else
      trellis.clrLED(i);
  }
}

void T_Sequencer::drumMachine(){
  Serial.println("-----DRUM PAD-----");
  int note = 30;
  while(1){
    delay(30);
    if(trellis.readSwitches()){
      for(uint8_t i=0; i<numKeys; i++){
        if (trellis.justPressed(i)){
          midiNoteOn(0, i+40, 127);
          trellis.setLED(i);            
        }
        else if(trellis.justReleased(i)){
          midiNoteOff(0, i+40, 127);
          trellis.clrLED(i);
        }
      }
      trellis.writeDisplay();
    }
    if(Serial.available()){
      char command = Serial.read();
      if(command == 'e'){
        Serial.println("Exit drum pad");
        Serial.read();
        return;
      }
    }
  }
}

void T_Sequencer::midiSetInstrument(uint8_t chan, uint8_t inst) {
  if (chan > 15) return;
  inst --; // page 32 has instruments starting with 1 not 0 :(
  if (inst > 127) return;

  VS1053_MIDI.write(MIDI_CHAN_PROGRAM | chan);  
  VS1053_MIDI.write(inst);
}


void T_Sequencer::midiSetChannelVolume(uint8_t chan, uint8_t vol) {
  if (chan > 15) return;
  if (vol > 127) return;

  VS1053_MIDI.write(MIDI_CHAN_MSG | chan);
  VS1053_MIDI.write(MIDI_CHAN_VOLUME);
  VS1053_MIDI.write(vol);
}

void T_Sequencer::midiSetChannelBank(uint8_t chan, uint8_t bank) {
  if (chan > 15) return;
  if (bank > 127) return;

  VS1053_MIDI.write(MIDI_CHAN_MSG | chan);
  VS1053_MIDI.write((uint8_t)MIDI_CHAN_BANK);
  VS1053_MIDI.write(bank);
}

void T_Sequencer::midiNoteOn(uint8_t chan, uint8_t n, uint8_t vel) {
  if (chan > 15) return;
  if (n > 127) return;
  if (vel > 127) return;

  VS1053_MIDI.write(MIDI_NOTE_ON | chan);
  VS1053_MIDI.write(n);
  VS1053_MIDI.write(vel);
}

void T_Sequencer::midiNoteOff(uint8_t chan, uint8_t n, uint8_t vel) {
  if (chan > 15) return;
  if (n > 127) return;
  if (vel > 127) return;

  VS1053_MIDI.write(MIDI_NOTE_OFF | chan);
  VS1053_MIDI.write(n);
  VS1053_MIDI.write(vel);
}

void T_Sequencer::clearLEDS(){
  Serial.println("Clearing LEDs");
  trellis.clear();
  for(uint8_t i=0; i<16; i++){
    trellis.clrLED(i);
  }
  trellis.writeDisplay();
}




