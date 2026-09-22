# PDV — Em Desenvolvimento

Segunda etapa do sistema de Ponto de Venda (PDV), evoluindo a versão inicial com estruturas de dados mais robustas e alocação dinâmica de memória.

## Funcionalidades

- Cadastro dinâmico de produtos (id, nome, preço, quantidade em estoque, área/setor), com `realloc`.
- Edição de produtos (id, nome, preço, estoque) e exclusão individual ou total.
- Abertura e fechamento de caixa, com cálculo de saldo e média de ganho por produto vendido.
- Registro de vendas com múltiplos itens por venda.
- Relatório de vendas do dia e relatório geral, com ordenação por valor total da venda.
- Controle de datas (avança dia/mês/ano a cada fechamento de caixa).

## Conceitos praticados

- `struct` (`Produto`, `itemVenda`, `venda`) e ponteiros para `struct`.
- Alocação dinâmica de memória (`malloc`/`realloc`/`free`).
- Ponteiros para ponteiros (`Produto **estoque`) para permitir que as funções redimensionem o array original.
- Recursão (`recursividadeProdutos`, usada para listar o estoque).
- Validação de entrada reutilizável (`validar`, `validarFloat`).

## Como compilar e executar

```bash
gcc main.c -o pdv_dev
./pdv_dev
```

## Sobre esta versão

Esta é a versão intermediária do projeto: ainda **não há persistência em arquivo** (os dados também são perdidos ao fechar o programa), mas já resolve a principal limitação da versão inicial, que era o catálogo fixo de produtos. A persistência em arquivo é implementada na versão `PROJETO PDV - FINAL`.

> Requer `windows.h` (Windows).
