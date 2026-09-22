#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>

int main(){   setlocale (LC_ALL, "Portuguese");

int opcao, resultado, confirmar=0;
char usuario[50], senha[50];


    do {
        printf ("===== MENU =====\n\n");
        printf ("1. CADASTRO: \n");
        printf ("2. LOGAR: \n");
        printf ("\nESCOLHA UMA OPÇÃO: \n");
        scanf ("%d", &opcao);
        setbuf(stdin, NULL);

        switch (opcao){

    case 1: system ("cls");
        confirmar=0;
        do {
            printf ("===== CADASTRO =====\n\n");
            printf ("DIGITE O USUÁRIO: ");
            fgets(usuario, 100, stdin);
            usuario[strcspn(usuario, "\n")] = 0;
            do {
                printf ("DIGITE A SENHA (MÍNIMO 8 CARACTERES): ");
                fgets(senha, 100, stdin);
                senha[strcspn(senha, "\n")] = 0;
                resultado = strcmp(usuario, senha);
                system ("cls");
            if (resultado==0){
                printf ("SENHA NÃO PODE SER IGUAL AO USUÁRIO!\n\n");}
            if (strlen (senha)<8){ system ("cls");
                printf ("SENHA FRACA, DIGITE NOVAMENTE!\n\n");
                }
                /*continue;*/
        }while (strlen (senha)<8);
        }while (resultado==0);
            system ("cls");
            printf ("CADASTRO REALIZADO COM SUCESSO!\n");
            char *i=senha;
            confirmar=+1;
        break;

    case 2: system ("cls");
        confirmar==0;
        if (confirmar==0){
            printf ("SEM CADASTRO!\n\n");
        break;
        }else if (confirmar=1){
            confirmar+=1;
            printf ("=====> CADASTRADO <=====\n\n");
            printf ("BEM VINDO, %s! \n\n", usuario);}
            printf ("========================\n");
        break;
        }
    }while (confirmar!=2);

    printf ("USUÁRIO: %s\n", usuario);
    printf ("SENHA: %s\n", senha);
    printf ("========================\n\n");

   return 0;
}
