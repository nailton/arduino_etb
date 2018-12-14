/***************************************************************************
****************************************************************************
** CENTRO DE ENSINO PROFISSIONALIZANTE - CEP                              **
** ESCOLA TÉCNICA DE BRASÍLIA - ETB                                       **
** PROFESSOR: SANDOVAL                                                    **
**                                                                        **
** PROJETO: CONTROLE MOTOR DC, GIRAR SENTIDO HORÁRIO E ANTI-HORÁRIO 1 MIN **
** ALUNOS:  FRANCISCO DE ASSIS DA ROCHA CAMPOS - 17177-8                  **
**          MARIA JUCICLÉIA DA SILVA 14904-7                              **
**          NAILTON SOUSA DE OLIVEIRA - 17286-3                           **
** TURMA: 2ºP Noturno Data inicial: 25/10/2017 Data final: 27/10/2017     **
****************************************************************************
***************************************************************************/
// Declaração das bibliotecas

// Definição das variáveis
//
// pino para rotação horário
int rotacaoHorario = 0;
// pino para rotação ant-horário
int rotacaoAnteHorario = 1;

// Setup básico para definição dos tipos de pinos
void setup() {
  pinMode(rotacaoHorario, OUTPUT);
  pinMode(rotacaoAnteHorario, OUTPUT);

  digitalWrite(rotacaoHorario, LOW);
  digitalWrite(rotacaoAnteHorario, LOW);
}

// Loop padrão arduino
void loop() {

  //Liga o motor em sentido horário
  digitalWrite(rotacaoHorario, HIGH);

  // Manda corrente negativa/desligada para o sentido oposto
  digitalWrite(rotacaoAnteHorario, LOW);

  // Aguarda 1 minuto em milissegundos
  delay(60000);

  // Para de mandar tensão entre um sentido e outro
  digitalWrite(rotacaoHorario, LOW);
  digitalWrite(rotacaoAnteHorario, LOW);

  //Liga o motor em sentido horário
  digitalWrite(rotacaoAnteHorario, HIGH);

  // Manda corrente negativa/desligada para o sentido oposto
  digitalWrite(rotacaoHorario, LOW);

  // Aguarda 1 minuto em milissegundos
  delay(60000);

  // Para de mandar tensão entre um sentido e outro
  digitalWrite(rotacaoHorario, LOW);
  digitalWrite(rotacaoAnteHorario, LOW);

}

