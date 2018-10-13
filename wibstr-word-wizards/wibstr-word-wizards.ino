#include <HashMap.h>

//CreateHashMap(scrabbleScores, int, int, 7);
// initialize 2D arrays
int board[3][3];
int multiplier[3][3];

//initialize button to switch 
int inPin = 7; 

// initialize 2 player scores 
int player1Score = 0;
int player2Score = 0;
boolean player = true; //true=player1, false=player2
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // declare pushbutton as input
  pinMode(inPin, INPUT);
  
  // making the initial board
  for (int i=0; i<3; ++i){
    for (int j=0; j<3; ++j){
      board[i][j]=0;
      multiplier[i][j]=0;
    }   
  }

  // making initial multiplier
  // if multiply letter by 2, fill with 2
  // if multiply word by 2, fill with 20
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue0 = analogRead(A0);
  int sensorValue1 = analogRead(A1);
  int sensorValue2 = analogRead(A2);

  float volt0 = sensorValue0 * (5.0 / 1023.0);
  float volt1 = sensorValue1 * (5.0 / 1023.0);
  float volt2 = sensorValue2 * (5.0 / 1023.0);

  val = digitalRead(inPin);  // read input value
  
  if (val == HIGH) {         // check if the input is HIGH (button released)
    //when player1 ends their turn
    if(player==true){
      player1Score=sumScore(player1Score, volt0, volt1, volt2);
      player=false;
      
    }
    //when player2 ends their turn
    else{
      player2Score=sumScore(player2Score, volt0, volt1, volt2);
      player=true;
    }
    //update score display code!
  }
  
  
}


// Can't use hashmap because voltage is a range :(
int getScoreFromVoltage(int voltage) {
  if (voltage //fill this in later){
    return 1;
  }
  else if (voltage ){
    return 2;
  }
  else if (voltage ){
    return 3;
  }
  else if (voltage ){
    return 4;
  }
  else if (voltage ){
    return 5;
  }
  else if (voltage ){
    return 8;
  } 
  else if (voltage ){
    return 10;
  }
  else if (voltage ){
    return 0;
  }
}

// sum up the player score after button is pressed
int sumScore (playerScore, v0, v1, v2){
  //update with new code!
  int totalScore=0;
  return totalScore;
}
