#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Nmoedas, valor, reais;
    do {
    printf ("digite um valor em centavos (ou 0 para sair): ");
    scanf ("%d", &valor);
    if (valor<0){
    printf ("valor invalido!\n");
                }
    }while(valor<0);
        if (valor==0){
    printf ("nenhuma moeda é necessaria.\n");
        return 0;
        }

        //contando quantas notas de 200 reais cabem
                Nmoedas = valor / 20000;
    if (Nmoedas > 0){
        printf ("%d moeda(s) de 200 reais\n", Nmoedas);
        valor = valor - Nmoedas*20000;
                    }

            //contando quantas notas de 100 reais cabem
            Nmoedas = valor / 10000;
        if (Nmoedas > 0){
            printf ("%d moeda(s) de 100 reais\n", Nmoedas);
            valor = valor - Nmoedas*10000;
                    }

                //contando quantas notas de 50 reais cabem
                Nmoedas = valor / 5000;
            if (Nmoedas > 0){
                printf ("%d moeda(s) de 50 reais\n", Nmoedas);
                valor = valor - Nmoedas*5000;
                    }

                    //contando quantas notas de 20 reais cabem
                    Nmoedas = valor / 2000;
                if (Nmoedas > 0){
                    printf ("%d moeda(s) de 20 reais\n", Nmoedas);
                    valor = valor - Nmoedas*2000;
                    }

                        //contando quantas notas de 10 reais cabem
                        Nmoedas = valor / 1000;
                    if (Nmoedas > 0){
                        printf ("%d moeda(s) de 10 reais\n", Nmoedas);
                        valor = valor - Nmoedas*1000;
                        }

                            //contando quantas notas de 5 reais cabem
                            Nmoedas = valor / 500;
                        if (Nmoedas > 0){
                            printf ("%d moeda(s) de 5 reais\n", Nmoedas);
                            valor = valor - Nmoedas*500;
                            }

                                //contando quantas notas de 2 reais cabem
                                Nmoedas = valor / 200;
                            if (Nmoedas > 0){
                                printf ("%d moeda(s) de 2 reais\n", Nmoedas);
                                valor = valor - Nmoedas*200;
                                }

                            //contando quantas moedas de 1 real cabem
                            Nmoedas = valor / 100;
                        if (Nmoedas > 0){
                            printf ("%d moeda(s) de 1 real\n", Nmoedas);
                            valor = valor - Nmoedas*100;
                            }

                        //contando quantas moedas de 50 centavos cabem
                        Nmoedas = valor / 50;
                    if (Nmoedas > 0){
                        printf ("%d moeda(s) de 50 centavos\n", Nmoedas);
                        valor = valor - Nmoedas*50;
                        }

                    //contando quantas moedas de 25 centavos cabem
                    Nmoedas = valor / 25;
                if (Nmoedas > 0){
                    printf ("%d moeda(s) de 25 centavos\n", Nmoedas);
                    valor = valor - Nmoedas*25;
                    }

                //contando quantas moedas de 10 centavos cabem
                Nmoedas = valor / 10;
            if (Nmoedas > 0){
                printf ("%d moeda(s) de 10 centavos\n", Nmoedas);
                valor = valor - Nmoedas*10;
                }

            //contando quantas moedas de 5 centavos cabem
            Nmoedas = valor / 5;
        if (Nmoedas > 0){
            printf ("%d moeda(s) de 5 centavos\n", Nmoedas);
            valor = valor - Nmoedas*5;
            }

        //contando quantas moedas de 1 centavo cabem
                Nmoedas = valor / 1;
    if (Nmoedas > 0){
        printf ("%d moeda(s) de 1 centavo\n", Nmoedas);
        }
    return 0;
    }
