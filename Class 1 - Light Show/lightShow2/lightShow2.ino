const int ledPin = 13;
const int led2Pin = 12;
const int led3Pin = 11;

const int buttonPin = 2;
bool buttonState ;

void setup() {
  pinMode(buttonPin = INPUT);
  pinMode(ledPin = OUTPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin);  
  if (buttonState == HIGH)  {
    doLightShow;  }
    else{
     digitalWrite(ledPin,LOW);
   }
 }
   void doLightShow{
     digitalWrite(ledPin,HIGH);
     delay(300);
     digitalWrite(led2Pin,HIGH);
     delay(300);
     digitalWrite(led3Pin,HIGH);
     delay(300);
     digitalWrite(led3Pin,LOW);
     delay(300);
     digitalWrite(led2Pin,LOW);
     delay(300);
     digitalWrite(ledPin,LOW);
     delay(300);
   }
