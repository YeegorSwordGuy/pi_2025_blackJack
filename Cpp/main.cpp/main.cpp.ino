// LiquidCrystal(RS, E, D4, D5, D6, D7)

#include <LiquidCrystal.h>


#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define E 8
#define RS 9

#define BtCompra 13
#define BtPassa 12


LiquidCrystal LCD(RS, E, D4, D5, D6, D7);  

unsigned long ultimaLeitura = 0;
const int atrasoDebounce = 200;

void setup() { 
	LCD.begin(16,2); 
  
   	pinMode(BtCompra, INPUT_PULLUP);
   	pinMode(BtPassa, INPUT_PULLUP);
}
 
void loop() {
  
  	LCD.clear();
  	debugBotao();
}


void debugBotao() {
  if (digitalRead(BtCompra) == LOW) {
    if (millis() - ultimaLeitura > atrasoDebounce) {
      ultimaLeitura = millis();
      LCD.print("Compra");
    }
  }
  if (digitalRead(BtPassa) == LOW) {
    if (millis() - ultimaLeitura > atrasoDebounce) {
      ultimaLeitura = millis();
      LCD.print("Passa");
    }
  }
}

// AI dealer

// lógica de pontuação
// -- armazenar as cartas 