#define D1 2
#define D2 3
#define CHAVE 4

bool estadoDaChave;

void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(CHAVE, INPUT);
  
  Serial.begin(9600);
}

void loop() {

  estadoDaChave = digitalRead(CHAVE);
  if (estadoDaChave)
  {
    freio(); // Freia o motor
    sentidoHorario();
    while(true)
    {
      if (estadoDaChave != digitalRead(CHAVE))
        break;
    }
  }
  else
  {
    freio(); // Freia o motor
    sentidoAntiHorario();
    while(true)
    {
      if (estadoDaChave != digitalRead(CHAVE))
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

void freio()
{
  Serial.println("Motor está freiado");
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  delay(200);
}
