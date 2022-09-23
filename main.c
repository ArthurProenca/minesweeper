#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void traduz(char *tratada, int lin, int col, char *saida)
{
    for(int i =0; i<(lin+2) * (col+2); i++){
        if(tratada[i] == '*'){
            saida[i] = tratada[i];
        }else{
            int cont = 0; 
            //ESQUERDA
            if(tratada[i-1] == '*'){
                cont++;
            }
            //DIREITA
            if(tratada[i+1] == '*'){
                cont++;
            }
            //SUPERIOR ESQUERDA
            if(tratada[i-col-1] == '*'){
                cont++;
            }
            //SUPERIOR DIREITA
            if(tratada[i-col+1] == '*'){
                cont++;
                printf(">>>>%d", i);
            }
            //SUPERIOR
            if(tratada[i-col] == '*'){
                cont++;
            }
            //INFERIOR
            if(tratada[i+col] == '*'){
                cont++;
            }
            //INFERIOR DIREITA
            if(tratada[i+col+1] == '*'){
                cont++;
            }
            //INFERIOR ESQUERDA
            if(tratada[i+col-1] == '*'){
                cont++;
            }
            saida[i] = cont + '0';
        }
    }
}


int main(int argc, char *argv[])
{
    int lin, col;

    scanf("%d %d", &lin, &col);
    printf("[[[%d]]] ", (lin + 2) * (col + 2));

    char entrada[9] = {'.','*','.','.','.','*','.','.','.'};

    char field[lin * col];

    // fill border with 0
    char tratada[(lin + 2) * (col + 2)];
    int size = (lin + 2) * (col + 2);
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (i < col + 2 || i > (lin + 1) * (col + 2) || i % (col + 2) == 0 || i % (col + 2) == col + 1)
        {
            tratada[i] = '.';
            //printf("[%d]", i);
        }
        else
        {
            tratada[i] = entrada[k];
            k++;
        }
    }

    char saida[(lin + 2) * (col + 2)];

    traduz(tratada, lin, col, saida);

    printf("\n\n\n\n\n");
    for (int i = 0; i < lin + 2; i++)
    {
        for (int j = 0; j < col + 2; j++)
        {
            printf("%c", saida[i * (col + 2) + j]);
        }
        printf("\n");
    }
}
