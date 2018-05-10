	

 //Programa : Teste modulo Joystick  
 //Autor : Arduino e Cia  
   
 int valorx = 0; //Armazena o valor lido do potenciometro - Eixo X  
 int valory = 0; //Armazena o valor lido do potenciometro - Eixo Y  
 int valorz = 0; //Armazena o valor lido do botão - Eixo Z  
 int pinoledesquerda = 2; //Pino Led Esquerdo  
 int pinoledsuperior = 3; //Pino Led Superior  
 int pinoleddireita = 4;  //Pino Led Direito  
 int pinoledinferior = 5; //Pino Led Inferior  
 int pinoledz = 10;    //Pino Led Eixo Z  
   
 void setup() 
 {  
 pinMode(7, INPUT);  //Pino Eixo Z  
 Serial.begin(9600);  
 pinMode(pinoledesquerda, OUTPUT);  
 pinMode(pinoledsuperior, OUTPUT);  
 pinMode(pinoleddireita, OUTPUT);  
 pinMode(pinoledinferior, OUTPUT);  
 pinMode(pinoledz, OUTPUT);  
 }  
   
 void loop() 
 {  
 //As linhas abaixo apagam todos os leds  
 digitalWrite(pinoledesquerda, LOW);  
 digitalWrite(pinoledsuperior, LOW);  
 digitalWrite(pinoleddireita, LOW);  
 digitalWrite(pinoledinferior, LOW);  
 digitalWrite(pinoledz, LOW);  
   
 //Le o valor do potenciometro ligado à porta analogica A0 - Eixo X  
 valorx = analogRead(0);   
   
 //Mostra o valor do eixo X no serial monitor  
 Serial.print("X:");  
 Serial.print(valorx, DEC);  
 delay(1000);
   
 //Testa o valor do Eixo X e aciona o led correspondente  
 if (valorx > -1 & valorx <200)  
 {  
  digitalWrite(pinoledinferior, HIGH); //Acende o led inferior  
 }  
 if (valorx > 700 & valorx <1025)  
 {  
  digitalWrite(pinoledsuperior, HIGH); //Acende o led superior  
 }  
   
 //Le o valor do potenciometro ligado à porta analogica A1 - Eixo Y  
 valory= analogRead(1);  
   
 //Mostra o valor do eixo Y no serial monitor  
 Serial.print(" | Y:");  
 Serial.print(valory, DEC);  
   
 //Testa o valor do Eixo Y e aciona o led correspondente  
 if (valory > -1 & valory <200)  
 {  
  digitalWrite(pinoleddireita, HIGH); //Acende o led da direita  
 }  
 if (valory > 700 & valory <1025)  
 {  
  digitalWrite(pinoledesquerda, HIGH); //Acende o led da equerda  
 }  
   
 //Lê o valor da porta Digital 7 - Eixo Z  
 valorz = digitalRead(7);  
   
 //Mostra o valor do Eixo Z no serial monitor  
 Serial.print(" | Z: ");  
 Serial.println(valorz, DEC);  
 delay(1000);
   
 //Caso o botão do Eixo Z seja pressionado, acende o led verde  
 if (valorz != 1 )  
 {  
  digitalWrite(pinoledz, HIGH);  
 }  
}  

