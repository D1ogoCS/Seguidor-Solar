#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothReader(2, 3);  //portas tx, rx do modulo bluetooth

Servo servoVertical, servoHorizontal; //criar os objetos para os servo motores

int automatico = 1;

int valor = 1;

int toleranciaLDR = 30; //definir a tolerancia dos LDR's

int amplitudeHorizontal = 0;
int amplitudeVertical = 0;

int limiteMaximoVertical = 180; //definir o limite maximo vertical
int limiteMinimoVertical = 0; //definir o limite minimo vertical
int limiteMaximoHorizontal = 180; //definir o limite maximo horizontal
int limiteMinimoHorizontal = 0; //definir o limite minimo horizontal

const int LDRdireita = A0; //  ----+
const int LDResquerda = A1; //     | portas analogicas 
const int LDRcima = A2; //         | onde se ligam os LDR's
const int LDRbaixo = A3; //  ------+

void setup() {
  Serial.begin(9600); 
  bluetoothReader.begin(9600); //iniciar a baud rate do bluetooth 

  servoVertical.attach(8); //porta de entrada do servo vertical
  servoHorizontal.attach(9); //porta de entrada do servo horizontal
    
  amplitudeVertical = 90;
  amplitudeHorizontal = 90;
  
  servoVertical.write(amplitudeVertical);
  servoHorizontal.write(amplitudeHorizontal);
}

void loop() {

  if(bluetoothReader.available()) // se houver dados para ler
  {
    valor = bluetoothReader.parseInt(); // lê, converte o caracter lido para inteiro e armazena na variavel "valor"
  }

  if(valor == 1)
  {
    automatico = 1; //Quando valor=1 entao quer dizer que esta em modo automatico, logo automatico=1
    }
  if(valor == 0)
  {
    automatico = 0; //Quando valor=0 entao quer dizer que esta em modo manual, logo automatico=0
    }

  if(automatico == 1) //Se automatico=1 executa a parte que pertence ao codigo da parte automatica
  {
    int ldr_direita = analogRead(LDRdireita); //-----+
    int ldr_esquerda = analogRead(LDResquerda); //   | Le os valores das portas
    int ldr_cima = analogRead(LDRcima); //           | analogicas onde estao os LDR's e guarda em variaveis correspondentes
    int ldr_baixo = analogRead(LDRbaixo); //---------+

    if(ldr_baixo+toleranciaLDR < ldr_cima) //compara para verificar se o valor do ldr_baixo é menor que o de cima
    {
      amplitudeVertical = amplitudeVertical + 3; // entao gira o servo motor para cima
    }
    
    if(ldr_baixo > ldr_cima+toleranciaLDR) //compara para verificar se o valor do ldr_cima é menor que o de baixo
    {
      amplitudeVertical = amplitudeVertical - 3; // entao gira o servo motor para baixo
    }

    if(ldr_esquerda > ldr_direita+toleranciaLDR) //compara para verificar se o valor do ldr_direita é menor que o da esquerda
    {
      amplitudeHorizontal = amplitudeHorizontal - 3; // entao gira o servo motor para a esquerda
    }

    if(ldr_esquerda +toleranciaLDR < ldr_direita) //compara para verificar se o valor do ldr_esquerda é menor que o da direita
    {
      amplitudeHorizontal = amplitudeHorizontal + 3; // entao gira o servo motor para a direita
    }
  }

  if(automatico == 0) //Se automatico=0 executa a parte que pertence ao codigo da parte manual
  {     
    if (valor == 8 && amplitudeVertical < limiteMaximoVertical) { 
      amplitudeVertical = amplitudeVertical + 10; // gira para cima
    }

    if (valor == 2 && amplitudeVertical > limiteMinimoVertical) {
      amplitudeVertical = amplitudeVertical - 10; // gira para baixo
    }

    if (valor == 4 && amplitudeHorizontal < limiteMaximoHorizontal) {
      amplitudeHorizontal = amplitudeHorizontal + 10; // gira para a esquerda
    }

    if (valor == 6 && amplitudeHorizontal > limiteMinimoHorizontal) {
      amplitudeHorizontal = amplitudeHorizontal - 10; // gira para a direita
    }

  }

  servoVertical.write(amplitudeVertical); // escreve o valor da variavel "amplitudeVertical" no servo motor
  servoHorizontal.write(amplitudeHorizontal); //escreve o valor da variavel "amplitudeHorizontal" no servo motor

  valor = 10; //reseta a variavel com um valor que nao usamos no programa que neste caso é o 10

  delay(80); //aguarda 80 ms
}
