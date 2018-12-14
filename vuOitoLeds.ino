/***************************************************************************
****************************************************************************
** CENTRO DE ENSINO PROFISSIONALIZANTE - CEP                              **
** ESCOLA TÉCNICA DE BRASÍLIA - ETB                                       **
** PROFESSOR: SANDOVAL                                                    **
**                                                                        **
** PROJETO: ROTINA CONTROLE OITO LEDS SIMULANDO VU ELETRÔNICO             **
** ALUNOS:  FRANCISCO DE ASSIS DA ROCHA CAMPOS - 17177-8                  **
**          MARIA JUCICLÉIA DA SILVA 14904-7                              **
**          NAILTON SOUSA DE OLIVEIRA - 17286-3                           **
** TURMA: 2ºP Noturno Data inicial: 19/09/2017 Data final: 24/09/2017     **
****************************************************************************
***************************************************************************/

// Declaração dos oito LEDs em um array inteiro
int led[8] = {0, 1, 2, 3, 4, 5, 6, 7};

// Variável de entrada analógica do áudio e indíce for
int input, i;

void setup()
{

// Seta os leds como saída e estado desligado
for(int i=0; i<=8; i++){

  pinMode(led[i], OUTPUT);
  digitalWrite(led[i], LOW);

}

}

void loop()
{
// Leitura(audio) no pino analógico 5
input = analogRead(5);

// Dividir a entrada pelo nº de LEDs
input = input / 9;

if (input < 9)
{
  // Seta os LEDs como desligado. Estado inicial ou sem leitura.
  if (input == 0)
  {
    for (i = 0; i < 9; i++)
    {
      digitalWrite(led[i], LOW);
    }
  }
  else
  {
    // Seta os LEDs como ligado
    for (i = 0; i < input; i++)
    {
      digitalWrite(led[i], HIGH);
      delay(4);
    }
    for (i = i; i < 9; i++)
    {
      digitalWrite(led[i], LOW);
    }
  }
}

}

