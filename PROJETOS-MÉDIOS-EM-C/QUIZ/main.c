#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int validar(char resp, char gabarito) {
    if (gabarito == 'A') {
        if (resp == 'A' || resp == 'a') return 1;
    } else if (gabarito == 'B') {
        if (resp == 'B' || resp == 'b') return 1;
    } else if (gabarito == 'C') {
        if (resp == 'C' || resp == 'c') return 1;
    }
    return 0;
    }
int i, opcao;
int soma=0, aberto=0;
char resp[10], pontos[10] = {0,0,0,0,0,0,0,0,0,0};
char gabarito [10] = {'A','C','B','A','B','C','A','A','B','B'};
char perguntas [10] [100] =
   {"1. Tipo para numeros inteiros?\n A) int\n B) float\n C) char\n R = ",
    "2. Operador 'E' Lógico?\n A) ||\n B) !\n C) &&\n R = ",
    "3. Comando para sair de um loop?\n A) continue\n B) break\n C) exit\n R = ",
    "4. Qual o caractere de fim de string?\n A) \\0\n B) \\n\n C) \\t\n R = ",
    "5. Qual funcao lê do teclado?\n A) printf\n B) scanf\n C) main\n R = ",
    "6. Qual operador e o 'OU' logico?\n A) &&\n B) !\n C) ||\n R = ",
    "7. Como declarar um vetor de 5 ints?\n A) int v[5]\n B) v{5}\n C) int v5\n R = ",
    "8. Qual biblioteca usa printf?\n A) stdio.h\n B) math.h\n C) string.h\n R = ",
    "9. Qual o resto de 10 %% 3?\n A) 0\n B) 3\n C) 1\n R = ",
    "10. O que significa 'void' na funcao?\n A) Erro\n B) Sem retorno\n C) Inteiro\n R = "};
void calcular() {scanf (" %c", &resp[i]);
    pontos[i]=validar(resp[i], gabarito[i]);}

int main(){  setlocale(LC_ALL, "Portuguese");
int extra;
    do {
    printf ("\n\n==============\n     QUIZ\n==============\n");
    printf ("\n1. ABRIR QUIZ\n");
    printf ("2. VER DESEMPENHO\n");
    printf ("3. SAIR\n");
    printf ("\nDIGITE SUA OPCÃO:");
    if (scanf ("%d%c", &opcao, &extra)!=2 || extra!='\n') { system ("cls");
        while (getchar()!='\n');
        opcao = -1;}

            switch (opcao){
        case 1: system ("cls");
        aberto=1;
        i=0;
            printf ("\n=====> QUESTÕES <=====\n");
            for (i=0; i<10; i++){
            printf ("\n%s", perguntas[i]);
            calcular();}
        break;
        case 2:system ("cls");
            if (aberto==0){
                printf ("FAÇA O QUIZ PRIMEIRO!");
            continue;}
        printf ("\n\n====================\n     DESEMPENHO\n====================\n");
        soma=0;
            for (i=0; i<10; i++) {
                printf ("Q%02d - ", i+1);
            if (pontos[i]==1){
                printf ("CORRETO\n");
        soma++;
            }else {
                printf ("INCORRETO\n");}
        }
        printf ("SUA NOTA FOI DE: %d/10!\n", soma);
        if (soma >=8){
            printf ("\nOLOKO AI TA TOP, PARABEEENS!! < = DD");
        }else if (soma>=5){
            printf ("\nESTUDA UM POUQUINHO MAIS...  | = /");
        }else if (soma>=3){
        printf ("\nVAMO QUERER SE ESFORÇAR MAIS??! > = [");
        }else {
        printf ("\nPEDE PRA SAIR QUE GASTA MENOS DINHEIRO > = 0");
        }
        break;
        case 3:
        printf ("\nENCERRANDO...\n");
        break;
    default: system ("cls");
        printf ("ENTRADA INVÁLIDA, DIGITE NOVAMENTE!\n");
     continue;}
    }while (opcao!=3);
    return 0;
}
