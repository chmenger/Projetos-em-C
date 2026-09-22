# PDV — Versão Final

Versão completa do sistema de Ponto de Venda (PDV) "Mercado Bom Jesus", com persistência em arquivos, autenticação de usuários e relatórios — o projeto em C mais completo deste repositório.

## Funcionalidades

- **Login com dois níveis de acesso:** ADM (acessa o CPD) e Operador (acessa o PDV), com usuário administrador padrão criado automaticamente na primeira execução.
- **Senha mascarada** durante a digitação (`*`), usando leitura customizada de caractere por caractere.
- **Hash de senha** (função hash própria, para fins didáticos — não é criptografia de nível de produção).
- **Gestão de produtos:** cadastro, listagem, edição e exclusão (individual ou total), com setor (Alimentos, Bebidas, Limpeza, Higiene, Outros) e status (ativo/inativo).
- **Gestão de usuários:** cadastro, listagem, edição, exclusão, com proteção especial para o usuário ADM padrão (ID 1).
- **Abertura e fechamento de caixa**, com detecção de divergência entre o saldo esperado e o valor informado no fechamento.
- **Fluxo de venda completo:** seleção de produtos, controle de estoque em tempo real, resumo da venda antes de confirmar.
- **Persistência em arquivos `.txt`:** `produtos.txt`, `usuarios.txt`, `vendas.txt`, `itens_venda.txt` e `caixas.txt` — os dados sobrevivem ao fechar o programa.
- **Relatórios:** relatório geral de vendas, relatório por operador e relatório de produtos vendidos (estoque).

## Conceitos praticados

- Manipulação de arquivos (`fopen`, `fscanf`, `fprintf`, `fclose`) como forma de persistência de dados.
- `struct` para modelar Produto, Usuário, Venda e ItemVenda.
- Funções auxiliares reutilizáveis (validação genérica por tipo, leitura de texto, hash de senha).
- Organização do código em módulos lógicos (auxiliares, arquivos, login, menus, CPD, PDV, relatórios) usando comentários de seção.
- Uso de `conio.h` para leitura de senha sem eco no terminal.

## Como compilar e executar

```bash
gcc main.c -o pdv_final
./pdv_final
```

Login padrão criado automaticamente na primeira execução:
- **Usuário:** ADMINSTRADOR
- **Senha:** 1234

> **Atenção:** este projeto depende de `windows.h` e `conio.h`, então só compila/roda nativamente no Windows. Para rodar em Linux/macOS seria necessário substituir `system("cls")` por `system("clear")` e reimplementar `lerSenha` sem `conio.h` (por exemplo, usando `termios.h`).

> A função de hash de senha é uma implementação própria simples, feita para fins de aprendizado — não deve ser usada como está em um sistema real de produção (o ideal seria uma biblioteca de hash criptográfico, como bcrypt ou SHA-256 de uma lib confiável).
