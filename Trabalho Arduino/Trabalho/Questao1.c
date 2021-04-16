const int buttonPin = 2;     // o numero do pino do botão
const int ledPin =  13;      // o numero do pino do LED
int buttonState = 0;
void setup() {
  pinMode(ledPin, OUTPUT);     
  pinMode(buttonPin, INPUT);   
}

void loop(){
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {     
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}