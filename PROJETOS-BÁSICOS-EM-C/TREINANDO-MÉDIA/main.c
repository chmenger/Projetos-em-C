#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

float analisarMediaAcima(float pacotes[10], int limite){
int i;
float total=0, media=0;
for (i = 0; i < limite; i++){
total+=pacotes[i];
}
return total/limite;
}

int main()
{   setlocale(LC_ALL,"Portuguese");
    float pacotes[10];
    int i;
    char extra;
    for (i=0;i<10;i++){
     printf("ESCREVA A %dº POSIÇÃO DO PACOTE: ",i+1);
     if (scanf ("%f%c", &pacotes[i], &extra)!=2 || extra!= '\n'){
        printf ("DIGITE APENAS NÚMEROS!\n\n");
        while (getchar() != '\n');
        i--;
     }
    } system ("cls");
    float media = analisarMediaAcima(pacotes,10);
    printf ("=== MEDIA ===\nA MEDIA É: ---%.2f---\n\n", media);
    for (i=0; i<10; i++){
    if (pacotes[i]>media) {
    printf ("===O PACOTE %dº É ACIMA DA MÉDIA!===\nCOM O VALOR DE: %.2f\n\n", i, pacotes[i]);
    }}
    return 0;
}
