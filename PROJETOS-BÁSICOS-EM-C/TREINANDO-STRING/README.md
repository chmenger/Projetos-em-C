# Treinando Strings — Cadastro e Login

Sistema simples de cadastro de usuário e senha, com validação de força de senha.

## Funcionalidades

- Cadastro de usuário e senha via `fgets`.
- Validação: a senha precisa ter no mínimo 8 caracteres e não pode ser igual ao usuário.
- Login simples que confirma se há um cadastro ativo na sessão.

## Conceitos praticados

- Manipulação de strings (`fgets`, `strcmp`, `strlen`, `strcspn`).
- Estruturas de repetição aninhadas para validação de entrada.

## Como compilar e executar

```bash
gcc main.c -o cadastro_login
./cadastro_login
```

> **Observação de segurança:** a senha é armazenada e comparada em texto puro (sem hash), o que é aceitável para fins didáticos, mas não deve ser replicado em um sistema real. Requer `windows.h` (Windows).
