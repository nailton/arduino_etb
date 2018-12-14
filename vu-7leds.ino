/***************************************************************************
****************************************************************************
** CENTRO DE ENSINO PROFISSIONALIZANTE - CEP                              **
** ESCOLA TÉCNICA DE BRASÍLIA - ETB                                       **
** PROFESSOR: SANDOVAL                                                    **
**                                                                        **
** PROJETO: ROTINA CONTROLE OITO LEDS SIMULANDO VU ELETRÔNICO             **
** ALUNOS:  FRANCISCO DE ASSIS DA ROCHA CAMPOS - 17177-8                  **
**          NAILTON SOUSA DE OLIVEIRA - 17286-3
**          PEDRO SANTANA                           **
** TURMA: 3ºP Noturno Data inicial: 23/02/2018 Data final: 08/03/2018     **
****************************************************************************
***************************************************************************/

// Declaração dos oito LEDs em um array inteiro
int led[8] = {0, 1, 2, 3, 4, 5, 6, 7};

// Declaração das variáveis
int i = 0, cont = 0, contDesc = 0;

void setup()
{

  // Seta os leds como saída e estado desligado
  for (int i = 0; i <= 7; i++)
  {

    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], LOW);

  }

}

void loop() //Programado do arduino
{
  if (cont <= 3)
  {
    acendeLedAsc();
  } else {
    acendeLedDesc();
  }
}

void acendeLedAsc() //Ligar os led em ordem ascendente
{
  if (cont <= 3)
  {
    // Seta os LEDs como ligado
    for (i = 0; i <= 7; i++)
    {
      digitalWrite(led[i], HIGH);
      delay(500);
    }
    for (i = 0; i <= 7; i++)
    {
      digitalWrite(led[i], LOW);
    }
    delay(500);

    cont++;
  }
}

void acendeLedDesc() ////Ligar os led em ordem descrescente
{
  cont=4;
  if (contDesc <= 3)
  {
    // Seta os LEDs como ligado
    for (i = 7; i >= 0; i--)
    {
      digitalWrite(led[i], HIGH);
      delay(500);
    }

    for (i = 7; i >= 0; i--)
    {
      digitalWrite(led[i], LOW);
    }
    delay(500);

    contDesc++;
  }
}

