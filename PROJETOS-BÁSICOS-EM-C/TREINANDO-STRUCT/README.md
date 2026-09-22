# Treinando Struct — Cadastro de Pessoas

Sistema de cadastro de pessoas usando `struct`, com listagem e busca por sobrenome.

## Funcionalidades

- Cadastro de nome, sobrenome, idade e sexo (com validação de M/F).
- Montagem automática do nome completo a partir de nome + sobrenome.
- Listagem de todas as pessoas cadastradas em formato de tabela.
- Busca por sobrenome (funcionalidade em desenvolvimento).

## Conceitos praticados

- `struct` e vetores de `struct`.
- Manipulação de strings (`strcpy`, `strcat`, `strcspn`).
- Validação de entrada (idade, sexo).

## Como compilar e executar

```bash
gcc main.c -o cadastro_pessoas
./cadastro_pessoas
```

> **Observação:** a opção "3. Buscar sobrenome" ainda não está funcional — a variável `achou` nunca é atualizada com o resultado real da busca, então o `strcmp` dentro do loop não gera o efeito esperado na mensagem final. É um bom próximo passo para fechar essa funcionalidade.
