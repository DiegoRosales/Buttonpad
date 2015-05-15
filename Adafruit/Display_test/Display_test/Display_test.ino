#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
 Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);


void setup() {
  Serial.begin(115200);
  display.begin();
  display.setContrast(50);
  display.display();
  delay(2000);
  display.clearDisplay();
  
  testdrawline();
  display.display();
  delay(2000);
  
  display.clearDisplay();
  testdrawchar();
  display.display();
  
  display.drawLine(0, 7, 83, 7, BLACK);
  display.display();
  // put your setup code here, to run once:

}

void testdrawline() {  
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, 0, i, display.height()-1, BLACK);
    display.display();
  }
  for (int16_t i=0; i<display.height(); i+=4) {
    display.drawLine(0, 0, display.width()-1, i, BLACK);
    display.display();
  }
  delay(250);
  
  display.clearDisplay();
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, display.height()-1, i, 0, BLACK);
    display.display();
  }
  for (int8_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(0, display.height()-1, display.width()-1, i, BLACK);
    display.display();
  }
  delay(250);
  
  display.clearDisplay();
  for (int16_t i=display.width()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, i, 0, BLACK);
    display.display();
  }
  for (int16_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, 0, i, BLACK);
    display.display();
  }
  delay(250);

  display.clearDisplay();
  for (int16_t i=0; i<display.height(); i+=4) {
    display.drawLine(display.width()-1, 0, 0, i, BLACK);
    display.display();
  }
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(display.width()-1, 0, i, display.height()-1, BLACK); 
    display.display();
  }
  delay(250);
}

void testdrawchar(void) {
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  
  String test = "Main Menu";
  for(int i=0; i<test.length(); i++){
    display.write(test[i]);  
  }
  display.display();

//  for (uint8_t i=0; i < 168; i++) {
//    if (i == '\n') continue;
//    display.write(i);
//    //if ((i > 0) && (i % 14 == 0))
//      //display.println();
//  }    
//  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}
