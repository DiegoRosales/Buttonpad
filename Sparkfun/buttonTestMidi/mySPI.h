#ifndef MYSPI_H
#define MYSPI_H

#include <Arduino.h>

#define PERIOD 20

void mySPIBegin();
void mySPITransmit(char data);
char mySPITransmitReceive(char data);

#endif
