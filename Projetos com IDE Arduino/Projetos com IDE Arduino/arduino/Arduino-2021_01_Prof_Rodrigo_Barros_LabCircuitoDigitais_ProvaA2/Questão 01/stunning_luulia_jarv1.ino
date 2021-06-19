const int buttonPin = 2;     // o numero do pino do botão
const int ledPin =  13; // o numero do pino do LED
int buttonState = 0;
int delay1 = 500;

void interrupt(){
  //coloquei um limite no delay para que a variavel não chegue a zero
	if (delay1 > 100) {     
    delay1 = delay1 - 100;
  }
}
void setup() {
  pinMode(ledPin, OUTPUT);     
  pinMode(buttonPin, INPUT);
  
  attachInterrupt(0, interrupt, FALLING);
}

void loop(){
  digitalWrite(ledPin, HIGH);
  delay(delay1);
  digitalWrite(ledPin, LOW);
  delay(delay1);  
}