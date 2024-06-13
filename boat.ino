// This part of the code includes the libraries that allow us to connect the arduino board with the bluetooth module and control it with the Dabble App
#include <Dabble.h>
#include <GamePadModule.h>
// This part of the code assigns a pin number for different parts of the H-Bridge connected to pins on the Arduino-uno board
int enA = 9;
int enB = 6;
int in1 = 8;
int in2 = 4;
int in3 = 5;
int in4 = 7;

void setup() {
  // put your setup code here, to run once:
  // The next line is needed for any board that is controlled by the Dabble App
  Serial.begin(250000);
  // The value entered must match the baud rate of the bluetooth module
  Dabble.begin(9600);
  // All the following pins are connected to the motors which are our outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Dabble.processInput();
  // When the up button is pressed in the app, both motors spin in the same direction with a speed of 200
  if (GamePad.isUpPressed())
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 200);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 200);
  }
  // When the down button is pressed in the app, both motors turn off
  if (GamePad.isDownPressed())
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enB, 0);
  }
  // When the left button is pressed in the app, the right motor spins in one direction with a speed of 200 to make the boat rotate to the left
  if (GamePad.isLeftPressed())
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 200);
  }
  // When the right button is pressed in the app, the left motor spins in one direction with a speed of 200 to make the boat rotate to the right
  if (GamePad.isRightPressed())
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 200);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enB, 0);
  }
}
