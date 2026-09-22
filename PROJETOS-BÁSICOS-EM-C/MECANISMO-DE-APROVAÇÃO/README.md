# Mecanismo de Aprovação de Alunos

Sistema de menu que recebe as notas de 10 alunos e permite consultar a média da turma, os aprovados, os reprovados e os números pares dentre as notas.

## Funcionalidades

- Cadastro de 10 notas em um vetor, com validação de entrada (somente números).
- Cálculo da média geral da turma.
- Listagem de alunos aprovados (nota ≥ 7) e reprovados.
- Listagem das notas que são números pares.

## Conceitos praticados

- Vetores (arrays) e passagem de vetores para funções.
- Funções com retorno (`float verMediaAcima`).
- Estrutura de menu com `switch` dentro de `do...while`.
- Validação robusta de entrada com `scanf` e checagem de caractere residual no buffer.

## Como compilar e executar

```bash
gcc main.c -o aprovacao
./aprovacao
```

> **Observação:** o programa usa `windows.h` e `system("cls")`, então é pensado para rodar no Windows. Em Linux/macOS, remova o `#include <windows.h>` e troque `"cls"` por `"clear"`.
