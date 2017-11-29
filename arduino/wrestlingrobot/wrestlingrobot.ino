#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2,3);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);
 // pinMode(4, OUTPUT);
}

void loop() {
  
  while(1){
  if(BTSerial.available())
      {  
      int no = BTSerial.readBytes(buffe, 1);  
      if(num=='1')
      {
        digitalWrite(8, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(13,LOW); 
        digitalWrite(12,HIGH);
        analogWrite(6, 255);
        analogWrite(9,255);
      }
      if(num=='2')
      {
        digitalWrite(8, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(13,HIGH); 
        digitalWrite(12,LOW);
        analogWrite(9, 255);
        analogWrite(6, 255);
      }
      if(num=='3')
      { 
        digitalWrite(8, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(13,LOW); 
        digitalWrite(12,HIGH);
        analogWrite(9, 255);
        analogWrite(6, 155);
      }
      if(num=='4')
      {         
        digitalWrite(8, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(13,LOW); 
        digitalWrite(12,HIGH);
        analogWrite(9, 155);
        analogWrite(6, 255);
      }
      if(num=='5')
      { 
        analogWrite(6, 0); 
        analogWrite(9, 0);     
      }
    }
  }      
}

