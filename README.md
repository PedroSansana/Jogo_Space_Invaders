# UEPG - Engenharia de Software - Programação de Computadores I - Jogo SPACE INVADERS
### Imagem da tela inicial do jogo

## Trabalho: Jogo Space Invaders em C++ com a biblioteca Raylib
O trabalho consiste em desenvolver um jogo 2D simples em C++, com a biblioteca Raylib. Optamos por realizar o jogo Space Invaders, um jogo arcade de jogabilidade infinita (o fim é mediante à falha do jogador) e tiro fixo (tela de fase estática e movimento restrito a um eixo).

## Integrantes: 
- Gabriel Colman Martins — RA: 26023723
- Lucas Van Santen Senchechem — RA: 26036723
- Pedro Gabriel Sansana — RA: 26013823
- Vinicius Miara Staichoki — RA:

## Comandos e mecânicas principais
### Comandos 
| Comando | Ação |

| Seta Esquerda | Move a nave para a esquerda |

| Seta Direita | Move a nave para a direita |

| Barra de espaço | Atira laser |

| Tecla ENTER | Reinicia o jogo após game over |

| Tecla ESC | Encerra a aplicação |

### Regras e Mecânicas Principais

Vidas: O jogador inicia a partida com 3 vidas.

Pontuação: Alien Tipo 1 (Inferior): 100 pontos; Alien Tipo 2 (Médio): 200 pontos; Alien Tipo 3 (Superior): 300 pontos

Nave Misteriosa: 500 pontos

Barreiras de Proteção:4 obstáculos formados por blocos destrutíveis de 3x3 pixels sofrem degradação progressiva a cada impacto de laser.

Recorde (Highscore): A pontuação máxima alcançada é gravada automaticamente no arquivo local \`recorde.txt\` e lida a cada nova execução do jogo.


## Instruções de instalação:
### Opção 1: Executável Pré-compilado (Release) 

1 - Acesse a aba [Releases](https://github.com/PedroSansana/Jogo\_Space\_Invaders/releases) do repositório. 

2 - Faça o download do arquivo Space.Invaders_v1.zip. 

3 - Extraia o conteúdo da pasta .zip no seu computador e clique duas vezes no arquivo .exe para jogar.

*Caso apareça alguma mensagem que o sistema operacional não permitiu a execução, clique em "Mais informações" e depois em "Executar mesmo assim".

### Opção 2: Compilando o Código-Fonte (VS Code + C++)

1 - Clone esse repositório em sua máquina.

2- Certifique-se de ter o compilador C++ (ex: MinGW/GCC) e a biblioteca Raylib instalados no seu ambiente.

3 - Abra a pasta do projeto no Visual Studio Code.

4 - Abra o arquivo `src/main.cpp` e execute o build/compilação (ou pressione `F5` se configurado) para rodar o jogo.



## Tecnologias utilizadas:
* **Linguagem:** C++
* **Biblioteca Gráfica e de Áudio:** [Raylib](https://www.google.com/url?sa=E&amp;q=https%3A%2F%2Fwww.raylib.com%2F)
* **Ambiente de Desenvolvimento:** Visual Studio Code
* **Controle de Versão:** Git &amp; GitHub

## Transparência de IA:
Declaramos que o uso de ferramentas de Inteligência Artificial no desenvolvimento deste projeto ficou restrito exclusivamente ao auxílio inicial na instalação da biblioteca Raylib e na configuração do ambiente de desenvolvimento C++ no VS Code.

Nenhuma lógica de jogo, algoritmo de colisão, gerenciamento de memória ou estrutura de classes foi gerada automaticamente por IA. Todo o código foi estudado, compreendido e implementado manualmente pelos integrantes do grupo.

##  Créditos 

- Tutorial Base: Canal do YouTube [Programming With Nick](https://www.google.com/url?sa=E&amp;q=https%3A%2F%2Fwww.youtube.com%2F%40ProgrammingWithNick), que disponibilizou o tutorial educacional que serviu de referência lógica para a reconstrução do jogo.
- Trilha Sonora: Trilha musical de fundo composta e disponibilizada por Spyros.
- Biblioteca Gráfica: [Raylib](https://www.google.com/url?sa=E&amp;q=https%3A%2F%2Fwww.raylib.com%2F) por Ramon Santamaria.
