#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

    int main(){
    setlocale(LC_ALL, "Portuguese"); // ACENTUA AS PALAVRAS

    // VARIAVEIS
    int opcao;// OPCOES DO MENU
    int caixa_aberto = 0; // INDICA SE O CAIXA ESTA ABERTO PARA INICIAR UMA VENDA
    int produto_escolhido;

    float p1 = 2.99; // AGUA S/GAS
    float p2 = 3.99; // AGUA C/GAS
    float p3 = 5.99; // COCA-COLA LATA
    float p4 = 10.90; // ARROZ 1KG
    float p5 = 9.98; // FEIJAO 1KG
    float p6 = 0.99; // PAO UN
    float p7 = 9.98; // PASTEL UN
    float p8 = 9.98; // COXINHA UN
    float p9 = 34.99; // CARNE KG
    float p10 = 19.99; // FRANGO KG

    //venda
    int qtd_item = 0;
    int qtd_venda_atual = 0;
    float valor_produtos = 0;
    float total_venda_atual = 0;

    //fechamento
    float valor_abertura = 0;
    float saldo_caixa = 0;
    int qtd_total_geral = 0;
    float valor_total_geral = 0;

    void calcular(){
    total_venda_atual=total_venda_atual+valor_produtos;
    valor_total_geral=total_venda_atual+valor_abertura;
    qtd_total_geral=qtd_venda_atual+qtd_item;
    scanf ("%.2f", &valor_total_geral);
     scanf ("%.2f", &qtd_total_geral);
    system ("cls");
        if (qtd_item<0 && qtd_item>10){
        system ("cls");
            printf ("ESCOLHA UMA QUANTIDADE REAL!");
            }else {
            printf ("VALOR DO(S) PRODUTO(S): %.2f\n", valor_produtos);
            printf ("QUANTIDADE DE PRODUTOS VENDIDOS: %d\n", qtd_venda_atual);
            printf ("\nTOTAL DA VENDA: %.2f\n", total_venda_atual);
            }}

     // MENU INICIAL
        do {
        do {
        printf("\n=== MERCADO BOM JESUS ===\n");
        printf("\n1 - ABRIR CAIXA");
        printf("\n2 - INICIAR NOVA VENDA");
        printf("\n3 - ENCERRAR PROGRAMA\n");
        printf ("\nESCOLHA UMA OPCAO: ");
        scanf("%d", &opcao);

        if (opcao<0 || opcao>3){
            system ("cls");
            printf ("OPCAO INVALIDA, TENTE UMA DAS TRES!\n");}
        } while (opcao<0 || opcao>3);

        switch (opcao){

        case 1:
            system ("cls");
            if (caixa_aberto==0){
            caixa_aberto=1;
            do {
            printf ("=== ABERTURA DE CAIXA ===\n");
            printf ("\n(A ABERTURA MÍNIMA DE UM CAIXA É DE R$50,00)");
            printf ("\nDEPOSITE UM VALOR DE ENTRADA: ");
            scanf ("%f", &valor_abertura);
            if (valor_abertura<50){
                system ("cls");
                printf ("VALOR INSUFICIENTE, DIGITE NOVAMENTE!\n\n");
            }
            } while (valor_abertura<50);
            system ("cls");
            printf ("CAIXA ABERTO COM DEPÓSITO DE: R$%.2f\n", valor_abertura);

            }else {
            system("cls");
                printf ("VOCE JA ESTA COM O CAIXA ABERTO! ABERTURA DE: R$%.2f\n", valor_abertura);
            }
            break;

        case 2:
            if (caixa_aberto==0){
                system ("cls");
                printf ("VOCE AINDA NÃO ABRIU O CAIXA!\n");
            }else {

                    system ("cls");
                    do {
                        printf ("\n=== TABELA DE PRODUTOS ===\n");
                        printf ("1. AGUA S/GAS por 2.99\n");
                        printf ("2. AGUA C/GAS por 3.99\n");
                        printf ("3. COCA-COLA LATA por 5.99\n");
                        printf ("4. ARROZ 1KG por 10.90\n");
                        printf ("5. FEIJAO 1KG por 9.98\n");
                        printf ("6. PAO UN por 0.99\n");
                        printf ("7. PASTEL UN por 9.98\n");
                        printf ("8. COXINHA UN por 9.98\n");
                        printf ("9. CARNE KG por 34.99\n");
                        printf ("10. FRANGO KG por 19.99\n");
                        printf ("0. FECHAR A CONTA\n");
                        printf ("ESCOLHA SEU(S) PRODUTO(S):");
                        scanf ("%d", &produto_escolhido);

                switch (produto_escolhido){

                case 1:
                    printf ("\n1 AGUA S/GAS, DIGITE A QUANTIDADE: ");
                    scanf ("%d", &qtd_item);
                    qtd_venda_atual=qtd_venda_atual+qtd_item;
                    calcular (valor_produtos = p1*qtd_item);
                    break;
                case 2:
                    printf ("\n1 AGUA C/GAS, DIGITE A QUANTIDADE: ");
                    scanf ("%d", &qtd_item);
                    qtd_venda_atual=qtd_venda_atual+qtd_item;
                    calcular (valor_produtos = p2*qtd_item);
                    break;
                case 3:
                    printf ("\n1 COCA-COLA LATA, DIGITE A QUANTIDADE: ");
                    scanf ("%d", &qtd_item);
                    qtd_venda_atual=qtd_venda_atual+qtd_item;
                    calcular (valor_produtos = p3*qtd_item);
                    break;
                case 4:
                    printf ("\n1 ARROZ 1KG, DIGITE A QUANTIDADE: ");
                    scanf ("%d", &qtd_item);
                    qtd_venda_atual=qtd_venda_atual+qtd_item;
                    calcular (valor_produtos = p4*qtd_item);
                    break;
                case 5:
                    printf ("\n1 FEIJAO 1KG, DIGITE A QUANTIDADE: ");
                    scanf ("%d", &qtd_item);
                    qtd_venda_atual=qtd_venda_atual+qtd_item;
                    calcular (valor_produtos = p5*qtd_item);
                    break;
                case 6:
                    printf ("\n1 PAO UN, DIGITE A QUANTIDADE: ");
                    scanf ("%d", &qtd_item);
                    qtd_venda_atual=qtd_venda_atual+qtd_item;
                    calcular (valor_produtos = p6*qtd_item);
                    break;
                case 7:
                    printf ("\n1 PASTEL UN, DIGITE A QUANTIDADE: ");
                    scanf ("%d", &qtd_item);
                    qtd_venda_atual=qtd_venda_atual+qtd_item;
                    calcular (valor_produtos = p7*qtd_item);
                    break;
                case 8:
                    printf ("\n1 COXINHA UN, DIGITE A QUANTIDADE: ");
                    scanf ("%d", &qtd_item);
                    qtd_venda_atual=qtd_venda_atual+qtd_item;
                    calcular (valor_produtos = p8*qtd_item);
                    break;
                case 9:
                    printf ("\n1 CARNE KG, DIGITE A QUANTIDADE: ");
                    scanf ("%d", &qtd_item);
                    qtd_venda_atual=qtd_venda_atual+qtd_item;
                    calcular (valor_produtos = p9*qtd_item);
                    break;
                case 10:
                    printf ("\n1 FRANGO KG, DIGITE A QUANTIDADE: ");
                    scanf ("%d", &qtd_item);
                    qtd_venda_atual=qtd_venda_atual+qtd_item;
                    calcular (valor_produtos = p10*qtd_item);
                    break;

                case 0:
                    system ("cls");
                    printf ("\nVENDA ENCERRADA, MENU DE OPÇÕES--> \n");

                    break;
                default:
                    system ("cls");
                    printf ("PRODUTO NAO REGISTRADO, TENTE NOVAMENTE!");
                    continue;
                }
                } while (produto_escolhido!=0);

                 if (opcao<0 || opcao>3){
                    printf ("OPCAO INVALIDA, TENTE UMA DAS TRES!");}
                    }
    }}while (opcao!=3);
    system ("cls");
    printf ("(ÚLTIMA VENDA)\n\n");
    printf ("=== RELATÓRIO ===\n\n");
    printf ("\nTOTAL EM VENDA(S): %.2f\n", total_venda_atual);
    printf ("VALOR DE ABERTURA DE CAIXA: R$%.2f\n", valor_abertura);
    printf ("\nSALDO FINAL DO CAIXA: R$%.2f\n", valor_total_geral);
    printf ("QUANTIDADE DE PRODUTOS VENDIDOS: %d\n", qtd_total_geral);
    printf ("\nENCERRANDO PROGRAMA...\n");
    return 0;
}
