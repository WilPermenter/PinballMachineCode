/* 
 *  ledShow - Enggineering II , Wil Permenter 
 *  Created 4/18/2018 Finished xx/xx/xxx
 *  Description: This Code is a to be used with pinball machine code and has  
 *  some led light shows for diffrent effects... Built for Arduino UNO
 *  
 */

#ifndef ledShow_h
#define ledshow_h

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class ledShow {
  public:
  ledShow(bool displayMsg = false);
  void begin(int baudRate=9600);

  int A = 6;
  int B = 7;
  int C = 8;
  int D = 9;
  int E = 10;
  int F = 11;
  int G = 12;

  int waitTime = 500;

  void startUp();
  void ledLoop();
  void loss();


  private:
   bool _msg;
};

#endif 

