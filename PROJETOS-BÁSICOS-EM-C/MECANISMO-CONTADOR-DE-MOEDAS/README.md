# Contador de Cédulas e Moedas

Programa que recebe um valor em centavos e calcula a menor quantidade de cédulas e moedas necessária para compor esse valor, usando as denominações do Real (R$200, R$100, R$50, R$20, R$10, R$5, R$2, R$1, 50¢, 25¢, 10¢, 5¢, 1¢).

## Funcionalidades

- Leitura de um valor em centavos, com validação de valores negativos.
- Cálculo sequencial de quantas cédulas/moedas de cada denominação são necessárias (divisão e módulo).
- Exibição apenas das denominações efetivamente usadas.

## Conceitos praticados

- Operadores aritméticos (`/` e `%`) aplicados a um problema real (troco).
- Estruturas de decisão (`if`) encadeadas.
- Validação de entrada em loop.

## Como compilar e executar

```bash
gcc main.c -o contador
./contador
```
