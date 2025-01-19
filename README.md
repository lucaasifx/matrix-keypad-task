# Tarefa 01: Simulação de Keypad 4x4 com a Raspberry Pi Pico W

## Descrição
Nessa tarefa simulamos uma placa Raspberry Pi Pico W conectado a um teclado matricial 4x4 para controlar três LEDs RGB e um buzzer.
Os seguintes recursos foram implementados:

- **Botoes 1 a 3**: Funcionam como interruptores para ligar/desligar os LEDs verde, azul e vermelho, respectivamente.
- **Botoes 4 a 6**: Controlam o modo "blink" (piscar) dos LEDs verde, azul e vermelho.
- **Botão B**: Emite um beep utilizando o buzzer.
O projeto foi desenvolvido de forma a funcionar também no hardware físico
## Estrutura do Projeto
O projeto foi desenvolvido em C e utiliza o simulador **Wokwi** para emular o circuito. A estrutura de diretórios é organizada para facilitar o desenvolvimento e a compilação com a extensão **Raspberry Pi Pico** no VS Code.

### Diretórios Principais
- src/: Contém o arquivo principal do código-fonte (main.c).
- lib/: Contém os arquivos de cabeçalho (.h) das bibliotecas implementadas e as suas respectivas implementações.
- diagram.json e wokwi.toml: Contém o arquivo de simulação do circuito Wokwi.

## Funcionalidades
### Controles dos LEDs
- **Botão 1**: Liga/desliga o LED verde.
- **Botão 2**: Liga/desliga o LED azul.
- **Botão 3**: Liga/desliga o LED vermelho.
- **Botão 4**: Realiza um ciclo de "blink" no LED verde.
- **Botão 5**: Realiza um ciclo de "blink" no LED azul.
- **Botão 6**: Realiza um ciclo de "blink" no LED vermelho.

### Controle do Buzzer
- **Botão B**: Emite um beep.

## Requisitos
- **Software**:
  - VS Code com a extensão **Raspberry Pi Pico**
  - Simulador **Wokwi**

## Como Compilar e Executar
1. Clone este repositório:
   
```bash
   git clone <https://github.com/lucaasifx/matrix-keypad-task>
```


2. Abra o projeto no VS Code.

3. Certifique-se de que a extensão **Raspberry Pi Pico** e  **Wokwi** estão instaladas e configuradas corretamente.
4. Clique no ícone da extensão da Pico<br>

  ![image](https://github.com/user-attachments/assets/28cdb91b-16e2-4687-a6a1-950f219ddf34)

5. Selecione importar projeto para que a pasta build seja gerada automaticamente:<br>
![image](https://github.com/user-attachments/assets/b0dc78cd-f619-4648-9b5b-d509c65800d7)
  - Selecione o caminho do projeto<br>
![image](https://github.com/user-attachments/assets/c1c414ea-0b8e-411b-bc43-839d72409821)

6. Navegue até a opção Compilar Projeto:<br>
![image](https://github.com/user-attachments/assets/366a506d-171c-4c30-9577-e61d1575da33)

7. Se desejar testar no simulador, abra o arquivo diagram.json e inicie a simulação. <br>
![image](https://github.com/user-attachments/assets/3964ec22-f6c8-4282-a344-893ae35e30f2)



## Simulação no Wokwi
O projeto inclui suporte para simulação do circuito utilizando o **Wokwi**. **Após compilar o projeto** basta abrir o arquivo diagram.json e iniciar a simulação.

## Contribuição
Esse projeto foi construído pelos membros do Grupo 04 Subgrupo 08 do EmbarcaTech, uma iniciativa do CEPEDI.
Alunos:
 - Elisson Nadson
 - Lucas Emanoel
 - Davi Moura
 - Ariel
 - Marcus Porto
 - Guilherme Lopes
 - Claudemir da Silva 
