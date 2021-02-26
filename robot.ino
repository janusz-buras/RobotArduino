#include <Servo.h>
#define trigPin 13
#define echoPin 12
Servo servo;
//#include "pitches.h"
// notes in the melody:
//int melody[] = {
//  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
//};
//// note durations: 4 = quarter note, 8 = eighth note, etc.:
//int noteDurations[] = {
//  4, 8, 8, 4, 4, 4, 4, 4
//};

void setup() {
Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
servo.attach(A1);
servo.write(90);
 pinMode(7, OUTPUT); 
  pinMode(6, OUTPUT);
 pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(A0, OUTPUT);
   //tone(A0, 1000);
}

int czas=0;
int dystans=0;
int a=0;
int b=0;
void loop() {
 
  jedzprosto();
  a=zmierzOdleglosc();
 delay(500);
Serial.print(a);
  if(a<11){                //sprawdzam czy mogę jechać w prawo, mierzę odległość, jeśli będzie mniejsza skręć w prawo i jedź
zatrzymaj();
servo.write(0); //w prawo
  delay(1500);
a=zmierzOdleglosc();
  delay(1000);
 
    if(a<15){  
    servo.write(180); // w lewo
    delay(1500);
    b=zmierzOdleglosc();
   
          if(b>18){
            skrecprawo();
          }
          else if(b<18){
//           graj();
           servo.write(90);
           delay(1000000);
          
          }
    }
   
    else if(a>15){
    skreclewo();
    }
 
  delay(800);
  }
  servo.write(90);
  delay(200);
}


//void graj(){
//for (int thisNote = 0; thisNote < 8; thisNote++) {
//    // to calculate the note duration, take one second divided by the note type.
//    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//    int noteDuration = 1000 / noteDurations[thisNote];
//    tone(A0, melody[thisNote], noteDuration);
//    // to distinguish the notes, set a minimum time between them.
//    // the note's duration + 30% seems to work well:
//    int pauseBetweenNotes = noteDuration * 1.30;
//    delay(pauseBetweenNotes);
//    // stop the tone playing:
//    noTone(A0);
//  }
//}
void skrecprawo(){
  digitalWrite(4, HIGH);
  analogWrite(3,240);
  delay(3500);
  digitalWrite(4, LOW);
  }
void skreclewo(){
  digitalWrite(7, HIGH);
  analogWrite(6,240);
  delay(3500);
  digitalWrite(7, LOW);
  }
void jedzprosto(){
 
   digitalWrite(4, HIGH);
  analogWrite(3,240);
  digitalWrite(7, HIGH);
  analogWrite(6,240);
 
}
void zatrzymaj(){
digitalWrite(4, LOW);
   digitalWrite(7, LOW);
}
void zawroc(){
  digitalWrite(7, HIGH);
  analogWrite(6,240);
  delay(7000);
  digitalWrite(7, LOW);
}

  int zmierzOdleglosc() {
  long czas, dystans;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;
 
  return dystans;
}
