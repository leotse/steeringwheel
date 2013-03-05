/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledRight = 13;
int ledCenter = 12;
int ledLeft = 11;
int steering = 1;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(ledRight, OUTPUT);     
  pinMode(ledCenter, OUTPUT);     
  pinMode(ledLeft, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  if(Serial.available() > 0) {
    steering = Serial.read();
    Serial.println(steering);
  }
  
    if(steering == 50)
    {
      digitalWrite(ledRight, HIGH);
      digitalWrite(ledCenter, LOW);    
      digitalWrite(ledLeft, LOW);  
    }

    if(steering == 49)
    {
      digitalWrite(ledRight, LOW);
      digitalWrite(ledCenter, HIGH);    
      digitalWrite(ledLeft, LOW);  
    }

    if(steering == 48)
    {
      digitalWrite(ledRight, LOW);
      digitalWrite(ledCenter, LOW);    
      digitalWrite(ledLeft, HIGH);  
    }
}
