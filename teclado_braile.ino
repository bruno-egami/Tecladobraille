#include <Keyboard.h>
#include <Mouse.h>

// Configuração dos delays (em milissegundos)
const int PRESS_DELAY = 50;    // Tempo que a tecla fica pressionada
const int RELEASE_DELAY = 200; // Tempo de espera após soltar a tecla

// Definição dos pinos de entrada para o teclado Braille
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

// Variável global para controle do modo numérico
bool modoNumerico = false;

void setup() {
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
  pinMode(pinSetaEsquerda, INPUT_PULLUP);
  pinMode(pinSetaDireita, INPUT_PULLUP);
  pinMode(pinSetaCima, INPUT_PULLUP);
  pinMode(pinSetaBaixo, INPUT_PULLUP);
  pinMode(pinCliqueMouse, INPUT_PULLUP);

  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  // Tratamento de teclas especiais
  if (digitalRead(pinEspaco) == LOW) {
    Keyboard.press(' ');
    delay(PRESS_DELAY);
    Keyboard.release(' ');
    delay(RELEASE_DELAY);
  }
  if (digitalRead(pinEnter) == LOW) {
    Keyboard.press(KEY_RETURN);
    delay(PRESS_DELAY);
    Keyboard.release(KEY_RETURN);
    delay(RELEASE_DELAY);
  }
  if (digitalRead(pinTab) == LOW) {
    Keyboard.press(KEY_TAB);
    delay(PRESS_DELAY);
    Keyboard.release(KEY_TAB);
    delay(RELEASE_DELAY);
  }
  if (digitalRead(pinBackspace) == LOW) {
    Keyboard.press(KEY_BACKSPACE);
    delay(PRESS_DELAY);
    Keyboard.release(KEY_BACKSPACE);
    delay(RELEASE_DELAY);
  }

  // Tratamento das teclas direcionais
  if (digitalRead(pinSetaEsquerda) == LOW) {
    Keyboard.press(KEY_LEFT_ARROW);
    delay(PRESS_DELAY);
    Keyboard.release(KEY_LEFT_ARROW);
    delay(RELEASE_DELAY);
  }
  if (digitalRead(pinSetaDireita) == LOW) {
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(PRESS_DELAY);
    Keyboard.release(KEY_RIGHT_ARROW);
    delay(RELEASE_DELAY);
  }
  if (digitalRead(pinSetaCima) == LOW) {
    Keyboard.press(KEY_UP_ARROW);
    delay(PRESS_DELAY);
    Keyboard.release(KEY_UP_ARROW);
    delay(RELEASE_DELAY);
  }
  if (digitalRead(pinSetaBaixo) == LOW) {
    Keyboard.press(KEY_DOWN_ARROW);
    delay(PRESS_DELAY);
    Keyboard.release(KEY_DOWN_ARROW);
    delay(RELEASE_DELAY);
  }
  if (digitalRead(pinCliqueMouse) == LOW) {
    Mouse.press(MOUSE_LEFT);
    delay(PRESS_DELAY);
    Mouse.release(MOUSE_LEFT);
    delay(RELEASE_DELAY);
  }

  // Armazena o estado dos pinos Braille
  int estadoPinos[] = {
    digitalRead(pinBraille1),
    digitalRead(pinBraille2),
    digitalRead(pinBraille3),
    digitalRead(pinBraille4),
    digitalRead(pinBraille5),
    digitalRead(pinBraille6)
  };

  // Verifica o sinal numérico
  if (estadoPinos[2] == LOW && estadoPinos[3] == LOW &&
      estadoPinos[4] == LOW && estadoPinos[5] == LOW &&
      estadoPinos[0] == HIGH && estadoPinos[1] == HIGH) {
    modoNumerico = true;
    delay(PRESS_DELAY);
    delay(RELEASE_DELAY);
    return;
  }

  // Mapeamento de números no modo numérico
  if (modoNumerico) {
    if (estadoPinos[0] == LOW && estadoPinos[1] == HIGH && estadoPinos[2] == HIGH) {
      Keyboard.press('1');
    } else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW) {
      Keyboard.press('2');
    } else if (estadoPinos[0] == LOW && estadoPinos[3] == LOW) {
      Keyboard.press('3');
    } else if (estadoPinos[0] == LOW && estadoPinos[3] == LOW && estadoPinos[4] == LOW) {
      Keyboard.press('4');
    } else if (estadoPinos[0] == LOW && estadoPinos[4] == LOW) {
      Keyboard.press('5');
    } else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW && estadoPinos[3] == LOW) {
      Keyboard.press('6');
    } else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW && estadoPinos[3] == LOW && estadoPinos[4] == LOW) {
      Keyboard.press('7');
    } else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW && estadoPinos[4] == LOW) {
      Keyboard.press('8');
    } else if (estadoPinos[1] == LOW && estadoPinos[3] == LOW) {
      Keyboard.press('9');
    } else if (estadoPinos[1] == LOW && estadoPinos[3] == LOW && estadoPinos[4] == LOW) {
      Keyboard.press('0');
    }
    delay(PRESS_DELAY);
    Keyboard.releaseAll();
    delay(RELEASE_DELAY);
    modoNumerico = false;
    return;
  }

  // Mapeamento de letras do alfabeto Braille (A-Z)

  if (estadoPinos[0] == LOW && estadoPinos[1] == HIGH) {
    Keyboard.press('a');
  } else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW) {
    Keyboard.press('b');
  } else if (estadoPinos[0] == LOW && estadoPinos[2] == LOW) {
    Keyboard.press('c');
  } else if (estadoPinos[0] == LOW && estadoPinos[2] == LOW && estadoPinos[3] == LOW) {
    Keyboard.press('d');
  } else if (estadoPinos[0] == LOW && estadoPinos[3] == LOW) {
    Keyboard.press('e');
  } else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW && estadoPinos[2] == LOW) {
    Keyboard.press('f');
  } else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW && estadoPinos[2] == LOW && estadoPinos[3] == LOW) {
    Keyboard.press('g');
  } else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW && estadoPinos[3] == LOW) {
    Keyboard.press('h');
  } else if (estadoPinos[1] == LOW && estadoPinos[2] == LOW) {
    Keyboard.press('i');
  } else if (estadoPinos[1] == LOW && estadoPinos[2] == LOW && estadoPinos[3] == LOW) {
    Keyboard.press('j');
  } else if (estadoPinos[0] == LOW && estadoPinos[4] == LOW) {
    Keyboard.press('k');
  } else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW && estadoPinos[4] == LOW) {
    Keyboard.press('l');
  } else if (estadoPinos[0] == LOW && estadoPinos[2] == LOW && estadoPinos[4] == LOW) {
    Keyboard.press('m');
  } else if (estadoPinos[0] == LOW && estadoPinos[2] == LOW && estadoPinos[3] == LOW && estadoPinos[4] == LOW) {
    Keyboard.press('n');
  } else if (estadoPinos[0] == LOW && estadoPinos[3] == LOW && estadoPinos[4] == LOW) {
    Keyboard.press('o');
  } else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW && estadoPinos[2] == LOW && estadoPinos[4] == LOW) {
    Keyboard.press('p');
  } else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW && estadoPinos[2] == LOW && estadoPinos[3] == LOW && estadoPinos[4] == LOW) {
    Keyboard.press('q');
  } else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW && estadoPinos[3] == LOW && estadoPinos[4] == LOW) {
    Keyboard.press('r');
  } else if (estadoPinos[1] == LOW && estadoPinos[2] == LOW && estadoPinos[4] == LOW) {
    Keyboard.press('s');
  } else if (estadoPinos[1] == LOW && estadoPinos[2] == LOW && estadoPinos[3] == LOW && estadoPinos[4] == LOW) {
    Keyboard.press('t');
  } else if (estadoPinos[0] == LOW && estadoPinos[4] == LOW && estadoPinos[5] == LOW) {
    Keyboard.press('u');
  } else if (estadoPinos[0] == LOW && estadoPinos[1] == LOW && estadoPinos[4] == LOW && estadoPinos[5] == LOW) {
    Keyboard.press('v');
  } else if (estadoPinos[1] == LOW && estadoPinos[2] == LOW && estadoPinos[3] == LOW && estadoPinos[5] == LOW) {
    Keyboard.press('w');
  } else if (estadoPinos[0] == LOW && estadoPinos[2] == LOW && estadoPinos[4] == LOW && estadoPinos[5] == LOW) {
    Keyboard.press('x');
  } else if (estadoPinos[0] == LOW && estadoPinos[2] == LOW && estadoPinos[3] == LOW && estadoPinos[4] == LOW && estadoPinos[5] == LOW) {
    Keyboard.press('y');
  } else if (estadoPinos[0] == LOW && estadoPinos[3] == LOW && estadoPinos[4] == LOW && estadoPinos[5] == LOW) {
    Keyboard.press('z');
  }

  delay(PRESS_DELAY);
  Keyboard.releaseAll();
  delay(RELEASE_DELAY);
}

