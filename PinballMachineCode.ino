/* 
 *  Pinball Machine- Enggineering II , Wil Permenter 
 *  Created 4/18/2018 End xx/xx/xxxx
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
 int spinnyPin = A1; // Hit Detection for spinny thing
 
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
int pointSpinnyLast = 0; // Will store the var and will be used to compare to the last 
// Display Var Most Right will be static 0

int scoreOnePlace = 0; // Second From Right 1's place
int scoreTenPlace = 0;// Third From Right 10's place
int scoreHundPlace = 0; // Most Left One  100's Place
int scoreThousPlace = 0; // Most Left One  1000's Place

bool scoreChange = true; //If score needs to be updated will be true

int scoreDisplay = 2; //Tells what segment to turn on based off Pin Numbe(look Above);

int scoreNumber = 0; //the number to be displayed

int latch = 0; //latching for preventing over count on score

int latch2 = 0;//
    
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

//run start up animation 

ledshow.startUp();  //does start up animation

}
  
void loop() {


// Score Detection

pointAdd = analogRead(scorePin); //reads For point

if(pointAdd > pointAddTen && pointAdd < pointAddTwent && latch == 0){ //Will Run if was +10
  scoreTenPlace += 1; //Adds Points to Score
  
  scoreChange = true; //Tells us to update Display

  latch =1; //sets latch to 1 bc a hit was detecteed
  }else if(pointAdd > pointAddTwent && latch == 0){ //Will run if +20
  scoreTenPlace += 2; //Adds Points to Score

  scoreChange = true;

  latch = 1; // sets latch to 1 bc hit was detected
  }else{ 
    scoreChange = false; // bool to skip score if no change needed ( this makes the leds not flicker as much);

int   spinnyNum = analogRead(spinnyPin);
   spinnyNum -= 1006; 
  if(spinnyNum > 10 && latch2 == 1){
    scoreChange = true;
    scoreOnePlace += 5;// adds ~ 5 points per spin might be off a bit due to delays in our sevenseg.cpp
    latch2 = 0;
  }
  if(spinnyNum <10){
    latch2= 1;
  }
  
   if (pointAdd < 400){ // this de latches the scoreing stuff
    latch = 0;
  } 

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
  

  
  }
  if(scoreTenPlace >= 10){                     //if tens place is 10 then will carry over to hundreds place scoreTwo
  
  scoreTenPlace  -= 10;
  scoreHundPlace  += 1;
}
if(scoreHundPlace >= 10){                     //if tens place is 10 then will carry over to hundreds place scoreTwo
  
  scoreHundPlace  -= 10;
  scoreThousPlace  += 1;
}

   Serial.print(scoreThousPlace);    // Prints Score
  Serial.print(scoreHundPlace);
  Serial.print(scoreTenPlace);
   Serial.println(scoreOnePlace); 

}
//Display Score  
   
/*
 * This will be using custom Library that is a work in progress.
 * It is written for a 4x 7 segment display part no. HS420561K-32
 */


 
 displayLoop: // for goto

   if(scoreDisplay == 2){
    scoreNumber = scoreThousPlace;
   }else if(scoreDisplay == 3){
    scoreNumber = scoreHundPlace;
   }else if(scoreDisplay == 4){
    scoreNumber = scoreTenPlace;
   }else if(scoreDisplay == 5){    //set as else if to try to fix problem did not work so just goint to leave it cause why not :I
    scoreNumber = scoreOnePlace;
   }
   
   if(scoreNumber == 0){           // will print 1 segment at a time and its coraspoindg number. Refer to SevenSeg.cpp for the code.
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
  }else if (scoreNumber == 9){                                 //leaveing else if for debugging cause why not
    sevenseg.nine(scoreDisplay);
  } 

  scoreDisplay += 1;  // counts what 7 seg we are displaying
  
 if( scoreDisplay <= 5){ // makes sure we have turned all of them on once
    goto displayLoop;
} 
    scoreDisplay = 2;        // resets scoreDisplay and will go back to top
  // else will go to top

}


