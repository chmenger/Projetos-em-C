# Quiz com Ranking de Jogadores

Evolução do projeto Quiz: agora com cadastro de várias perguntas, vários jogadores e um ranking final ordenado por pontuação (bubble sort).

## Funcionalidades

- Cadastro de até 7 perguntas verdadeiro/falso.
- Cadastro de até 5 jogadores.
- Fluxo de jogo: escolha do jogador, resposta às perguntas cadastradas, pontuação por acerto.
- Ranking final dos jogadores, ordenado da maior para a menor pontuação.

## Conceitos praticados

- Duas `struct` diferentes (`jogador` e `quiz`) para modelar os dados.
- Algoritmo de ordenação (Bubble Sort) implementado manualmente para o ranking.
- Vetores de `struct` e vetores paralelos de controle (quem já jogou, pontuação de cada um).

## Como compilar e executar

```bash
gcc main.c -o ranking
./ranking
```

## Observações

- O arquivo contém bastante código comentado (tentativas anteriores de implementação). Vale a pena limpar esses trechos antes de subir a versão "final" do projeto — deixa o código mais legível para quem for ler depois.
- Existe uma inconsistência: no fluxo do `case 3`, a pontuação final é impressa com `pontos[escolha[r]]`, mas `escolha` é um `int`, não um vetor — isso deve gerar erro de compilação ou comportamento inesperado dependendo do compilador. Vale revisar esse trecho para deixar `pontos[escolha]`.
- Requer `windows.h` (Windows).
