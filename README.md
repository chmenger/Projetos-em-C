# Projetos em C

Repositório com projetos e exercícios desenvolvidos em linguagem C, organizados por nível de complexidade, como parte do aprendizado das estruturas e conceitos fundamentais da linguagem.

## Estrutura

### 📁 Projetos Básicos em C
Exercícios de fundamentos: variáveis, condicionais, laços, vetores, funções e structs simples.

| Projeto | Descrição |
|---|---|
| [Calculadora Interativa](<PROJETOS-BÁSICOS-EM-C/CALCULADORA INTERATIVA>) | Calculadora com menu (soma, subtração, multiplicação, divisão) |
| [Mecanismo Contador de Moedas](<PROJETOS-BÁSICOS-EM-C/MECANISMO-CONTADOR-DE-MOEDAS>) | Decompõe um valor em cédulas e moedas |
| [Mecanismo de Aprovação](<PROJETOS-BÁSICOS-EM-C/MECANISMO-DE-APROVAÇÃO>) | Sistema de notas: média, aprovados e reprovados |
| [Mecanismo Fatoração](<PROJETOS-BÁSICOS-EM-C/MECANISMO-FATORAÇÃO>) | Calculadora de fatorial |
| [Mecanismo Matemática](<PROJETOS-BÁSICOS-EM-C/MECANISMO-MATEMÁTICA>) | Rascunho de soma de dois números *(precisa de correção)* |
| [Mecanismo Tabela de 10](<PROJETOS-BÁSICOS-EM-C/MECANISMO-TABELA-DE-10>) | Gerador de tabuada |
| [Treinando If/Else](<PROJETOS-BÁSICOS-EM-C/TREINANDO-IF-ELSE>) | Verificação de maioridade |
| [Treinando Matriz](<PROJETOS-BÁSICOS-EM-C/TREINANDO-MATRIZ>) | Operações entre matrizes 3x3 |
| [Treinando Média](<PROJETOS-BÁSICOS-EM-C/TREINANDO-MÉDIA>) | Cálculo de média e itens acima da média |
| [Treinando String](<PROJETOS-BÁSICOS-EM-C/TREINANDO-STRING>) | Cadastro e login de usuário |
| [Treinando Struct](<PROJETOS-BÁSICOS-EM-C/TREINANDO-STRUCT>) | Cadastro de pessoas com structs |

### 📁 Projetos Intermediários em C
Evolução de um único sistema de PDV (Ponto de Venda), em três etapas.

| Projeto | Descrição |
|---|---|
| [PDV - Inicial](<PROJETOS-INTERMEDIÁRIOS-EM-C/PROJETO PDV - INICIAL>) | Primeira versão: catálogo fixo, sem persistência |
| [PDV - Em Desenvolvimento](<PROJETOS-INTERMEDIÁRIOS-EM-C/PROJETO PDV - EM DESENVOLVIMENTO>) | Cadastro dinâmico de produtos, alocação de memória |
| [PDV - Final](<PROJETOS-INTERMEDIÁRIOS-EM-C/PROJETO PDV - FINAL>) | Sistema completo com login, persistência em arquivo e relatórios |

### 📁 Projetos Médios em C
Projetos com lógica de jogo/sistema um pouco mais elaborada.

| Projeto | Descrição |
|---|---|
| [Quiz](<PROJETOS-MÉDIOS-EM-C/QUIZ>) | Quiz de múltipla escolha sobre C, com nota final |
| [Ranking](<PROJETOS-MÉDIOS-EM-C/RANKING>) | Quiz multiplayer com ranking ordenado por pontuação |
| [Verificação de Iguais](<PROJETOS-MÉDIOS-EM-C/VERIFICAÇÃO-DE-IGUAIS>) | Detecção de IDs duplicados entre duas listas |

## Como compilar os projetos

Todos os projetos usam apenas a biblioteca padrão C (mais `windows.h`/`conio.h` em alguns casos, específicos do Windows). Para compilar qualquer um deles:

```bash
gcc main.c -o nome_do_programa
./nome_do_programa
```

> A maioria dos projetos usa `system("cls")` para limpar a tela, o que só funciona no Windows. Para rodar em Linux/macOS, troque por `system("clear")`.
