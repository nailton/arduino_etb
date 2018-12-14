/***************************************************************************
****************************************************************************
** CENTRO DE ENSINO PROFISSIONALIZANTE - CEP                              **
** ESCOLA TÉCNICA DE BRASÍLIA - ETB                                       **
** PROFESSOR: SANDOVAL                                                    **
**                                                                        **
** PROJETO: PISCAR LED LIGADO AO PINO 13 DO ARDUINO                       **
** ALUNOS:  FRANCISCO DE ASSIS DA ROCHA CAMPOS - 17177-8                  **
**          MARIA JUCICLÉIA DA SILVA 14904-7                              **
**          NAILTON SOUSA DE OLIVEIRA - 17286-3                           **
** TURMA: 2ºP Noturno Data inicial: 24/09/2017 Data final: 24/09/2017     **
****************************************************************************
***************************************************************************/

//Definir pino 13 para led
int led0 = 13;

// Setup básico, setando led como output e led desligado
void setup()
{
  pinMode(led0, OUTPUT);
  digitalWrite(led0, LOW);
}

// Loop padrão arduino com liga e desliga led
void loop()
{
  digitalWrite(led0, HIGH);
  atrasoTempo();
  digitalWrite(led0, LOW);
  atrasoTempo();
}

// Delay "1Seg" com laço for
/* Afim de ficar mais perceptivel o led piscando
no proteus coloquei 0.9ms */
void atrasoTempo()
{
  for(int i=0; i<1000; i++){
      delay(0.9);
  }
}
