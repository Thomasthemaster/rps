/* Rock Paper Scissors Game
Made by Thomas
On September 17 2026

A rock paper scissors game (1/2 player) using the following:
- Liquid Crystal Display (I2C) to display data 
- A servo to show Rock, Paper, & Scissors (random)
- A passive buzzer for sound effects
- An ultrasonic sensor to detect when hand is near
- Buttons for choosing player's guess
- (on physical circuit): A Power MB V2 to supply power and make the project portable
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Servo stuff
int pos = 0;
int servoPin = 12;

Servo computer;

// Sound stuff
int buzzerPin = 5;

// LCD stuff
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Ultrasonic Sensor stuff
int echoPin = 11;
int trigPin = 10;
int distance;
int dThreshold = 5; // cm

// Button stuff
int tButton = 3; // Tie Button
int tVal;

// Other stuff + game mechanics
int setupDelay = 1000;
int throwDelay = 500;
int beatDelay = 1300;
int prepDelay = 1000;
int wait = 3000;
int spamDelay = 20;

int computerChoice;
int playerChoice;

int neutralPos = 0;
int rPos = 0;
int pPos = 90;
int sPos = 180;

void setup() {
  computer.attach(servoPin);
  lcd.init();
  lcd.backlight();
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(tButton, INPUT_PULLUP);
  computer.write(neutralPos);
  randomSeed(analogRead(A0));

  lcd.home();
  lcd.print("Setting up...");
  delay(setupDelay);
  lcd.clear();
}

long readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long dist = duration * 0.034 / 2; // cm
  return dist;
}

void moveServoTo(int choice) {
  if (choice == 0) computer.write(rPos);
  else if (choice == 1) computer.write(pPos);
  else computer.write(sPos);
}

void loop() {
  lcd.clear();
  lcd.home();
  computer.write(neutralPos); 
  
  lcd.print("Ready?");
  delay(prepDelay);

  lcd.clear();
  lcd.home();
  lcd.print("ROCK...");
  tone(buzzerPin, 440, 150);
  delay(beatDelay);

  lcd.clear();
  lcd.home();
  lcd.print("PAPER...");
  tone(buzzerPin, 440, 150);
  delay(beatDelay);

  lcd.clear();
  lcd.home();
  lcd.print("SCISSORS...");
  tone(buzzerPin, 440, 150);
  delay(beatDelay);

  lcd.clear();
  lcd.home();
  lcd.print("SHOOT!!");
  tone(buzzerPin, 880, 200);

   // Confirm a hand is actually near the sensor
  distance = readDistance();
  while (distance >= 6 || distance == 0) {
    distance = readDistance();
    delay(spamDelay); // avoids spamming the sensor
  }

  // Computer commits its random throw after hand detected
  computerChoice = random(0, 3);
  moveServoTo(computerChoice);

  // Result
  lcd.clear();
  lcd.home();

  tVal = digitalRead(tButton);
  while (tVal == 1) {
    tVal = digitalRead(tButton);
  }
  lcd.print("Restarting...");
  delay(wait);
}
