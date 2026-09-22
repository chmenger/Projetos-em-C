#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>


    int validar(int registro) {
        if (registro == 0) {
            system ("cls");
            printf("\nERRO: REGISTRE AS MATRIZES PRIMEIRO!\n\n");
            return 1;
        }
        return 0;
    }

    float exibirMatriz(float resultado[3][3], int registro) {
        validar(registro);
        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                printf("%.2f\t", resultado[x][y]);
            }
            printf ("\n");
        }
    }

    void lerMatriz(float matriz[3][3], char nome) {
    printf("Digite os valores para a Matriz %c (3x3):\n", nome);
        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                printf("%c[%d][%d]: ", nome, x, y);
                scanf("%f", &matriz[x][y]);
            }
        }
    }

    int somaMatrizes(float A[3][3], float B[3][3], float resultado[3][3], int registro) {
        if (validar(registro)) {
        return 1;
        }

        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                resultado[x][y] = A[x][y] + B[x][y];
            }
        }
        exibirMatriz(resultado, registro);
        return 0;
    }

    int subMatrizes(float A[3][3], float B[3][3], float resultado[3][3], int registro) {
        if (validar(registro)) {
        return 1;
        }

        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                resultado[x][y] = A[x][y] - B[x][y];
            }
        }
        exibirMatriz(resultado, registro);
    }

    int multMatrizes(float A[3][3], float B[3][3], float resultado[3][3], int registro) {
        if (validar(registro)) {
        return 1;
        }

        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                resultado[x][y] = A[x][y] * B[x][y];
            }
        }
        exibirMatriz(resultado, registro);
    }

    int divMatrizes(float A[3][3], float B[3][3], float resultado[3][3], int registro) {
        if (validar(registro)) {
        return 1;
        }

        for(int x = 0; x < 3; x++) {
            for(int y = 0; y < 3; y++) {
                if (B[x][y]==0){
                    system ("cls");
                    printf ("ERRO: DIVISAO POR ZERO DETECTADA!\n\n");
                    return 1;
                }
                resultado[x][y] = A[x][y] / B[x][y];
            }
        }
        exibirMatriz(resultado, registro);
    }

int main(){
    setlocale (LC_ALL, "Portuguese");
    float matA[3][3], matB[3][3], resultado[3][3];
    int opcao, registro=0;
    char extra;

    do {
    printf ("==========> MENU <==========\n\n");
    printf ("1. REGISTRAR NÚMEROS\n");
    printf ("2. SOMA\n");
    printf ("3. SUBTRAÇÃO\n");
    printf ("4. MULTIPLICAÇÃO\n");
    printf ("5. DIVISÃO\n");
    printf ("0. SAIR\n");
    if (scanf (" %d%c", &opcao, &extra)!=2 || extra!='\n'){
    system ("cls");
    printf ("OPÇÃO INVÁLIDA, TENTE OUTRA...\n\n");
    while (getchar()!='\n');
    continue;}
    switch (opcao){

    case 1: system ("cls");
            printf ("============== MATRIZ [A] ==============\n\n");
            lerMatriz(matA, 'A');
            printf ("============== MATRIZ [B] ==============\n\n");
            lerMatriz(matB, 'B');
            registro=1;
            break;
    case 2:
        somaMatrizes(matA, matB, resultado, registro);
        break;

    case 3:
        subMatrizes(matA, matB, resultado, registro);
        break;

    case 4:
        multMatrizes(matA, matB, resultado, registro);
        break;

    case 5:
        divMatrizes(matA, matB, resultado, registro);
        break;

    case 0:
        printf ("\n\nENCERRANDO...\n\n");
        break;

    default:
        system ("cls");
        printf ("OPCÃO INEXISTENTE, TENTE OUTRA...\n\n");
    break;
    }
    }while (opcao!=0);
    return 0;
}




