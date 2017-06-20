#include <stdio.h>
#include <stdlib.h>

#include <AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4); 
 
typedef unsigned char    uint8;
typedef unsigned int     uint16;
typedef unsigned long    uin32;
typedef signed short     int8;
typedef signed int       int16;
typedef signed long      int32;

#define TRUE    1
#define FALSE   0
#define None    2

#define ON      1
#define OFF     0

void Setup_MotorPin (void);//change?
void Setup_SensorPin (void);
void Setup_Bluetooth(void);




void forward(void);
void left(void);
void right(void);
void backward(void);
void stop_Mov(void);
void rightup(void);
void leftup(void);
void leftdown(void);
void rightdown(void);
void leftturn(void);
void rightturn(void);




void InteligentMove(void);


uint8 Move_Flag = FALSE;
uint16 IR_Sensor_Val = 0;
uint8 IR_Sensor_Pin = A0;



void setup(void)
{ 
 
  Setup_MotorPin ();
  Setup_Bluetooth();
}
			
void Setup_Bluetooth(void)
{
  Serial.begin(9600);		 
 
  
}

void Setup_MotorPin(void)
{
  motor1.setSpeed(255); 
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255); 
 
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE); 
  motor4.run(RELEASE);  
 
}


void InteligentMove(void)
{
    IR_Sensor_Val = analogRead(IR_Sensor_Pin);
    Serial.println(IR_Sensor_Val);
    if(IR_Sensor_Val >= 970){
      forward();
       delay(6);
     stop_Mov();
     delay(6);
    }
    else if(IR_Sensor_Val < 970){  
    stop_Mov();
      delay(1500);
      backward();
      delay(1000);
      stop_Mov();
      delay(500);
      right();     
      delay(3000);
      stop_Mov();
    }
}

void  forward(void)
{

  
   motor1.run(BACKWARD);
   motor2.run(FORWARD);
   motor3.run(BACKWARD);
   motor4.run(FORWARD);

}  

void left(void)
{

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
 
  
}

void right(void)
{
  
   
   motor1.run(BACKWARD);
   motor2.run(BACKWARD);
   motor3.run(FORWARD);
   motor4.run(FORWARD);

}

void backward(void)
{

  
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);

}

void stop_Mov(void)
{
  
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

void rightup(void)  
{
  motor1.run(BACKWARD);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(FORWARD);
  
}

void leftup(void)
{
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(RELEASE);
 
}

void leftdown(void)
{
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(BACKWARD);
 
}

void rightdown(void)
{
  motor1.run(RELEASE);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(RELEASE);
  
}

void leftturn(void)
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
 
}

void rightturn(void)
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
 
}

 void loop(void)
{
  int nRecv_Uart = Serial.read();
  switch(nRecv_Uart)
  {
    case 'w' : forward();	  break;
    case 'a' : left();		  break;
    case 'd' : right();		  break;
    case 'x' : backward();	  break;
    case 's' : stop_Mov();	  break;
     case 'e' : rightup();	  break;
    case 'q' : leftup();	  break;
    case 'z' : leftdown();	  break;
    case 'c' : rightdown();  	  break;
    case 'r' : leftturn();	  break;
    case 't' : rightturn();	  break;
    

    case 'u' :       break;
    //자동주행모드
    case 'i' : Move_Flag = TRUE;    break;
    case 'o' : Move_Flag = FALSE;  break;
  }
  
  if(Move_Flag == TRUE){
     InteligentMove();
  }
  else if(Move_Flag == FALSE){
    stop_Mov();
    Move_Flag = None;
  }
}
