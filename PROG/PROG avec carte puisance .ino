const int motA_EN=6; //pwm           //motor right
const int motA_pin1=7;              
const int motA_pin2=8;

const int motB_EN=11; //pwm         // motor left 
const int motB_pin1=10;             
const int motB_pin2=9;


char speed=250; //speed of dc motor pwm

int command=0;  //variable to save data received from bluetooth


void setup() {
Serial.begin(9600);
  // set the pins in read or write mode
pinMode (motA_pin1,OUTPUT);      
pinMode (motA_pin2,OUTPUT);
pinMode (motA_EN,OUTPUT);

pinMode (motB_pin1,OUTPUT);
pinMode (motB_pin2,OUTPUT);
pinMode (motB_EN,OUTPUT);

//--

}

// function 
void FWD() {
analogWrite(motA_EN,speed);
digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW); 
digitalWrite(motB_pin1,HIGH);
digitalWrite(motB_pin2,LOW);
 analogWrite(motB_EN,speed); 
Serial.println("fwd");
}

void LEFT() {
analogWrite(motA_EN,speed);
digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW);
analogWrite(motB_EN,speed);
digitalWrite(motB_pin1,LOW); 
digitalWrite(motB_pin2,HIGH);
Serial.println("left"); 
}
void RIGHT() {
analogWrite(motA_EN,speed);
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);
analogWrite(motB_EN,speed);
digitalWrite(motB_pin1,HIGH); 
digitalWrite(motB_pin2,LOW);
Serial.println("RIGHT"); 
}
void REV() {
analogWrite(motA_EN,speed);
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,HIGH);
analogWrite(motB_EN,speed);
Serial.println("rev");
}
void UP_LEFT() {
  analogWrite(motA_EN,speed);
  digitalWrite(motA_pin1, HIGH);
  digitalWrite(motA_pin2, LOW);
  analogWrite(motB_EN, 0);
  digitalWrite(motB_pin1, LOW);
  digitalWrite(motB_pin2, LOW);

  Serial.println("up_left");
}
void UP_RIGHT() {
  analogWrite(motA_EN,0);
  digitalWrite(motA_pin1, LOW);
  digitalWrite(motA_pin2, LOW);
  analogWrite(motB_EN, speed);
  digitalWrite(motB_pin1, HIGH);
  digitalWrite(motB_pin2, LOW);

  Serial.println("UP_RIGHT");
}
void DOWN_RIGHT() {
  analogWrite(motA_EN,speed);
  digitalWrite(motA_pin1, LOW);
  digitalWrite(motA_pin2, HIGH);
  analogWrite(motB_EN, 0);
  digitalWrite(motB_pin1, LOW);
  digitalWrite(motB_pin2, LOW);

  Serial.println("DOWN_RIGHT");
}
void DOWN_LEFT() {
  analogWrite(motA_EN,0);
  digitalWrite(motA_pin1, LOW);
  digitalWrite(motA_pin2, LOW);
  analogWrite(motB_EN, speed);
  digitalWrite(motB_pin1, LOW);
  digitalWrite(motB_pin2, HIGH);

  Serial.println("down_left");
}
void STOP(){
analogWrite(motA_EN,0);
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,LOW);
analogWrite(motB_EN,0);
digitalWrite(motB_pin1,LOW); 
digitalWrite(motB_pin2,LOW);
Serial.println("stop"); 
}

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
