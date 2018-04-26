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
  
}


