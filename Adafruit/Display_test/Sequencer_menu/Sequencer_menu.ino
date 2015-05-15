#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "seq_menu.h"

#include <Wire.h>
#include "Adafruit_Trellis.h"
#include "T_Seq.h"
#include "TimerOne.h"
#include <SoftwareSerial.h>

// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
 Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);

Menu_system trellis_menu = Menu_system();

void setup() {
  Serial.begin(115200);
  Serial.println("Starting...");
  display.begin();
  display.setContrast(50);
  display.display();
  delay(2000);
  display.clearDisplay();

      
  display.display();
  delay(5000);
  
  //trellis_menu = new Menu_system();
  trellis_menu.begin();
  Serial.println("Done!");
}

void loop() {
  if(Serial.available()){
    char x = Serial.read();
    Serial.print(x);
    if(x == 's'){
      trellis_menu.select(0xFE);
    }else if(x == 'u'){
      trellis_menu.select(0xFF);
    }else{
      Serial.println((uint8_t)(x-'0'));
      trellis_menu.select((uint8_t)(x-'0'));  
    }
  }

}
