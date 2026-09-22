# Calculadora Interativa

Calculadora de linha de comando com menu, que executa as quatro operações matemáticas básicas a partir da escolha do usuário.

## Funcionalidades

- Menu interativo em loop (`do...while`) com as opções: soma, subtração, multiplicação, divisão e sair.
- Leitura de dois números via `scanf`.
- Tratamento de divisão por zero.
- Tratamento básico de opção inválida no menu.

## Conceitos praticados

- Estruturas de repetição (`do...while`) e decisão (`switch`).
- Funções (uso de uma função auxiliar para reaproveitar a leitura dos números).
- Entrada e formatação de saída com `printf`/`scanf`.

## Como compilar e executar

```bash
gcc main.c -o calculadora
./calculadora
```

> **Observação:** o programa usa `system("cls")`, que é específico do Windows. Para rodar em Linux/macOS, troque por `system("clear")`.

> **Nota técnica:** a função `printar()` é declarada dentro de `main()` (função aninhada). Isso é uma extensão do compilador GCC e não faz parte do padrão C — não compila em compiladores como o MSVC. Se quiser portabilidade total, vale mover essa função para fora da `main`.
