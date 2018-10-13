#include <HashMap.h>
#include <LiquidCrystal.h>

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

// initialize library with numbers of the interface pins (unsure which pins yet) TODO
LiquidCrystal lcd(12, 11, 5, 4, 3, 2, 1);

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
  // this is the multiplier for the innermost 3x3 square
  multiplier[0][0]=2;
  multiplier[0][2]=2;
  multiplier[2][0]=2;
  multiplier[2][2]=2;

  // set up LCD's number of col and row
  lcd.begin(16, 2);
  // beginning message
  lcd.print("Welcome to Wibstr's Scrabble!");

  // delay a little then displays initial scores
  lcd.delay(1000);
  lcd.print("Player 1 Score: 0");
  lcd.setCursor(0, 1);
  lcd.print("Player 2 Score: 0");
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
    lcd.print("Player 1 Score: "+player1Score);
    lcd.setCursor(0, 1);
    lcd.print("Player 2 Score: "+player2Score);     
  }
  
  
}

// TODO: fill in the voltage range 
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
  /*else if (voltage ){
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
  }*/
  else{
    return 0;
  }
}

// sum up the player score after button is pressed
int sumScore (playerScore, v0, v1, v2){
  //update with new code! TODO implement with the analog
  
  int totalScore=0;
  return totalScore;
}
