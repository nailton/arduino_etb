/***************************************************************************
****************************************************************************
** CENTRO DE ENSINO PROFISSIONALIZANTE - CEP                              **
** ESCOLA TÉCNICA DE BRASÍLIA - ETB                                       **
** PROFESSOR: SANDOVAL                                                    **
**                                                                        **
** PROJETO: ACIONAR MOTOR DC PARA AMBOS OS LADOS                          **
** ALUNOS:  FRANCISCO DE ASSIS DA ROCHA CAMPOS - 17177-8                  **
**          NAILTON SOUSA DE OLIVEIRA - 17286-3                           **
**          PEDRO DE SANTANA SILVA - 17301-0                              **
** TURMA: 3ºL Noturno Data inicial: 10/04/2018 Data final: 30/04/2018     **
****************************************************************************
***************************************************************************/
// Declaração das bibliotecas

// Definição das variáveis

int rotacaoHorario = 0; // pino para rotação horário

int rotacaoAnteHorario = 1; // pino para rotação ant-horário

void setup() { // Setup básico para definição dos tipos de pinos
  pinMode(rotacaoHorario, OUTPUT); // Define como saída
  pinMode(rotacaoAnteHorario, OUTPUT); // Define como saída

  digitalWrite(rotacaoHorario, LOW); // Inicia desligado
  digitalWrite(rotacaoAnteHorario, LOW); // Inicia desligado
}

void loop() { // Programa propriamente dito

  digitalWrite(rotacaoHorario, HIGH); //Liga o motor em sentido horário

  digitalWrite(rotacaoAnteHorario, LOW); // Manda corrente negativa/desligada para o sentido oposto

  delay(60000); // Aguarda 1 minuto em milissegundos

  digitalWrite(rotacaoHorario, LOW); // Desligar motor
  digitalWrite(rotacaoAnteHorario, LOW); // Desligar motor

  digitalWrite(rotacaoAnteHorario, HIGH); //Liga o motor em sentido horário

  digitalWrite(rotacaoHorario, LOW); // Manda corrente negativa/desligada para o sentido oposto

  delay(60000); // Aguarda 1 minuto em milissegundos

  digitalWrite(rotacaoHorario, LOW); // Desligar motor
  digitalWrite(rotacaoAnteHorario, LOW); // Desligar motor

}

