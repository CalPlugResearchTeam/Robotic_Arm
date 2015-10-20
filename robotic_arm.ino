#include <Servo.h> 
#include <SoftwareSerial.h>
 
Servo bottomServo; // base 
Servo leftServo;  //bottom half of arm 
Servo rightServo; //top half of arm

String cmd;

char type; 
char dir; //direction 
 
int bPos; 
int rPos; 
int lPos;
int pos;
int degree; //for moving 

SoftwareSerial mySerial(0, 1); // RX, TX
 
void setup() 
{ 
  Serial.begin(9600);

  //init servo with pin
  bottomServo.attach(11);
  leftServo.attach(10); 
  rightServo.attach(9); 
  
  //init position 
  bPos = 0; 
  rPos = 120;
  lPos = 85;
  
  bottomServo.write(bPos);
  leftServo.write(lPos);
  rightServo.write(rPos); 
  
  Serial.println("Robotic Arm Project"); 
} 
 
void loop() 
{ 
  while (Serial.available()==0) // wait for user input
  {
  }
  cmd = Serial.readString();
  Serial.println("Command: "+cmd);

  type = cmd[0];
  dir = cmd[2]; 
  degree = cmd.substring(4).toInt(); 

  if(type == 'B')
  {
    if(dir == 'U') //go left 
    {
      for(pos=bPos; pos<=(bPos+degree); pos+=1) //Bottom Servo 
      {
        bottomServo.write(pos); 
        delay(300);  
      }
      bPos = bPos+degree;
    }
    else // dir = D. Go right
    {
      for(pos=bPos; pos>=(bPos-degree); pos-=1) //Bottom Servo 
      {
        bottomServo.write(pos); 
        delay(300);  
      } 
      bPos = bPos-degree;
    }
  }
  else if(type == 'L')
  {
    if(dir == 'U')
    {
      for(pos=lPos; pos<=(lPos+degree); pos+=1) //Left Servo 
      {
        leftServo.write(pos); 
        delay(300);  
      }
      lPos = lPos+degree;
    }
    else // dir = D
    {
      for(pos=lPos; pos>=(lPos-degree); pos-=1) //Left Servo 
      {
        leftServo.write(pos); 
        delay(300);  
      }
      lPos = lPos-degree;
    } 
  }
  else //type = R
  {
    if(dir == 'U')
    {
      for(pos=rPos; pos>=(rPos-degree); pos-=1) //Right Servo 
      {
        rightServo.write(pos); 
        delay(300);  
      }
      rPos = rPos-degree;
      
    }
    else // dir = D
    {
      for(pos=rPos; pos<=(rPos+degree); pos+=1) //Right Servo 
      {
        rightServo.write(pos); 
        delay(300);  
      }
      rPos = rPos+degree;
    }
  }
  
  //Movement 
  /*for(pos=90; pos<=120; pos+=1) //Bottom Servo 
  {
    bottomServo.write(pos); 
    delay(500);  
  }
  for(pos=40; pos<=90; pos+=1) //Right Servo 
  {
    rightServo.write(pos); 
    delay(500);  
  }
  for(pos=90; pos>=60; pos-=1) //Left Servo 
  {
    leftServo.write(pos); 
    delay(500);  
  } 
  for(pos=120; pos>=90; pos-=1) //Bottom Servo 
  {
    bottomServo.write(pos); 
    delay(500);  
  }
  for(pos=60; pos<=90; pos+=1) //Left Servo 
  {
    leftServo.write(pos); 
    delay(500);  
  } 
  for(pos=90; pos>=40; pos-=1) //Right Servo 
  {
    rightServo.write(pos); 
    delay(500);  
  }*/
  
   
} 


