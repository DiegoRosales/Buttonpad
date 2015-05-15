#ifndef SEQ_MENU_H
#define SEQ_MENU_H

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#include <Wire.h>
#include "Adafruit_Trellis.h"
#include "T_Seq.h"
#include "TimerOne.h"
#include <SoftwareSerial.h>

#define MENU_SPACING 1
#define MENU_WIDTH 9
#define CHAR_WIDTH 8
#define MENU_TITLE_WIDTH 9

class menu{
  public:
    uint8_t root;
    uint8_t level;
    uint8_t id;
    String name; 
};

class Menu_system{
  T_Sequencer mSequencer;
  Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);  
  static const uint8_t num_menus = 9;
  menu currentMenu;
  uint8_t currentSelection;
  menu myMenus[num_menus];
  public:
    Menu_system();
    void go_to(menu myMenu, uint8_t select_id);
    void select(uint8_t id);
    void begin();
    
  private:
    
};





#endif
