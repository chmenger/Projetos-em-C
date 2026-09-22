#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nome, genero, idade;
    printf ("diga seu nome: ");
    scanf ("%d", &nome);
    printf ("nos fale seu genero: ");
    scanf ("%d", &genero);
    printf ("nos fale sua idade: ");
    scanf ("%d", &idade);

    if (idade >= 18)
        printf ("você está autorizado!");
    else
        printf ("você é de menor!");
    return 0;


