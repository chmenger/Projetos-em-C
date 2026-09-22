# Quiz de Lógica de Programação

Quiz de múltipla escolha com 10 perguntas fixas sobre fundamentos de C, que calcula a nota final e dá um feedback de acordo com o desempenho.

## Funcionalidades

- Exibição de 10 perguntas de múltipla escolha (A, B ou C) sobre conceitos de C.
- Correção automática comparando a resposta do usuário com o gabarito.
- Tela de desempenho, mostrando questão a questão o que foi acertado/errado e a nota final.
- Mensagens de feedback diferentes de acordo com a faixa de nota.

## Conceitos praticados

- Vetores de strings (matriz de `char` para armazenar as perguntas).
- Vetores paralelos (gabarito, respostas e pontuação).
- Funções com retorno booleano/inteiro (`validar`).
- Estrutura de menu com `switch`.

## Como compilar e executar

```bash
gcc main.c -o quiz
./quiz
```

> Requer `windows.h` (Windows). Em Linux/macOS, remova esse include e troque `system("cls")` por `system("clear")`.
