// 변수 닉네임 설정
int triggerPin1 = 8;
int triggerPin2 = 2;

int echoPin1 = 9;
int echoPin2 = 3;

int motor1 = 5;
int motor2 = 10;


void setup()
{
  pinMode(triggerPin1,OUTPUT); //trig 1
  pinMode(echoPin1,INPUT); // Echo 1
  
  pinMode(triggerPin2,OUTPUT); //trig 2
  pinMode(echoPin2,INPUT); // Echo 2
  
  pinMode(motor1,OUTPUT); // Motor1
  pinMode(motor2,OUTPUT); // Motor2
}

void loop()
{
  // 초음파센서1, 2 거리측정
  
  digitalWrite(triggerPin1,HIGH); //trig1 HIGH
  delayMicroseconds(10);
  digitalWrite(triggerPin1,LOW); //trig1 LOW
  long duration1 = pulseIn(echoPin1, HIGH);
  
  digitalWrite(triggerPin2,HIGH); //trig2 HIGH
  delayMicroseconds(10);
  digitalWrite(triggerPin2,LOW); //trig2 LOW
  long duration2 = pulseIn(echoPin2, HIGH);
  
  //초음파 센서 거리 0일시 
  if((duration1 && duration2)  ==0)
  {
    return;
  }
  
  // 21.9us/cm*2=58.2cm으로 환산하는 값
  long distance1 = duration1/58.2;
  long distance2 = duration2/58.2;
  
  
  //초음파1 , 모터1 좌측
  if(distance1<50){
         analogWrite(motor1,255);
         delay(1000);

  }
  	else if(distance1<100){
         	analogWrite(motor1,127);
         	delay(1000);

  	}
  		else if(distance1<150){
         	analogWrite(motor1,40);
         	delay(1000);
    
 		}
  
  //초음파2 , 모터2 우측
  if(distance2<50){
         analogWrite(motor2,255);
         delay(1000);

  }
  else if(distance1<100){
         analogWrite(motor2,127);
         delay(1000);

  }
  else if(distance1<150){
         analogWrite(motor2,40);
         delay(1000);
    
  }
  
 //초음파1,2 , 모터1,2 전방
  if(distance1 && distance2<50){
  	analogWrite(motor1,255);
  	delay(1000);
  	analogWrite(motor2,255);
  	delay(1000);

  }
  else if(distance1<100){
    analogWrite(motor1,127);
  	delay(1000);
  	analogWrite(motor2,127);
  	delay(1000);

  }
  else if(distance1<150){
   	analogWrite(motor1,40);
  	delay(1000);
  	analogWrite(motor2,40);
  	delay(1000);
    
  }
 
  
    
}