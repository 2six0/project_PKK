#include <SoftwareSerial.h>

SoftwareSerial serial (2, 3);

String data;
int byteReceived ;

void setup() {
  Serial.begin(9600);
  serial.begin(9600);

}

void loop () {
  if (Serial.available())
  {
    byteReceived = Serial.read();
    serial.write(byteReceived);
  }
}
/*
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
  }*/
