#include <SoftwareSerial.h>
#define button1 4
#define button2 5
#define button3 6
#define button4 12

SoftwareSerial BTSerial(2,3);
int pinLED[4] = {8,9,10,11};
int k;
int cds_pin = A0;
bool pre_state1 = false;
bool pre_state2 = false;
bool pre_state3 = false;
bool pre_state4 = false;


void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  pinMode(button1,INPUT); 
  pinMode(button2,INPUT); 
  pinMode(button3,INPUT); 
  pinMode(button4,INPUT); 
  
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
  for(int k=0; k<4; k++) {
    pinMode(pinLED[k], OUTPUT);
  }
}

void loop() {

    
    
    bool cur_state1 = !digitalRead(button1);
    if(pre_state1 != cur_state1) {
      if(cur_state1 == HIGH) {
        BTSerial.write('a');
      }
      pre_state1 = cur_state1;
    }
    delay(100);

    bool cur_state2 = !digitalRead(button2);
    if(pre_state2 != cur_state2) {
      if(cur_state2 == HIGH) {
        BTSerial.write('b');
      }
      pre_state2 = cur_state2;
    }
    delay(100);

    bool cur_state3 = !digitalRead(button3);
    if(pre_state3 != cur_state3) {
      if(cur_state3 == HIGH) {
        BTSerial.write('c');
      }
      pre_state3 = cur_state3;
    }
    delay(100);

    bool cur_state4 = !digitalRead(button4);
    if(pre_state4 != cur_state4) {
      if(cur_state4 == HIGH) {
        BTSerial.write('d');
      }
      pre_state4 = cur_state4;
    }
    delay(100);
    
    int mel = BTSerial.read();
    Serial.println(mel);

    if(mel == 0) {
      digitalWrite(8, HIGH);
      tone(7, 262, 500);
      delay(500);
      digitalWrite(8, LOW);
    }else if(mel == 1) {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      tone(7, 294, 500);
      delay(500);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
    }else if(mel == 2) {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      tone(7, 330, 500);
      delay(500);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
    }else if(mel == 3) {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      tone(7, 349, 500);
      delay(500);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    }else if(mel == 4) {
      digitalWrite(11, HIGH);
      tone(7, 392, 500);
      delay(500);
      digitalWrite(11, LOW);
    }else if(mel == 5) {
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      tone(7, 440, 500);
      delay(500);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    }else if(mel == 6) {
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      tone(7, 494, 500);
      delay(500);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    }
    else if(mel == 7) {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      tone(7, 523, 500);
      delay(500);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    }else if(mel == 8) {
      int cds = analogRead(cds_pin);
      if(cds < 500) {
        BTSerial.write('e');
      }else if(cds > 500){
        BTSerial.write('f');
      }delay(100);
    }

    
 

}
