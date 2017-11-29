#include <SoftwareSerial.h>
#define VERT 1
#define HORIZ 0
#define BUT 7
#define TX 3
#define RX 2

SoftwareSerial bluetooth(TX, RX);

void setup() {
  pinMode(BUT, INPUT);
  digitalWrite(BUT, HIGH);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  int vertical = analogRead(VERT);
  int horizon = analogRead(HORIZ);
  int button = digitalRead(BUT);

   Serial.print("vertical: ");
   Serial.println(vertical,DEC);
   Serial.print("horizon : ");
   Serial.println(horizon, DEC);
   Serial.print("button: ");
   if(button == HIGH)
      Serial.println("not pressed");
   else
      Serial.println("PRESSED");

   if(vertical>=400&&vertical<=560&&horizon>=450&&horizon<=650){
      Serial.println("STOP");
      bluetooth.write(53);//STOP 5
   }
   else if(vertical<500&&horizon>=400&&horizon<=650){
      Serial.println("UP");
      bluetooth.write(49);//UP  1
   }
   else if(vertical>=600&&horizon>=400&&horizon<=650){
      Serial.println("DOWN");
      bluetooth.write(50);//DOWN 2
   }                                                                                                    
   else if(horizon>700 ){
      Serial.println("RIGHT");
      bluetooth.write(52);//RIGHT 4 
   }
   else if(horizon<450){
      Serial.println("LEFT");
      bluetooth.write(51);//LEFT  3
   }
   
  delay(200);
}
