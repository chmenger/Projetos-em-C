# Calculadora de Fatorial

Programa de menu simples que calcula o fatorial de um número inteiro informado pelo usuário.

## Funcionalidades

- Menu com opções "Fatorar" e "Sair".
- Cálculo do fatorial usando um laço `for`.

## Conceitos praticados

- Estrutura de repetição (`for`) para cálculo acumulado.
- Estrutura de decisão (`switch`) dentro de um loop de menu.

## Como compilar e executar

```bash
gcc main.c -o fatorial
./fatorial
```

> **Observação:** como a variável `fatorial` não é reiniciada a cada operação, calcular o fatorial mais de uma vez na mesma execução acumula o resultado anterior. Vale a pena resetar `fatorial = 1` no início do `case 1` como próximo passo de melhoria.
