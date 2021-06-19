#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // Saída (Atuador):
  DDRB |= (1 << DDB3); // Pino 11 (PB3) -> Buzzer
  DDRB |= (1 << DDB4); // Pino 12 (PB4) -> LED A
  DDRB |= (1 << DDB5); // Pino 13 (PB5) -> LED B 
  // Entrada (Sensor):
  DDRD &= ~(1 << DDD2); // Pino 2 (PD2) -> Chave1
  DDRD &= ~(1 << DDD3); // Pino 3 (PD3) -> Chave2
  DDRD &= ~(1 << DDD4); // Pino 4 (PD4) -> Chave3
  DDRD &= ~(1 << DDD5); // Pino 5 (PD5) -> Chave4

  char estadoPortaSala, estadoJanelaSala, estadoJanelaQuarto1, 
    estadoJanelaQuarto2;

  while (1) {
    estadoPortaSala = (PIND & (1 << PIND2)) == (1 << PIND2);
    estadoJanelaSala = (PIND & (1 << PIND3)) == (1 << PIND3);
    estadoJanelaQuarto1 = (PIND & (1 << PIND5)) == (1 << PIND5);
    estadoJanelaQuarto2 = (PIND & (1 << PIND4)) == (1 << PIND4);

    // Porta/Janela Fechada = 0 ou Aberta = 1
    if (estadoPortaSala == 1 || estadoJanelaSala == 1 || 
      estadoJanelaQuarto1 == 1 ||estadoJanelaQuarto2 == 1) {
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
    _delay_ms(50);
  }
}
