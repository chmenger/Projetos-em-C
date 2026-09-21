#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#define MAX_PESSOAS 50

typedef struct {
    char nome[30];
    char sobrenome[30];
    char nomecompleto[60];
    int idade;
    char sexo;
}Pessoa;

Pessoa pessoa[MAX_PESSOAS];

char busca[30];
int valido (int registro){
if (registro =='M' || registro =='m' ||registro =='F' ||registro =='f'){
    return 0;
}
return 1;}
int buscando (char titulo[60]){
if (titulo!=pessoa[60]nomecompleto){
    return 0;
}
return 1;}

int main(){ setlocale (LC_ALL, "Portuguese");
int opcao, aberto=0, i, k=0;
char c;

    do {
    printf ("\n============== MENU ==============\n\n");
    printf ("1. CADASTRAR\n");
    printf ("2. LISTA\n");
    printf ("3. BUSCAR SOBRENOME\n");
    printf ("0. SAIR\n");
    printf ("\nDIGITE SUA OPÇÃO: ");
    if (scanf ("%d%c", &opcao, &c)!=2 || c!='\n'){
        system ("cls");
        printf ("\n         OPÇÃO INVÁLIDA...\n");
        while (getchar()!='\n');
        continue;
    }

    switch (opcao){

    case 1: system ("cls");
        printf ("============ CADASTRO ============\n");
        printf ("NOME: ");
        fgets (pessoa[k].nome, 30, stdin);
        pessoa[k].nome[strcspn (pessoa[k].nome, "\n")]=0;
        printf ("SOBRENOME: ");
        fgets (pessoa[k].sobrenome, 30, stdin);
        pessoa[k].sobrenome[strcspn (pessoa[k].sobrenome, "\n")]=0;
            do {
                printf ("IDADE: ");
                if (scanf ("%d", &pessoa[k].idade)!=1){
                    printf ("\n------INVÁLID0------\n\n");
                    while (getchar()!='\n');
                } else {
                    while (getchar()!='\n');
                break;}
            }while (pessoa[k].idade!=1); /*else {break;}*/
        do{
            printf ("SEXO: ");
            scanf (" %c", &pessoa[k].sexo);
                if (valido (pessoa[k].sexo)==0){
            break;
            } else {printf ("\n------INVÁLIDO------\n\n");
            continue;}
        }while (valido (pessoa[k].sexo)==1);
        getchar();
        strcpy(pessoa[k].nomecompleto, pessoa[k].nome);
        strcat(pessoa[k].nomecompleto, " ");
        strcat(pessoa[k].nomecompleto, pessoa[k].sobrenome);
        k++;
        aberto=1;
        break;
    case 2: system ("cls");
    if (aberto==0){
        printf ("\n   NAO HÁ REGISTROS NO MOMENTO...\n");
        break;
    } else {
        printf ("=================================================================================\n");
        printf ("id | nome                                                        | idade | sexo |\n");
        printf ("---------------------------------------------------------------------------------\n");
        for (i=0;i<k;i++){
        printf ("%d  | %-60s|  %02d   |  %c   |\n", i+1, pessoa[i].nomecompleto, pessoa[i].idade, pessoa[i].sexo);}
        printf ("---------------------------------------------------------------------------------\n");}
        break;
    case 3: system ("cls");
        if (aberto==0){
        printf ("\n      BUSCAS INDISPONIVEIS...\n");
        break;
    } else {
        printf ("DIGITE A BUSCA: \n");
        fgets (busca, 30, stdin);
        busca[strcspn (busca, "\n")]=0;
        int achou = 0;
        if (achou==0){
            printf ("|     NENHUM REGISTRO NEStE SOBRENOME     |");
            break;
        } else {
        achou =1;
        printf ("---------------------------------------------------------------------------------\n");
        for (i=0;i<k;i++){
        if (strcmp(busca, pessoa[i].sobrenome) == 0){
        printf ("%d  | %-60s|  %02d   |  %c   |\n", i+1, pessoa[i].nomecompleto, pessoa[i].idade, pessoa[i].sexo);}}
        printf ("---------------------------------------------------------------------------------\n");}}
        break;
    case 0:
        printf ("\n\nENCERRANDO...\n\n");
        break;
    default: system ("cls");
        printf ("\nOPÇÃO INEXISTENTE, TENTE OUTRA...\n");
    }


    }while (opcao!=0);
    return 0;
}
