#include <SoftwareSerial.h>
SoftwareSerial BTSerial(12, 13);   //RX,TX

int motor1PinA  = 2  ;
int motor1PinB  = 3  ;
int enablelPin  =11 ;   
int motor2PinA  = 4  ;
int motor2PinB  = 5  ;
int enablerPin  = 10 ;  
int ledrpin = 7;
int ledlpin = 8;
char in;
   void setup() {
        BTSerial.begin(9600);//블루투스 통신
        Serial.begin(9600);//시리얼통신
    
        pinMode(motor1PinA, OUTPUT);
        pinMode(motor1PinB, OUTPUT);
        pinMode(motor2PinA, OUTPUT);
        pinMode(motor2PinB, OUTPUT);
        pinMode(enablerPin, OUTPUT);
        pinMode(enablelPin, OUTPUT);
        pinMode(ledrpin,OUTPUT);
        pinMode(ledlpin,OUTPUT);
        // set enablePin high so that motor can turn on:
       analogWrite(enablelPin, 150);
       analogWrite(enablerPin, 150);
       //
    
       }
   void loop() {
       if (BTSerial.available())
          { in =BTSerial.read();
            Serial.write(in);
         }
         if (Serial.available()) 
          {  BTSerial.write(Serial.read());
             Serial.print("data =");
           Serial.println(in);
          }
    
    switch(in){
               case 'F':Forward(); break;
               case 'R': Right(); break; 
               case 'S': Stop(); break;
               case 'L': Left(); break;
               case 'B': Back(); break;
               case 'G': ForwardLeft(); break;
               case 'I': ForwardRight(); break;
               case 'H': BackLeft(); break;
               case 'J': BackRight(); break;
             } 
     
      
     
      }  
void Forward(){  
    //  앞
    digitalWrite(motor1PinA, LOW);
       digitalWrite(motor1PinB,HIGH);
       digitalWrite(motor2PinA,HIGH);
       digitalWrite(motor2PinB,LOW);
}
void Left(){
  digitalWrite(motor1PinA, LOW);    //좌회전
     digitalWrite(motor1PinB, HIGH);
     digitalWrite(motor2PinA, LOW);
     digitalWrite(motor2PinB, LOW);
     digitalWrite(ledlpin,HIGH);
     digitalWrite(ledrpin,LOW);
       
}
void Right(){ 
    digitalWrite(motor1PinA, LOW);    //우회전
    digitalWrite(motor1PinB, LOW);
    digitalWrite(motor2PinA, LOW);
    digitalWrite(motor2PinB, HIGH);
    digitalWrite(ledrpin,HIGH);
    digitalWrite(ledlpin,LOW);
    
    

}
void Stop(){
  digitalWrite(motor1PinA, LOW);     //정지
  digitalWrite(motor1PinB, LOW);
  digitalWrite(motor2PinA, LOW);
  digitalWrite(motor2PinB, LOW);
}
 void Back(){
  digitalWrite(motor1PinA, HIGH);
  digitalWrite(motor1PinB,LOW);
  digitalWrite(motor2PinA,LOW);
  digitalWrite(motor2PinB,HIGH);
  }
 void ForwardLeft(){
  analogWrite(enablelPin, 250);
  analogWrite(enablerPin, 60);
 
  digitalWrite(motor1PinA, LOW);
  digitalWrite(motor1PinB,HIGH);
  digitalWrite(motor2PinA,HIGH);
  digitalWrite(motor2PinB,LOW);
 }
 void ForwardRight(){
  analogWrite(enablelPin, 60);
  analogWrite(enablerPin, 250);

  digitalWrite(motor1PinA, LOW);    //우회전
    digitalWrite(motor1PinB, HIGH);
    digitalWrite(motor2PinA, HIGH);
    digitalWrite(motor2PinB, LOW);
 }

 void BackLeft(){
  analogWrite(enablelPin,250);
  analogWrite(enablerPin,60);

    digitalWrite(motor1PinA, HIGH);
    digitalWrite(motor1PinB,LOW);
    digitalWrite(motor2PinA, LOW);
    digitalWrite(motor2PinB, HIGH);//
 }
 void BackRight(){
  analogWrite(enablelPin,60);
  analogWrite(enablerPin, 250);

    digitalWrite(motor1PinA, HIGH);
    digitalWrite(motor1PinB,LOW);
    digitalWrite(motor2PinA, LOW);
    digitalWrite(motor2PinB, HIGH);
 }
 
 
       
 
 
