int pinLed[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
unsigned int ledAtual, maxLeds = 8, minLeds = 0;
int chave = 10;
bool chave_on;

void setup() {
  for (int i = 0; i <= maxLeds; i++)
  {
    pinMode(pinLed[i], OUTPUT);
  }
  pinMode(chave, INPUT); 

   Serial.begin(9600);
   ledAtual = digitalRead(chave) ? 0 : 8;

}

void loop() {   

  chave_on = digitalRead(chave);
    
  Serial.println(ledAtual);

  if (chave_on)
  {
    for ( int i = ledAtual; i < maxLeds; i++)
    {
      digitalWrite(pinLed[ledAtual], HIGH);
      delay(300);
      digitalWrite(pinLed[ledAtual], LOW);      
      if (digitalRead(chave) != chave_on)
        return;
    }
  } else {
    for ( ledAtual = ledAtual; ledAtual > minLeds; ledAtual--)
    {
      digitalWrite(pinLed[ledAtual-1], HIGH);
      delay(300);
      digitalWrite(pinLed[ledAtual-1], LOW);
      if (digitalRead(chave) != chave_on)
        return;
    }
  }

}
