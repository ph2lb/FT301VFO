# FT301VFO summary
Arduino based external VFO for Yaesu FT301 with AD9850 or AD9833 DDS with LCD or LED display.

# FT301 VFO background info
The FT301 uses a VFO in the range from 5Mhz to 5.5Mhz allowing to tune a 500Khz piece of a selected band. That 500Khz is shown on a white (0 - 500Khz) and orange (500Khz - 1000Khz) roller indicator. The band base frequency of the band (e.g. 14Mhz for 20m) is used to determen which roller indicator should be used (e.g. the white one for 20m). The VFO frequency is the reverse, so the range from 0 - 500Khz leads to a VFO frequency from 5.5Mhz - 5Mhz (e.g. for a 0Khz tune frequency the VFO had a freqency of 5.5Mhz).

The FT301 has a external VFO connector (model 5 pins DIN) on the back of the rig.

 ![5p DIN](http://www.bolkesteijn.nl/blog/uploads/images/5pindin.gif)  
 Viewed from the back of the socket of the front of the plug.
 
1. GND
2. Shield for signal
3. 6V switch power (switch on when ext VFO is selected for RX of TX), which can be used to power a small 6V relay to pass pasthrough or block the output signal from the DDS VFO (handy when working in Split)
4. VFO signal (is connected to the internal VFO which is switched of when external VFO is selected voor RX or TX). External VFO should send no signal when internal VFO is used (see pin 3).
5. 13.5V continues power (always handy to power the external DDS VFO).
 
# This project
Contains the code for a Arduino based external VFO for the Yaesu FT301(D) with AD9850 or AD9833 DDS to generate the frequency and a  LCD or LED display as user interface. Allowing the user to switch band and step size and show the current (band) frequency. The bandplan is defined in a struct in the main source file (default PA country full licensed bandplan).

# Hardware used : 
- Arduino Uno R3 
- DDS one of : 
  - QRP-Labs Arduino Shields (http://qrp-labs.com/uarduino.html) when using AD9850
  - Simple Arduino experiment shield when using AD9833
- Display option one (or both) : 
  - LCD keypad shield (http://www.hobbytronics.co.uk/arduino-lcd-keypad-shield) (warning : don't use D10 with this shield) 
    with analog button. 
  - MAX7219 led display (8 digit) 
- Simpel rotary encoder (gray code encoder)

# External project page 
- http://www.ph2lb.nl/blog/index.php?page=ft301-dds-vfo
