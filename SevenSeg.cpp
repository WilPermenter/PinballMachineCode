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


    Serial.println(segmentNumber, "Zero");
  
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

digitalWrite(segmentNumber,HIGH);
}


void SevenSeg::one(int segmentNumber){
digitalWrite(segmentNumber,LOW);
  
 digitalWrite(B,HIGH);
delay(waitTime); 
digitalWrite(B,LOW);

digitalWrite(C,HIGH);
delay(waitTime); 
digitalWrite(C,LOW);

digitalWrite(5,HIGH);
}


void SevenSeg::two(int segmentNumber){
  
digitalWrite(segmentNumber,LOW);

digitalWrite(A,HIGH);
delay(waitTime); 
digitalWrite(A,LOW);

digitalWrite(B,HIGH);
delay(waitTime); 
digitalWrite(B,LOW);

digitalWrite(G,HIGH);
delay(waitTime); 
digitalWrite(G,LOW);

digitalWrite(E,HIGH);
delay(waitTime); 
digitalWrite(E,LOW);

digitalWrite(D,HIGH);
delay(waitTime); 
digitalWrite(segmentNumber,HIGH);
}

void SevenSeg::three(int segmentNumber){
  
digitalWrite(segmentNumber,LOW);
  
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

digitalWrite(G,HIGH);
delay(waitTime); 
digitalWrite(G,LOW);

digitalWrite(segmentNumber,HIGH);
 
}


void SevenSeg::four(int segmentNumber){
digitalWrite(segmentNumber,LOW);

digitalWrite(B,HIGH);
delay(waitTime); 
digitalWrite(B,LOW);

digitalWrite(C,HIGH);
delay(waitTime); 
digitalWrite(C,LOW);

digitalWrite(F,HIGH);
delay(waitTime); 
digitalWrite(F,LOW);

digitalWrite(G,HIGH);
delay(waitTime); 
digitalWrite(G,LOW);

digitalWrite(segmentNumber,HIGH);
 
}


void SevenSeg::five(int segmentNumber){
digitalWrite(segmentNumber,LOW);

digitalWrite(A,HIGH);
delay(waitTime); 
digitalWrite(A,LOW);

digitalWrite(C,HIGH);
delay(waitTime); 
digitalWrite(C,LOW);

digitalWrite(D,HIGH);
delay(waitTime); 
digitalWrite(D,LOW);

digitalWrite(F,HIGH);
delay(waitTime); 
digitalWrite(F,LOW);

digitalWrite(G,HIGH);
delay(waitTime); 
digitalWrite(G,LOW);

digitalWrite(segmentNumber,HIGH); 
}


void SevenSeg::six(int segmentNumber){
digitalWrite(segmentNumber,LOW);

digitalWrite(5,LOW);
  
digitalWrite(A,HIGH);
delay(waitTime); 
digitalWrite(A,LOW);

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

digitalWrite(G,HIGH);
delay(waitTime); 
digitalWrite(G,LOW);

  
digitalWrite(segmentNumber,HIGH);  
}


void SevenSeg::seven(int segmentNumber){
digitalWrite(segmentNumber,LOW);

digitalWrite(5,LOW);
  
digitalWrite(A,HIGH);
delay(waitTime); 
digitalWrite(A,LOW);

digitalWrite(B,HIGH);
delay(waitTime); 
digitalWrite(B,LOW);

digitalWrite(C,HIGH);
delay(waitTime); 
digitalWrite(C,LOW);

digitalWrite(5,HIGH);
  
digitalWrite(segmentNumber,HIGH);   
}


void SevenSeg::eight(int segmentNumber){
digitalWrite(segmentNumber,LOW);

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

digitalWrite(G,HIGH);
delay(waitTime); 
digitalWrite(G,LOW);

  
digitalWrite(segmentNumber,HIGH);   
}


void SevenSeg::nine(int segmentNumber){
digitalWrite(segmentNumber,LOW);

digitalWrite(5,LOW);
 
digitalWrite(A,HIGH);
delay(waitTime); 
digitalWrite(A,LOW);

digitalWrite(B,HIGH);
delay(waitTime); 
digitalWrite(B,LOW);

digitalWrite(C,HIGH);
delay(waitTime); 
digitalWrite(C,LOW);

digitalWrite(F,HIGH);
delay(waitTime); 
digitalWrite(F,LOW);

digitalWrite(G,HIGH);
delay(waitTime); 
digitalWrite(G,LOW);

  
digitalWrite(segmentNumber,HIGH);  
}

 

