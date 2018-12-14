/***************************************************************************
****************************************************************************
** CENTRO DE ENSINO PROFISSIONALIZANTE - CEP                              **
** ESCOLA TÉCNICA DE BRASÍLIA - ETB                                       **
** PROFESSOR: SANDOVAL                                                    **
**                                                                        **
** PROJETO: LER A MEMÓRIA EEPROM DO ARDUINO                               **
** ALUNOS:  FRANCISCO DE ASSIS DA ROCHA CAMPOS - 17177-8                  **
**          NAILTON SOUSA DE OLIVEIRA - 17286-3                           **
**          PEDRO DE SANTANA SILVA - 17301-0                              **
** TURMA: 3ºP Noturno Data inicial: 27/04/2018 Data final: 27/04/2018     **
****************************************************************************
***************************************************************************/

// Declaração de Bibliotecas
#include <EEPROM.h>

//Declaração de Variáveis

void setup() { // Inicialização das variáveis
  
  Serial.begin(9600); // Iniciar o monitor serial

}

void loop() { // Programa propriamente dito

  int i = 0; // Iniciar variável local
  
  for(;;) // Laço for de modo infinito
  {
    Serial.println(EEPROM.read(i)); // Ler a memória do Arduino
    
    delay(1000); // Aguarda 1 segundo
    
    i++; // Incrementa mais um na variável local
  }

}
