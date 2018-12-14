/***************************************************************************
****************************************************************************
** CENTRO DE ENSINO PROFISSIONALIZANTE - CEP                              **
** ESCOLA TÉCNICA DE BRASÍLIA - ETB                                       **
** PROFESSOR: SANDOVAL                                                    **
**                                                                        **
** PROJETO: ESCREVER LCD COM BIBLIOTECA                                   **
** ALUNOS:  FRANCISCO DE ASSIS DA ROCHA CAMPOS - 17177-8                  **
**          MARIA JUCICLÉIA DA SILVA 14904-7                              **
**          NAILTON SOUSA DE OLIVEIRA - 17286-3                           **
** TURMA: 2ºP Noturno Data inicial: 27/10/2017 Data final: 27/10/2017     **
****************************************************************************
***************************************************************************/
// Declaração das bibliotecas
#include <LiquidCrystal.h>

// Definição das variáveis

//display no modo 8 bits
LiquidCrystal lcd(12, 11, 9, 8, 7, 6, 5, 4, 3, 2); //Modo 8 bits

void setup()
{
 // configura o número de colunas e linhas do display LCD:
 lcd.begin(16, 2);

}

void loop()
{

  lcd.clear(); // Limpar display

  lcd.setCursor(0,0); //Cursor

  lcd.print("A"); //Escreve

  lcd.clear(); // Limpar display

  lcd.setCursor(14,0); //Cursor

  lcd.print("B"); //Escreve

}
