#include <SoftwareSerial.h>
SoftwareSerial module_bluetooth(0, 1); // pin RX | TX

#define echopin_1 8
#define trigpin_1 9
#define echopin_2 10
#define trigpin_2 11
#define echopin_3 12
#define trigpin_3 13
#define echopin_4 A1
#define trigpin_4 A2

#define ENA 5 //pin 5
#define ENB 6 // pin 6 

#define IN_1  2        // driver in  to pin 2
#define IN_2  3        // driver in  to pin 3
#define IN_3  4        // driver in  to pin 4
#define IN_4  7        // driver in  to pin 7 

long duration, distance;

int minimumRange = 5;
int maximumRange = 200;

void setup()
{
  Serial.begin(9600);
  Serial.println("Input command AT:");
  module_bluetooth.begin(38400);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);

  pinMode(trigpin_1, OUTPUT);
  pinMode(echopin_1, INPUT);
  pinMode(trigpin_2, OUTPUT);
  pinMode(echopin_2, INPUT);
  pinMode(trigpin_3, OUTPUT);
  pinMode(echopin_3, INPUT);
  pinMode(trigpin_4, OUTPUT);
  pinMode(echopin_4, INPUT);


}
void loop() {


}

void bluetooth() {
  if (module_bluetooth.available())
    Serial.write(module_bluetooth.read());
  if (Serial.available())
    module_bluetooth.write(Serial.read());
}

void ultrasonic_1 () {
  digitalWrite(trigpin_1, LOW); delayMicroseconds(2);
  digitalWrite(trigpin_1, HIGH); delayMicroseconds(10);
  digitalWrite(trigpin_1, LOW);
  duration = pulseIn(echopin_1, HIGH);

  distance = duration / 58.2;
}

void ultrasonic_2 () {
  digitalWrite(trigpin_2, LOW); delayMicroseconds(2);
  digitalWrite(trigpin_2, HIGH); delayMicroseconds(10);
  digitalWrite(trigpin_2, LOW);
  duration = pulseIn(echopin_2, HIGH);

  distance = duration / 58.2;
}

void ultrasonic_3 () {
  digitalWrite(trigpin_3, LOW); delayMicroseconds(2);
  digitalWrite(trigpin_3, HIGH); delayMicroseconds(10);
  digitalWrite(trigpin_3, LOW);
  duration = pulseIn(echopin_3, HIGH);

  distance = duration / 58.2;
}

void ultrasonic_4 () {
  digitalWrite(trigpin_4, LOW); delayMicroseconds(2);
  digitalWrite(trigpin_4, HIGH); delayMicroseconds(10);
  digitalWrite(trigpin_4, LOW);
  duration = pulseIn(echopin_4, HIGH);

  distance = duration / 58.2;
}
