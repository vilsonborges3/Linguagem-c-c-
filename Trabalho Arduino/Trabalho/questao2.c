const int led1Pin =  13; 
const int led2Pin =  9;   
const int led3Pin =  6;

void setup() {
  Serial.begin(115200);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
}

void loop(){
  if (Serial.available()) { // Verificar se há caracteres disponíveis
  	char caractere = Serial.read();
    Serial.print("Caractere recebido: ");
    Serial.print(caractere);
    Serial.print("\n");
    if(caractere == 'w'){
       digitalWrite(led3Pin, HIGH);
       delay(1000);
       digitalWrite(led3Pin, LOW);
       delay(1000);
       digitalWrite(led3Pin, HIGH);
       delay(1000);
       digitalWrite(led3Pin, LOW);
       delay(1000);
    }
    if(caractere == 'e'){
       digitalWrite(led2Pin, HIGH);
       delay(1000);
       digitalWrite(led2Pin, LOW);
       delay(1000);
       digitalWrite(led2Pin, HIGH);
       delay(1000);
       digitalWrite(led2Pin, LOW);
       delay(1000);
       digitalWrite(led2Pin, HIGH);
       delay(1000);
       digitalWrite(led2Pin, LOW);
       delay(1000);
    }
    
    if(caractere == 'r'){
      switch (digitalRead(led1Pin))
        {
          case LOW: 
        	digitalWrite(led1Pin, HIGH);
            break;
          case HIGH:
        	digitalWrite(led1Pin, LOW);
           break;
          default:
        	break;
        }
    }
  }
}