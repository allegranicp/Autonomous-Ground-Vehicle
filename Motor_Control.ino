#define LW_PWM 2 //assigning pin 2 to left motor pwm controller
#define RW_PWM 3 //assigning pin 3 to right motor pwm controller
#define LW_EN 6 //assigning pin 6 to left motor enable controller
#define RW_EN 7 //assigning pin 7 to right motor enable controller
#define LW_DIR 4 //assigning pin 4 to left motor direction controller
#define RW_DIR 5 //assigning pin 5 to right motor direction controller
#define LW_ENCODER_A 24 //assigning pin 24 to left motor hall sensor 1
#define LW_ENCODER_B 28 //assigning pin 28 to left motor hall sensor 2
#define RW_ENCODER_A 26 //assigning pin 26 to right motor hall sensor 1
#define RW_ENCODER_B 30 //assigning pin 30 to right motor hall sensor 2

//Tells compiler value has changed on the fly
volatile unsigned long L_ENCODER_POS = 0;
volatile unsigned long R_ENCODER_POS = 0;

void setup()
{
 Serial.begin(9600);     //baudrate
 pinMode(LW_PWM,OUTPUT);
 pinMode(LW_DIR, OUTPUT);
 pinMode(LW_EN,OUTPUT);
 pinMode(RW_PWM,OUTPUT);
 pinMode(RW_DIR, OUTPUT);
 pinMode(RW_EN,OUTPUT);
 pinMode(LW_ENCODER_A,INPUT);
 pinMode(LW_ENCODER_B,INPUT);
 pinMode(RW_ENCODER_A,INPUT);
 pinMode(RW_ENCODER_B,INPUT);
}

void loop()
{
  moveLeftMotorRearForward();

}

//moves left rear wheel foward
void moveLeftMotorRearForward()
{
  digitalWrite(LW_DIR,HIGH);
  digitalWrite(LW_EN,HIGH);
  digitalWrite(LW_PWM,157);
  delayMicroseconds(2000);
  digitalWrite(LW_EN,LOW);
  delayMicroseconds(2000);
}

//moves right rear wheel forward
void moveRightMotorRearForward()
{
  digitalWrite(RW_DIR,HIGH);
  digitalWrite(RW_EN,HIGH);
  digitalWrite(RW_PWM,157);
  delayMicroseconds(2000);
  digitalWrite(RW_EN,LOW);
  delayMicroseconds(2000);
}

//stops left rear wheel
void stopLeftRearMotor()
{
  digitalWrite(LW_EN,LOW);
}

//stops right rear wheel
void stopRightRearMotor()
{
  digitalWrite(RW_EN,LOW);
}

//reverse left rear wheel
void reverseLeftRearMotor()
{
  
  digitalWrite(LW_DIR,LOW);
  digitalWrite(LW_EN,HIGH);
  digitalWrite(LW_PWM, 157);
  delayMicroseconds(2000);
  digitalWrite(LW_EN,LOW);
  delayMicroseconds(2000);
}

//reverse right rear wheel
void reverseRightRearMotor()
{
  digitalWrite(RW_DIR,LOW);
  digitalWrite(RW_EN,HIGH);
  digitalWrite(RW_PWM, 157);
  delayMicroseconds(2000);
  digitalWrite(RW_EN,LOW);
  delayMicroseconds(2000);
}

//pause left rear wheel
void brakeLeftRearMotor()
{
  digitalWrite(LW_EN,HIGH);
  digitalWrite(LW_PWM, 0);
}

//pause right rear wheel
void brakeRightRearMotor()
{
  digitalWrite(RW_EN,HIGH);
  digitalWrite(RW_PWM, 0);
}

//read left rear wheel encoder
void readLeftRearEncoder()
{
  if (digitalRead(LW_ENCODER_A) == HIGH) 
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(LW_ENCODER_B) == LOW) 
    { 
      L_ENCODER_POS += L_ENCODER_POS;       // CW
    }
    else 
    {
      L_ENCODER_POS -= L_ENCODER_POS;         // CCW
    }
  }
  else                                       
  {
    // check channel B to see which way encoder is turning 
    if (digitalRead(LW_ENCODER_B) == HIGH) 
    {   
      L_ENCODER_POS += L_ENCODER_POS;          // CW
    }
    else
    {
      L_ENCODER_POS -= L_ENCODER_POS;          // CCW
    }
  }
  Serial.println (L_ENCODER_POS, DEC);
}

//read right rear wheel encoder
void readRightRearEncoder()
{
  if (digitalRead(RW_ENCODER_A) == HIGH) 
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(RW_ENCODER_B) == LOW) 
    { 
      R_ENCODER_POS += R_ENCODER_POS;       // CW
    }
    else {
      R_ENCODER_POS -= R_ENCODER_POS;         // CCW
    }
  }
  else                                      
  {
    // check channel B to see which way encoder is turning 
    if (digitalRead(RW_ENCODER_B) == HIGH) 
    {   
      R_ENCODER_POS += R_ENCODER_POS;          // CW
    }
    else 
    {
      R_ENCODER_POS -= R_ENCODER_POS;          // CCW
    }
  }
  Serial.println (R_ENCODER_POS, DEC);
}



