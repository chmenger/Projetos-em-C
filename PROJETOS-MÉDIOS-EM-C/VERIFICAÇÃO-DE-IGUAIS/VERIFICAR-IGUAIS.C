#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int verificarDuplicados(int srv1[5], int srv2[5]){
    int i, k;
    int erros=0;
        printf ("=================  CONFLITO DETECTADO  ==================\n");
        printf ("|        SERVIDOR 1                   SERVIDOR 2        |\n|                                                       |\n");
    for (i=0; i<5; i++){
        for (k=0; k<5; k++){
            if (srv1[i]==srv2[k]){
                printf ("|     %dº POSIÇÃO: [%02d]    COM    [%02d] NA %dº POSIÇÃO     |\n", i+1, srv1[i], srv2[k], k+1);
                erros++;
    }}}printf ("=========================================================\n");
    return erros;}

int main(){

    system("chcp 65001 > nul");
    setlocale (LC_ALL, "Portuguese");
    
    char c, opcao2;
    int srv1[5] = {0,0,0,0,0};
    int srv2[5] = {0,0,0,0,0};
    int i, k, opcao, erros=0;

        system ("cls");
        printf ("\n==========> 1º RELATÓRIO <===========\n\n");
        for (i=0; i<5; i++){
            printf ("DIGITE O %dº ID (servidor 1): ", i+1);
            if (scanf ("%d%c", &srv1[i], &c) !=2 || c!= '\n'){
                printf ("SOMENTE NÚMEROS!-----\n\n");
            while (getchar()!= '\n');i--;
            } else if (srv1[i]<0){
                printf ("NÚMERO INVÁLIDO.-----\n\n"); i--;}}

        system ("cls");
        printf ("\n==========> 2º RELATÓRIO <===========\n\n");
        for (k=0; k<5; k++){
            printf ("DIGITE O %dº ID (servidor 2): ", k+1);
            if (scanf ("%d%c", &srv2[k], &c)!=2 || c!= '\n'){
                printf ("SOMENTE NÚMEROS!-----\n\n");
            while (getchar()!= '\n');k--;
            } else if (srv2[k]<0){
                printf ("NÚMERO INVÁLIDO.-----\n\n"); k--;}}

        system ("cls");
        do {
            printf ("\n=============> MENU <=============\n\n");
            printf ("1. NÚMEROS DO PRIMEIRO SERVIDOR\n");
            printf ("2. NÚMEROS DO SEGUNDO SERVIDOR\n");
            printf ("3. DETECTAR CONFLITO ENTRE OS DOIS\n");
            printf ("0. ENCERRAR SESSÃO\n");
            printf ("DIGITE SUA OPÇÃO: ");
        if (scanf ("%d%c", &opcao, &c)!=2 || c!= '\n'){system ("cls");
            printf ("SOMENTE NÚMEROS!\n");
        while (getchar()!= '\n'); opcao=-1;}

        switch (opcao){

    case 1:system ("cls");
        printf ("========= SERVIDOR 1 =========\n");
            for (i=0; i<5; i++){
                printf ("|      %dº POSIÇÃO: [%02d]      |\n", i+1, srv1[i]);}
                printf ("==============================\n\n");
        break;


    case 2:system ("cls");
        printf ("========= SERVIDOR 2 =========\n");
            for (k=0; k<5; k++){
                printf ("|      %dº POSIÇÃO: [%02d]      |\n", k+1, srv2[k]);}
                printf ("==============================\n\n");
        break;


    case 3: system ("cls");
        erros = verificarDuplicados(srv1, srv2);
            printf ("     |    ID's SERVIDOR 1º: (%02d, %02d, %02d, %02d, %02d)    |\n", srv1[0], srv1[1], srv1[2], srv1[3], srv1[4]);
            printf ("     |    ID's SERVIDOR 2º: (%02d, %02d, %02d, %02d, %02d)    |\n", srv2[0], srv2[1], srv2[2], srv2[3], srv2[4]);
            printf ("     |          QUANTIDADE DE COnFLITOS: %d          |\n", erros);
            printf ("     ================================================\n\n");
        break;
    case 0:
        printf ("\n\nENCERRANDO PROGRAMA...\n\n\n");
        break;
    default: system ("cls");
         printf ("OPÇÃO INVÁLIDA, TENTE NOVAMENTE!\n");}

    } while (opcao!=0);

return 0;
}





