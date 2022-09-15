/*detects wall*/

//defining pin
#define echoPin 2 
#define trigPin 3 

// defines variables
long duration ;
int distance ;

void setup() {
  pinMode(trigPin, OUTPUT) ;
  pinMode(echoPin, INPUT) ;
  Serial.begin(9600) ;
}

void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW) ;
  delayMicroseconds(2) ;
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH) ;
  delayMicroseconds(10) ;
  digitalWrite(trigPin, LOW) ;
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH) ;
  
  // Calculating the distance
  distance = duration * 0.0343 / 2 ; //uses speed of sound here
  
  //is wall
  if(distance<=10)
    Serial.println("There is a wall") ;
  else
    Serial.println("No wall detected") ;
}
