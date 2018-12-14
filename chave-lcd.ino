/***************************************************************************
****************************************************************************
** CENTRO DE ENSINO PROFISSIONALIZANTE - CEP                              **
** ESCOLA TÉCNICA DE BRASÍLIA - ETB                                       **
** PROFESSOR: SANDOVAL                                                    **
**                                                                        **
** PROJETO: CHAVE LCD                                                     **
** ALUNOS:  FRANCISCO DE ASSIS DA ROCHA CAMPOS - 17177-8                  **
**          MARIA JUCICLÉIA DA SILVA 14904-7                              **
**          NAILTON SOUSA DE OLIVEIRA - 17286-3                           **
** TURMA: 2ºP Noturno Data inicial: 27/10/2017 Data final: 27/10/2017     **
****************************************************************************
***************************************************************************/
// Declaração das bibliotecas
#include <LiquidCrystal.h>

// Definição das variáveis
int leituraChave = 2;
int read_chave;

// Definir os pinos LCD no ARDUINO
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  pinMode(leituraChave, INPUT);
  digitalWrite(leituraChave, LOW);
  lcd.begin(16, 2);
}

void loop() {

  //Leitura simples no pino da chave
  read_chave = digitalRead(leituraChave);

  lcd.clear();

  //Verifica se está chegando corrente
  if (read_chave == HIGH)
  {

    // Coloca as informações no LCD
    lcd.begin(16, 2);
    lcd.print("SENTIDO HORARIO");

  }else{

    // Coloca as informações no LCD
    lcd.begin(16, 2);
    lcd.print("SENTIDO ANTI-HOR");

  }

}
