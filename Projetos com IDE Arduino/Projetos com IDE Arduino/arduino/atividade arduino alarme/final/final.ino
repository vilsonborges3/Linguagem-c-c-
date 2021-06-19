#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void setup(){
  pinMode(A1, INPUT);
    Serial.begin(115200);
}
void loop() {
  
  // Saída (Atuador):
  DDRB |= (1 << DDB3); // Pino 11 (PB3) -> Buzzer
  DDRB |= (1 << DDB4); // Pino 12 (PB4) -> LED A
  DDRB |= (1 << DDB5); // Pino 13 (PB5) -> LED B 
  // Entrada (Sensor):
  DDRD &= ~(1 << DDD2); // Pino 2 (PD2) -> Chave1
  DDRD &= ~(1 << DDD3); // Pino 3 (PD3) -> Chave2
  DDRD &= ~(1 << DDD4); // Pino 4 (PD4) -> Chave3
  DDRD &= ~(1 << DDD5); // Pino 5 (PD5) -> Chave4
  DDRD &= ~(1 << DDD6); // Pino 6 (PD6) -> Chave4

  char estadoPortaSala, estadoJanelaSala, estadoJanelaQuarto1, 
    estadoJanelaQuarto2, chave;
  float readInVolts = 0.0;
  float temp = 0.0;
  int read = 0;
  
  while (1) {
    estadoPortaSala = (PIND & (1 << PIND2)) == (1 << PIND2);
    estadoJanelaSala = (PIND & (1 << PIND3)) == (1 << PIND3);
    estadoJanelaQuarto1 = (PIND & (1 << PIND5)) == (1 << PIND5);
    estadoJanelaQuarto2 = (PIND & (1 << PIND4)) == (1 << PIND4);
    chave = (PIND & (1 << PIND6)) == (1 << PIND6);
    
    // Porta/Janela Fechada = 0 ou Aberta = 1
    if (estadoPortaSala == 1 || estadoJanelaSala == 1 || 
      estadoJanelaQuarto1 == 1 ||estadoJanelaQuarto2 == 1) {
      
    Serial.print("Algum alarme foi acionado! \n");
      // Ativar o Buzzer
      PORTB |= (1 << PORTB3);
    }
    else {
      // Desligar o Buzzer
      PORTB &= ~(1 << PORTB3);
    }

    // Indicação de Acionamento por Zona
    if (estadoPortaSala == 1 || estadoJanelaSala == 1) {
      // Ativar LED A
      PORTB |= (1 << PORTB4);
    }
    else {
      // Desligar LED A
      PORTB &= ~(1 << PORTB4);
    }

    if (estadoJanelaQuarto1 == 1 ||estadoJanelaQuarto2 == 1) {
      // Ativar LED B
      PORTB |= (1 << PORTB5);
    }
    else {
      // Desligar LED B
      PORTB &= ~(1 << PORTB5);
    }
    
    if (chave == 1) {
      // Ativar LED A e B
      PORTB |= (1 << PORTB5);
      PORTB |= (1 << PORTB4);
      _delay_ms(200);
      PORTB &= ~(1 << PORTB5);
      PORTB &= ~(1 << PORTB4);
      _delay_ms(200);
      PORTB |= (1 << PORTB5);
      PORTB |= (1 << PORTB4);
      _delay_ms(200);
      PORTB &= ~(1 << PORTB5);
      PORTB &= ~(1 << PORTB4);
      _delay_ms(200);
      PORTB |= (1 << PORTB5);
      PORTB |= (1 << PORTB4);
      _delay_ms(200);
      PORTB &= ~(1 << PORTB5);
      PORTB &= ~(1 << PORTB4);
      _delay_ms(200);
      
    }
    else {
      // Desligar LED B
      PORTB &= ~(1 << PORTB5);
      PORTB &= ~(1 << PORTB4);
    }
    read = analogRead(A1);
    readInVolts = read*0.00488;
    temp = 99.987*readInVolts - 50.259;
    
    if(temp >= 35.0){
      Serial.print("Temperatura excedeu 35oC. \n");
      Serial.print("A Ttemperatura e de: ");
        Serial.print(temp);
        Serial.print("oC.");
        Serial.print("\n");
    }
    _delay_ms(50);
  }
  
}
