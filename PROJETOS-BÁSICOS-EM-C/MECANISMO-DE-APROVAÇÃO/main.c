#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

float verMediaAcima(int vet[10], int limite){
int i;
float soma=0, media=0;
for (i=0; i<10; i++){
    soma+=vet[i];
}return soma/limite;
}

int main(){
setlocale(LC_ALL, "Portuguese");
int soma=0, limite=10, media, mediaGeral=7;
int vet[10];
int i, opcao=0;
char c;
void aprovado(){
    for (i=0; i<10; i++){
        if (vet[i]>=mediaGeral) {
            printf ("|       %dº ALUNO COM A NOTA: %.2f/10!       |\n", i+1, vet[i]);
        } else if (vet[i]<mediaGeral){system ("cls");
         printf ("=============> REPROVADOS <=============\n");
        printf ("|  %dº ALUNO COM A NOTA: %.2f/10!  |\n", i+1, vet[i]);}
    }printf ("===================================\n\n");
}


printf ("============: NOTAS <=============\n\n");
for (i=0; i<limite; i++){
    printf ("DIGITE A %dº ENTRADA: ", i+1);
    if (scanf ("%d%c", &vet[i], &c)!=2 || c!= '\n'){
        printf ("\nENTRADA INVALIDA! DIGITE SOMENTE NUMEROS.\n");
    while (getchar() != '\n');
    i--;
    }
}

        system ("cls");
    do {
        printf ("============> MENU <=============\n\n");
        printf ("\n1. VISUALIZAR MÉDIA\n");
        printf ("2. VISUALIZAR APROVADOS\n");
        printf ("3. VISUALIZAR REPROVADOS\n");
        printf ("4. VISUALIZAR NÚMEROS PARES\n");
        printf ("5. SAIR\n");
        printf ("\nDIGITE SUA ESCOLHA: ");
        if (scanf ("%d%c", &opcao, &c)!=2 || c!= '\n'){ system ("cls");
            printf ("\nENTRADA INVALIDA! DIGITE SOMENTE NUMEROS.\n\n");
        while (getchar() != '\n');
        continue;
}

        switch (opcao){

    case 1: system ("cls");
        float media = verMediaAcima(vet, 10);
        printf ("=========> MÉDIA <=========\n|                         |");
        printf ("\n|     A MEDIA É: %.2f     |\n", media);
        printf ("|                         |\n===========================\n\n\n");
        break;

            case 2: system ("cls");
                printf ("================> APROVADOS <================\n");
                    for (i=0; i<10; i++){
                    if (vet[i]>=mediaGeral) {
                        printf ("|       %02dº ALUNO COM A NOTA: %02d/10!        |\n", i+1, vet[i]);}
                    }   printf ("=============================================\n\n");
        break;

                    case 3: system ("cls");
                        printf ("==============> REPROVADOS <===============\n");
                            for (i=0; i<10; i++){
                            if (vet[i]<mediaGeral) {
                                printf ("|     %02dº ALUNO COM A NOTA: %02d/10...      |\n", i+1, vet[i]);}
                            }   printf ("===========================================\n\n");
        break;
                            case 4: system ("cls");
                                printf("===============> PARES <===============\n");
                                    for (i = 0; i < 10; i++){
                                    if (vet[i] % 2 == 0) {
                                        printf("|         %02dº VALOR É: ( PAR )        |\n", i+1, vet[i]);
                                    }else if (vet[i] % 2 != 0){
                                        printf("|         %02dº VALOR É: (IMPAR)        |\n", i+1, vet[i]);}
                                    }   printf("=======================================\n\n");
        break;
                    case 5: system ("cls");
                        printf ("\nENCERRANDO...\n");
        break;
        default:
            printf ("\nOPÇÃO NÃO EXISTENTE, TENTE UMA DAS TRÊS!\n\n");
}

    }while (opcao!=5);
    return 0;
}
