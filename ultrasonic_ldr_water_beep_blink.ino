//https://www.youtube.com/watch?v=PWCAMvCIliA  -- ultrasonic
//https://www.youtube.com/watch?v=SkGmtsA69ts  -- ldr



#define ledPin1 7
#define trigPin 8
#define echoPin 9
#define buzzerPin 10
#define ledPin 11
#define ldrPin A0

long duration;
float distanceInch;
int timer;

void setup() {
  
  Serial.begin(9600);

  pinMode(echoPin, INPUT);
  pinMode(ldrPin,INPUT);
  
  pinMode(trigPin, OUTPUT);  
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin1, LOW);

}

void loop() {

   // Ultrasonic Sensor code:
   
  //code needed for the ultrasonic sensor to receive the signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //end of above code

  //calculate the duration needed for the signal to hit back from the obstacle
  duration = pulseIn(echoPin, HIGH);
  
  //convert the duration in distance of inches
  distanceInch = duration * 0.0133 /2;
  
  //sound the buzzer and blink
  if(distanceInch<=100)
  {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);

    timer = distanceInch * 15;

    Serial.print("ultrasonic");
    Serial.println(distanceInch);
    
    //this line shows the delay in time for the loop
    //the shorter the distance from obstacle the faster the beep goes
    if(timer<=500)
      delay(timer);

    return ;
  }
  else
  {
    
      // ldr sensor code:
  
      int ldrStatus=analogRead(ldrPin);
      
      if(ldrStatus<180)
      {
        digitalWrite(buzzerPin,HIGH);
        digitalWrite(ledPin,HIGH);
        delay(100);
    
        digitalWrite(buzzerPin,LOW);
        digitalWrite(ledPin,LOW);
        delay(100);

        Serial.print("ldr");
        Serial.println(ldrStatus);
      }
      else
      {
        digitalWrite(buzzerPin,LOW);
        digitalWrite(ledPin,LOW);
      }

      digitalWrite(ledPin1,HIGH);
      delay(100);
      digitalWrite(ledPin1,LOW);
      return ;
    
  }
  
}
