#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

#define MAX_PESSOAS 5
#define MAX_QUEST 7

typedef struct {
char jogador[30];// é do CASE 2
} jogador;
typedef struct {
char pergunta [30]; // AS PERGUNTAS DO CASE 1
char gabarito;
} quiz;
jogador usuarios[MAX_PESSOAS];
quiz questao[MAX_QUEST];




/*quiz usuario[MAX_PESSOAS]; // CASE 2
quiz questao[MAX_QUEST]; // CASE 1
quiz defina[GABARITO];// CASE 1/3
quiz respostas[GABARITO];*/


int validar (int cadastro, int questionario){
        if (cadastro==0){
        return 1;
        }else if (questionario==0){
            return 1;
        }
return 0;
}





/*resp = respostas[r].game
resolvido = defina[q].gabarito*/


int respostain (char resp, char resolvido, char pontos[MAX_QUEST]) {
    if (resolvido == 'V') {
        if (resp == 'V' || resp == 'v') return 1;
    } else if (resolvido == 'F') {
        if (resp == 'F' || resp == 'f') return 1;
    }
    return 0;
    }
/*defina[GABARITO].gabarito
int validar (char resp, char gab){
        pontos[10] = {0,0,0,0,0,0,0,0,0,0};
        if (strcmp(defina[r].gabarito, respostas[r].game) == 0){
            return 1;
        }else if (strcmp(respostas[r].game, defina[r].gabarito) != 0) {
            return 0;}}

    void calcular() {scanf (" %c", &resp[i]);
    pontos[i]=validar(resp[i], gabarito[i]);}*/

int jogando (int comecar, int player[MAX_PESSOAS], int status){
    int i;
    status=0;
    for (i=0; i<MAX_PESSOAS; i++){
if (comecar=player[i]){
    return status;}}
return 0;}









int main()
{ setlocale (LC_ALL, "Portuguese");
    int cad=0, quest=0, status1=0;
    char c;
    int jogou[MAX_PESSOAS] = {0};
    int pontos[MAX_PESSOAS] = {0};
    int opcao, escolha[MAX_PESSOAS]={0};
    int i=0, k=0, j=0, q=0, r=0, g=0;


    do {
    printf("\n======== QUIZ PERGUNTAS =======\n\n");
    printf("1. CADASTRAR PERGUNTAS (%d/7): \n", q);
    printf("2. CADASTRAR JOGADORES (%d/5): \n", i);
    printf("3. JOGAR\n");
    printf("4. VER RANKING\n");
    printf("0. SAIR\n");
    printf("DIGITE A OPÇÃO: \n");
    if (scanf ("%d", &opcao)!=1){
        system ("cls");
        printf ("ERRO: OPÇÃO INVÁLIDA...\n\n");
        while (getchar()!= '\n');
        opcao=-1;
        continue;}

    switch (opcao){

        case 1: system ("cls");
            getchar();
            printf ("\n====== CADASTRO DAS PERGUNTAS ======\n");
                for (q=0; q<MAX_QUEST; q++){
                    printf ("\nCRIE A %dº QUESTÃO:\n - ", q+1);
                    fgets (questao[q].pergunta, 30, stdin);
                    questao[q].pergunta[strcspn (questao[q].pergunta, "\n")]=0;
                    printf ("DEFINA: V ou F  -  ");
                    scanf (" %c", &questao[q].gabarito);}
            quest=1;
            break;
        case 2: system ("cls");
            if (i==MAX_PESSOAS){
                printf ("\n   LIMITE DE JOGADORES [5]... ");
                break;}
            printf ("\n====== CADASTRO DOS JOGADORES ======\n\n");
            printf ("DIGITE O NOME DO USUÁRIO: \n");
            getchar();
            fgets (usuarios[i].jogador, 30, stdin);
            usuarios[i].jogador[strcspn (usuarios[i].jogador, "\n")]=0;
            pontos[i]=0;
            cad=1;
            i++;
            break;
        case 3: system ("cls");
            if (validar (cad,quest)){
                printf ("\nOPÇÃO SEM PERMISSÃO...\n\n");
                continue;}
                printf ("\n\n======= PLAY =======\n\n");
                    for (j=0; j<i; j++){
                        if (jogou[j]==0){
                            printf ("[%d]| %-30s| (DISPONIVEL) |\n", j+1, usuarios[j].jogador);
                        } else {
                            printf ("[%d]| %-30s| (JA JOGOU) |\n", j+1, usuarios[j].jogador);}}
                        if (escolha=jogou[j]!=0){
                            printf ("JA JOGOOOOUU...!");
                        }
                        printf ("\n\nESCOLHA O JOGADOR: ");
                        if (scanf ("%d", &escolha)!=1 ){
                            system ("cls");
                            printf ("ERRO: OPÇÃO INVÁLIDA...\n\n");
                            while (getchar()!= '\n');
                            continue;}

                            while (getchar() != '\n');
                            pontos[escolha] = 0;

                            printf ("========== QUESTIONÁRIO ==========\n\n");
                            printf ("  RESPONDA AS QUESTÕES ABAIXO...\n");
                            for (r=0; r<MAX_QUEST; r++){
                                char resp;
                                printf ("__________________________________");
                                printf ("\n%02d - %s - ASSINALE:\nv) VERDADEIRA\nF) FALSA\nR:", r+1, questao[r].pergunta);
                                scanf (" %c", &resp);
                                    if ((resp == 'V' || resp == 'v') && (questao[r].gabarito == 'V' || questao[r].gabarito == 'v')){
                                        printf("CORRETO!\n");
                                        pontos[escolha] += 10;
                                    }
                                    else if ((resp == 'F' || resp == 'f') && (questao[r].gabarito == 'F' || questao[r].gabarito == 'f')){
                                        printf("CORRETO!\n");
                                        pontos[escolha] += 10;
                                    }
                                    else{
                                        printf("INCORRETO!\n");
                                    }
                            }
                            printf("\nPONTUAÇÃO FINAL: %d\n", pontos[escolha[r]]);
                            break;



                        /*switch (escolha){



                  case 1: case 2: case 3: case 4: case 5: system ("cls");
                  getchar();
                  printf ("========== QUESTIONÁRIO ==========\n\n");
                  printf ("  RESPONDA AS QUESTÕES ABAIXO...\n");
                    for (r=0; r<MAX_QUEST; r++){
                        printf ("__________________________________");
                        printf ("\n%02d - %s - ASSINALE:\nv) VERDADEIRA\nF) FALSA\nR:", r+1, questao[r].pergunta);
                        fgets (respostas[r].game, 30, stdin);
                        respostas[r].game[strcspn (respostas[r].game, "\n")]=0;
                            if (strcmp(defina[r].gabarito, respostas[r].game) == 0){
                                printf ("-----CORRETO-----\n");
                                if (respostain (respostas[r].game, defina[r].gabarito)){
                                point[r]=+1;
                                }
                            } else if (strcmp(respostas[r].game, defina[r].gabarito) != 0) {
                                printf ("-----INCORRETO-----\n");}}
                                break;

                                default: system ("cls");
                                printf ("OPÇÃO INVÁLIDA...");
                                continue;}*/

        case 4:
            system("cls");

            // BUBBLE SORT
            for (int x = 0; x < i - 1; x++){
                for (int y = 0; y < i - x - 1; y++){

                    if (pontos[y] < pontos[y+1]){

                        int temp = pontos[y];
                        pontos[y] = pontos[y+1];
                        pontos[y+1] = temp;

                        jogador tempJ = usuarios[y];
                        usuarios[y] = usuarios[y+1];
                        usuarios[y+1] = tempJ;
                    }
                }
            }
            printf("\n=== RANKING ===\n");

            for (int g = 0; g < i; g++){
                printf("[%d] %s - %d pontos\n", g+1, usuarios[g].jogador, pontos[g]);
            }
            break;

        case 0:
            printf ("\n\nENCERRANDO...\n\n");
            break;

        default: system ("cls");
            printf ("\nOPÇÃO INVÁLIDA...\n\n");
            break;
        }

    }while (opcao!=0);

  return 0;
}
