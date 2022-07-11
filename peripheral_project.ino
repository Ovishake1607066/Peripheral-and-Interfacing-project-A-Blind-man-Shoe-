int trigPin1 = 12;
int trigPin2 = 8; 
int trigPin3 = 6; 
int echoPin1 = 11;
int echoPin2 = 9;
int echoPin3 = 7;
int trigPinm = 4; 
int echoPinm = 5;
int Relay =13;
long duration1, cm1,duration2, cm2,duration3, cm3,cmm,durationm,a,b,c;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
    pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
    pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
      pinMode(trigPinm, OUTPUT);
  pinMode(echoPinm, INPUT);
  pinMode(Relay, OUTPUT);
}
void loop() {
    digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
    delayMicroseconds(10);
        pinMode(echoPin2, INPUT);
 duration2 = pulseIn(echoPin2, HIGH);
    digitalWrite(trigPin3, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
      pinMode(echoPin3, INPUT);
  duration3 = pulseIn(echoPin3, HIGH);
    digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
    delayMicroseconds(10);
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);
      digitalWrite(trigPinm, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPinm, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinm, LOW);
    delayMicroseconds(10);
  pinMode(echoPinm, INPUT);
 durationm = pulseIn(echoPinm, HIGH);
  cm1 = (duration1/2) / 29.1;
   cm2 = (duration2/2) / 29.1;  
    cm3 = (duration3/2) / 29.1;  
  cmm = (durationm/2) / 29.1;
  if ((abs(cm1-cm2)<=2 && abs(cm2-cm3)<=2) || (abs(cm1-cm3)<=2 && abs(cm2-cm3)<=2))
  {
       digitalWrite(Relay, HIGH);   
         delay(2000); 
             digitalWrite(Relay, LOW);     
     delay(200); 
  }
  else if(abs(cm1-cm2)<=3 && cm1<=20 && cm2<=20 && (cmm<=50 && cmm>=35))
  {
    digitalWrite(Relay, HIGH);   
         delay(100); 
             digitalWrite(Relay, LOW);    
         delay(100); 
             digitalWrite(Relay, HIGH);    
         delay(100);
             digitalWrite(Relay, LOW);   
         delay(100); 
             digitalWrite(Relay, HIGH);  
 delay(100); 
             digitalWrite(Relay, LOW);   
         delay(100);
                      digitalWrite(Relay, HIGH);    
         delay(100);
             digitalWrite(Relay, LOW);   
         delay(100);
                               digitalWrite(Relay, HIGH);    
         delay(100); 
             digitalWrite(Relay, LOW);   
         delay(3000); 
         Serial.println("yes");
  }
    else if(abs(cm1-cm2)<=3 && cm1<=20 && cm2<=20 && cmm<=20 && (cm3<=50 && cm3>=35))
  {
    digitalWrite(Relay, HIGH);  
         delay(100); 
             digitalWrite(Relay, LOW);   
         delay(100); 
             digitalWrite(Relay, HIGH);   
         delay(100);
             digitalWrite(Relay, LOW);    
         delay(100); 
             digitalWrite(Relay, HIGH);   
         delay(100); 
             digitalWrite(Relay, LOW);   
         delay(100);
                      digitalWrite(Relay, HIGH);    
         delay(100); 
             digitalWrite(Relay, LOW); 
         delay(100);
                               digitalWrite(Relay, HIGH);   
                               delay(100); 
             digitalWrite(Relay, LOW);   
         delay(100); 
                                        digitalWrite(Relay, HIGH);   
         delay(100); 
             digitalWrite(Relay, LOW);   
         delay(3000); 
         Serial.println("yes");
  }
  else if( cm1<=17 && cm2>=30 && cmm>=30 && cm3>=30)
  {
        digitalWrite(Relay, HIGH);   
         delay(300); 
             digitalWrite(Relay, LOW);   
         delay(300); 
         delay(3000);
  }
    else if(cm1<=20 && cm2<=20 && cmm>=30 && cm3>=30)
  {
            digitalWrite(Relay, HIGH);   
         delay(300); 
             digitalWrite(Relay, LOW);   
         delay(300); 
             digitalWrite(Relay, HIGH);    
         delay(300);
             digitalWrite(Relay, LOW);   
         delay(300); 
         delay(3000);
  }
    else if(cm1<=20 && cm2<=20 && cmm<=20 && cm3>=30)
  {
            digitalWrite(Relay, HIGH);   
         delay(300); 
             digitalWrite(Relay, LOW);   
         delay(300); 
             digitalWrite(Relay, HIGH);   
         delay(300);
             digitalWrite(Relay, LOW);   
         delay(300); 
                     digitalWrite(Relay, HIGH);   
         delay(300);
             digitalWrite(Relay, LOW);   
         delay(3000);
  }
  else
  {
     digitalWrite(Relay, LOW);    
     delay(200); 
  }
  Serial.println(cm1);
  Serial.println(cm2);
  Serial.println(cmm);
  Serial.println(cm3);
  Serial.println("cm");
  Serial.println();
}

