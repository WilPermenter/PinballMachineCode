#include "SevenSeg.h"
#include "Arduino.h"
//Start MSG for debugging
SevenSeg::SevenSeg(bool displayMsg){
  _msg = displayMsg;
}
void SevenSeg::begin(int baudRate){
  Serial.begin(baudRate);
  if(_msg) {
    Serial.println("SevenSeg Library Initiated");
  }
}

  





// Settings for Displays Usage SevenSeg::zero(display#);
 void SevenSeg::zero(int segmentNumber){
digitalWrite(segmentNumber,LOW);

digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
digitalWrite(E,LOW);
digitalWrite(F,LOW);
digitalWrite(G,LOW);

//Serial.println(segmentNumber);
  
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

digitalWrite(segmentNumber,HIGH);
}


void SevenSeg::one(int segmentNumber){
digitalWrite(segmentNumber,LOW);

digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
digitalWrite(E,LOW);
digitalWrite(F,LOW);
digitalWrite(G,LOW);
  
digitalWrite(B,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(B,LOW);

digitalWrite(C,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(C,LOW);

digitalWrite(segmentNumber,HIGH);
}


void SevenSeg::two(int segmentNumber){
  
digitalWrite(segmentNumber,LOW);

digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
digitalWrite(E,LOW);
digitalWrite(F,LOW);
digitalWrite(G,LOW);

digitalWrite(A,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(A,LOW);

digitalWrite(B,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(B,LOW);

digitalWrite(G,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(G,LOW);

digitalWrite(E,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(E,LOW);

digitalWrite(D,HIGH);
delayMicroseconds(waitTime);
digitalWrite(D,LOW);

delayMicroseconds(waitTime); 
digitalWrite(segmentNumber,HIGH);
}

void SevenSeg::three(int segmentNumber){
  
digitalWrite(segmentNumber,LOW);

digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
digitalWrite(E,LOW);
digitalWrite(F,LOW);
digitalWrite(G,LOW);
  
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

digitalWrite(G,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(G,LOW);

digitalWrite(segmentNumber,HIGH);
 
}


void SevenSeg::four(int segmentNumber){
digitalWrite(segmentNumber,LOW);

digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
digitalWrite(E,LOW);
digitalWrite(F,LOW);
digitalWrite(G,LOW);

digitalWrite(B,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(B,LOW);

digitalWrite(C,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(C,LOW);

digitalWrite(F,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(F,LOW);

digitalWrite(G,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(G,LOW);

digitalWrite(segmentNumber,HIGH);
 
}


void SevenSeg::five(int segmentNumber){
digitalWrite(segmentNumber,LOW);

digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
digitalWrite(E,LOW);
digitalWrite(F,LOW);
digitalWrite(G,LOW);

digitalWrite(A,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(A,LOW);

digitalWrite(C,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(C,LOW);

digitalWrite(D,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(D,LOW);

digitalWrite(F,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(F,LOW);

digitalWrite(G,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(G,LOW);

digitalWrite(segmentNumber,HIGH); 
}


void SevenSeg::six(int segmentNumber){
digitalWrite(segmentNumber,LOW);

digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
digitalWrite(E,LOW);
digitalWrite(F,LOW);
digitalWrite(G,LOW);


  
digitalWrite(A,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(A,LOW);

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

digitalWrite(G,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(G,LOW);

  
digitalWrite(segmentNumber,HIGH);  
}


void SevenSeg::seven(int segmentNumber){
digitalWrite(segmentNumber,LOW);

digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
digitalWrite(E,LOW);
digitalWrite(F,LOW);
digitalWrite(G,LOW);


  
digitalWrite(A,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(A,LOW);

digitalWrite(B,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(B,LOW);

digitalWrite(C,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(C,LOW);

 
digitalWrite(segmentNumber,HIGH);   
}


void SevenSeg::eight(int segmentNumber){
digitalWrite(segmentNumber,LOW);

digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
digitalWrite(E,LOW);
digitalWrite(F,LOW);
digitalWrite(G,LOW);

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

digitalWrite(G,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(G,LOW);

  
digitalWrite(segmentNumber,HIGH);   
}


void SevenSeg::nine(int segmentNumber){
digitalWrite(segmentNumber,LOW);

digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
digitalWrite(E,LOW);
digitalWrite(F,LOW);
digitalWrite(G,LOW);
 
digitalWrite(A,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(A,LOW);

digitalWrite(B,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(B,LOW);

digitalWrite(C,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(C,LOW);

digitalWrite(F,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(F,LOW);

digitalWrite(G,HIGH);
delayMicroseconds(waitTime); 
digitalWrite(G,LOW);

  
digitalWrite(segmentNumber,HIGH);  
}

 


