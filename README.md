# Seguidor Solar
## Desenvolvimento de um seguidor solar através da utilização do Arduino para proporcionar uma melhor eficiência na captação da energia solar

O projeto proposto consiste num seguidor solar, que foi desenvolvido com o intuito de proporcionar uma melhor eficiência na captação da energia solar através de um sistema de rastreamento com sensores LDR (Light Dependent Resistor).

Este protótipo visa aproveitar ainda mais a energia do sol, pois verifica a posição da fonte de luz com a ajuda de quatro sensores LDR e consequentemente através de dois servos motores, movimenta uma plataforma para se posicionar de forma a captar o máximo de luz possível.

Os resultados típicos para um LDR podem ser:
- Escuridão: resistência máxima (valores lidos são mais baixos);
- Luz muito brilhante: resistência mínima (valores lidos mais altos).

É possivel controlar o seguidor solar remotamente através de uma aplicação desenvolvida na plataforma [MIT App Inventor](https://appinventor.mit.edu/), que fornece uma interface para a conexão Bluetooth entre o seguidor solar e um dispositivo Android.

**Nota:** 
Para se conseguir utilizar a aplicação e efetuar os ajustes necessário no código da aplicação é necessario executar os passos a seguir:

1. Fazer download do ficheiro [seguidorSolarMobileApp.aia](https://github.com/D1ogoCS/Seguidor-Solar/raw/main/SeguidorSolar/seguidorSolarMobileApp.aia)
2. Entrar no MIT App Inventor através da utilização de uma conta Gmail
3. Na barra superior do MIT App Inventor clicar **Projetos > Importar projeto (.aia) do meu computador**. Com o projeto no MIT App Inventor, é possivel modificar o código da aplicação para o ajustar a situações específicas
4. Fazer download da aplicação [MIT AI2 Companion](https://play.google.com/store/apps/details?id=edu.mit.appinventor.aicompanion3&hl=pt_PT&pli=1) para Android
5. Na barra superior do MIT App Inventor clicar **Conectar > Assistente AI**
6. Com a aplicação do MIT AI2 Companion, fazer scan do código QR

### Objetivos: 
- Desenvolver um protótipo que se movimenta com base na incidência da luz
- Estabelecer uma conexão entre o protótipo e um dispositivo
- Utilizar o Arduino Uno
  
### Ferramentas utilizadas:
- Arduino IDE
- MIT App Inventor
- MIT AI2 Companion

### Tecnologias utilizadas:
- Linguagem C++

### Materiais necessários:
- 1 Arduino Uno
- 4 LDR (Light Dependent Resistor)
- 4 Resistências 10kΩ
- 2 Servo motores
- 1 Modulo Bluetooth HC-05
- 1 Protoboard
- Jumpers ou fios
- Peças em 3D ([Pan tilt head by eltitomanolo – Thingiverse](https://www.thingiverse.com/thing:2467743), consultado em 17/10/2023)







