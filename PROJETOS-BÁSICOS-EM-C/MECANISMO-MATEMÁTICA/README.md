# Soma de Dois Números (rascunho)

Exercício inicial com o objetivo de somar dois números digitados pelo usuário.

## Status

⚠️ **Este arquivo está incompleto e não compila no estado atual** — parece ser um rascunho/anotação de estudo (há uso incorreto de `scanf` sem o operador `&`, uma linha sem ponto e vírgula e uma string de formatação de `printf` não fechada).

## O que o código pretende fazer

- Ler dois números inteiros.
- Somar os dois valores.
- Exibir o resultado.

## Sugestão de correção

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, soma;
    printf("digite um numero: ");
    scanf("%d", &num1);
    printf("digite o segundo numero: ");
    scanf("%d", &num2);
    soma = num1 + num2;
    printf("a soma e: %d\n", soma);
    return 0;
}
```

> Recomendo substituir o `main.c` por essa versão corrigida (ou remover a pasta do repositório) antes de divulgar o portfólio, já que hoje o projeto não compila.
