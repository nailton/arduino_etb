#define D1 2
#define D2 3
#define CHAVE 4
#define PWM 5
const int LED[8] = { 6, 7, 8, 9, 10, 11, 12, 13 };
int ledAtual = 0;

int tempoEmHigh = 500;
int tempoEmLow = 500;

void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(CHAVE, INPUT);
  pinMode(PWM, OUTPUT);

  for(int i = 0; i < 8; i++)
  {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], HIGH);
  }
  
  Serial.begin(9600);
}

void loop() {
  if (ledAtual == 8) {
    ledAtual = 0;
  } else if (ledAtual == -1) {
    ledAtual = 7;
  }
  
  
  if (digitalRead(CHAVE) == HIGH)
  {
    sentidoHorario();
    while(digitalRead(CHAVE) == HIGH && ledAtual < 8)
    {
      digitalWrite(PWM, LOW);
      digitalWrite(LED[ledAtual], LOW);
      delay(tempoEmLow);
      digitalWrite(PWM, HIGH);
      digitalWrite(LED[ledAtual], HIGH);
      delay(tempoEmHigh);

      ledAtual++;
      if (digitalRead(CHAVE) != HIGH)
         break;
    }
  }
  else
  {
    sentidoAntiHorario();
    while(digitalRead(CHAVE) == LOW && ledAtual > -1)
    {
      digitalWrite(PWM, LOW);
      digitalWrite(LED[ledAtual], LOW);
      delay(tempoEmLow);
      digitalWrite(PWM, HIGH);
      digitalWrite(LED[ledAtual], HIGH);
      delay(tempoEmHigh);

      ledAtual--;
      if (digitalRead(CHAVE) != LOW)
         break;
    }
  }
}

void sentidoHorario()
{
  Serial.println("Motor está ligado");
  Serial.println("Girando no sentido Horário");
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  delay(2);
}
void sentidoAntiHorario()
{
  Serial.println("Motor está ligado");
  Serial.println("Girando no sentido Anti-Horário");
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  delay(2);
}
