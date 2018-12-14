/***************************************************************************
****************************************************************************
** CENTRO DE ENSINO PROFISSIONALIZANTE - CEP                              **
** ESCOLA TÉCNICA DE BRASÍLIA - ETB                                       **
** PROFESSOR: SANDOVAL                                                    **
**                                                                        **
** PROJETO: DETECTOR DE FALTA DE FASE (DFF)                               **
** ALUNOS:  FRANCISCO DE ASSIS DA ROCHA CAMPOS - 17177-8                  **
**          MARIA JUCICLÉIA DA SILVA 14904-7                              **
**          NAILTON SOUSA DE OLIVEIRA - 17286-3                           **
** TURMA: 2ºP Noturno Data inicial: 18/08/2017 Data final: 25/11/2017     **
****************************************************************************
***************************************************************************/

// Inclusão de bibliotecas
#include <LiquidCrystal.h>

// Definir porta do rele

// Definir as portas dos sensores
int SENSOR_FA = 2;
int SENSOR_FB = 3;
int SENSOR_FC = 4;

// Definir variáveis de leituras dos sensores
int READ_SENSOR_FA;
int READ_SENSOR_FB;
int READ_SENSOR_FC;

// Definir as portas dos alertas
int LED0 = 5;
int BUZZER0 = 6;

// Definir porta do relé
int RELE = 2;

// Paramêtros da função estadoAlerta
unsigned long millisAnterior = 0;
int estadoPino = LOW;
const long intervalo = 1000;

// Paramêtros da função retornaLeituraSensor
bool ALERTA;

const char * LCD_ESCREVER;

// Definir os pinos LCD no ARDUINO
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Início do programa
void setup()
{

  // Definir o tipo de entrada das variáveis
  pinMode(SENSOR_FA, INPUT);
  pinMode(SENSOR_FB, INPUT);
  pinMode(SENSOR_FC, INPUT);
  pinMode(LED0, OUTPUT);
  pinMode(BUZZER0, OUTPUT);
  pinMode(RELE, INPUT);

  // Inicializa as váriaveis com estado desligado
  digitalWrite(SENSOR_FA, LOW);
  digitalWrite(SENSOR_FB, LOW);
  digitalWrite(SENSOR_FC, LOW);
  digitalWrite(LED0, LOW);
  digitalWrite(BUZZER0, LOW);
  digitalWrite(RELE, LOW);

}

// Loop do programa ARDUINO
void loop()
{

  // Função que faz a leitura dos sensores A, B, C
  ALERTA = retornaLeituraSensor();

  // Faz um teste de igualdade e executado uma ação
  switch (ALERTA) {
    case true:
    estadoPino = estadoAlerta(estadoPino);
    digitalWrite(LED0, estadoPino);
    digitalWrite(BUZZER0, estadoPino);
    break;
    default:
    digitalWrite(LED0, LOW);
    digitalWrite(BUZZER0, LOW);
    break;
  }

}

// Essa função retorna o estado do pino LOW/HIGH com base no paramêtro passado
int estadoAlerta(int estadoPino)
{
  unsigned long millisAtual = millis();

  if (millisAtual - millisAnterior >= intervalo) {

    // salve a última vez que estava ativo o alerta
    millisAnterior = millisAtual;

    // Se o alerta estiver desligado, ligue-o e vice-versa:
    if (estadoPino == LOW) {
      estadoPino = HIGH;
      } else {
        estadoPino = LOW;
      }
      return estadoPino;
    }
  }


// Função faz a leitura dos sensores e retorna o estado true/false
int retornaLeituraSensor()
{
  ALERTA = false;

  // Ler o estado dos sensores
  READ_SENSOR_FA = digitalRead(SENSOR_FA); // SENSOR R
  READ_SENSOR_FB = digitalRead(SENSOR_FB); // SENSOR S
  READ_SENSOR_FC = digitalRead(SENSOR_FC); // SENSOR T

  delay(1000);
  lcd.clear();

// Escrever no LCD conforme cada fase desativada
 if(READ_SENSOR_FA == LOW && READ_SENSOR_FB == LOW)
  {
    LCD_ESCREVER = "FASE R/S";

  }else if(READ_SENSOR_FA == LOW && READ_SENSOR_FC == LOW)
  {
    LCD_ESCREVER = "FASE R/T";

  }else if(READ_SENSOR_FB == LOW && READ_SENSOR_FC == LOW)
  {
    LCD_ESCREVER = "FASE S/T";

  }else if(READ_SENSOR_FA == LOW)
  {
    LCD_ESCREVER = "FASE R";

  }else if(READ_SENSOR_FB == LOW)
  {
    LCD_ESCREVER = "FASE S";

  }else
  {
    LCD_ESCREVER = "FASE T";
  }

  if(READ_SENSOR_FA == LOW && READ_SENSOR_FB == LOW && READ_SENSOR_FC == LOW)
  {
    // Imputa no ALERTA como verdadeiro, ou seja, caiu a fase
    ALERTA = true;

    // Enviar tensão para relé abrir
    digitalWrite(RELE, HIGH);

    // Coloca as informações no LCD
    lcd.begin(16, 2);
    lcd.print("FASE R/S/T");
    lcd.setCursor(0,1);
    lcd.print("0V");
    return ALERTA;
  }

  if (READ_SENSOR_FA == LOW)
  {
    // Imputa no ALERTA como verdadeiro, ou seja, caiu a fase
    ALERTA = true;

    // Enviar tensão para relé abrir
    digitalWrite(RELE, HIGH);

    // Coloca as informações no LCD
    lcd.begin(16, 2);
    lcd.print(LCD_ESCREVER);
    lcd.setCursor(0,1);
    lcd.print("0V");
    return ALERTA;
  }

  if (READ_SENSOR_FB == LOW)
  {
    // Imputa no ALERTA como verdadeiro, ou seja, caiu a fase
    ALERTA = true;

    // Enviar tensão para relé abrir
    digitalWrite(RELE, HIGH);

    // Coloca as informações no LCD
    lcd.begin(16, 2);
    lcd.print(LCD_ESCREVER);
    lcd.setCursor(0,1);
    lcd.print("0V");
    return ALERTA;
  }

  if (READ_SENSOR_FC == LOW)
  {
    // Imputa no ALERTA como verdadeiro, ou seja, caiu a fase
    ALERTA = true;

    // Enviar tensão para relé abrir
    digitalWrite(RELE, HIGH);

    // Coloca as informações no LCD
    lcd.begin(16, 2);
    lcd.print(LCD_ESCREVER);
    lcd.setCursor(0,1);
    lcd.print("0V");
    return ALERTA;
  }

  if (ALERTA == false)
  {

    // Enviar para relé abrir
    digitalWrite(RELE, LOW);

    // Coloca as informações no LCD
    lcd.begin(16, 2);
    lcd.print("MOTOR LIGADO");
    lcd.setCursor(0,1);
    lcd.print("220V");
    return ALERTA;
  }

}
