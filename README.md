# 💡 Atividade 2: Temporizador de um Disparo (One Shot)

Este projeto utiliza a função `add_alarm_in_ms()` do **Pico SDK** para implementar um sistema de **temporização** que controla o acionamento de **LEDs** através de um **botão (pushbutton)**.

## 📌 Link do vídeo de demonstração de funcionamento
https://drive.google.com/file/d/149QWWUzceAYSvegseN4Ey2pP-fkDrIiT/view?usp=sharing


## 🛠 Componentes Utilizados
- Raspberry Pi Pico W
- 3 LEDs (azul, vermelho e verde)
- 3 Resistores de 330 Ω
- 1 Botão (Pushbutton)

## 🔄 Funcionamento
1. **Ao pressionar o botão**, os três LEDs são ligados simultaneamente.
2. Após **3 segundos**, um LED é desligado, permanecendo apenas **dois ligados**.
3. Após mais **3 segundos**, outro LED é desligado, restando apenas **um ligado**.
4. Após **mais 3 segundos**, o último LED se apaga completamente.
5. O botão **só pode ser acionado novamente** quando todos os LEDs estiverem desligados.

## 📌 Requisitos de Implementação
✔ O **temporizador do alarme** é configurado com um **atraso de 3 segundos (3.000ms)** para cada mudança de estado dos LEDs.  
✔ As transições dos LEDs são realizadas por **funções de call-back do temporizador**, como `turn_off_callback()`.  
✔ O **botão não interrompe** o ciclo de temporização enquanto os LEDs ainda estiverem acesos.  

## 🚀 Execução
1. Após baixar o projeto, clique em compilar para poder criar a pasta build.
2. Entre no arquivo diagram.json.
3. Clique no botão de executar no diagram.json e assista ao funcionamento.

