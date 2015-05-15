#ifndef T_SEQ_H
#define T_SEQ_H

#include <Wire.h>
#include <SoftwareSerial.h>
#include "Adafruit_Trellis.h"
#include "TimerOne.h"

#define NUMTRELLIS 1
#define numKeys (NUMTRELLIS * 16)
#define INTPIN 2

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

enum seqState{DRUM_PAD, SEQUENCER};

class track{
  public:
    unsigned int pattern;
    unsigned int instrument;
    unsigned char velocity[16];
};

class T_Sequencer{

  unsigned int sequence;
  track seqTracks[8];
  Adafruit_Trellis trellis;
  
  public:
    void begin();
    void record();
    void play();
    void recordPlay();
    void drumMachine();
    void tracksNoteOn(unsigned int i);
    void tracksNoteOff(unsigned int i);
    void midiSetInstrument(uint8_t chan, uint8_t inst);
    void midiSetChannelVolume(uint8_t chan, uint8_t vol);
    void midiSetChannelBank(uint8_t chan, uint8_t bank);
    void midiNoteOn(uint8_t chan, uint8_t n, uint8_t vel);
    void midiNoteOff(uint8_t chan, uint8_t n, uint8_t vel);
    void clearLEDS();
    
  private:
    void updateSequence(unsigned int k);
    void loadTrack(unsigned char k);
};



void timer1Callback();

#endif
