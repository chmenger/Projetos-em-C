#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

int menuPrincipal(int aberto, int totalVendas, int dia, int mes, int ano, float *entrada, float *totalvalorVendas);

//==================== UTILIDADES ====================
typedef struct {
    int id;
    char nome[30];
    float preco;
    int tipo;
} Produto;


typedef struct{
int idItem;
char nome[30];
int quantidade;
float subtotal;
} itemVenda;


typedef struct{
itemVenda *itens;
int totalItem;
float totalGeral;
int numeroVenda;
} venda;

void limparTela(){
system ("cls");
}

int produtoExiste(Produto *estoque, int total, int id){
    for (int i=0; i<total; i++){
        if (estoque[i].id==id){
            return 1;
        }
    }
    return 0;
}

void datas(int *dia, int *mes, int *ano){
        (*dia)++;
    if (*dia>31){
        *dia=1;
        (*mes)++;
    }
    if (*mes>12){
        (*ano)++;
        *mes=1;
    }
}

//============= VALIDA��ES =============
int validar(int min, int max){
    char c;
    int check;

    while (1) {
        if (scanf("%d", &check) != 1) {
            printf("\nENTRADA INVALIDA! DIGITE APENAS NUMEROS: ");
            while (getchar() != '\n');
            continue;
        }

        c = getchar();

        if (c != '\n') {
            printf("\nENTRADA INVALIDA! CARACTERES INVALIDOS DETECTADOS: ");
            while (getchar() != '\n');
            continue;
        }

        if (check < min || check > max) {
            printf("\nENTRADA INVALIDA! DIGITE UM NUMERO ENTRE %d E %d: ", min, max);
            continue;
        }

        break;
    }
    return check;
}

int validando (int *livre, int *total, int *totalVendas){
    if (*totalVendas>0){
        return 0;
    }
    if (total==0){
        limparTela();
        printf ("NENHUM ITEM CADASTRADO...\n");
        return 1;
    }else if (*livre==0){
        limparTela();
        printf ("ABRA O CAIXA PRIMEIRO...\n");
        return 1;
    }else {
    return 0;
    }
}


float validarFloat(float min){
    char c;
    float valor;

    while (1) {
        if (scanf("%f", &valor)!=1){
            printf ("ENTRADA INVALIDA, SOMENTE NUMEROS:");
            while (getchar()!='\n');
            continue;
        }
        c = getchar();

        if (c != '\n') {
            printf("\nINVALIDO-> CARACTERES INVALIDOS DETECTADOS: ");
            while (getchar() != '\n');
            continue;
        }
        if (valor<min){
            printf ("VALOR INVALIDO, TENTE OUTRO:");
            continue;
        }
        break;
    }
    return valor;
}

//============================= CADASTRO, LISTAGEM E ESTOQUE DE PRODUTOS =============================
void recursividadeProdutos(Produto *estoque, int *quantidades, int total, int i) {

    if (i >= total) return;
        printf("|%02d) | %-30s | R$%7.2f   | %05d      | %-7s |\n",
                estoque[i].id, estoque[i].nome, estoque[i].preco, quantidades[i], estoque[i].tipo==1 ? "MERCADO" : "PADARIA");
        recursividadeProdutos(estoque, quantidades, total, i + 1);
}

void listarEstoque (Produto *estoque, int total, Produto *tal, float subtotal, float totalVendaAtual, int *quantidades){
    printf ("============================================================================\n");
    printf ("|                            LISTA DE PRODUTOS                             |\n");
    printf ("|==========================================================================|\n");
    printf ("|ID  | NOME                           |    PRECO    | EM ESTOQUE |  AREA   |\n");
    printf ("|----|--------------------------------|-------------|------------|---------|\n");

    if (total > 0) {
        recursividadeProdutos(estoque, quantidades, total, 0);
    }

    printf ("|----|--------------------------------|-------------|------------|---------|\n");
    if (tal !=NULL){
        printf ("        ------------------------------\n        |  PRODUTO: %-16s |\n", tal->nome);
        printf ("        |  SUBTOTAL: %10.2f      |\n", subtotal);
        printf ("        |  TOTAL: %10.2f         |\n        ------------------------------\n\n", totalVendaAtual);
    }
}

void listarProdutos(Produto *estoque, int total, Produto *tal, float subtotal, float totalVendaAtual, int *quantidades){
    listarEstoque (estoque, total, tal, subtotal, totalVendaAtual, quantidades);
    printf ("PARA SAIR, DIGITE [0]\n\n");
}

int usoOpcao(){
    int continuar;

    printf ("\n   [1] SIM   |   [0] N�O\n");
    printf ("\nESCOLHA: ");
    continuar=validar(0,1);

    return continuar;
}

void cadastrarProduto(Produto **estoque, int *total, int **quantidades) {
    int continuar, escolha;

    limparTela();

    do {

        listarEstoque(*estoque, *total, NULL, 0, 0, *quantidades);

        Produto *tempEstoque = realloc(*estoque, (*total + 1) * sizeof(Produto));
        int *tempQuantidades = realloc(*quantidades, (*total + 1) * sizeof(int));

        if (tempEstoque == NULL || tempQuantidades == NULL){
            printf("ERRO DE MEMORIA!\n");
            return;
        }

        *estoque = tempEstoque;
        *quantidades = tempQuantidades;

        Produto *p = &(*estoque)[*total];

            printf ("\nDESEJA CADASTRAR UM PRODUTO NOVO?\n");
            escolha=usoOpcao();
        if (escolha==0){
            limparTela();
            printf ("VOLTANDO DA AREA DE CADASTRO...\n");
            break;
        }
        limparTela();
        printf ("\n=============== CADASTRO DE PRODUTOS ===============\n\n");
        listarEstoque(*estoque, *total, NULL, 0, 0, *quantidades);
        printf("\nID DO PRODUTO: ");

        int novoId;

        while (1){
            novoId=validar(1, 1000);
            if (produtoExiste(*estoque, *total, novoId)) {
                printf("\nERRO: O ID [%d] JA ESTA CADASTRADO!\n", novoId);
                printf("POR FAVOR, DIGITE OUTRO ID: ");
            } else{
                break; // ID �nico, sai do loop de valida��o
            }
        }
        ((*estoque) + *total)->id = novoId; // Aritm�tica de ponteiro
        //p->id = validar (1, 9999);
        printf("NOME DO PRODUTO: ");
        fgets(p->nome, 30, stdin);
        p->nome [strcspn (p->nome, "\n")]='\0';
        for (int i=0; p->nome[i]!='\0'; i++){
            p->nome[i]=toupper (p->nome[i]);
        }
        printf("PREAO: ");
        ((*estoque) + *total)->preco = validarFloat(0.01);
        //p->preco = validarFloat(0.01);
        printf ("QUANTIDADE EM ESTOQUE: ");
        (*quantidades)[*total] = validar (1, 9999);
        printf ("\nVAI PARA QUAL AREA DA EMPRESA?\n\n");
        printf ("[1] MERCADO   |   [2] PADARIA\n\n");
        printf ("DEFINA O LOCAL: ");
        ((*estoque) + *total)->tipo=validar(1,2);

        (*total)++; // Incrementa o valor apontado por total

        limparTela();

        printf ("PRODUTO CADASTRADO COM SUCESSO!\n\n");



        //listarEstoque(*estoque, *total, NULL, 0, 0, *quantidades);
        /*printf("PRODUTO CADASTRADO COM SUCESSO!\n");
        printf("DESEJA CADASTRAR OUTRO?\n");
        continuar=usoOpcao();*/
        if (escolha==0){
            limparTela();
            printf ("RETORNANDO A AREA DE ESTOQUE/PRODUTOS...\n");
            return;
        }
        }while (escolha==1);

}

void estoqueProdutos(Produto **estoque, int *total, int **quantidades){
    limparTela();
    int escolha, opcao, i;
    do {
        printf("\n========== MENU PRODUTOS ==========\n\n");
        printf("1. CADASTRAR PRODUTO (%d)\n", *total);
        printf("2. LISTAR PRODUTOS CADASTRADOS\n");
        printf("3. EXCLUIR UM PRODUTO\n");
        printf("4. EXCLUIR TODOS OS PRODUTOS\n");
        printf("5. AREA DE EDICAO\n");
        printf("0. VOLTAR AO MENU PRINCIPAL\n");

        opcao=validar(0,5);

        switch (opcao){

        case 1:
            cadastrarProduto(estoque, total, quantidades);
            break;

        case 2:
            if (*total==0){
                limparTela();
                printf ("SEM PRODUTOS PARA LISTAR...\n");
                break;
            }
            limparTela();
            listarEstoque(*estoque, *total, NULL, 0, 0, *quantidades);
            printf("\nAPERTE ENTER PARA VOLTAR...");
            getchar();
            limparTela();
            printf ("VOLTANDO DA LISTAGEM...\n");
            break;

        case 3:
            if (*total==0){
                limparTela();
                printf ("NAO HA PRODUTOS NO ESTOQUE...\n");
                break;
            }
            limparTela();
            listarEstoque(*estoque, *total, NULL, 0, 0, *quantidades);
            printf ("ESCOLHA QUAL PRODUTO DESEJA EXCLUIR (0 PARA VOLTAR): ");
            //escolha=usoOpcao();
            escolha = validar(0, 9999);

            if (escolha==0){
                limparTela();
                printf ("VOLTANDO, NENHUM PRODUTO PARA EXCLUIR NO MOMENTO...\n");
                break;
            }

            int diminuir=-1;

            for (int i=0; i< *total; i++){
                if (escolha==(*estoque)[i].id){
                    diminuir=i;
                    break;
                }
            }
            if (diminuir==-1){
                limparTela();
                printf ("PRODUTO NAO ENCONTRADO...\n");
                break;
            }
            for (i=diminuir; i< *total - 1; i++){
                estoque[i]=estoque[i+1];
                quantidades[i]=quantidades[i+1];
            }
            (*total)--;
            limparTela();
            printf ("PRODUTO REMOVIDO COM SUCESSO!\n");
            break;

        case 4:
            limparTela();

            if (*total==0){
                printf ("NENHUM PRODUTO NO ESTOQUE...\n");
                break;
            }
            printf ("=============== EXCLUIR TODOS OS PRODUTOS ===============\n\n");
            int escolha_exclusao;
            printf ("\nOBS: ESTA OPCAO IRA APAGAR OS DADOS DE TODOS OS PRODUTOS!\n\n\n\n");
            printf ("TEM CERTEZA QUE DESEJA EXCLUIR TODOS OS PRODUTOS?\n");
            escolha_exclusao=usoOpcao();
            if (escolha_exclusao==0){
                limparTela();
                printf ("NENHUM PRODUTO FOI EXCLUIDO DO ESTOQUE, RETORNANDO...\n");
                break;
            }
            *total=0;
            limparTela();
            printf ("TODOS OS PRODUTOS FORAM EXCLUIDOS!\n");
            break;

        case 5:

            int opcao_edicao, escolha;

            if (*total==0){
                limparTela();
                printf ("SEM PRODUTOS PARA EDICAO...\n");
                break;
            }
            limparTela();
            do {
                printf ("\n=============== EDICAO ===============\n\n");
                printf ("1. EDITAR ID\n");
                printf ("2. EDITAR NOME\n");
                printf ("3. EDITAR PRECO\n");
                printf ("4. EDITAR ESTOQUE\n");
                printf ("ESCOLHA (O PARA SAIR): ");
                opcao_edicao=validar (0, 4);

                if (opcao_edicao==0){
                    limparTela();
                    printf ("VOLTANDO DO MENU DE EDICAO...\n");
                    break;
                }

                switch (opcao_edicao){

                    case 1: {
                        limparTela();

                        int editando=1;

                        while (editando) {
                            printf ("============== EDITANDO ID's ==============\n\n");

                            listarEstoque(*estoque, *total, NULL, 0, 0, *quantidades);
                            printf ("DIGITE O ID DE EDICAO DESEJADO (0 PARA VOLTAR): ");
                            escolha=validar(0, 1000);

                            if (escolha==0){
                                limparTela();
                                printf ("VOLTANDO AO MENU DE EDICAO...\n");
                                editando=0;
                                break;
                            }

                            int produto=-1;

                            for (int i=0; i< *total; i++){
                                if (escolha==(*estoque)[i].id){
                                    produto = i;
                                    break;
                                }
                            }
                            if (produto==-1){
                                limparTela();
                                printf ("PRODUTO NAO ENCONTRADO...\n");
                                break;
                            }
                            printf ("\nPRODUTO ESCOLHIDO: %s\n", (*estoque)[produto].nome);
                            printf ("[ID] ATUAL: %d\n", (*estoque)[produto].id);
                            printf ("POR QUAL [ID] VOCE DESEJA TROCAR? ");

                            int idCandidato;

                            while (1){
                                idCandidato=validar(1, 1000);

                                if (idCandidato==(*estoque)[*total].id){
                                    limparTela();
                                    printf ("O ID ESCOLHIDO NAO FOI ALTERADO, PERMANECERA O MESMO...\n");
                                    break;
                                }
                                if (produtoExiste(*estoque, *total, idCandidato)) {
                                    printf("\nERRO: ESTE ID JA PERTENCE A OUTRO PRODUTO, TENTE OUTRO: ");
                                }else{
                                    (*estoque)[produto].id = idCandidato;
                                    limparTela();
                                    printf ("ID ALTERADO COM SUCESSO!\n\n");
                                    break;
                                }
                            }
                        }
                        break;
                    }

                    case 2: {
                        limparTela();
                        int editando=1;

                        while (editando){
                            printf ("============== EDITANDO NOME ==============\n\n");
                            listarEstoque(*estoque, *total, NULL, 0, 0, *quantidades);
                            printf ("DIGITE O ID DE EDICAO DESEJADO (0 PARA VOLTAR): ");
                            escolha=validar(0, 1000);

                            if (escolha==0){
                                limparTela();
                                printf ("VOLTANDO AO MENU DE EDICAO...\n");
                                editando=0;
                                break;
                            }

                            int produto=-1;

                            for (int i=0; i< *total; i++){
                                if (escolha==(*estoque)[i].id){
                                    produto = i;
                                    break;
                                }
                            }
                            if (produto==-1){
                                limparTela();
                                printf ("PRODUTO NAO ENCONTRADO...");
                                break;
                            }
                            printf ("\nPRODUTO ESCOLHIDO: %s\n", (*estoque)[produto].nome);
                            printf ("NOME ATUAL: %s\n", (*estoque)[produto].nome);
                            printf ("PARA QUAL NOME DESEJA ALTERAR? ");
                            fgets ((*estoque)[produto].nome, 30, stdin);
                            (*estoque)[produto].nome[strcspn((*estoque)[produto].nome, "\n")] = '\0';

                            for (int i=0; (*estoque)[produto].nome[i]!='\0'; i++){
                                (*estoque)[produto].nome[i] = toupper ((*estoque)[produto].nome[i]);
                            }
                            while (1){
                                limparTela();
                                printf ("NOME ALTERADO COM SUCESSO!\n\n");
                                break;
                            }
                        }
                        break;
                    }

                    case 3: {
                        limparTela();
                        int editando=1;

                        while (editando){
                            printf ("============== EDITANDO PRECO ==============\n\n");
                            listarEstoque(*estoque, *total, NULL, 0, 0, *quantidades);
                            printf ("DIGITE O ID DE EDICAO DESEJADO (0 PARA VOLTAR): ");
                            escolha=validar(0, 1000);

                            if (escolha==0){
                                limparTela();
                                printf ("VOLTANDO AO MENU DE EDICAO...\n");
                                break;
                            }

                            int produto=-1;

                            for (int i=0; i< *total; i++){
                                if (escolha==(*estoque)[i].id){
                                    produto = i;
                                    break;
                                }
                            }
                            if (produto==-1){
                                limparTela();
                                printf ("PRODUTO NAO ENCONTRADO...");
                                break;
                            }
                            printf ("\nPRODUTO ESCOLHIDO: %s\n", (*estoque)[produto].nome);
                            printf ("PRECO ATUAL: %.2f\n", (*estoque)[produto].preco);
                            printf ("QUANTO VOCE DESEJA COBRAR? ");
                            (*estoque)[produto].preco=validarFloat(0.01);
                            break;

                            while (1){
                                limparTela();
                                printf ("PRECO ALTERADO COM SUCESSO!\n\n");
                                break;
                            }
                        }
                        break;
                    }

                    case 4: {
                        limparTela();
                        int editando=1;

                        while (editando){
                            printf ("============== EDITANDO ESTOQUE ==============\n\n");
                            listarEstoque(*estoque, *total, NULL, 0, 0, *quantidades);
                            printf ("DIGITE O ID DE EDICAO DESEJADO (0 PARA VOLTAR): ");
                            escolha=validar(0, 1000);

                            if (escolha==0){
                                limparTela();
                                printf ("VOLTANDO AO MENU DE EDICAO...\n");
                                break;
                            }

                            int produto=-1;

                            for (int i=0; i< *total; i++){
                                if (escolha==(*estoque)[i].id){
                                    produto = i;
                                    break;
                                }
                            }
                            if (produto==-1){
                                limparTela();
                                printf ("PRODUTO NAO ENCONTRADO...");
                                break;
                            }
                            printf ("\nPRODUTO ESCOLHIDO: %s\n", (*estoque)[produto].nome);
                            printf ("ESTOQUE ATUAL: %d\n", (*quantidades)[produto]);
                            printf ("QUAL A QUANTIDADE QUE DESEJA TROCAR? ");
                            (*quantidades)[produto]=validar(1, 1000);
                            break;

                            while (1){
                                limparTela();
                                printf ("ESTOQUE ALTERADO COM SUCESSO!\n\n");
                                break;
                            }
                        }
                    }
                    break;
                }
            }while (opcao_edicao!=0);
            break;

        case 0:
            limparTela();
            printf ("VOLTANDO AO MENU PRINCIPAL...\n");
            return;
        }
    }while (opcao!=0);
}

//================================= CALCULO E RELATORIO DE VENDAS =================================
void calcular (Produto *estoque, int *total, venda **vendas, int *totalVendas, float *totalGeral, int *quantidades){
    int product, quantidade;
    float subtotal=0;
    venda *temp = realloc(*vendas, (*totalVendas + 1) * sizeof(venda));

    if (temp == NULL){
        printf("ERRO DE MEMORIA!\n");
            return;
    }

    *vendas = temp;

    venda *v = &(*vendas)[*totalVendas];

    Produto *tal=NULL;

    v->totalItem = 0;
    v->totalGeral = 0;
    v->itens = NULL;
    limparTela();
    do {
        listarProdutos(estoque, *total, tal, subtotal, v->totalGeral, quantidades);
        printf ("ESCOLHA O PRODUTO: ");
        product = validar(0, 9999);

        if (product==0){
            limparTela();
            if (v->totalItem==0){
                printf ("NENHUMA VENDA REALIZADA\n");
            }
            else if (v->totalItem>0){
                v->numeroVenda = *totalVendas + 1;
                printf ("VENDA REALIZADA COM SUCESSO!\n");
                (*totalVendas)++;
            }
            break;
        }

        tal=NULL;

        int indice=-1;

            for (int i=0; i<total; i++){
                if (product==estoque[i].id){
                    tal =&estoque[i];
                    indice = i;
                    break;
                }
            }

        if (tal==NULL){
            limparTela();
            printf ("SEM PRODUTO COM ESTE REGISTRO...\n\n");
            continue;
        }
        printf ("\n----------------------------------\n");
        printf ("PRODUTO ESCOLHIDO: %-16s\n\n", tal->nome);

        printf ("DIGITE A QUANTIDADE: ");
        quantidade = validar (1, 1000);
        if (quantidades[indice]==0){
            limparTela();
            printf ("PRODUTO INDISPONIVEL NO ESTOQUE...\n\n");
            continue;
        }
        if (quantidades[indice]<quantidade){
            limparTela();
            printf ("NAO HA MAIS ESTA QUANTIDADE DE %s NO ESTOQUE...\n\n", tal->nome);
            continue;
        }

        quantidades[indice]-=quantidade;
        subtotal = tal->preco * quantidade;

        int i = v->totalItem;

        itemVenda *tempItens = realloc(v->itens,
                                        (v->totalItem + 1) * sizeof(itemVenda));

        if (tempItens == NULL){
            printf("ERRO DE MEMORIA!\n");
            return;
        }

        v->itens = tempItens;
        v->itens[i].idItem=tal->id;

        strcpy(v->itens[i].nome, tal->nome);

        v->itens[i].quantidade=quantidade;
        v->itens[i].subtotal=subtotal;

        v->totalItem++;
        v->totalGeral+=subtotal;
        *totalGeral += subtotal;
        limparTela();

    }while (product!=0);
}

void relatorio(Produto *estoque, int *total, venda **vendas, int *totalVendas, float *totalGeral, int *expediente){
    limparTela();

    float valorTotal= *totalGeral;
    char nomeTemp[16];
    int ids, q, ver_relatorio;
    float s;
    char *p;

    if (*totalVendas==0){
        limparTela();
        printf ("NENHUMA VENDA REALIZADA NO MOMENTO...\n");
        return;
    }

    for (int i=0; i<*totalVendas; i++){
        for (int j=0; j<*totalVendas; j++){
            if ((*vendas)[j].totalGeral<(*vendas)[j+1].totalGeral){
                venda temp=(*vendas)[j];
                (*vendas)[j]=(*vendas)[j+1];
                (*vendas)[j+1]=temp;
            }
        }
    }

    do {
        printf ("\n====================== RELATORIO ======================\n\n");
        printf ("1. LISTA DE PRODUTOS VENDIDOS NO DIA\n");
        printf ("2. RELATORIO GERAL DE VENDAS\n\n");
        printf ("QUAL DESEJARIA VER (0 PARA SAIR): ");
        ver_relatorio=validar(0, 2);

        switch (ver_relatorio){
            case 1:
            limparTela();
            printf ("=============== LISTA DE VENDIDOS NO DIA ===============\n\n");
            printf ("\n-----------------------------------------------------|\n");
            printf ("ID  | NOME                              | QUANTIDADE |\n");
            for (int r=0; r<*totalVendas; r++){
                for (int R=0; R<(*vendas)[r].totalItem; R++){
                    ids = (*vendas)[r].itens[R].idItem;
                    p = (*vendas)[r].itens[R].nome;
                    q = (*vendas)[r].itens[R].quantidade;
                    printf ("%02d  | %-11s                       |    %03d     |\n", ids, p, q);
                }
            }
            printf ("-----------------------------------------------------|\n");
            printf("\nAPERTE ENTER PARA VOLTAR...");
            getchar();
            limparTela();
            break;

            case 2:
            limparTela();
            for (int i=0; i<*totalVendas; i++){
                printf ("\n\n\n\n-------------- %dº VENDA (EXPEDIENTE: %d) -------------\n\n", (*vendas)[i].numeroVenda, *expediente);
                printf ("ID  | NOME                    |  QTD  | SUBTOTAL\n");
                printf ("----------------------------------------------------\n");
                    for (int k=0; k<(*vendas)[i].totalItem; k++){
                        ids = (*vendas)[i].itens[k].idItem;
                        p = (*vendas)[i].itens[k].nome;
                        q = (*vendas)[i].itens[k].quantidade;
                        s = (*vendas)[i].itens[k].subtotal;
                        if (produtoExiste(estoque, *total, (*vendas)[i].itens[k].idItem)){
                            printf ("%02d  | %-23s |  %03d  | %.2f\n", ids, p, q, s);
                        }else{
                            sprintf (nomeTemp, "%s (REMOVIDO)", p);
                            printf ("%02d  | %-23s |  %03d  | %.2f\n", ids, nomeTemp, q, s);
                        }
                    }
                    printf ("----------------------------------------------------");
                    printf ("\nTOTAL DESTA VENDA: %.2f\n", (*vendas)[i].totalGeral);
                    printf ("====================================================\n");
            }
            printf ("\n           TOTAL GERAL: R$%.2f\n\n", *totalGeral);
            printf ("====================================================\n\n");

            printf("\nAPERTE ENTER PARA VOLTAR...");
            getchar();
            limparTela();
            break;

            case 0:
            limparTela();
            printf ("SAINDO DO MENU DE RELATORIO...\n");
            return;
        }
    }while (ver_relatorio!=0);
}

//======================================= ABERTURA, FECHAMENTO DE CAIXA E FINALIZA��O (FREE) =======================================
int abrindo (float *inicial, int *livre, float *totalGeral){
    limparTela();

    if (*livre==1){
        printf ("O CAIXA JA ESTA ABERTO! [R$%.2f]\n", *inicial);
        return 1;
    }
    printf ("\n==================== CAIXA =====================\n\n");
    do{
        printf ("DE UMA ENTRADA DE CAIXA (MINIMO DE R$100): ");
        *inicial = validarFloat(0.01);

        if (*inicial<100){
            printf ("\n[VALOR INSUFICIENTE!]\n\n");
        }else{
            limparTela();
            printf ("O CAIXA ESTA ABERTO [R$%.2f]\n", *inicial);
            *livre=1;
            break;
        }
    }while (*inicial<100);
}

void fechamento(venda **vendas, float *entrada, float *totalvalorVendas,
    int *totalVendas, int *livre, int *dia, int *mes, int *ano, int *expediente){

    float totalFinal= *entrada+ *totalvalorVendas;
    int totalProdutosVendidos=0;
    float media=0;

    if (*livre==0){
        limparTela();
        printf ("INDISPONIVEL, NENHUMA ABERTURA DE CAIXA REALIZADA...\n");
        return;
    }

    limparTela();

    for (int i = 0; i < *totalVendas; i++) {
        for (int k = 0; k < (*vendas)[i].totalItem; k++) {
            totalProdutosVendidos += (*vendas)[i].itens[k].quantidade;
        }
    }

if (totalProdutosVendidos > 0){
    media = *totalvalorVendas / totalProdutosVendidos;
}

    printf ("\n\nFECHANDO CAIXA...\n\n\n");
    printf ("SALDO DE ENTRADA DO CAIXA: [ %.2f ]\n", *entrada);
    printf ("TOTAL DE PRODUTOS VENDIDOS [ %d ]\n", totalProdutosVendidos);
    printf ("MEDIA DE GANHO POR PRODUTO VENDIDO: [ %.2f ]\n", media);
    printf ("TOTAL EM VENDAS: [ %.2f ]\n", *totalvalorVendas);
    printf ("TOTAL GERAL: [ %.2f ]\n\n\n", totalFinal);

    *livre=0;
    *totalvalorVendas=0;
    *entrada=0;
    (*expediente)++;
    datas (dia, mes, ano);
}
int finalizacao(int *livre, venda *vendas, Produto *estoque, int *quantidades, int totalVendas){
    if (*livre==1){
        limparTela();
        printf ("VOCE PRECISA FECHAR O CAIXA ANTECIPADAMENTE...\n");
        return 1;
    }
    if (*livre==0){
        printf ("\n\n\nEXPEDIENTE FINALIZADO COM SUCESSO!\n\n\n");
        free (estoque);
        for (int i = 0; i < totalVendas; i++){
            free(vendas[i].itens);
        }
        free (vendas);
        free(quantidades);
        return 0;
    }
}

int menuPrincipal(int aberto, int totalVendas, int dia, int mes, int ano, float *entrada, float *totalvalorVendas){

    int opcao;
    float saldo_caixa= *entrada + *totalvalorVendas;
    printf ("\n-------------------------------------");
    printf ("\n|         DATA: %02d/%02d/%d          |\n", dia, mes, ano);
    printf ("-------------------------------------\n");

    printf ("SALDO ATUAL DO CAIXA: [ %.2f ]", saldo_caixa);

    printf ("\n============== MENU ===============\n");
    printf ("                                  |\n");

    printf ("1. AREA DE CADASTRO               |\n");
    printf ("2. ABRIR CAIXA (%-7s)          |\n", aberto ? "ABERTO" : "FECHADO");
    printf ("3. REALIZAR VENDA                 |\n");
    printf ("4. VER RELATORIO (%02d)             |\n", totalVendas);
    printf ("5. FECHAR CAIXA                   |\n");
    printf ("0. FINALIZAR EXPEDIENTE           |\n");

    printf ("- ESCOLHA: ");

    opcao = validar(0,5);

    return opcao;
}

//========================= A MAIN, MENU PRINCIPAL E USO DE CADA FUN��O =========================
int main()
{ setlocale (LC_ALL, "Portuguese");
Produto *estoque = NULL;
venda *vendas = NULL;
int *quantidades = NULL;

int totalVendas=0, total=0, expediente=1;
int opcao, livre=0, dia=4, mes=5, ano=2026;
float inicial=0, totalGeral=0;

    do {
        opcao = menuPrincipal(livre, totalVendas, dia, mes, ano, &inicial, &totalGeral);

        switch (opcao){

        case 1:
            estoqueProdutos(&estoque, &total, &quantidades);
            break;
        case 2:
            abrindo (&inicial, &livre, &totalGeral);
            break;
        case 3:
            if (validando (&livre, &total, &totalVendas)){break;}
            calcular(estoque, &total, &vendas, &totalVendas, &totalGeral, quantidades);
            break;
        case 4:
            if (validando (&livre, &total, &totalVendas)){break;}
            relatorio(estoque, &total, &vendas, &totalVendas, &totalGeral, &expediente);
            break;
        case 5:
            fechamento(&vendas, &inicial, &totalGeral, &totalVendas, &livre, &dia, &mes, &ano, &expediente);
            break;
        case 0:
            if (finalizacao(&livre, vendas, estoque, quantidades, totalVendas)==0){
                return 0;
            }
        }
    }while (1);
    return 0;
}
