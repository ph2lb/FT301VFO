/*
 * AD9833 arduino library
 * based on : AD9833 Waveform Module vwlowen.co.uk
 * found on : http://www.vwlowen.co.uk/arduino/AD9833-waveform-generator/AD9833-waveform-generator.htm
 */

#include "AD9833.h"
AD9833::AD9833(int dataPin, int clkPin, int csPin)
{
    SPI_MOSI=dataPin;
    SPI_CLK=clkPin;
    FSYNC=csPin;
    
    pinMode(FSYNC,OUTPUT);
    digitalWrite(FSYNC,HIGH);   
} 

void AD9833::init()
{     
//    SPI.begin();  
//    SPI.setDataMode(SPI_MODE2);   
}

void AD9833::reset() {
  WriteRegister(0x100);   // Write '1' to AD9833 Control register bit D8.
  delay(10);
}

// Set the frequency and waveform registers in the AD9833.
void AD9833::setFrequency(long frequency) {
  
  long FreqWord = (frequency * pow(2, 28)) / refFreq;

  int MSB = (int)((FreqWord & 0xFFFC000) >> 14);    //Only lower 14 bits are used for data
  int LSB = (int)(FreqWord & 0x3FFF);
  
  //Set control bits 15 ande 14 to 0 and 1, respectively, for frequency register 0
  LSB |= 0x4000;
  MSB |= 0x4000; 
  
  WriteRegister(0x2100);   
  WriteRegister(LSB);                  // Write lower 16 bits to AD9833 registers
  WriteRegister(MSB);                  // Write upper 16 bits to AD9833 registers.
  WriteRegister(0xC000);               // Phase register
  WriteRegister(SINE);             // Exit & Reset to SINE, SQUARE or TRIANGLE

}

void AD9833::WriteRegister(int dat) { 
  // Maybe the AD9833 use different SPI MODES so it has to be set for the AD9833 here.
  // SPI.setDataMode(SPI_MODE2);	        
  digitalWrite(FSYNC, LOW);           // Set FSYNC low before writing to AD9833 registers
  delayMicroseconds(10);              // Give AD9833 time to get ready to receive data.
  
  SPI.transfer(highByte(dat));        // Each AD9833 register is 32 bits wide and each 16
  SPI.transfer(lowByte(dat));         // bits has to be transferred as 2 x 8-bit bytes.

  digitalWrite(FSYNC, HIGH);          //Write done. Set FSYNC high 
  delayMicroseconds(10);              // Give AD9833 time to get ready to receive data.
}
 
