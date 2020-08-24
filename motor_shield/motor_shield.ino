#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial serial (9, 10);

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int kec = 255;
String input, data;
int int1;

void setup() {
  Serial.begin(9600);
  serial.begin(9600);

  motor1.setSpeed(kec);
  motor2.setSpeed(kec);
  motor3.setSpeed(kec);
  motor4.setSpeed(kec);
}

void loop() {
  komunikasi();

  switch (int1)
  {
    case 'w':
      forward();
      break;
    case 's':
      backward();
      break;
    case 'a':
      left();
      break;
    case 'd':
      right();
      break;
    case 'c':
      rest();
      break;
  }
}

void forward () {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  Serial.println("MAJU");
}

void backward () {

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  Serial.println("MUNDUR");
}

void right() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  Serial.println("KANAN");
}

void left() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  Serial.println("KIRI");
}

void rest() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  Serial.println("RELEASEI");
}

void komunikasi () {
  while (serial.available() > 0) {
    int1 = serial.read();
  }
}
