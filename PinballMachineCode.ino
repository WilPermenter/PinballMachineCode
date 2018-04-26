/* 
 *  Pinball Machine- Enggineering II , Wil Permenter 
 *  Created 4/18/2018 End xx/xx/xxx
 *  Description: This Code is a pinball machine code and has the 
 *  ability to add score and controll lights. Built for Arduino UNO
 */

//used to better control 7 Segment LED's

#include "SevenSeg.h"


SevenSeg sevenseg(true); //True For debugging

//used to have led light shows stored else where

#include "ledShow.h"

ledShow ledshow(true); //True for debugging

int waitTime = 1; // sets refreshRate, Lowest = 1

//Pin Var Setup

 int scorePin = A0; //Used for point/hit detection


//Connect these pins to the coraspoinding spots on display
/*
    1  = 2
    2  = 3
    3  = 4
    4  = 5
 */
 int A = 6;
 int B = 7;
 int C = 8;
 int D = 9;
 int E = 10;
 int F = 11;
 int G = 12;

//Score Var Setup
int pointAddTen = 600;  //Analog Input for +10
int pointAddTwent = 650;//Analog Input for + 20
int pointAdd = 0; // Storage Var
// Display Var Most Right will be static 0

int scoreOnePlace = 0; // Second From Right 1's place
int scoreTenPlace = 0;// Third From Right 10's place
int scoreHundPlace = 0; // Most Left One  100's Place
int scoreThousPlace = 0; // Most Left One  1000's Place

bool scoreChange = true; //If score needs to be updated will be true

int scoreDisplay = 2; //Tells what segment to turn on based off Pin Numbe(look Above);

int scoreNumber = 0; //the number to be displayed

int latch = 0; //latching for preventing over count on score

    
void setup() {

  //setup

  sevenseg.begin(9200); //starts serial dont ask why this is done 2x
  ledshow.begin(9200); // starts serial
  
  //Pins For Seven Seg 

  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);

  
  //Pins For LED Control
  
  //Other Stuff

          // Sets All Segments to off on Start
 digitalWrite(2,HIGH); 
 digitalWrite(3,HIGH);
 digitalWrite(4,HIGH);
 digitalWrite(5,HIGH);
 
}
  


void loop() {




// Score Detection

pointAdd = analogRead(scorePin); //reads For point

if(pointAdd > pointAddTen && pointAdd < pointAddTwent && latch == 0){ //Will Run if was +10
  scoreOnePlace += 1; //Adds Points to Score
  
  scoreChange = 1; //Tells us to update Display

  latch =1; //sets latch to 1 bc a hit was detecteed
  }else if(pointAdd > pointAddTwent && latch == 0){ //Will run if +20
  scoreOnePlace += 2; //Adds Points to Score

  scoreChange = true;

  latch = 1; // sets latch to 1 bc hit was detected
  }else{ 
    scoreChange = false; // bool to skip score if no change needed ( this makes the leds not flicker as much);
  
   if (pointAdd < 400){ // this de latches the scoreing stuff
    latch = 0;
  } 
  Serial.println(scoreThousPlace);    // Prints Score
  Serial.print(scoreHundPlace);
  Serial.print(scoreTenPlace);
  Serial.print(scoreOnePlace);
  }

  

//ScoreMaths
 if(scoreChange){                    // skips steps if change not needed, scoreChange is a bool so it will be true of false

  /* 
   *  I know this part is basiclly reinventing the wheel but i feel this gives more control over scores. Its basicly just 
   *  going in and looking at the specific place value of our score.
   */
   
 if(scoreOnePlace >= 10){                     //if ones place is 10 then will carry over to tens place scoreTwo
  
  scoreOnePlace -= 10;
  scoreTenPlace += 1;
  

  
  }else if(scoreTenPlace >= 10){                     //if tens place is 10 then will carry over to hundreds place scoreTwo
  
  scoreTenPlace  -= 10;
  scoreHundPlace  += 1;
}else if(scoreHundPlace >= 10){                     //if tens place is 10 then will carry over to hundreds place scoreTwo
  
  scoreHundPlace  -= 10;
  scoreThousPlace  += 1;
}

}
//Display Score                                // Need to get it to decide what its doing with its life...
   
/*
 * This will be using custom Library that is a work in progress.
 * It is written for a 4x 7 segment display part no. HS420561K-32
 */

 
displayLoop: // for goto

    if(1){   
    
   }
   
  if(scoreNumber == 0){
    sevenseg.zero(scoreDisplay);
  }else if (scoreNumber == 1){
    sevenseg.one(scoreDisplay);
  }else if (scoreNumber == 2){
    sevenseg.two(scoreDisplay);
  }else if( scoreNumber == 3){
    sevenseg.three(scoreDisplay);
  }else if (scoreNumber == 4){
    sevenseg.four(scoreDisplay);
  }else if (scoreNumber == 5){
    sevenseg.five(scoreDisplay);
  }else if (scoreNumber == 6){
    sevenseg.six(scoreDisplay);
  }else if (scoreNumber == 7){
    sevenseg.seven(scoreDisplay);
  }else if (scoreNumber == 8){
    sevenseg.eight(scoreDisplay);
  }else{                                 // if its not 0-8 it must be 9 so we can use an else here
    sevenseg.nine(scoreDisplay);
  }

  scoreDisplay += 1;  // counts what 7 seg we are displaying
  
  if( scoreDisplay >= 4){ // makes sure we have turned all of them on once
    goto displayLoop;

    scoreDisplay = 2;        // resets scoreDisplay and will go back to top
  } // else will go to top



  


}

