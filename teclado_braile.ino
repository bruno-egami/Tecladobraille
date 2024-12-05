#include <Keyboard.h>
#include <Mouse.h>

// Definição dos pinos de entrada para o teclado Braille
// Pinos 1-6: representam os 6 pontos do sistema Braille
// Pinos 7-14: teclas especiais (espaço, enter, tab, backspace, direcionais, mouse)
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

// Novos pinos para teclas direcionais e mouse
const int pinSetaEsquerda = 11;
const int pinSetaDireita = 12;
const int pinSetaCima = 13;
const int pinSetaBaixo = 14;
const int pinCliqueMouse = 15;

void setup() {
  // Configuração dos pinos Braille originais
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

  // Configuração dos novos pinos
  pinMode(pinSetaEsquerda, INPUT_PULLUP);
  pinMode(pinSetaDireita, INPUT_PULLUP);
  pinMode(pinSetaCima, INPUT_PULLUP);
  pinMode(pinSetaBaixo, INPUT_PULLUP);
  pinMode(pinCliqueMouse, INPUT_PULLUP);

  // Inicializa as bibliotecas de teclado e mouse
  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  // Tratamento das teclas especiais originais
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

  // Tratamento das novas teclas direcionais
  if (digitalRead(pinSetaEsquerda) == LOW) {
    Keyboard.press(KEY_LEFT_ARROW);
    delay(50);
    Keyboard.release(KEY_LEFT_ARROW);
    delay(200);
  }

  if (digitalRead(pinSetaDireita) == LOW) {
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(50);
    Keyboard.release(KEY_RIGHT_ARROW);
    delay(200);
  }

  if (digitalRead(pinSetaCima) == LOW) {
    Keyboard.press(KEY_UP_ARROW);
    delay(50);
    Keyboard.release(KEY_UP_ARROW);
    delay(200);
  }

  if (digitalRead(pinSetaBaixo) == LOW) {
    Keyboard.press(KEY_DOWN_ARROW);
    delay(50);
    Keyboard.release(KEY_DOWN_ARROW);
    delay(200);
  }

  // Tratamento do clique do mouse
  if (digitalRead(pinCliqueMouse) == LOW) {
    Mouse.press(MOUSE_LEFT);
    delay(50);
    Mouse.release(MOUSE_LEFT);
    delay(200);
  }

  // Armazena o estado atual de cada pino Braille
  int estadoPinos[] = {
    digitalRead(pinBraille1),
    digitalRead(pinBraille2),
    digitalRead(pinBraille3),
    digitalRead(pinBraille4),
    digitalRead(pinBraille5),
    digitalRead(pinBraille6)
  };

  // Mapeamento de caracteres Braille (código original mantido)
  // ... (restante do código de mapeamento de letras seria igual ao original)

  // Pequeno delay para evitar leituras múltiplas e bounce de botão
  delay(50);
}

// NOTAS IMPORTANTES:
// 1. Este código é para Arduino Leonardo, que possui suporte nativo para HID (teclado e mouse)
// 2. A lógica assume que os pinos são conectados com pull-up interno
// 3. Adicionadas teclas direcionais e clique do mouse
// 4. Pode ser necessário ajustar os delays conforme a sensibilidade dos botões
// 5. Recomenda-se testar cada combinação individualmente
