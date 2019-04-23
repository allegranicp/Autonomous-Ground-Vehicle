const int PWM1 = 2; //assigning pin 13 to pwm controller
const int PWM2 = 3;
const int EN1 = 6;
const int EN2 = 7;
const int DIR1 = 4;
const int DIR2 = 5;
const int OUT1A = 24;
const int OUT1B = 28;
const int OUT2A = 26;
const int OUT2B = 30;

int counter = 0;
int curr_state;
int init_state;
int curr_state2;
int init_state2;

void setup()
{
 Serial.begin(9600);
 pinMode(PWM1,OUTPUT);
 pinMode(DIR1, OUTPUT);
 pinMode(EN1,OUTPUT);
 pinMode(PWM2,OUTPUT);
 pinMode(DIR2, OUTPUT);
 pinMode(EN2,OUTPUT);
 pinMode(OUT1A,INPUT);
 pinMode(OUT1B,INPUT);
 pinMode(OUT2A,INPUT);
 pinMode(OUT2B,INPUT);
 
 init_state = digitalRead(OUT1A);
 init_state2 = digitalRead(OUT2A);
 
}

void ForwardMotor()
{
  digitalWrite(DIR1,HIGH);
  digitalWrite(EN1,HIGH);
  digitalWrite(PWM1,157);
  delayMicroseconds(2000);
  digitalWrite(EN1,LOW);
  delayMicroseconds(2000);
  

  digitalWrite(DIR2,HIGH);
  digitalWrite(EN2,HIGH);
  digitalWrite(PWM2,157);
  delayMicroseconds(2000);
  digitalWrite(EN2,LOW);
  delayMicroseconds(2000);
}

void StopMotor()
{
  digitalWrite(EN1,LOW);

  digitalWrite(EN2,LOW);
}

void ReverseMotor()
{
  
  digitalWrite(DIR1,LOW);
  digitalWrite(EN1,HIGH);
  digitalWrite(PWM1, 157);
  delayMicroseconds(2000);
  digitalWrite(EN1,LOW);
  delayMicroseconds(2000);
  
  digitalWrite(DIR2,LOW);
  digitalWrite(EN2,HIGH);
  digitalWrite(PWM2, 157);
  delayMicroseconds(2000);
  digitalWrite(EN2,LOW);
  delayMicroseconds(2000);
}

void BrakeMotor()
{
  digitalWrite(EN1,HIGH);
  digitalWrite(PWM1, 0);
  
  digitalWrite(EN2,HIGH);
  digitalWrite(PWM2, 0);
}

void loop()
{
  ForwardMotor();
  
  curr_state = digitalRead(OUT1A);
  curr_state2 = digitalRead(OUT2A);
  
  if (curr_state != init_state && curr_state2 != init_state2)
  {
    if (digitalRead (OUT1B) != curr_state && digitalRead (OUT2B) != curr_state2)
    {
      counter+=counter;
    }
     else
    { 
     counter-=counter;
    }
   Serial.println("Position: ");
   Serial.println(counter); 
  }
  init_state = curr_state;
  init_state2 = curr_state2;
}


