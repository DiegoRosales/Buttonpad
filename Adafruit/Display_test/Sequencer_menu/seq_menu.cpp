#include "seq_menu.h"

Menu_system::Menu_system() {

}

void Menu_system::begin() {
  mSequencer.begin();
  
  myMenus[0].root = 0;
  myMenus[0].level = 0;
  myMenus[0].id = 0;
  myMenus[0].name = "Main menu";
  Serial.println("1");
  myMenus[1].root = 0;
  myMenus[1].level = 1;
  myMenus[1].id = 0;
  myMenus[1].name = "Sequencer";

  myMenus[2].root = 0;
  myMenus[2].level = 1;
  myMenus[2].id = 1;
  myMenus[2].name = "Drum Machine";
  
  myMenus[3].root = 0;
  myMenus[3].level = 2;
  myMenus[3].id = 0;
  myMenus[3].name = "Tempo";
  
  myMenus[4].name = "Velocity";
  myMenus[4].root = 0;
  myMenus[4].level = 2;
  myMenus[4].id = 1;
  Serial.println("4");
  myMenus[5].name = "Track";
  myMenus[5].root = 0;
  myMenus[5].level = 2;
  myMenus[5].id = 2;
 
  myMenus[6].name = "Instrument";
  myMenus[6].root = 0;
  myMenus[6].level = 2;
  myMenus[6].id = 3;
  
  myMenus[7].name = "Instrument";
  myMenus[7].root = 1;
  myMenus[7].level = 2;
  myMenus[7].id = 0;
  
  myMenus[8].name = "Velocity";
  myMenus[8].root = 1;
  myMenus[8].level = 2;
  myMenus[8].id = 1;
  Serial.println("8");
  currentMenu = myMenus[0];
  
  
  display.begin();
  display.setContrast(50);
  display.display();
  delay(1000);
  display.clearDisplay();
  
  go_to(myMenus[0], 0);
  delay(3000);
//  for(;;){
//    go_to(myMenus[1], 0);
//    delay(2000);
//    go_to(myMenus[1], 1);
//    delay(2000);
//    go_to(myMenus[1], 2);
//    delay(2000);
//    go_to(myMenus[1], 3);
//    delay(2000);
//  }
  go_to(myMenus[1], 0);
}

void Menu_system::go_to(menu myMenu, uint8_t select_id) {
  uint8_t x, y;
  x = 0;
  y = 0;
  currentMenu = myMenu;
  display.clearDisplay();
  display.drawLine(0, 7, 84, 7, BLACK);
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(y, x);

  for (int i = 0; i < currentMenu.name.length(); i++) {
    display.write(currentMenu.name[i]);
  }
  
  if(select_id != 0xFF && select_id != 0xFE){
    for (int i = 0; i < num_menus; i++) {
      // Check from the list of menus a match
      if (myMenus[i].root == currentMenu.id && myMenus[i].level == (currentMenu.level+1)) {
        x = myMenus[i].id * (CHAR_WIDTH + 2*MENU_SPACING) + MENU_TITLE_WIDTH;
        if(myMenus[i].id == select_id){
          currentSelection = select_id;
          uint8_t start_pos = x-1; //myMenus[i].id * (MENU_WIDTH + MENU_SPACING) + MENU_TITLE_WIDTH;
          display.fillRoundRect(0, start_pos, 84, CHAR_WIDTH + 2, 1, BLACK);
          display.setTextColor(WHITE);          
        }else{
          display.setTextColor(BLACK);
        }
        
        display.setCursor(y, x);
        for (int j = 0; j < myMenus[i].name.length(); j++) {
          display.write(myMenus[i].name[j]);
        }
      }
    }
  // Jump back to an upper level
  }else if(select_id == 0xFF){
     for (int i = 0; i < num_menus; i++) {
      // Check from the list of menus a match
      if (myMenus[i].id == currentMenu.root && myMenus[i].level == (currentMenu.level-1)) {
        go_to(myMenus[i], 0);
        currentSelection = 0;
        break;  
      }
    }
  }else{
    for (int i = 0; i < num_menus; i++) {
      // Check from the list of menus a match
      if (myMenus[i].id == currentSelection && currentMenu.id == myMenus[i].root && (currentMenu.level+1) == myMenus[i].level) {
        Serial.println(myMenus[i].id);
        Serial.println(myMenus[i].level);
        Serial.println(myMenus[i].root);
        Serial.println(myMenus[i].name);
        if(myMenus[i].id == 1 && myMenus[i].level == 1){
          mSequencer.drumMachine();
        }else if(myMenus[i].id == 0 && myMenus[i].level == 1){
          mSequencer.recordPlay();    
        }
        go_to(myMenus[i], 0);
        currentSelection = 0;
        break;  
      }
    }  
  }
 
  display.display();

}

void Menu_system::select(uint8_t id){
    //currentSelection = id;
    go_to(currentMenu, id);
}

