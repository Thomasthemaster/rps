/* Rock Paper Scissors Game
Made by Thomas
On September 17 2026

A rock paper scissors game (1/2 player) using the following:
- A servo to show Rock, Paper, & Scissors (random)
- A passive buzzer for sound effects
- An ultrasonic sensor to detect when hand is near
- (on physical circuit): A Power MB V2 to supply power and make the project portable
*/

#include <Wire.h>
#include <Servo.h>

// Servo stuff
int pos = 0;
int servoPin = 12;

Servo computer;

// Sound stuff
int buzzerPin = 5;

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
int prepDelay = 1000;
int wait = 3000;
int spamDelay = 20;
int movingDelay = 30;

int computerChoice;
int playerChoice;

int neutralPos = 0;
int rPos = 0;
int pPos = 90;
int sPos = 180;
int movingPos;

void setup() {
  computer.attach(servoPin);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(tButton, INPUT_PULLUP);
  computer.write(neutralPos);
  randomSeed(analogRead(A0));

  delay(setupDelay);

  computer.write(neutralPos); 
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
  movingPos = computer.read();
  while (movingPos < 180) { // to build suspense
    movingPos = movingPos + 5;
    computer.write(movingPos);
    delay(movingDelay);
  }
  while (movingPos > 0) {
    movingPos = movingPos - 5;
    computer.write(movingPos);
    delay(movingDelay);
  }
  if (choice == 0) computer.write(rPos);
  else if (choice == 1) computer.write(pPos);
  else computer.write(sPos);
}

void loop() {
  tone(buzzerPin, 880, 200);

   // Confirm a hand is actually near the sensor
  distance = readDistance();
  while (distance >= 10 || distance == 0) {
    distance = readDistance();
    delay(spamDelay); // avoids spamming the sensor
  }

  // Computer commits its random throw after hand detected
  computerChoice = random(0, 3);
  moveServoTo(computerChoice);

  distance = readDistance();
  while (distance <= 9) {
    distance = readDistance();
  }
  delay(wait);
}
