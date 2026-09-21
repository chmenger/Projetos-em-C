// BIBLIOTECAS
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #include <conio.h>
    #include <ctype.h>
    #include <windows.h>
// ARQUIVOS
    #define ARQ_PRODUTOS    "produtos.txt"
    #define ARQ_USUARIOS    "usuarios.txt"
    #define ARQ_VENDAS      "vendas.txt"
    #define ARQ_ITENS_VENDA "itens_venda.txt"
    #define ARQ_CAIXAS      "caixas.txt"
// FUNÇÃO VALIDAR
    #define TIPO_INT   1
    #define TIPO_FLOAT 2
    #define COM_MAX 1
    #define SEM_MAX 0
// STATUS
    #define ATIVO 1
    #define INATIVO 0
//NÍVEIS
    #define NIVEL_ADM 1
    #define NIVEL_OPERADOR 2
// SETORES
    #define SETOR_ALIMENTOS 1
    #define SETOR_BEBIDAS   2
    #define SETOR_LIMPEZA   3
    #define SETOR_HIGIENE   4
    #define SETOR_OUTROS    5

#define MAX_ITENS_VENDA 100

// ESTRUTURAS
    typedef struct{ // PRODUTO
        int id;
        char nome[100];
        float preco;
        int tipo;
        int quantidade;
        int ativo;
    } Produto;
    typedef struct{ // USUARIO
        int id;
        char nome[100];
        char hashSenha[65];
        int nivel;
        int ativo;
    } Usuario;
    typedef struct{ // ITEM VENDA
        int idProduto;
        char nomeProduto[100];
        float precoUnitario;
        int quantidade;
        float subtotal;
    } ItemVenda;
    typedef struct{ // VENDA
        int idVenda;
        char operador[100];
        ItemVenda itens[MAX_ITENS_VENDA];
        int totalItens;
        float valorTotal;
        char data[11];
        char hora[9];
    } Venda;

// VARIAVEIS GLOBAIS
    int caixa_aberto = 0;
    float valor_abertura = 0;
    float total_vendas_caixa = 0;

    int usuarioAutenticado = 0;
    int idLogado = 0;
    char nomeLogado[100] = "";
    int nivelLogado = 0;

// FUNÇÕES AUXILIARES
    void limparTela(void);
    void pausar(void);
    void limparBuffer(void);
    void validar(void *valor, float min, float max, int usarMax, int tipo);
    void lerTexto(char texto[], int tamanho);
    void lerSenha(char *senha, int tamanho);
    void maiusculo(char texto[]);
    void obterDataHora(char data[], char hora[]);
    void gerarHashSenha(const char senha[], char hash[65]);
// MANIPULAR ARQUIVOS
    int arquivoExiste(const char nomeArquivo[]);
    int contarUsuarios(void);
    int gerarProximoIdUsuario(void);
    int gerarProximoIdProduto(void);
    int gerarProximoIdVenda(void);
// LOGIN
    void inicializarAdminPadrao(void);
    int login(int exigirAdm);
    void logout(void);
// MENUS
    void menuInicial(void);
    void menuPDV(void);
    void menuCPD(void);
// CPD
    void gerenciarProdutos(void);
    void gerenciarUsuarios(void);
    void gerenciarRelatorios(void);
// MANIPULAR PRODUTOS
    void listarProdutos(int mostrarInativos);
    void cadastrarProduto(void);
    int buscarProdutoPorId(int id, Produto *produtoEncontrado);
    void salvarTodosProdutos(Produto produtos[], int total);
    int carregarProdutos(Produto produtos[], int maximo);
    void editarProduto(void);
    void deletarProduto(void);
    void deletarTodosProdutos(void);
    const char *nomeSetor(int tipo);
// MANIPULAR USUARIOS
    void listarUsuarios(int mostrarInativos);
    void cadastrarUsuario(void);
    int buscarUsuarioPorId(int id, Usuario *usuarioEncontrado);
    void salvarTodosUsuarios(Usuario usuarios[], int total);
    int carregarUsuarios(Usuario usuarios[], int maximo);
    void editarUsuario(void);
    void deletarUsuario(void);
    void deletarTodosUsuariosExcetoAdm(void);
    const char *nomeNivel(int nivel);
// PDV
    void abrirCaixa(void);
    void fecharCaixa(void);
    void iniciarVenda(void);
    void salvarVenda(Venda venda);
    void atualizarEstoqueProduto(int idProduto, int quantidadeVendida);
// RELATORIOS
    void relatorioGeral(void);
    void relatorioOperador(void);
    void relatorioEstoque(void);
// MAIN
int main(void){
    SetConsoleOutputCP(65001);
    inicializarAdminPadrao();
    menuInicial();
    return 0;
}

// CRIANDO FUNÇÕES
void limparTela(void){
    system("cls");
}
void pausar(void){
    printf("\nPressione Enter para continuar...");
    getchar();
}
void limparBuffer(void){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
void validar(void *valor, float min, float max, int usarMax, int tipo){
    char entrada[100];
    char extra;
    int inteiro;
    float decimal;

    while(1){
        if(fgets(entrada, sizeof(entrada), stdin) == NULL){
            printf("\nENTRADA INVALIDA! DIGITE NOVAMENTE: ");
            continue;
        }

        if(tipo == TIPO_INT){
            if(sscanf(entrada, "%d %c", &inteiro, &extra) != 1){
                printf("\nENTRADA INVALIDA! DIGITE APENAS NUMEROS INTEIROS: ");
                continue;
            }

            if(inteiro < (int)min || (usarMax && inteiro > (int)max)){
                if(usarMax){
                    printf("\nENTRADA INVALIDA! DIGITE UM VALOR ENTRE %d E %d: ", (int)min, (int)max);
                }else{
                    printf("\nENTRADA INVALIDA! DIGITE UM VALOR MAIOR OU IGUAL A %d: ", (int)min);
                }
                continue;
            }

            *(int *)valor = inteiro;
            return;
        }

        if(sscanf(entrada, "%f %c", &decimal, &extra) != 1){
            printf("\nENTRADA INVALIDA! DIGITE APENAS NUMEROS: ");
            continue;
        }

        if(decimal < min || (usarMax && decimal > max)){
            if(usarMax){
                printf("\nENTRADA INVALIDA! DIGITE UM VALOR ENTRE %.2f E %.2f: ", min, max);
            }else{
                printf("\nENTRADA INVALIDA! DIGITE UM VALOR MAIOR OU IGUAL A %.2f: ", min);
            }
            continue;
        }

        *(float *)valor = decimal;
        return;
    }
}
void lerTexto(char texto[], int tamanho){
    fgets(texto, tamanho, stdin);
    texto[strcspn(texto, "\n")] = '\0';
}
void lerSenha(char *senha, int tamanho) {
    int i = 0;
    char c;

    while(1){
        c = _getch();

        if(c == 13){
            break;
        }

        if(c == 8){
            if(i > 0){
                i--;
                printf("\b \b");
            }
            continue;
        }

        if(i < tamanho - 1){
            senha[i++] = c;
            printf("*");
        }
    }

    senha[i] = '\0';
    printf("\n");
}
void maiusculo(char texto[]){
    int i;

    for(i = 0; texto[i] != '\0'; i++){
        texto[i] = toupper((unsigned char)texto[i]);
    }
}
void obterDataHora(char data[], char hora[]){
    time_t agora = time(NULL);
    struct tm *info = localtime(&agora);

    strftime(data, 11, "%d/%m/%Y", info);
    strftime(hora, 9, "%H:%M:%S", info);
}
void gerarHashSenha(const char senha[], char hash[65]){
    // Hash demonstrativo
    unsigned long h1 = 2166136261u;
    unsigned long h2 = 5381u;
    unsigned long h3 = 1315423911u;
    unsigned long h4 = 0x9e3779b9u;
    int i;

    for(i = 0; senha[i] != '\0'; i++){
        unsigned char c = (unsigned char)senha[i];
        h1 = (h1 ^ c) * 16777619u;
        h2 = ((h2 << 5) + h2) + c;
        h3 ^= ((h3 << 5) + c + (h3 >> 2));
        h4 += c + (h4 << 6) + (h4 >> 2);
    }

    sprintf(hash, "%08lx%08lx%08lx%08lx%08lx%08lx%08lx%08lx",
            h1 & 0xffffffffu,
            h2 & 0xffffffffu,
            h3 & 0xffffffffu,
            h4 & 0xffffffffu,
            (h1 ^ h3) & 0xffffffffu,
            (h2 ^ h4) & 0xffffffffu,
            (h1 + h2) & 0xffffffffu,
            (h3 + h4) & 0xffffffffu);
    hash[64] = '\0';
}

int arquivoExiste(const char nomeArquivo[]){
    FILE *arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        return 0;
    }
    fclose(arquivo);
    return 1;
}
int contarUsuarios(void){
    FILE *arquivo = fopen(ARQ_USUARIOS, "r");
    Usuario usuario;
    int total = 0;

    if(arquivo == NULL){
        return 0;
    }

    while(fscanf(arquivo, "%d;%99[^;];%64[^;];%d;%d\n",
                 &usuario.id, usuario.nome, usuario.hashSenha,
                 &usuario.nivel, &usuario.ativo) == 5){
        total++;
    }

    fclose(arquivo);
    return total;
}
int gerarProximoIdUsuario(void){
    FILE *arquivo = fopen(ARQ_USUARIOS, "r");
    Usuario usuario;
    int maiorId = 0;

    if(arquivo == NULL){
        return 1;
    }

    while(fscanf(arquivo, "%d;%99[^;];%64[^;];%d;%d\n",
                 &usuario.id, usuario.nome, usuario.hashSenha,
                 &usuario.nivel, &usuario.ativo) == 5){
        if(usuario.id > maiorId){
            maiorId = usuario.id;
        }
    }

    fclose(arquivo);
    return maiorId + 1;
}
int gerarProximoIdProduto(void){
    FILE *arquivo = fopen(ARQ_PRODUTOS, "r");
    Produto produto;
    int maiorId = 0;

    if(arquivo == NULL){
        return 1;
    }

    while(fscanf(arquivo, "%d;%99[^;];%f;%d;%d;%d\n",
                 &produto.id, produto.nome, &produto.preco,
                 &produto.tipo, &produto.quantidade, &produto.ativo) == 6){
        if(produto.id > maiorId){
            maiorId = produto.id;
        }
    }

    fclose(arquivo);
    return maiorId + 1;
}
int gerarProximoIdVenda(void){
    FILE *arquivo = fopen(ARQ_VENDAS, "r");
    Venda venda;
    int maiorId = 0;

    if(arquivo == NULL){
        return 1;
    }

    while(fscanf(arquivo, "%d;%99[^;];%f;%10[^;];%8[^\n]\n",
                 &venda.idVenda, venda.operador, &venda.valorTotal,
                 venda.data, venda.hora) == 5){
        if(venda.idVenda > maiorId){
            maiorId = venda.idVenda;
        }
    }

    fclose(arquivo);
    return maiorId + 1;
}

void inicializarAdminPadrao(void){
    FILE *arquivo;
    char hash[65];

    if(contarUsuarios() > 0){
        return;
    }

    gerarHashSenha("1234", hash);
    arquivo = fopen(ARQ_USUARIOS, "w");

    if(arquivo == NULL){
        printf("Erro ao criar arquivo de usuarios.\n");
        exit(1);
    }

    fprintf(arquivo, "1;ADMINSTRADOR;%s;1;1\n", hash);
    fclose(arquivo);
}
int login(int exigirAdm){
    FILE *arquivo = fopen(ARQ_USUARIOS, "r");
    Usuario usuario;
    char nome[100];
    char senha[100];
    char hashDigitado[65];
    int encontrou = 0;

    if(arquivo == NULL){
        printf("\nArquivo de usuarios nao encontrado.\n");
        pausar();
        return 0;
    }

    limparTela();
    printf("\n╔═══════════════════════════════════╗");
    printf("\n║              LOGIN                ║");
    printf("\n╚═══════════════════════════════════╝\n");
    printf("\n  ► Usuário: ");
    lerTexto(nome, sizeof(nome));
    maiusculo(nome);
    printf("\n  ► Senha: ");
    lerSenha(senha, sizeof(senha));

    gerarHashSenha(senha, hashDigitado);

    while(fscanf(arquivo, "%d;%99[^;];%64[^;];%d;%d\n",
                 &usuario.id, usuario.nome, usuario.hashSenha,
                 &usuario.nivel, &usuario.ativo) == 5){
        if(strcmp(usuario.nome, nome) == 0 &&
           strcmp(usuario.hashSenha, hashDigitado) == 0 &&
           usuario.ativo == ATIVO){

            if(exigirAdm && usuario.nivel != NIVEL_ADM){
                fclose(arquivo);
                printf("\nAcesso negado. Esta area e somente para ADM.\n");
                pausar();
                return 0;
            }

            usuarioAutenticado = 1;
            idLogado = usuario.id;
            strcpy(nomeLogado, usuario.nome);
            nivelLogado = usuario.nivel;
            encontrou = 1;
            break;
        }
    }

    fclose(arquivo);

    if(!encontrou){
        printf("\nUsuario ou senha invalidos.\n");
        pausar();
        return 0;
    }

    return 1;
}
void logout(void){
    usuarioAutenticado = 0;
    idLogado = 0;
    nomeLogado[0] = '\0';
    nivelLogado = 0;
}

void menuInicial(void){
    int opcao;

    do{
        limparTela();
        printf("\n╔═══════════════════════════════════╗");
        printf("\n║   MERCADO BOM JESUS - BY OPTIMUS  ║");
        printf("\n╠═══════════════════════════════════╣");
        printf("\n║  [1] Acessar PDV                  ║");
        printf("\n║  [2] Acessar CPD                  ║");
        printf("\n║  [0] Sair                         ║");
        printf("\n╚═══════════════════════════════════╝\n");
        printf("\n  ► Escolha uma opção: ");
        validar(&opcao, 0, 2, COM_MAX, TIPO_INT);

        switch(opcao){
            case 1:
                if(login(0)){
                    menuPDV();
                    logout();
                }
                break;
            case 2:
                if(login(1)){
                    menuCPD();
                    logout();
                }
                break;
            case 0:
                printf("\nEncerrando sistema...\n");
                break;
        }
    }while(opcao != 0);
}
void menuPDV(void){
    int opcao;

    do{
        limparTela();
        printf("\n╔═══════════════════════════════════╗");
        printf("\n║             MENU  PDV             ║");
        printf("\n╚═══════════════════════════════════╝\n");
        printf("\n  ► Operador: %s", nomeLogado);
        printf("\n  ► Caixa: %s", caixa_aberto ? "ABERTO" : "FECHADO");
        printf("\n\n╔═══════════════════════════════════╗");
        printf("\n║  [1] Abrir Caixa                  ║");
        printf("\n║  [2] Fechar Caixa                 ║");
        printf("\n║  [3] Iniciar Venda                ║");
        printf("\n║  [0] Voltar                       ║");
        printf("\n╚═══════════════════════════════════╝\n");
        printf("\n  ► Escolha uma opção: ");
        validar(&opcao, 0, 3, COM_MAX, TIPO_INT);

        switch(opcao){
            case 1:
                abrirCaixa();
                break;
            case 2:
                fecharCaixa();
                break;
            case 3:
                iniciarVenda();
                break;
            case 0:
                if(caixa_aberto){
                    printf("\nFeche o caixa antes de voltar ao menu inicial.\n");
                    pausar();
                    opcao = -1;
                }
                break;
        }
    }while(opcao != 0);
}
void menuCPD(void){
    int opcao;

    do{
        limparTela();
        printf("\n╔═══════════════════════════════════╗");
        printf("\n║             MENU  CPD             ║");
        printf("\n╚═══════════════════════════════════╝\n");
        printf("\n  ► ADM: %s", nomeLogado);
        printf("\n\n╔═══════════════════════════════════╗");
        printf("\n║  [1] Gerenciar Produtos           ║");
        printf("\n║  [2] Gerenciar Usuários           ║");
        printf("\n║  [3] Gerenciar Relatórios         ║");
        printf("\n║  [0] Voltar                       ║");
        printf("\n╚═══════════════════════════════════╝\n");
        printf("\n  ► Escolha uma opção: ");
        validar(&opcao, 0, 3, COM_MAX, TIPO_INT);

        switch(opcao){
            case 1:
                gerenciarProdutos();
                break;
            case 2:
                gerenciarUsuarios();
                break;
            case 3:
                gerenciarRelatorios();
                break;
        }
    }while(opcao != 0);
}

void gerenciarProdutos(void){
    int opcao;

    do{
        limparTela();
        printf("\n╔═══════════════════════════════════╗");
        printf("\n║     GERENCIAMENTO DE PRODUTOS     ║");
        printf("\n╠═══════════════════════════════════╣");
        printf("\n║  [1] Ver produtos cadastrados     ║");
        printf("\n║  [2] Cadastrar produto            ║");
        printf("\n║  [3] Editar produto               ║");
        printf("\n║  [4] Deletar produto              ║");
        printf("\n║  [5] Deletar todos os produtos    ║");
        printf("\n║  [0] Voltar                       ║");
        printf("\n╚═══════════════════════════════════╝\n");
        printf("\n  ► Escolha uma opção: ");
        validar(&opcao, 0, 5, COM_MAX, TIPO_INT);

        switch(opcao){
            case 1:
                listarProdutos(1);
                pausar();
                break;
            case 2:
                cadastrarProduto();
                break;
            case 3:
                editarProduto();
                break;
            case 4:
                deletarProduto();
                break;
            case 5:
                deletarTodosProdutos();
                break;
        }
    }while(opcao != 0);
}
void gerenciarUsuarios(void){
    int opcao;

    do{
        limparTela();
        printf("\n╔═══════════════════════════════════╗");
        printf("\n║     GERENCIAMENTO DE USUÁRIOS     ║");
        printf("\n╠═══════════════════════════════════╣");
        printf("\n║  [1] Ver usuários cadastrados     ║");
        printf("\n║  [2] Cadastrar usuário            ║");
        printf("\n║  [3] Editar usuário               ║");
        printf("\n║  [4] Deletar usuário              ║");
        printf("\n║  [5] Deletar todos os usuários    ║");
        printf("\n║  [0] Voltar                       ║");
        printf("\n╚═══════════════════════════════════╝\n");
        printf("\n  ► Escolha uma opção: ");
        validar(&opcao, 0, 5, COM_MAX, TIPO_INT);

        switch(opcao){
            case 1:
                listarUsuarios(1);
                pausar();
                break;
            case 2:
                cadastrarUsuario();
                break;
            case 3:
                editarUsuario();
                break;
            case 4:
                deletarUsuario();
                break;
            case 5:
                deletarTodosUsuariosExcetoAdm();
                break;
        }
    }while(opcao != 0);
}
void gerenciarRelatorios(void){
    int opcao;

    do{
        limparTela();
        printf("\n╔═══════════════════════════════════╗");
        printf("\n║    GERENCIAMENTO DE RELATÓRIOS    ║");
        printf("\n╠═══════════════════════════════════╣");
        printf("\n║  [1] Relatório geral de vendas    ║");
        printf("\n║  [2] Relatório de operador        ║");
        printf("\n║  [3] Relatório de estoque         ║");
        printf("\n║  [0] Voltar                       ║");
        printf("\n╚═══════════════════════════════════╝\n");
        printf("\n  ► Escolha uma opção: ");
        validar(&opcao, 0, 3, COM_MAX, TIPO_INT);

        switch(opcao){
            case 1:
                relatorioGeral();
                break;
            case 2:
                relatorioOperador();
                break;
            case 3:
                relatorioEstoque();
                break;
        }
    }while(opcao != 0);
}

const char *nomeSetor(int tipo){
        switch(tipo){
            case SETOR_ALIMENTOS: return "Alimentos";
            case SETOR_BEBIDAS: return "Bebidas";
            case SETOR_LIMPEZA: return "Limpeza";
            case SETOR_HIGIENE: return "Higiene";
            default: return "Outros";
        }
    }
void listarProdutos(int mostrarInativos){
    FILE *arquivo = fopen(ARQ_PRODUTOS, "r");
    Produto produto;
    int encontrou = 0;

    limparTela();
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗");
    printf("\n║                                   PRODUTOS                                    ║");
    printf("\n╠════╦════════════════════════╦════════════╦════════════╦══════════╦════════════╣");
    printf("\n║ ID ║ Nome                   ║ Preço      ║ Setor      ║ Estoque  ║ Status     ║");
    printf("\n╠════╬════════════════════════╬════════════╬════════════╬══════════╬════════════╣");

    if(arquivo == NULL){
        printf("\n╠════╩════════════════════════╩════════════╩════════════╩══════════╩════════════╣");
        printf("\n║ Nenhum produto cadastrado.                                                    ║");
        printf("\n╚═══════════════════════════════════════════════════════════════════════════════╝\n");
        pausar();
        return;
    }

    while(fscanf(arquivo, "%d;%99[^;];%f;%d;%d;%d\n",
                 &produto.id, produto.nome, &produto.preco,
                 &produto.tipo, &produto.quantidade, &produto.ativo) == 6){

        if(mostrarInativos || produto.ativo == ATIVO){
            printf("\n║ %-2d ║ %-22s ║ %-10.2f ║ %-10s ║ %-8d ║ %-10s ║",
                   produto.id,
                   produto.nome,
                   produto.preco,
                   nomeSetor(produto.tipo),
                   produto.quantidade,
                   produto.ativo ? "ATIVO" : "INATIVO");

            encontrou = 1;
        }
    }

    if(!encontrou){
        printf("\n╠════╩════════════════════════╩════════════╩════════════╩══════════╩════════════╣");
        printf("\n║ Nenhum produto encontrado.                                                    ║");
        printf("\n╠════╦════════════════════════╦════════════╦════════════╦══════════╦════════════╣");
    }
    printf("\n╚════╩════════════════════════╩════════════╩════════════╩══════════╩════════════╝\n");

    fclose(arquivo);
}
void cadastrarProduto(void){
        FILE *arquivo = fopen(ARQ_PRODUTOS, "a");
        Produto produto;

        if(arquivo == NULL){
            printf("\nErro ao abrir arquivo de produtos.\n");
            pausar();
            return;
        }

        limparTela();
        printf("\n╔═══════════════════════════════════╗");
        printf("\n║      CADASTRANDO NOVO PRODUTO     ║");
        printf("\n╚═══════════════════════════════════╝\n");
        produto.id = gerarProximoIdProduto();
        printf("\n  ► Nome: ");
        lerTexto(produto.nome, sizeof(produto.nome));
        maiusculo(produto.nome);
        printf("\n  ► Preco: ");
        validar(&produto.preco, 0.01, 0, SEM_MAX, TIPO_FLOAT);
        printf("\n  ► Setor (1-Alimentos, 2-Bebidas, 3-Limpeza, 4-Higiene, 5-Outros): ");
        validar(&produto.tipo, 1, 5, COM_MAX, TIPO_INT);
        printf("\n  ► Quantidade em estoque: ");
        validar(&produto.quantidade, 0, 0, SEM_MAX, TIPO_INT);
        produto.ativo = ATIVO;

        fprintf(arquivo, "%d;%s;%.2f;%d;%d;%d\n",
                produto.id, produto.nome, produto.preco,
                produto.tipo, produto.quantidade, produto.ativo);

        fclose(arquivo);
        printf("\nProduto cadastrado com sucesso.\n");
        pausar();
    }
int carregarProdutos(Produto produtos[], int maximo){
        FILE *arquivo = fopen(ARQ_PRODUTOS, "r");
        int total = 0;

        if(arquivo == NULL){
            return 0;
        }

        while(total < maximo &&
              fscanf(arquivo, "%d;%99[^;];%f;%d;%d;%d\n",
                     &produtos[total].id, produtos[total].nome, &produtos[total].preco,
                     &produtos[total].tipo, &produtos[total].quantidade, &produtos[total].ativo) == 6){
            total++;
        }

        fclose(arquivo);
        return total;
    }
void salvarTodosProdutos(Produto produtos[], int total){
        FILE *arquivo = fopen(ARQ_PRODUTOS, "w");
        int i;

        if(arquivo == NULL){
            printf("\nErro ao salvar produtos.\n");
            return;
        }

        for(i = 0; i < total; i++){
            fprintf(arquivo, "%d;%s;%.2f;%d;%d;%d\n",
                    produtos[i].id, produtos[i].nome, produtos[i].preco,
                    produtos[i].tipo, produtos[i].quantidade, produtos[i].ativo);
        }

        fclose(arquivo);
    }
int buscarProdutoPorId(int id, Produto *produtoEncontrado){
        FILE *arquivo = fopen(ARQ_PRODUTOS, "r");
        Produto produto;

        if(arquivo == NULL){
            return 0;
        }

        while(fscanf(arquivo, "%d;%99[^;];%f;%d;%d;%d\n",
                     &produto.id, produto.nome, &produto.preco,
                     &produto.tipo, &produto.quantidade, &produto.ativo) == 6){
            if(produto.id == id){
                *produtoEncontrado = produto;
                fclose(arquivo);
                return 1;
            }
        }

        fclose(arquivo);
        return 0;
    }
void editarProduto(void){
        Produto produtos[1000];
        int total = carregarProdutos(produtos, 1000);
        int id, opcao, i, pos = -1;

        listarProdutos(1);
        printf("\n  ► ID do produto para editar: ");
        validar(&id, 1, 0, SEM_MAX, TIPO_INT);

        for(i = 0; i < total; i++){
            if(produtos[i].id == id){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            printf("\nProduto nao encontrado.\n");
            pausar();
            return;
        }

        do{
            limparTela();
            printf("\n╔═══════════════════════════════════╗");
            printf("\n║         EDIÇÃO DE PRODUTO         ║");
            printf("\n╚═══════════════════════════════════╝");
            printf("\n  ► Produto: %s", produtos[pos].nome);
            printf("\n╔═══════════════════════════════════╗");
            printf("\n║  [1] Editar Nome                  ║");
            printf("\n║  [2] Editar Preço                 ║");
            printf("\n║  [3] Editar Setor                 ║");
            printf("\n║  [4] Editar Quantidade            ║");
            printf("\n║  [5] Editar Status                ║");
            printf("\n║  [0] Voltar                       ║");
            printf("\n╚═══════════════════════════════════╝\n");
            printf("\n  ► Escolha uma opção: ");
            validar(&opcao, 0, 5, COM_MAX, TIPO_INT);

            switch(opcao){
                case 1:
                    printf("\n  ► Novo Nome: ");
                    lerTexto(produtos[pos].nome, sizeof(produtos[pos].nome));
                    maiusculo(produtos[pos].nome);
                    break;
                case 2:
                    printf("\n  ► Novo Preço: ");
                    validar(&produtos[pos].preco, 0.01, 0, SEM_MAX, TIPO_FLOAT);
                    break;
                case 3:
                    printf("\n  ► Novo Setor (1-Alimentos, 2-Bebidas, 3-Limpeza, 4-Higiene, 5-Outros): ");
                    validar(&produtos[pos].tipo, 1, 5, COM_MAX, TIPO_INT);
                    break;
                case 4:
                    printf("\n  ► Nova Quantidade: ");
                    validar(&produtos[pos].quantidade, 0, 0, SEM_MAX, TIPO_INT);
                    break;
                case 5:
                    printf("\n  ► Status (1-Ativo, 0-Inativo): ");
                    validar(&produtos[pos].ativo, 0, 1, COM_MAX, TIPO_INT);
                    break;
            }

            if(opcao != 0){
                salvarTodosProdutos(produtos, total);
                printf("\nProduto atualizado.\n");
                pausar();
            }
        }while(opcao != 0);
    }
void deletarProduto(void){
        Produto produtos[1000];
        int total = carregarProdutos(produtos, 1000);
        int id, i, j, encontrou = 0;

        listarProdutos(1);
        printf("\n  ► ID do produto para deletar: ");
        validar(&id, 1, 0, SEM_MAX, TIPO_INT);

        for(i = 0; i < total; i++){
            if(produtos[i].id == id){
                for(j = i; j < total - 1; j++){
                    produtos[j] = produtos[j + 1];
                }
                total--;
                encontrou = 1;
                break;
            }
        }

        if(encontrou){
            salvarTodosProdutos(produtos, total);
            printf("\nProduto deletado.\n");
        }else{
            printf("\nProduto nao encontrado.\n");
        }

        pausar();
    }
void deletarTodosProdutos(void){
        FILE *arquivo;
        int confirmar;

        printf("\nTem certeza? Isso apaga todos os produtos. Digite 1 para confirmar: ");
        validar(&confirmar, 0, 1, COM_MAX, TIPO_INT);

        if(confirmar != 1){
            printf("\nOperacao cancelada.\n");
            pausar();
            return;
        }

        arquivo = fopen(ARQ_PRODUTOS, "w");
        if(arquivo != NULL){
            fclose(arquivo);
        }

        printf("\nTodos os produtos foram deletados.\n");
        pausar();
    }

const char *nomeNivel(int nivel){
        return nivel == NIVEL_ADM ? "ADM" : "OPERADOR";
    }
void listarUsuarios(int mostrarInativos){
    FILE *arquivo = fopen(ARQ_USUARIOS, "r");
    Usuario usuario;
    int encontrou = 0;

    limparTela();
    printf("\n╔═════════════════════════════════════════════════╗");
    printf("\n║                   USUÁRIOS                      ║");
    printf("\n╠════╦════════════════════╦══════════╦════════════╣");
    printf("\n║ ID ║ Nome               ║ Nível    ║ Status     ║");
    printf("\n╠════╬════════════════════╬══════════╬════════════╣");

    if(arquivo == NULL){
        printf("\n╠════╩════════════════════╩══════════╩════════════╣");
        printf("\n║ Nenhum usuário cadastrado.                      ║");
        printf("\n╚═════════════════════════════════════════════════╝\n");
        pausar();
        return;
    }

    while(fscanf(arquivo, "%d;%99[^;];%64[^;];%d;%d\n",
                 &usuario.id, usuario.nome, usuario.hashSenha,
                 &usuario.nivel, &usuario.ativo) == 5){

        if(mostrarInativos || usuario.ativo == ATIVO){
            printf("\n║ %-2d ║ %-18s ║ %-8s ║ %-10s ║",
                   usuario.id,
                   usuario.nome,
                   nomeNivel(usuario.nivel),
                   usuario.ativo ? "ATIVO" : "INATIVO");

            encontrou = 1;
        }
    }

    if(!encontrou){
        printf("\n╠════╩════════════════════╩══════════╩════════════╣");
        printf("\n║ Nenhum usuário encontrado.                      ║");
        printf("\n╠════╦════════════════════╦══════════╦════════════╣");
    }
    printf("\n╚════╩════════════════════╩══════════╩════════════╝\n");

    fclose(arquivo);
}
void cadastrarUsuario(void){
        FILE *arquivo = fopen(ARQ_USUARIOS, "a");
        Usuario usuario;
        char senha[100];

        if(arquivo == NULL){
            printf("\nErro ao abrir arquivo de usuarios.\n");
            pausar();
            return;
        }

        limparTela();
        printf("\n╔═══════════════════════════════════╗");
        printf("\n║      CADASTRANDO NOVO USUÁRIO     ║");
        printf("\n╚═══════════════════════════════════╝\n");
        usuario.id = gerarProximoIdUsuario();
        printf("\n  ► Nome: ");
        lerTexto(usuario.nome, sizeof(usuario.nome));
        maiusculo(usuario.nome);
        printf("\n  ► Senha: ");
        lerSenha(senha, sizeof(senha));
        gerarHashSenha(senha, usuario.hashSenha);
        printf("\n  ► Nivel (1-ADM, 2-Operador): ");
        validar(&usuario.nivel, 1, 2, COM_MAX, TIPO_INT);
        usuario.ativo = ATIVO;

        fprintf(arquivo, "%d;%s;%s;%d;%d\n",
                usuario.id, usuario.nome, usuario.hashSenha,
                usuario.nivel, usuario.ativo);

        fclose(arquivo);
        printf("\nUsuario cadastrado com sucesso.\n");
        pausar();
    }
int carregarUsuarios(Usuario usuarios[], int maximo){
        FILE *arquivo = fopen(ARQ_USUARIOS, "r");
        int total = 0;

        if(arquivo == NULL){
            return 0;
        }

        while(total < maximo &&
              fscanf(arquivo, "%d;%99[^;];%64[^;];%d;%d\n",
                     &usuarios[total].id, usuarios[total].nome, usuarios[total].hashSenha,
                     &usuarios[total].nivel, &usuarios[total].ativo) == 5){
            total++;
        }

        fclose(arquivo);
        return total;
    }
void salvarTodosUsuarios(Usuario usuarios[], int total){
        FILE *arquivo = fopen(ARQ_USUARIOS, "w");
        int i;

        if(arquivo == NULL){
            printf("\nErro ao salvar usuarios.\n");
            return;
        }

        for(i = 0; i < total; i++){
            fprintf(arquivo, "%d;%s;%s;%d;%d\n",
                    usuarios[i].id, usuarios[i].nome, usuarios[i].hashSenha,
                    usuarios[i].nivel, usuarios[i].ativo);
        }

        fclose(arquivo);
    }
int buscarUsuarioPorId(int id, Usuario *usuarioEncontrado){
        FILE *arquivo = fopen(ARQ_USUARIOS, "r");
        Usuario usuario;

        if(arquivo == NULL){
            return 0;
        }

        while(fscanf(arquivo, "%d;%99[^;];%64[^;];%d;%d\n",
                     &usuario.id, usuario.nome, usuario.hashSenha,
                     &usuario.nivel, &usuario.ativo) == 5){
            if(usuario.id == id){
                *usuarioEncontrado = usuario;
                fclose(arquivo);
                return 1;
            }
        }

        fclose(arquivo);
        return 0;
    }
void editarUsuario(void){
        Usuario usuarios[1000];
        int total = carregarUsuarios(usuarios, 1000);
        int id, opcao, i, pos = -1;
        char senha[100];

        listarUsuarios(1);
        printf("\n  ► ID do usuario para editar: ");
        validar(&id, 1, 0, SEM_MAX, TIPO_INT);

        for(i = 0; i < total; i++){
            if(usuarios[i].id == id){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            printf("\nUsuario nao encontrado.\n");
            pausar();
            return;
        }

        do{
            limparTela();
            printf("\n╔═══════════════════════════════════╗");
            printf("\n║         EDIÇÃO DE USUÁRIO         ║");
            printf("\n╚═══════════════════════════════════╝");
            printf("\n  ► Usuário: %s", usuarios[pos].nome);
            printf("\n╔═══════════════════════════════════╗");
            printf("\n║  [1] Editar Nome                  ║");
            printf("\n║  [2] Editar Senha                 ║");
            printf("\n║  [3] Editar Nível                 ║");
            printf("\n║  [4] Editar Status                ║");
            printf("\n║  [0] Voltar                       ║");
            printf("\n╚═══════════════════════════════════╝\n");
            printf("\n  ► Escolha uma opção: ");
            validar(&opcao, 0, 4, COM_MAX, TIPO_INT);

            switch(opcao){
                case 1:
                    printf("\n  ► Novo Nome: ");
                    lerTexto(usuarios[pos].nome, sizeof(usuarios[pos].nome));
                    maiusculo(usuarios[pos].nome);
                    break;
                case 2:
                    printf("\n  ► Nova Senha: ");
                    lerSenha(senha, sizeof(senha));
                    gerarHashSenha(senha, usuarios[pos].hashSenha);
                    break;
                case 3:
                    printf("\n  ► Nível (1-ADM, 2-Operador): ");
                    validar(&usuarios[pos].nivel, 1, 2, COM_MAX, TIPO_INT);
                    break;
                case 4:
                    if(usuarios[pos].id == 1){
                        printf("\nO ADM ID 1 nao pode ser desativado.\n");
                        pausar();
                        break;
                    }
                    printf("\n  ► Status (1-Ativo, 0-Inativo): ");
                    validar(&usuarios[pos].ativo, 0, 1, COM_MAX, TIPO_INT);
                    break;
            }

            if(opcao != 0){
                salvarTodosUsuarios(usuarios, total);
                printf("\nUsuario atualizado.\n");
                pausar();
            }
        }while(opcao != 0);
    }
void deletarUsuario(void){
        Usuario usuarios[1000];
        int total = carregarUsuarios(usuarios, 1000);
        int id, i, j, encontrou = 0;

        listarUsuarios(1);
        printf("\n  ► ID do usuario para deletar: ");
        validar(&id, 1, 0, SEM_MAX, TIPO_INT);

        if(id == 1){
            printf("\nO ADM ID 1 nao pode ser deletado.\n");
            pausar();
            return;
        }

        for(i = 0; i < total; i++){
            if(usuarios[i].id == id){
                for(j = i; j < total - 1; j++){
                    usuarios[j] = usuarios[j + 1];
                }
                total--;
                encontrou = 1;
                break;
            }
        }

        if(encontrou){
            salvarTodosUsuarios(usuarios, total);
            printf("\nUsuario deletado.\n");
        }else{
            printf("\nUsuario nao encontrado.\n");
        }

        pausar();
    }
void deletarTodosUsuariosExcetoAdm(void){
        Usuario usuarios[1000];
        Usuario mantidos[1000];
        int total = carregarUsuarios(usuarios, 1000);
        int totalMantidos = 0;
        int i, confirmar;

        printf("\nTem certeza? Sera mantido apenas o ADM ID 1. Digite 1 para confirmar: ");
        validar(&confirmar, 0, 1, COM_MAX, TIPO_INT);

        if(confirmar != 1){
            printf("\nOperacao cancelada.\n");
            pausar();
            return;
        }

        for(i = 0; i < total; i++){
            if(usuarios[i].id == 1){
                mantidos[totalMantidos++] = usuarios[i];
            }
        }

        salvarTodosUsuarios(mantidos, totalMantidos);
        printf("\nUsuarios deletados. ADM ID 1 mantido.\n");
        pausar();
    }

void abrirCaixa(void){
    char data[11], hora[9];

    if(caixa_aberto){
        printf("\nO caixa ja esta aberto.\n");
        pausar();
        return;
    }

    limparTela();
        printf("\n╔═══════════════════════════════════╗");
        printf("\n║         ABERTURA DE CAIXA         ║");
        printf("\n╚═══════════════════════════════════╝\n");
    printf("\n  ► Valor de abertura: ");
    validar(&valor_abertura, 0, 0, SEM_MAX, TIPO_FLOAT);

    caixa_aberto = 1;
    total_vendas_caixa = 0;
    obterDataHora(data, hora);

    printf("\nCaixa aberto por %s em %s as %s.\n", nomeLogado, data, hora);
    pausar();
}
void fecharCaixa(void){
    FILE *arquivo;
    char data[11], hora[9];
    float valorFechamento;
    float saldoFinal;

    if(!caixa_aberto){
        printf("\nO caixa ja esta fechado.\n");
        pausar();
        return;
    }

    saldoFinal = valor_abertura + total_vendas_caixa;
    obterDataHora(data, hora);

    limparTela();
    printf("\n╔═══════════════════════════════════╗");
    printf("\n║        FECHAMENTO DE CAIXA        ║");
    printf("\n╚═══════════════════════════════════╝\n");
    printf("\n  ► Operador: %s", nomeLogado);
    printf("\n  ► Valor de abertura: R$ %.2f", valor_abertura);
    printf("\n  ► Total em vendas: R$ %.2f", total_vendas_caixa);
    printf("\n  ► Saldo esperado: R$ %.2f", saldoFinal);
    printf("\n  ► Valor informado no caixa: ");
    validar(&valorFechamento, 0, 0, SEM_MAX, TIPO_FLOAT);

    arquivo = fopen(ARQ_CAIXAS, "a");
    if(arquivo != NULL){
        fprintf(arquivo, "%s;%s;%.2f;%.2f;%.2f;%s;%s\n",
                nomeLogado, data, valor_abertura, total_vendas_caixa, valorFechamento, hora,
                ((valorFechamento - saldoFinal) > 4.99 || (valorFechamento - saldoFinal) < -4.99) ? "DIVERGENCIA" : "OK");
        fclose(arquivo);
    }

    printf("\n  ► Saldo esperado: R$ %.2f", saldoFinal);
    printf("\n  ► Diferenca: R$ %.2f\n", valorFechamento - saldoFinal);

    caixa_aberto = 0;
    valor_abertura = 0;
    total_vendas_caixa = 0;

    pausar();
}
void iniciarVenda(void){
    Venda venda;
    Produto produto;
    int idProduto, quantidade, opcao = 1;

    if(!caixa_aberto){
        printf("\nAbra o caixa antes de iniciar venda.\n");
        pausar();
        return;
    }

    venda.idVenda = gerarProximoIdVenda();
    strcpy(venda.operador, nomeLogado);
    venda.totalItens = 0;
    venda.valorTotal = 0;
    obterDataHora(venda.data, venda.hora);

    do{
        listarProdutos(0);
        printf("\nID do produto (0 para finalizar venda): ");
        validar(&idProduto, 0, 0, SEM_MAX, TIPO_INT);

        if(idProduto == 0){
            break;
        }

        if(!buscarProdutoPorId(idProduto, &produto) || produto.ativo == INATIVO){
            printf("\nProduto nao encontrado ou inativo.\n");
            pausar();
            continue;
        }

        if(produto.quantidade <= 0){
            printf("\nProduto sem estoque.\n");
            pausar();
            continue;
        }

        printf("Quantidade: ");
        validar(&quantidade, 1, produto.quantidade, COM_MAX, TIPO_INT);

        venda.itens[venda.totalItens].idProduto = produto.id;
        strcpy(venda.itens[venda.totalItens].nomeProduto, produto.nome);
        venda.itens[venda.totalItens].precoUnitario = produto.preco;
        venda.itens[venda.totalItens].quantidade = quantidade;
        venda.itens[venda.totalItens].subtotal = produto.preco * quantidade;
        venda.valorTotal += venda.itens[venda.totalItens].subtotal;
        venda.totalItens++;

        printf("\nItem adicionado. Subtotal da venda: R$ %.2f\n", venda.valorTotal);
        printf("1 - Adicionar outro item | 0 - Finalizar venda: ");
        validar(&opcao, 0, 1, COM_MAX, TIPO_INT);
    }while(opcao != 0 && venda.totalItens < MAX_ITENS_VENDA);

    if(venda.totalItens == 0){
        printf("\nVenda cancelada. Nenhum item foi adicionado.\n");
        pausar();
        return;
    }

    limparTela();
    printf("\n╔════════════════════════════════════════════════════════════════════════════╗");
    printf("\n║                               RESUMO DA VENDA                              ║");
    printf("\n╠════════════════════════════════════════════════════════════════════════════╣");
    printf("\n║ Venda Nº: %-5d                                                            ║", venda.idVenda);
    printf("\n║ Operador: %-20s                                             ║", venda.operador);
    printf("\n║ Data: %-10s   Hora: %-8s                                          ║", venda.data, venda.hora);
    printf("\n╠════╦══════════════════════════════╦══════════╦═════════════╦═══════════════╣");
    printf("\n║ ID ║ Produto                      ║ Quant.   ║ Unitário    ║ Subtotal      ║");
    printf("\n╠════╬══════════════════════════════╬══════════╬═════════════╬═══════════════╣");

    for(opcao = 0; opcao < venda.totalItens; opcao++){
        printf("\n║ %-2d ║ %-28s ║ %-8d ║ R$ %-8.2f ║ R$ %-10.2f ║",
               venda.itens[opcao].idProduto,
               venda.itens[opcao].nomeProduto,
               venda.itens[opcao].quantidade,
               venda.itens[opcao].precoUnitario,
               venda.itens[opcao].subtotal);
    }

    printf("\n╠════╩══════════════════════════════╩══════════╩═════════════╩═══════════════╣");
    printf("\n║ TOTAL DA VENDA: R$ %-56.2f║", venda.valorTotal);
    printf("\n╚════════════════════════════════════════════════════════════════════════════╝\n");

    printf("\nConfirmar venda? 1-Sim 0-Nao: ");
    validar(&opcao, 0, 1, COM_MAX, TIPO_INT);

    if(opcao != 1){
        printf("\nVenda cancelada.\n");
        pausar();
        return;
    }

    salvarVenda(venda);

    for(opcao = 0; opcao < venda.totalItens; opcao++){
        atualizarEstoqueProduto(venda.itens[opcao].idProduto, venda.itens[opcao].quantidade);
    }

    total_vendas_caixa += venda.valorTotal;
    printf("\nVenda finalizada com sucesso.\n");
    pausar();
}
void salvarVenda(Venda venda){
    FILE *arquivoVendas = fopen(ARQ_VENDAS, "a");
    FILE *arquivoItens = fopen(ARQ_ITENS_VENDA, "a");
    int i;

    if(arquivoVendas != NULL){
        fprintf(arquivoVendas, "%d;%s;%.2f;%s;%s\n",
                venda.idVenda, venda.operador, venda.valorTotal,
                venda.data, venda.hora);
        fclose(arquivoVendas);
    }

    if(arquivoItens != NULL){
        for(i = 0; i < venda.totalItens; i++){
            fprintf(arquivoItens, "%d;%d;%s;%.2f;%d;%.2f\n",
                    venda.idVenda,
                    venda.itens[i].idProduto,
                    venda.itens[i].nomeProduto,
                    venda.itens[i].precoUnitario,
                    venda.itens[i].quantidade,
                    venda.itens[i].subtotal);
        }
        fclose(arquivoItens);
    }
}
void atualizarEstoqueProduto(int idProduto, int quantidadeVendida){
    Produto produtos[1000];
    int total = carregarProdutos(produtos, 1000);
    int i;

    for(i = 0; i < total; i++){
        if(produtos[i].id == idProduto){
            produtos[i].quantidade -= quantidadeVendida;
            if(produtos[i].quantidade < 0){
                produtos[i].quantidade = 0;
            }
            break;
        }
    }

    salvarTodosProdutos(produtos, total);
}

void relatorioGeral(void){
    FILE *arquivo = fopen(ARQ_VENDAS, "r");
    Venda venda;
    int totalVendas = 0;
    float totalGeral = 0;

    limparTela();
    printf("\n╔════════════════════════════════════════════════════════════════╗");
    printf("\n║                        RELATÓRIO GERAL                         ║");
    printf("\n╠══════╦════════════════════╦══════════════╦═════════════════════╣");
    printf("\n║ ID   ║ Operador           ║ Total        ║ Data/Hora           ║");
    printf("\n╠══════╬════════════════════╬══════════════╬═════════════════════╣");

    if(arquivo == NULL){
        printf("\n╠══════╩════════════════════╩══════════════╩═════════════════════╣");
        printf("\n║ Nenhuma venda registrada.                                      ║");
        printf("\n╚════════════════════════════════════════════════════════════════╝\n");
        pausar();
        return;
    }

    while(fscanf(arquivo, "%d;%99[^;];%f;%10[^;];%8[^\n]\n",
                 &venda.idVenda, venda.operador, &venda.valorTotal,
                 venda.data, venda.hora) == 5){

        printf("\n║ %-4d ║ %-18s ║ %-12.2f ║ %s %s ║",
               venda.idVenda,
               venda.operador,
               venda.valorTotal,
               venda.data,
               venda.hora);
        totalVendas++;
        totalGeral += venda.valorTotal;
    }
    printf("\n╚══════╩════════════════════╩══════════════╩═════════════════════╝\n");
    printf("\n  ► Total de vendas: %d", totalVendas);
    printf("\n  ► Faturamento total: R$ %.2f\n", totalGeral);

    fclose(arquivo);
    pausar();
}
void relatorioOperador(void){
    FILE *arquivo = fopen(ARQ_VENDAS, "r");
    Venda venda;
    char operador[100];
    int totalVendas = 0;
    float totalOperador = 0;

    limparTela();
    printf("\n╔═════════════════════════════════════════════════════════╗");
    printf("\n║                   RELATÓRIO DE OPERADOR                 ║");
    printf("\n╚═════════════════════════════════════════════════════════╝\n");
    printf("\n  ► Nome do operador: ");
    lerTexto(operador, sizeof(operador));
    maiusculo(operador);

    if(arquivo == NULL){
        printf("\nNenhuma venda registrada.\n");
        pausar();
        return;
    }

    printf("\n╔══════╦════════════════════╦══════════════╦═══════════════╗");
    printf("\n║ ID   ║ Data               ║ Hora         ║ Total         ║");
    printf("\n╠══════╬════════════════════╬══════════════╬═══════════════╣");

    while(fscanf(arquivo, "%d;%99[^;];%f;%10[^;];%8[^\n]\n",
                 &venda.idVenda, venda.operador, &venda.valorTotal,
                 venda.data, venda.hora) == 5){
        if(strcmp(venda.operador, operador) == 0){
            printf("\n║ %-4d ║ %-18s ║ %-12s ║ R$ %-10.2f ║",
                   venda.idVenda,
                   venda.data,
                   venda.hora,
                   venda.valorTotal);

            totalVendas++;
            totalOperador += venda.valorTotal;
        }
    }
    printf("\n╠══════╩════════════════════╩══════════════╩═══════════════╣");
    printf("\n║ TOTAL DE VENDAS: %-10d                              ║", totalVendas);
    printf("\n║ TOTAL VENDIDO:   R$ %-12.2f                         ║", totalOperador);
    printf("\n╚══════════════════════════════════════════════════════════╝\n");

    fclose(arquivo);
    pausar();
}
void relatorioEstoque(void){
    FILE *arquivo = fopen(ARQ_ITENS_VENDA, "r");
    int idVenda, idProduto, quantidade;
    char nomeProduto[100];
    float precoUnitario, subtotal;
    int encontrou = 0;
    int totalRegistros = 0;

    limparTela();
    printf("\n╔═════════════════════════════════════════════════════════════════════════════╗");
    printf("\n║                       RELATÓRIO DE PRODUTOS VENDIDOS                        ║");
    printf("\n╠═══════╦══════════════════════════════╦════════════╦═══════════╦═════════════╣");
    printf("\n║ Venda ║ Produto                      ║ Quantidade ║ Unitário  ║ Subtotal    ║");
    printf("\n╠═══════╬══════════════════════════════╬════════════╬═══════════╬═════════════╣");

    if(arquivo == NULL){
        printf("Nenhum item vendido registrado.\n");
        pausar();
        return;
    }

    while(fscanf(arquivo, "%d;%d;%99[^;];%f;%d;%f\n", &idVenda, &idProduto, nomeProduto, &precoUnitario, &quantidade, &subtotal) == 6){
        printf("\n║ %-5d ║ %-28s ║ %-10d ║ R$ %-6.2f ║ R$ %-8.2f ║",
            idVenda,
            nomeProduto,
            quantidade,
            precoUnitario,
            subtotal);
            encontrou = 1;
            totalRegistros++;
    }
    printf("\n╚═══════╩══════════════════════════════╩════════════╩═══════════╩═════════════╝\n");
    printf("\n  ► Total de registros: %d\n", totalRegistros);

    if(!encontrou){
        printf("Nenhum produto vendido.\n");
    }

    fclose(arquivo);
    pausar();
}
