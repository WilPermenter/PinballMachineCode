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
delayMicroseconds(waitTime); 
digitalWrite(A,LOW);

digitalWrite(B,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(B,LOW);

digitalWrite(C,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(C,LOW);

digitalWrite(D,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(D,LOW);

digitalWrite(E,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(E,LOW);

digitalWrite(F,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(F,LOW);


digitalWrite(5,HIGH);
digitalWrite(4,HIGH);
digitalWrite(3,HIGH);
digitalWrite(2,HIGH);
  
}





