int eixoX[] = {1, 2, 3, 4, 5}; // array coordenadas do pinos arduino
int eixoY[] = {6, 7, 8, 9, 10}; // array coordenas pinos arduino
int indiceX = 0;
int indiceY = 0;

void setup() {
  pinMode(1 , OUTPUT);
  pinMode(2 , OUTPUT);
  pinMode(3 , OUTPUT);
  pinMode(4 , OUTPUT);
  pinMode(5 , OUTPUT);
  pinMode(6 , OUTPUT);
  pinMode(7 , OUTPUT);
  pinMode(8 , OUTPUT);
  pinMode(9 , OUTPUT);
  pinMode(10 , OUTPUT);

}

void loop() {
  printM (eixoX[0] , eixoY[0]);
  indiceX++;
  indiceY++;
  if ( indiceX > 4) {
    indiceX = 0;
  }
  if ( indiceY > 4) {
    indiceY = 0;
  }
}

void printM (int veixoX, int veixoY) {
  digitalWrite(veixoX ,LOW);
  digitalWrite(veixoY , HIGH);
  delay(1000);
  digitalWrite(veixoX , HIGH);
  digitalWrite(veixoY , LOW);
  delay(1000);

}


