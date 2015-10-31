#include <Servo.h>     // Slightly different version of the sweep. Changes were to frequency and amount of input.
#include <SoftwareSerial.h>


Servo turnServo; // base 
Servo dropServo;  //bottom half of arm 
Servo extendServo; //top half of the arm

int tpos;
int dpos;
int epos;


String cmd;
int pos;
int degree;

SoftwareSerial mySerial(0, 1); // RX, TX


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  turnServo.attach(11); //BLUE OR A
  dropServo.attach(10); //yellow  OR B
  extendServo.attach(9);  //red OR C
  
}

void loop() {


  while (Serial.available()==0) // wait for user input
  {
  }
  cmd = Serial.readString();
  Serial.println("Command: "+cmd);
  

  pos  = cmd.substring(0).toInt();


  if (pos ==0) //initialize TO UNCUT STAGE
  {
    
//    delay(1000);
//    dropServo.write(65);
//    
//      //35 is all the way up
//    delay(1000);
//    dropServo.write(55);
//    delay(500);
//    dropServo.write(45);
//    delay(500);
//    dropServo.write(35);
//    delay(500);
//    dropServo.write(90);  //125 is all the way down

    //for these values
    dropServo.write(40);  //raises it up
    extendServo.write(155); //brings arm back
    delay(1000);
    turnServo.write(175);
    delay(1000);
    dropServo.write(120); //raise it down
    delay(1000); 
    extendServo.write(70);  //bring arm down.
    delay(1000);   
  }
  
  
  else if (pos ==1) //CUTTING PHASE
  {
    delay(1000);
    dropServo.write(35);
    delay(1000);
    extendServo.write(150);
    delay(1000);
    turnServo.write(0);
    delay(1000);
    dropServo.write(150);
    delay(1000);
    extendServo.write(90);
    delay(1000);
  }
  else if (pos ==2) //uncut
  {
    delay(1000);
    dropServo.write(35);
    delay(1000);
    dropServo.write(90);
    delay(1000);
    dropServo.write(150);
    
    
  }
  //have servo turn arm
//  turnServo.write(0);
//
//  
//
//  
//
//  delay(3000);
//
//
//  //have servo bring arm down
//  turnServo.write(90);
//  
//  
//
//
//  delay(3000);
//
//  turnServo.write(120);
//  //have servo bring arm up
//
//
//  

}
