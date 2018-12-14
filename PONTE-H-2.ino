//Declaração de Bibliotecas

//Declaração de Variáveis
#define D1 12 //Define porta para transistores
#define D2 11 //Define porta para transistores
#define CHAVE 13 //Porta Chave
#define PWM 10 //Porta PWM
const int LED[8] = { 2, 4, 6, 8, 9, 7, 5, 3 }; //Array de leds
#define POT A0 //Define porta Potenciômetro

int ledAtual = 0; //Variável do led atual

int tempoTotal = 500; //Define tempo inicial para dutyCycle
int tempoEmHigh, tempoEmLow; //Define tipo das variáveis

// Inicialização das variáveis
void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(CHAVE, INPUT);
  pinMode(PWM, OUTPUT);

  for(int i = 0; i < 8; i++)
  {
    pinMode(LED[i], OUTPUT);
  }
}

//Programa propriamente dito
void loop() {
  //Define onde iniciar a contagem dos leds
  if (ledAtual == 8) {
    ledAtual = 0;
  } else if (ledAtual == -1) {
    ledAtual = 7;
  }

  //Leitura da chave para define as configurações necessárias
  if (digitalRead(CHAVE) == HIGH)
  {
    sentidoHorario(); //Aplicar a tensão adequada para rotação do motor
    while(digitalRead(CHAVE) == HIGH && ledAtual < 8)
    {
      configurarDutyCycle(); //Definir duty cycle

      digitalWrite(PWM, HIGH);
      digitalWrite(LED[ledAtual], HIGH);
      delay(tempoEmHigh);
      digitalWrite(PWM, LOW);
      digitalWrite(LED[ledAtual], LOW);
      delay(tempoEmLow);

      ledAtual++;
      //Encerra o processo, caso o status da chave altere
      if (digitalRead(CHAVE) != HIGH)
         break;
    }
  }
  else
  {
    sentidoAntiHorario(); //Aplicar a tensão adequada para rotação do motor
    while(digitalRead(CHAVE) == LOW && ledAtual > -1)
    {
      configurarDutyCycle(); //Definir duty cycle

      digitalWrite(PWM, HIGH);
      digitalWrite(LED[ledAtual], HIGH);
      delay(tempoEmHigh);
      digitalWrite(PWM, LOW);
      digitalWrite(LED[ledAtual], LOW);
      delay(tempoEmLow);

      ledAtual--;
      //Encerra o processo, caso o status da chave altere
      if (digitalRead(CHAVE) != LOW)
         break;
    }
  }
}

void sentidoHorario() //Função para rotação horário
{
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
}
void sentidoAntiHorario() //Função para rotação anti-horário
{
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
}

void configurarDutyCycle() //Função ler o potenciômetro
{
  int valorPot = analogRead(POT);
  tempoEmLow = map(valorPot, 0, 1023, 0, 500);
  tempoEmHigh = tempoTotal - tempoEmLow;
}

