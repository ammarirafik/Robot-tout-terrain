const int motA_pin1=7;              
const int motA_pin2=8;
const int motB_pin1=10;             
const int motB_pin2=9;
int command=0;

void setup() {
pinMode (motA_pin1,OUTPUT);      
pinMode (motA_pin2,OUTPUT);
pinMode (motB_pin1,OUTPUT);
pinMode (motB_pin2,OUTPUT);
  
}
void FWD() {
digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW); 
digitalWrite(motB_pin1,HIGH);
digitalWrite(motB_pin2,LOW);
Serial.println("fwd");
}

void LEFT() {
digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW);
digitalWrite(motB_pin1,LOW); 
digitalWrite(motB_pin2,HIGH);
Serial.println("left"); 
}
void RIGHT() {
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);
digitalWrite(motB_pin1,HIGH); 
digitalWrite(motB_pin2,LOW);
Serial.println("RIGHT"); 
}
void REV() {
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,HIGH);
Serial.println("rev");
}
void UP_LEFT() {
  digitalWrite(motA_pin1, HIGH);
  digitalWrite(motA_pin2, LOW);
  digitalWrite(motB_pin1, LOW);
  digitalWrite(motB_pin2, LOW);

  Serial.println("up_left");
}
void UP_RIGHT() {
  digitalWrite(motA_pin1, LOW);
  digitalWrite(motA_pin2, LOW);
  digitalWrite(motB_pin1, HIGH);
  digitalWrite(motB_pin2, LOW);

  Serial.println("UP_RIGHT");
}
void DOWN_RIGHT() {
  digitalWrite(motA_pin1, LOW);
  digitalWrite(motA_pin2, HIGH);
  digitalWrite(motB_pin1, LOW);
  digitalWrite(motB_pin2, LOW);

  Serial.println("DOWN_RIGHT");
}
void DOWN_LEFT() {
  digitalWrite(motA_pin1, LOW);
  digitalWrite(motA_pin2, LOW);
  digitalWrite(motB_pin1, LOW);
  digitalWrite(motB_pin2, HIGH);

  Serial.println("down_left");
}
void STOP(){
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,LOW);
digitalWrite(motB_pin1,LOW); 
digitalWrite(motB_pin2,LOW);
Serial.println("stop"); 
}
void loop() {
  void loop() {
if (Serial.available()>0){
    command=Serial.read();      /// read data from blutooth app
    if (command=='w'){
      speed=250;
      Serial.println("speed=250"); 
    }
    if (command=='W'){
      speed=155;
      Serial.println("speed=155"); 
    }
    else if ( command == 70) 
      FWD();
    else if ( command == 76)
      LEFT();
    else if ( command == 82)
      RIGHT();
    else if ( command == 66)
      REV();
    else if ( command == 71)
      UP_LEFT();
    else if ( command == 73)
      UP_RIGHT();
    else if ( command == 72)
      DOWN_LEFT();
    else if ( command == 74)
      DOWN_RIGHT();
    else
      STOP();
  }
}

  
