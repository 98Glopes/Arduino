//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn
 pin 11 is connected to the CLK
 pin 10 is connected to LOAD
 We have only a single MAX72XX.
 */
LedControl lc = LedControl(12, 11, 10, 1);
int x = 0;
int y = 0;
char snakeSize = 3;


unsigned long delaytime = 500;
int snake[4][2] = {{3, 1}, {2, 1}, {1, 1}, {0, 1}};
int snakeAux[4][2] = {{3, 1}, {2, 1}, {1, 1}, { 0, -1}};

void setup() {
  Serial.begin(9600);
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  /* and clear the display */
  lc.clearDisplay(0);
  randomSeed(analogRead(0));
}
void loop() {

  printSnake();
  down();
  delay(300);

}
  void printSnake() {
    lc.clearDisplay(0);
    int indice = 0;
    while (indice <= snakeSize) {
      lc.setLed(0 , snake[indice][0] , snake[indice][1], 1);
      indice++;

    } delay(1);
  }
  void right() { // move snake pra direita
    int indice = 0;
    snake[indice][0]++;
    if (snake[0][0] > 7) {
      snake[0][0] = 0;
    }
    indice++;
    while (indice <= snakeSize) {
      snake[indice][0] = snakeAux[indice - 1][0];
      snake[indice][1] = snakeAux[indice - 1][1];
      indice++;

    } delay(1);
    indice = 0;
    while (indice <= snakeSize) {
      snakeAux[indice][0] = snake[indice][0];  snakeAux[indice][1] = snake[indice][1];
      indice++;
    }
}

    void left() { // move snake pra esquerda
    int indice = 0;
    snake[indice][0]--;
    if(snake[0][0] < 0){
      snake[0][0] = 7;
    }

    indice++;
    while (indice <= snakeSize) {
      snake[indice][0] = snakeAux[indice - 1][0];
      snake[indice][1] = snakeAux[indice - 1][1];
      indice++;

    } delay(1);
    indice = 0;
    while (indice <= snakeSize) {
      snakeAux[indice][0] = snake[indice][0];  snakeAux[indice][1] = snake[indice][1];
      indice++;
    }
}
  void down() { // move snake pra baixo
    int indice = 0;
    snake[indice][1]--;
    if (snake[0][1] < 0) {
      snake[0][1] = 7;
    }
    indice++;
    while (indice <= snakeSize) {
      snake[indice][0] = snakeAux[indice - 1][0];
      snake[indice][1] = snakeAux[indice - 1][1];
      indice++;

    } delay(1);
    indice = 0;
    while (indice <= snakeSize) {
      snakeAux[indice][0] = snake[indice][0];  snakeAux[indice][1] = snake[indice][1];
      indice++;
    }
}
  void up() { // move snake pra cima
    int indice = 0;
    snake[indice][1]++;
    if (snake[0][1] > 7) {
      snake[0][1] = 0;
    }
    indice++;
    while (indice <= snakeSize) {
      snake[indice][0] = snakeAux[indice - 1][0];
      snake[indice][1] = snakeAux[indice - 1][1];
      indice++;

    } delay(1);
    indice = 0;
    while (indice <= snakeSize) {
      snakeAux[indice][0] = snake[indice][0];  snakeAux[indice][1] = snake[indice][1];
      indice++;
    }
}
