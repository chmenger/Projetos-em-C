#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, fatorial=1;
    int sair;
    do {
    printf ("==== MENU =======================\n\n");
    printf("1. FATORAR\n");
    printf("2. SAIR\n\n");
    printf ("ESCOLHA UMA OPCAO: ");
    scanf ("%d", &sair);

    switch (sair){

    case 1: system ("cls");
        printf ("==== FATORANDO ==================\n\n");
        printf ("DIGITE UM NUMERO PARA FATORAR: ");
        scanf ("%d", &num);
        for (i=1; i<=num; i++)
            fatorial *= i;
            printf ("O RESULTADO E: %d\n\n", fatorial);
            break;
    case 2: system ("cls");
        printf ("==== PROGRAMA ENCERRADO ====\n");
        printf ("\nSAINDO DO PROGRAMA EM 3, 2, 1...\n");
        break;
    default: system ("cls");
        printf ("OPCAO INVALIDA, TENTE NOVAMENTE!");
    }
    } while (sair!=2);
return 0;
}
