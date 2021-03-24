// Electronica Digital 2 - seccion 30
// Laboratorio 4
// Mario Estrada - 18123
 
const byte W1= 39;
const byte W2= 40;
const byte SW1 = 31;
const byte SW2 = 17;
volatile byte state = LOW;
int cont1 = 0;
int cont2 = 0;
int leds1[] = {2,3,4,5,6,7,8,9,39};
int leds2[] = {38,37,36,35,34,33,32,11,40};

void setup() {
  //Semaforo
  pinMode(30, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  digitalWrite(30, LOW);
  digitalWrite(39, LOW);
  digitalWrite(40, LOW);

  //Jugador 1
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  //Jugador 2
  pinMode(38, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(38, LOW);
  digitalWrite(37, LOW);
  digitalWrite(36, LOW);
  digitalWrite(35, LOW);
  digitalWrite(34, LOW);
  digitalWrite(33, LOW);
  digitalWrite(32, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

  //Push Buttons 
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SW1), blink, RISING);
  attachInterrupt(digitalPinToInterrupt(SW2), blink, RISING);
}

void loop(){
  if (digitalRead(SW1) == HIGH || digitalRead(SW2) == HIGH){
  semaforo ();
  while(digitalRead(W1) == LOW || digitalRead(W2) == LOW){
    if(digitalRead(SW1) == HIGH){
      digitalWrite(leds1[cont1], LOW);
      cont1++;
      digitalWrite(leds1[cont1], HIGH);
    }
    if(digitalRead(SW2) == HIGH){
      digitalWrite(leds2[cont2], LOW);
      cont2++;
      digitalWrite(leds2[cont2], HIGH);
    }
  }
}
}
void semaforo(){
  digitalWrite(30, HIGH);
  delay(3000);
  digitalWrite(30, LOW);
  digitalWrite(40, HIGH);
  delay(3000);
  digitalWrite(40, LOW);
  digitalWrite(39, HIGH);
  delay(1000);
  digitalWrite(39, LOW);
}

void blink() {
  state = !state;
}
