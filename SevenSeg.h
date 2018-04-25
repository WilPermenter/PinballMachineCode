/* 
 *  SevenSeg- Enggineering II , Wil Permenter 
 *  Created 4/18/2018 Finished xx/xx/xxx
 *  Description: This Code is a to be used with pinball machine code and has the 
 *  ability to control 7 Segmet LED... Built for Arduino UNO
 */

#ifndef SevenSeg_h
#define SevenSeg_h

#include "Arduino.h"


class SevenSeg {
  public:
  SevenSeg(bool displayMsg = false);
  void begin(int baudRate=9600);
  //numbers
  //printScore
 
  int A = 6;
  int B = 7;
  int C = 8;
  int D = 9;
  int E = 10;
  int F = 11;
  int G = 12;

  int waitTime = 1;
  
  void zero(int segmentNumber);
  void one(int segmentNumber);
  void two(int segmentNumber);
  void three(int segmentNumber);
  void four(int segmentNumber);
  void five(int segmentNumber);
  void six(int segmentNumber);
  void seven(int segmentNumber);
  void eight(int segmentNumber);
  void nine(int segmentNumber);
  
  private:
   int _selector;
   bool _msg;
   int _segmentNumber;
 
   
};
 


#endif 

