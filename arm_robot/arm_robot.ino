#include <VarSpeedServo.h>
#define pi 3.14159265359
int ccX; // variaveis para receber as coordenadas
int ccY;
int ccZ;
float servo1; // variaveis dos servos
float servo2;
float servo3;
float servo4;
float servo5;
int distAC; // variavel que recebe a distancia de abertura do braço
char leitura; // recebe os dados da porta serial
int teste;
int contador;
int memoria[10][5]; // vetor onde ficam salvo as posições dos servos
int numeroMemoria; // var indice para o vetor memoria
VarSpeedServo servo_base;//servo1
VarSpeedServo servo_ombro1;//servo2
VarSpeedServo servo_ombro2;//servo3
VarSpeedServo servo_cotovelo;//servo4
VarSpeedServo servo_punho;//servo5


void setup() {
  servo_base.attach(2 , 1 , 10);
  servo_ombro1.attach(3 , 1 , 10);
  servo_ombro2.attach(4 , 1 , 10);
  servo_cotovelo.attach(5 , 1 , 10);
  servo_punho.attach(6 , 1 , 10);
  Serial.begin(9600);
}

void loop() {

  delay(2000);
reset:
  while (Serial.available()) {
    leitura = Serial.read();// le o primeiro byte
    delay(10);
    switch (leitura) { // começa a comparar o primeiro byte para redirecionar a devida função
      case 'C' || 'c': // função executarCC;
        Serial.println("Voce selecionou a funcao de coordenadas");
        while (Serial.available()) {
          leitura = Serial.read();
          contador = 0;
          switch (leitura) { // começa a colher os parametros
            case 'X'||'x':  // verfica sintaxe
              Serial.println("Coordenada X");
              ccX = Serial.parseInt(); // le o parametro e redireciona pra devida variavel
              delay(10);
              Serial.println(ccX, DEC); // printa o parametro no monitor serial
              contador ++;
              if (contador > 2) {
                serialClean();
              }
              break;
            case 'Y': // o processo acima se repete pros proximos parametros
              Serial.println("Coordenada Y");
              ccY = Serial.parseInt();
              delay(10);
              Serial.println(ccY);
              contador ++;
              Serial.println(Serial.read());
              if (contador > 2) {
                serialClean();
              }
              break;
            case 'Z':
              Serial.println("Coordenada Z");
              ccZ = Serial.parseInt();
              delay(10);
              Serial.println(ccZ);
              contador ++;
              if (contador > 2 ) {
                serialClean();
              }
              break;
            case 10:
              break;
            default:
              Serial.println("Erro de sintaxe"); // caso o caractere digitado nao se enquadre no padrao estabelecido
              goto reset;
              break;
          }
        }// executa a função executarCC();
        Serial.println("movendo motores");
        executarCC(ccX, ccY, ccZ);

        break;
      case 'H':
        Serial.println("Voce selecionou a funcao home");
        HOME();
        serialClean();
        break;
      case 'M':
        while (Serial.available()) {
          leitura = Serial.read();
          delay(10);
          switch (leitura) {
            case 'E'||'e':
              numeroMemoria = Serial.parseInt();
              delay(10);
              Serial.print("Executando memoria ");
              Serial.print(numeroMemoria, DEC);
              executarMemoria(numeroMemoria);
              serialClean;
              break;
            case 'G':
              numeroMemoria = Serial.parseInt();
              delay(10);
              Serial.print("Gravando memoria ");
              Serial.println(numeroMemoria, DEC);
              gravarMemoria(numeroMemoria);
              serialClean();
            case 10:
            break;
            default:
              Serial.println("Erro de Sintaxe1");
              serialClean;
              break;
          }
        }
      case 10:
      break;
      default:
        Serial.println("Erro de Sintaxe2");
        serialClean();

    }

  }
}




void executarCC( int X, int Y, int Z) {
  HOME(); // Coloca os motores na posição inicial
  //Servo 1
  if ( X / Y > 0) {
    servo1 = 90 - (atan((X / Y))) * 180 / pi; // Rotaciona a base no sentido anti horario

  } else {
    servo1 = 90 + ((atan(X / Y * -1))) * 180 / pi; // Rotaciona a base no sentido horario
  }
  // Servo 2 e 3
  servo2 = (atan((Z / (sqrt(X * X + Y * Y))))) * 180 / pi; // define inclinação do braço
  servo3 = 180 - servo2;// Servo em sincronia com o servo 2
  // Servo 4
  distAC = sqrt(Z * Z + pow(sqrt(X * X + Y * Y) , 2)); // define a abertura do braço
  servo4 = ((acos((distAC * distAC - 13122) / -13122)) * 180 / pi) - 36; // angulo de abertura do braço para atingir a distancia acima ^

  // Servo 5
  Align(1);
  /* **********************************************
        EXECUTA O MOVIMENTO DOS SERVOS NA ORDEM:
           SERVO 1
           SERVO 4
           SERVO 5
           SERVO 2 E 3
     **********************************************
  */
}
void HOME () {
  servo_ombro1.slowmove(120 , 2);// ombro1 e ombro2 funcionam em sincronica, não por delay entre os dois
  servo_ombro2.slowmove(60 , 2);
  delay(100);
  servo_cotovelo.slowmove(0 , 2);
  delay(100);
  servo_base.slowmove(90 , 2);
  delay(100);
  servo_punho.slowmove(0 , 0);
  delay(250);

}

void Align (char pos) {}


void serialClean () {
  while (Serial.available()) {
    leitura = Serial.read(); // para limapr o buffer
  }

}
void executarMemoria(int indice) { // função que executa os movimentos guardados na memoria
  HOME();
  servo_base.slowmove(memoria[indice][0] , 2);
  delay(100);
  servo_cotovelo.slowmove(memoria[indice][3] , 2);
  delay(100);
  servo_ombro1.slowmove(memoria[indice][1] , 2);
  servo_ombro2.slowmove(memoria[indice][2] , 2);
  delay(100);
  servo_punho.slowmove(memoria[indice][4] , 2);
  delay(100);
}
void gravarMemoria(int indice2) { // função que grava a posição atual dos servos na memoria
  memoria[indice2][0] == servo1;
  memoria[indice2][1] == servo2;
  memoria[indice2][2] == servo3;
  memoria[indice2][3] == servo4;
  memoria[indice2][4] == servo5;
}

