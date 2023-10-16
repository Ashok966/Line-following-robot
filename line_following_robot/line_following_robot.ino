 int IR1=A0;     
int IR2=A1; 
int enA = 9;   
int MotorAip1=12;
int MotorAip2=13;

int enB = 6;   
int MotorBip1=11;
int MotorBip2=10;
void setup() 
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);
  Serial.begin(9600);
}
void loop() 
{
  int a=analogRead(IR1);
  int b=analogRead(IR2);
   digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 0);
    analogWrite (enB, 0);
   if(a&&b) //Move Forward
  {
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    int c=analogRead(A2);
    Serial.println(c);
    Serial.println(c/4);
    
    analogWrite (enA, (c/4));
    analogWrite (enB, (c/4));
     delay(100);
  }

  if(!(a)&&b) 
  {
    Serial.println("MOve Right"); 
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    analogWrite (enA, 150);
    analogWrite (enB, 200);
    delay(100);
  }

  if(a&&!(b))
  {
    Serial.println("MOve Left"); 
    digitalWrite(MotorAip1,LOW);     
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 200);
    analogWrite (enB, 150);
   delay(100);
  }

  if(!(a)&&!(b))
  {
    Serial.println("STOP"); 
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 0);
    analogWrite (enB, 0);
    delay(100);
  }
}
