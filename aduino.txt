#include <stdio.h>
#include <stdlib.h>
 
#include <AFMotor.h>	//DC모터 구동을 위한 라이브러리  

AF_DCMotor motor1(1); // motor 선언(왼쪽 앞바퀴)  
AF_DCMotor motor2(2); // motor 선언(오른쪽 앞바퀴)
AF_DCMotor motor3(3); // motor 선언(왼쪽 뒷바퀴)
AF_DCMotor motor4(4); // motor 선언(오른쪽 뒷바퀴)
 
 
typedef unsigned char    uint8;	    //변수선언(인자 손쉽게 사용을 위한 변환) 
typedef unsigned int     uint16;   

#define TRUE    1 	//TRUE를 1로 선언
#define FALSE   0	//FALSE를 0로 선언
#define None    2	//None을 2로 선언

#define ON      1	//ON을 1로 선언
#define OFF     0	//OFF를 0로 선언

void Setup_MotorPin (void);//change?  //모터 관련 설정함수 선언
void Setup_Bluetooth(void);		//블루투스 관련 설정함수 선언



//// 모터 방향 설정 함수 선언 Motor Direction Function ////

void forward(void);   	// 앞으로 가는 방향구현 함수 선언
void left(void);		// 왼쪽으로 가는 방향구현 함수 선언
void right(void);		// 오른쪽으로 가는 방향구현 함수 선언
void backward(void);	// 뒤로 가는 방향구현 함수 선언
void stop_Mov(void);	// 정지 함수 선언
void rightup(void);	// 오른쪽 위로 가는 방향구현 함수 선언
void leftup(void);	// 왼쪽 위로 가는 방향구현 함수 선언
void leftdown(void);	// 왼쪽 아래로 가는 방향구현 함수 선언
void rightdown(void);	// 오른쪽 아래로 가는 방향구현 함수 선언
void leftturn(void);	// 왼쪽 방향으로 회전 함수 선언
void rightturn(void);	// 오른쪽 방향으로 회전 함수 선언
