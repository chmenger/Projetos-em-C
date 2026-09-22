# Treinando If/Else — Verificação de Maioridade

Exercício introdutório de estruturas condicionais: verifica se a idade informada indica maioridade.

## Funcionalidades

- Leitura de nome, gênero e idade.
- Verificação simples: maior ou menor de idade, usando `if/else`.

## Conceitos praticados

- Estrutura condicional `if/else`.
- Leitura de dados via `scanf`.

## Como compilar e executar

```bash
gcc main.c -o if_else
./if_else
```

> **Observação:** o campo `nome` está sendo lido com `scanf("%d", &nome)`, ou seja, como número — mas nomes são texto. Para ler um nome corretamente, `nome` deveria ser um `char nome[50]` e a leitura feita com `scanf("%s", nome)` ou `fgets`. Bom próximo passo para evoluir este exercício.
