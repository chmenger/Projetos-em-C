# Verificação de IDs Duplicados entre Servidores

Programa que recebe duas listas de 5 IDs (representando dois "servidores") e detecta quais números aparecem repetidos entre as duas listas.

## Funcionalidades

- Cadastro de 5 IDs para o "Servidor 1" e 5 IDs para o "Servidor 2", com validação de entrada.
- Menu para visualizar os IDs de cada servidor separadamente.
- Detecção de conflitos (IDs presentes em ambas as listas), indicando a posição em que cada um aparece.

## Conceitos praticados

- Vetores e comparação cruzada entre dois vetores (laços aninhados).
- Funções com retorno (`int verificarDuplicados`).
- Validação de entrada numérica com tratamento de caracteres inválidos.

## Como compilar e executar

```bash
gcc main.c -o verificacao_iguais
./verificacao_iguais
```

> Requer `windows.h` (Windows). Em Linux/macOS, remova esse include e troque `system("cls")` por `system("clear")`.
