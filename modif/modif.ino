#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define light_DEPAN    14    //LED depan kanan   pin A0  
#define light_BELAKANG 15    //LED depan kiri   pin A1  
#define light_KELAKSON   16     //LED belakang kanan    pin A2 
#define light_BAWAH  17     //LED belakang kiri    pin A3 


#define ENA 5        // pin 5
#define ENB 6        // pin 6
       
 
#define IN_1  2        // driver in  to pin 2
#define IN_2  3        // driver in  to pin 3
#define IN_3  4        // driver in  to pin 4
#define IN_4  7        // driver in  to pin 7 


int command;                   // status perintah 
int speedCar         = 150;    // 0 - 255.
int speed_Coeff      = 4;
boolean lightFront   = false;
boolean lightBack    = false;
boolean Horn         = false;
boolean Extra        = false;

void setup() {  

 
  lcd.begin(); 
  
  lcd.setCursor(0,0);
  lcd.print("   WELCOME TO   ");
  lcd.setCursor(0,1);
  lcd.print("MY HOBY ROBOTIC,");
  delay (4000);

  lcd.setCursor(0,0);
  lcd.print("  RC BLUETOOTH  ");
  lcd.setCursor(0,1);
  lcd.print(" MADE BY PUJI K ");


    pinMode(light_DEPAN, OUTPUT);
    pinMode(light_BELAKANG, OUTPUT);
    pinMode(light_KELAKSON, OUTPUT);
    pinMode(light_BAWAH, OUTPUT);
    
    
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN_1, OUTPUT);
    pinMode(IN_2, OUTPUT);
    pinMode(IN_3, OUTPUT);
    pinMode(IN_4, OUTPUT);
   
  Serial.begin(9600); 

  } 

void goAhead(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);

      
  lcd.setCursor(0,0);
  lcd.print("    # MAJU #    ");
  lcd.setCursor(0,1);
  lcd.print("   TAK GENTAR   ");
  delay (10);

  }

void goBack(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);

      
  lcd.setCursor(0,0);
  lcd.print("   # MUNDUR #   ");
  lcd.setCursor(0,1);
  lcd.print("    ALON ALON   ");
  delay (10);

  }

void goRight(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);   

      
  lcd.setCursor(0,0);
  lcd.print("     BELOK     ");
  lcd.setCursor(0,1);
  lcd.print("    # KIRI #   ");
  delay (10);

  }

void goLeft(){
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);       

      
  lcd.setCursor(0,0);
  lcd.print("     BELOK     ");
  lcd.setCursor(0,1);
  lcd.print("   # KANAN #   ");
  delay (10);

  }

void goAheadRight(){
      
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar/speed_Coeff);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar/speed_Coeff); 


  }

void goAheadLeft(){
      
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);


  }

void goBackRight(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar/speed_Coeff);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar/speed_Coeff);


  }

void goBackLeft(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);


  }

void stopRobot(){  

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar); 

      
  lcd.setCursor(0,0);
  lcd.print("  RC BLUETOOTH  ");
  lcd.setCursor(0,1);
  lcd.print(" MADE BY PUJI K ");

  
  }
  
void loop(){


if (Serial.available() > 0) {
  command = Serial.read();
  stopRobot();      //Initialize with motors stopped.

if (lightFront)  {digitalWrite(light_DEPAN, HIGH);} 
if (!lightFront) {digitalWrite(light_DEPAN, LOW);} 
if (lightBack)  {digitalWrite(light_BELAKANG, HIGH);}
if (!lightBack) {digitalWrite(light_BELAKANG, LOW);} 
if (Extra)     {digitalWrite(light_BAWAH, HIGH);}
if (!Extra)    {digitalWrite(light_BAWAH, LOW);} 
if (Horn)     {tone(light_KELAKSON,1000 );}
if (!Horn)    {noTone(light_KELAKSON);} 




switch (command) {
case 'F':goAhead();break;
case 'B':goBack();break;
case 'L':goLeft();break;
case 'R':goRight();break;
case 'I':goAheadRight();break;
case 'G':goAheadLeft();break;
case 'J':goBackRight();break;
case 'H':goBackLeft();break;
case '0':speedCar = 100;break;
case '1':speedCar = 115;break;
case '2':speedCar = 130;break;
case '3':speedCar = 145;break;
case '4':speedCar = 160;break;
case '5':speedCar = 175;break;
case '6':speedCar = 190;break;
case '7':speedCar = 205;break;
case '8':speedCar = 220;break;
case '9':speedCar = 235;break;
case 'q':speedCar = 255;break;
case 'W':lightFront = true;break;
case 'w':lightFront = false;break;
case 'U':lightBack  = true;break;
case 'u':lightBack  = false;break;
case 'V':Horn      = true;break;
case 'v':Horn      = false;break;
case 'X':Extra      = true;break;
case 'x':Extra      = false;break;



}
}
}
