/*
 * AD9833 arduino library
 * based on : AD9833 Waveform Module vwlowen.co.uk
 * found on : http://www.vwlowen.co.uk/arduino/AD9833-waveform-generator/AD9833-waveform-generator.htm
 */

#ifndef AD9833_H
#define AD9833_H
#include <Arduino.h>
#include <stdint.h>
#include <SPI.h>


class AD9833
{
  private:
    const int SINE = 0x2000;                    // Define AD9833's waveform register value.
    const int SQUARE = 0x2020;                  // When we update the frequency, we need to
    const int TRIANGLE = 0x2002;                // define the waveform when we end writing.

    int wave = 0;
    int waveType = SINE;
    int wavePin = 7;

    const float refFreq = 25000000.0;           // On-board crystal reference frequency
    int FSYNC = 10;                       // Standard SPI pins for the AD9833 waveform generator.
    int SPI_CLK = 13;                         // CLK and DATA pins are shared with the TFT display.
    int SPI_MOSI = 11;
    void WriteRegister(int dat);
  public:
    AD9833(int dataPin, int clkPin, int csPin);
    void init();
    void reset();
    void setFrequency(long frequency);
};
#endif
