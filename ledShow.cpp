#include "ledShow.h"

//Start MSG for debugging
ledShow::ledShow(bool displayMsg){
  _msg = displayMsg;
}
void ledShow::begin(int baudRate){
  Serial.begin(baudRate);
  if(_msg) {
    Serial.println("ledShow Library Initiated");
  }
}

void ledShow::startUp(){ // put led stuff in here

digitalWrite(5,LOW);
digitalWrite(4,LOW);
digitalWrite(3,LOW);
digitalWrite(2,LOW);

digitalWrite(A,HIGH);
delay(waitTime); 
digitalWrite(A,LOW);

digitalWrite(B,HIGH);
delay(waitTime); 
digitalWrite(B,LOW);

digitalWrite(C,HIGH);
delay(waitTime); 
digitalWrite(C,LOW);

digitalWrite(D,HIGH);
delay(waitTime); 
digitalWrite(D,LOW);

digitalWrite(E,HIGH);
delay(waitTime); 
digitalWrite(E,LOW);

digitalWrite(F,HIGH);
delay(waitTime); 
digitalWrite(F,LOW);


digitalWrite(5,HIGH);
digitalWrite(4,HIGH);
digitalWrite(3,HIGH);
digitalWrite(2,HIGH);
  
}

void ledShow::bonus(long delayTime0){
  
   delayDiff = delayTime0 - delayTime1; //math find diff
   
   if(delayDiff > 100 && tick == 1){
     digitalWrite(1,HIGH);
     tick = 0;
   }
   
   if(delayDiff > 100 && tick == 0){
    digitalWrite(1,LOW);
    tick = 1;
   }
 delayTime0 = delayTime1;
  
}



