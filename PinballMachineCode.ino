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
    5  = 6
 */
 int A = 6;
 int B = 7;
 int C = 8;
 int D = 9;
 int E = 10;
 int F = 11;
 int G = 12;

//Score Var Setup
int pointAddTen = 500;  //Analog Input for +10
int pointAddTwent = 800;//Analog Input for + 20
int pointAdd = 0; // Storage Var
// Display Var Most Right will be static 0

int scoreOnePlace = 0; // Second From Right 1's place
int scoreTenPlace = 0;// Third From Right 10's place
int scoreHundPlace = 0; // Most Left One  100's Place
int scoreThousPlace = 0; // Most Left One  1000's Place

bool scoreChange = true; //If score needs to be updated will be true


void setup() {

  //setup

  sevenseg.begin(9200); //starts serial
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

if(pointAdd > pointAddTen && pointAdd < pointAddTwent){ //Will Run if was +10
  scoreOnePlace += 1; //Adds Points to Score
  
  scoreChange = 1; //Tells us to update Display
  }else if(pointAdd > pointAddTwent){ //Will run if +20
  scoreOnePlace += 2; //Adds Points to Score

  scoreChange = true;
  }else{ 
    scoreChange = false;
  Serial.print("Score not updated Skiped");
  }

//ScoreMaths
 if(scoreChange){                    // skips steps if change not needed
  
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
//Display Score 

int  x = 1;
int  y = 4;


  if(x){
    sevenseg::zero(y);
  }else if (x){
    sevenseg one(y);
  }else if (x){
    sevenseg two(y);
  }else if (x){
    sevenseg four(y);
  }else if (x){
    SevenSeg five(y);
  }else if (x){
    SevenSeg six(y);
  }else if (x){
    SevenSeg seven();
  }else if (x){
    SevenSeg eight();
  }else if (x){
    SevenSeg nine();
  }else{
    
  }

/*
 * This will be using custom Library that is a work in progress.
 * It is written for a 4x 7 segment display part no. HS420561K-32
 */


  


}

