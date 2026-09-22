# PDV — Versão Inicial

Primeira versão de um sistema de Ponto de Venda (PDV) para um mercado fictício ("Mercado Bom Jesus"). Este é o ponto de partida do projeto PDV, que evolui nas pastas `PROJETO PDV - EM DESENVOLVIMENTO` e `PROJETO PDV - FINAL`.

## Funcionalidades

- Abertura de caixa com valor mínimo de entrada.
- Catálogo fixo de 10 produtos (preços fixos no código).
- Registro de vendas com quantidade por produto.
- Relatório final ao encerrar o programa (total vendido, saldo do caixa, quantidade de produtos vendidos).

## Conceitos praticados

- Estrutura de menus aninhados com `switch` e `do...while`.
- Uso de múltiplas variáveis para controlar o estado da venda e do caixa (versão pré-`struct`).
- Primeiros passos com funções locais.

## Como compilar e executar

```bash
gcc main.c -o pdv_inicial
./pdv_inicial
```

## Sobre esta versão

Esta é a versão mais simples do PDV: os produtos são fixos no código (sem cadastro dinâmico) e não há persistência em arquivo — tudo é perdido ao fechar o programa. Essas limitações são resolvidas nas versões seguintes do projeto.

> Requer `windows.h` (Windows).
