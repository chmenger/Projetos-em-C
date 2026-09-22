#include <stdio.h>
#include <stdlib.h>


int main()
{
    int sinal;
    float num, num2;
    float resultado;

    void printar (){
        printf ("\n DIGITE O PRIMEIRO NUMERO: ");
        scanf ("%f", &num);
        printf ("\n AGORA DIGITE O SEGUNDO NUMERO: ");
        scanf ("%f", &num2);}

    do {
        printf ("\n---- CALCULADORA INTERATIVA ---- ");
        printf ("\n 1. SOMA");
        printf ("\n 2. SUBTRACAO");
        printf ("\n 3. MULTIPLICACAO");
        printf ("\n 4. DIVISAO");
        printf ("\n 0. SAIR");
        printf ("\n ESCREVA UMA OPCAO: ");
        scanf ("%d", &sinal);

        if (sinal<0 && sinal>4){
            printf ("OPCAO INVALIDA, TENTE NOVAMENTE!");
        }

        switch (sinal){

        case 1: system ("cls");
            printf ("==== SOMA ====\n");
            printar();
            resultado=num+num2;
            printf ("\nO RESULTADO E: %.2f\n", resultado);
            break;

        case 2: system ("cls");
            printf ("==== SUBTRACAO ====\n");
            printar();
            resultado=num-num2;
            printf ("\nO RESULTADO E: %.2f\n", resultado);
            break;

        case 3: system ("cls");
            printf ("==== MULTIPLICACAO ====\n");
            printar();
            resultado=num*num2;
            printf ("\nO RESULTADO E: %.2f\n", resultado);
            break;

        case 4: system ("cls");
            printf ("==== DIVISAO ====\n");
            printf ("\n DIGITE O PRIMEIRO NUMERO: ");
            scanf ("%f", &num);
            printf ("\n AGORA DIGITE O SEGUNDO NUMERO: ");
            scanf ("%f", &num2);
                if (num2 != 0){
                    resultado=num/num2;
                    printf ("\nO RESULTADO E %.2f\n", resultado);
                    }else {
                    printf ("NUMERO INVALIDO (ERRO)");}
            break;
        case 0:
            printf ("\nENCERRANDO...\n");
            break;
        default: system ("cls");
            printf ("OPCAO INVALIDA, TENTE NOVAMENTE!");
                    }
    } while (sinal!=0);
return 0;
}

