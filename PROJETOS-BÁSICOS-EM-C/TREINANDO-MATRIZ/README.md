# Treinando Matrizes — Calculadora de Matrizes 3x3

Programa de menu que registra duas matrizes 3x3 e realiza operações entre elas.

## Funcionalidades

- Registro de duas matrizes 3x3 (`Matriz A` e `Matriz B`).
- Soma, subtração, multiplicação e divisão entre as matrizes, elemento a elemento.
- Validação que impede realizar operações antes de registrar as matrizes.
- Tratamento de divisão por zero.

## Conceitos praticados

- Matrizes (arrays bidimensionais) e passagem de matrizes para funções.
- Modularização do código em várias funções (`lerMatriz`, `exibirMatriz`, `somaMatrizes`, `subMatrizes`, `multMatrizes`, `divMatrizes`, `validar`).
- Laços aninhados (`for` dentro de `for`).

## Como compilar e executar

```bash
gcc main.c -o matrizes
./matrizes
```

> **Observação:** as operações de "multiplicação" e "divisão" são feitas elemento a elemento (Hadamard), e não multiplicação matricial tradicional (linha × coluna). Isso é perfeitamente válido como exercício — só vale deixar claro se o objetivo futuro for implementar multiplicação de matrizes no sentido formal.
>
> Requer `windows.h` (Windows). Em Linux/macOS, remova esse include e troque `system("cls")` por `system("clear")`.
