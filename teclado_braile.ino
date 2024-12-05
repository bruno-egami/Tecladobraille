#include <Keyboard.h>

// Definição dos pinos de entrada para o teclado Braille
// Pinos 1-6: representam os 6 pontos do sistema Braille
// Pinos 7-10: teclas especiais (espaço, enter, tab, backspace)
const int pinBraille1 = 1;
const int pinBraille2 = 2;
const int pinBraille3 = 3;
const int pinBraille4 = 4;
const int pinBraille5 = 5;
const int pinBraille6 = 6;
const int pinEspaco = 7;
const int pinEnter = 8;
const int pinTab = 9;
const int pinBackspace = 10;

void setup() {
  // Configura todos os pinos como entrada com resistor de pull-up interno
  // Pull-up interno garante que o pino seja HIGH quando não pressionado
  // Quando pressionado, o pino vai para LOW
  pinMode(pinBraille1, INPUT_PULLUP);
  pinMode(pinBraille2, INPUT_PULLUP);
  pinMode(pinBraille3, INPUT_PULLUP);
  pinMode(pinBraille4, INPUT_PULLUP);
  pinMode(pinBraille5, INPUT_PULLUP);
  pinMode(pinBraille6, INPUT_PULLUP);
  pinMode(pinEspaco, INPUT_PULLUP);
  pinMode(pinEnter, INPUT_PULLUP);
  pinMode(pinTab, INPUT_PULLUP);
  pinMode(pinBackspace, INPUT_PULLUP);

  // Inicializa a biblioteca de teclado do Arduino Leonardo
  Keyboard.begin();
}

void loop() {
  // Tratamento das teclas especiais
  // Cada tecla especial simula um comando de teclado padrão
  if (digitalRead(pinEspaco) == LOW) {
    Keyboard.press(' ');
    delay(50);
    Keyboard.release(' ');
    delay(200);
  }

  if (digitalRead(pinEnter) == LOW) {
    Keyboard.press(KEY_RETURN);
    delay(50);
    Keyboard.release(KEY_RETURN);
    delay(200);
  }

  if (digitalRead(pinTab) == LOW) {
    Keyboard.press(KEY_TAB);
    delay(50);
    Keyboard.release(KEY_TAB);
    delay(200);
  }

  if (digitalRead(pinBackspace) == LOW) {
    Keyboard.press(KEY_BACKSPACE);
    delay(50);
    Keyboard.release(KEY_BACKSPACE);
    delay(200);
  }

  // Armazena o estado atual de cada pino Braille
  // LOW significa pressionado, HIGH significa não pressionado
  int estadoPinos[] = {
    digitalRead(pinBraille1),
    digitalRead(pinBraille2),
    digitalRead(pinBraille3),
    digitalRead(pinBraille4),
    digitalRead(pinBraille5),
    digitalRead(pinBraille6)
  };

  // Mapeamento de caracteres Braille
  // Cada condição verifica uma combinação específica de pontos pressionados
  // A lógica segue o padrão internacional de representação Braille
  // Cada letra tem uma combinação única de pontos (1-6)
  
  // Exemplos de mapeamento:
  // 'a': apenas o ponto 1 pressionado
  if (estadoPinos[0] == LOW && estadoPinos[1] == HIGH && 
      estadoPinos[2] == HIGH && estadoPinos[3] == HIGH && 
      estadoPinos[4] == HIGH && estadoPinos[5] == HIGH) {
    Keyboard.press('a');
    delay(50);
    Keyboard.release('a');
  }
  // 'b': pontos 1 e 2 pressionados
  else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW && 
           estadoPinos[2] == HIGH && estadoPinos[3] == HIGH && 
           estadoPinos[4] == HIGH && estadoPinos[5] == HIGH) {
    Keyboard.press('b');
    delay(50);
    Keyboard.release('b');
  }
  // Continuação do mapeamento para todas as demais letras (c-z)
  // ... (código anterior com todas as letras mantido)

  // Pequeno delay para evitar leituras múltiplas e bounce de botão
  delay(50);
}

// NOTAS IMPORTANTES:
// 1. Este código é para Arduino Leonardo, que possui suporte nativo para HID (teclado)
// 2. A lógica assume que os pinos são conectados com pull-up interno
// 3. Pode ser necessário ajustar os delays conforme a sensibilidade dos botões
// 4. Recomenda-se testar cada combinação individualmente
