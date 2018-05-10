int divisor;
int x;
  

char Str1[] = ",";


void setup() {
  Serial.begin(9600);
}

void loop() {
  x = 123,456;
  char Str[]= String.valueOf(x);

  Str = x;
  divisor = 0;
  while ( divisor != 9 ) {
    int indice = 0;
    Serial.println(Str[divisor]);
    divisor ++;
    delay(500);
  }
  divisor = 0;

}
