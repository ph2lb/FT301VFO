#ifndef SI5351A_H
#define SI5351A_H
#include <Arduino.h>
#include <stdint.h> 

class SI5351A { 
 private :
  void setupPLL(uint8_t pll, uint8_t mult, uint32_t num, uint32_t denom);
  void setupMultisynth(uint8_t synth, uint32_t divider, uint8_t rDiv);
 public:
	SI5351A();
	void CLK0OutputOff(uint8_t clk);
	void CLK0SetFrequency(uint32_t frequency);


  
#define SI_CLK0_CONTROL  16      // Register definitions
#define SI_CLK1_CONTROL 17
#define SI_CLK2_CONTROL 18
#define SI_SYNTH_PLL_A  26
#define SI_SYNTH_PLL_B  34
#define SI_SYNTH_MS_0   42
#define SI_SYNTH_MS_1   50
#define SI_SYNTH_MS_2   58
#define SI_PLL_RESET    177

#define SI_R_DIV_1    0b00000000      // R-division ratio definitions
#define SI_R_DIV_2    0b00010000
#define SI_R_DIV_4    0b00100000
#define SI_R_DIV_8    0b00110000
#define SI_R_DIV_16   0b01000000
#define SI_R_DIV_32   0b01010000
#define SI_R_DIV_64   0b01100000
#define SI_R_DIV_128    0b01110000

#define SI_CLK_SRC_PLL_A  0b00000000
#define SI_CLK_SRC_PLL_B  0b00100000

#define XTAL_FREQ 27000000      // Crystal frequency
};
#endif //SI5351A_H
