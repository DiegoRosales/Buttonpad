#include "mySPI.h"

void mySPIBegin(){
  pinMode(10, OUTPUT); // CS
  pinMode(13, OUTPUT); // CK
  pinMode(12, OUTPUT); // Output
  pinMode(11, INPUT); // input
  
  digitalWrite(13, HIGH);
}

void mySPITransmit(char data){
    char index = 1;
    for(int i=0; i<8; i++){
      digitalWrite(13, LOW);
      digitalWrite(12, data&(index<<i));
      delayMicroseconds(PERIOD/2);
      digitalWrite(13, HIGH);
      delayMicroseconds(PERIOD/2);  
    }      
}

char mySPITransmitReceive(char data){
    char index = 1;
    char receivedData = 0x00;
    for(int i=0; i<8; i++){
      digitalWrite(13, LOW);
      digitalWrite(12, data&(index<<i));
      delayMicroseconds(PERIOD/2);
      digitalWrite(13, HIGH);
      delayMicroseconds(10);
      receivedData |= (1&digitalRead(11));
      if(i<7) receivedData <<= 1;
      delayMicroseconds(PERIOD/2-5);  
    }      
    return (1&receivedData);
}
