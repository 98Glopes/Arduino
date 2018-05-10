#include <TimerOne.h>

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
int x = 3;
int y = 5;
int z;
int snakeSize = 0;
int dir = 50;
boolean grow = false;




unsigned long delaytime = 500;
int snake[64][2];
int snakeAux[64][2];


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
  Timer1.initialize(500000 * 2);
  Timer1.attachInterrupt(moveSnake);
  int indice = 0;
  while (indice <= 63) {
    snake[indice][0] = indice * -1;
    snake[indice][1] = 0;
    snakeAux[indice][0] = indice * -1;
    snakeAux[indice][1] = 0;
    indice++;
  }

  }
  void loop() {



    lc.setLed(0 , x, y , 1);
    if (Serial.available()) {
      dir = Serial.read();
      delay(10);
      while (Serial.available()) {
        z = Serial.read();
      }
    }


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
  
    if (x == snake[snakeSize][0] && y == snake[snakeSize][1]) {
      snakeSize++;
      x = random(7);
      y = random(7);
    }
    int indice = 0;
    snake[indice][0]++;
    if (snake[0][0] > 7) {
      snake[0][0] = 0;
    }
    indice++;
    while (indice <= 63) {
      snake[indice][0] = snakeAux[indice - 1][0];
      snake[indice][1] = snakeAux[indice - 1][1];
      indice++;

    } delay(1);
    indice = 0;
    while (indice <= 63) {
      snakeAux[indice][0] = snake[indice][0];  snakeAux[indice][1] = snake[indice][1];
      indice++;
    }
  }

  void left() { // move snake pra esquerda
    if (x == snake[snakeSize][0] && y == snake[snakeSize][1]) {
      snakeSize++;
      x = random(7);
      y = random(7);
    }
    int indice = 0;
    snake[indice][0]--;
    if (snake[0][0] < 0) {
      snake[0][0] = 7;
    }

    indice++;
    while (indice <= 63) {
      snake[indice][0] = snakeAux[indice - 1][0];
      snake[indice][1] = snakeAux[indice - 1][1];
      indice++;

    } delay(1);
    indice = 0;
    while (indice <= 63) {
      snakeAux[indice][0] = snake[indice][0];  snakeAux[indice][1] = snake[indice][1];
      indice++;
    }
  }
  void down() { // move snake pra baixo
    if (x == snake[snakeSize][0] && y == snake[snakeSize][1]) {
      snakeSize = snakeSize + 1;
      x = random(7);
      y = random(7);
    }
    int indice = 0;
    snake[indice][1]--;
    if (snake[0][1] < 0) {
      snake[0][1] = 7;
    }
    indice++;
    while (indice <= 63) {
      snake[indice][0] = snakeAux[indice - 1][0];
      snake[indice][1] = snakeAux[indice - 1][1];
      indice++;

    } delay(1);
    indice = 0;
    while (indice <= 63) {
      snakeAux[indice][0] = snake[indice][0];  snakeAux[indice][1] = snake[indice][1];
      indice++;
    }
  }
  void up() { // move snake pra cima
    if (x == snake[snakeSize][0] && y == snake[snakeSize][1]) {
      snakeSize++;
      x = random(7);
      y = random(7);
    }
    int indice = 0;
    snake[indice][1]++;
    if (snake[0][1] > 7) {
      snake[0][1] = 0;
    }
    indice++;
    while (indice <= 63) {
      snake[indice][0] = snakeAux[indice - 1][0];
      snake[indice][1] = snakeAux[indice - 1][1];
      indice++;

    } delay(1);
    indice = 0;
    while (indice <= 63) {
      snakeAux[indice][0] = snake[indice][0];  snakeAux[indice][1] = snake[indice][1];
      indice++;
    }
  }
  void moveSnake() {
    if (dir == 50) {
      printSnake();


      down();
    } else if (dir == 52) {
      printSnake();
      left();
    } else if (dir == 54) {
      printSnake();
      right();
    } else if (dir == 56) {
      printSnake();
      up();
    }


  }

