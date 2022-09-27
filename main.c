#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostraJogo(int lin, int col, char *saida)
{
    for (int i = 0; i < lin + 2; i++)
    {
        for (int j = 0; j < col + 2; j++)
        {
            printf("%c", saida[i * (col + 2) + j]);
        }
        printf("\n");
    }
}

void traduz(char *tratada, int lin, int col, char *saida)
{
    for (int i = 0; i < (lin + 2) * (col + 2); i++)
    {
        if (tratada[i] == '*')
        {
            saida[i] = tratada[i];
        }
        else
        {
            int cont = 0;
            if(tratada[i - 1] == '*')
            {
                cont++;
            }
            if(tratada[i + 1] == '*')
            {
                cont++;
            }
            if(tratada[i - col - 2] == '*')
            {
                cont++;
            }
            if(tratada[i + col + 2] == '*')
            {
                cont++;
            }
            if(tratada[i - col - 3] == '*')
            {
                cont++;
            }
            if(tratada[i + col + 3] == '*')
            {
                cont++;
            }
            if(tratada[i - col - 1] == '*')
            {
                cont++;
            }
            if(tratada[i + col + 1] == '*')
            {
                cont++;
            }

            if (i < col + 2 || i > (lin + 1) * (col + 2) || i % (col + 2) == 0 || i % (col + 2) == col + 1)
            {
                saida[i] = '.';
            } else {
                saida[i] = cont + '0';
            }

        }
    }
}

int main(int argc, char *argv[])
{
    int lin, col;

    scanf("%i", &lin);
    scanf("%i", &col);

    char field[lin * col];

    // fill border with 0
    char tratada[(lin + 2) * (col + 2)];

    int size = (lin + 2) * (col + 2);

    int k = 0;

    for (int i = 0; i < size; i++)
    {
        if (i < col + 2 || i > (lin + 1) * (col + 2) || i % (col + 2) == 0 || i % (col + 2) == col + 1)
        {
            tratada[i] = 'O';
        }
        else
        {
            scanf(" %c", &tratada[i]);
        }
    }

    char saida[(lin + 2) * (col + 2)];

    traduz(tratada, lin, col, saida);

    printf("\n\n\n\n\n");
    mostraJogo(lin, col, tratada);
    printf("\n\n\n\n\n");
    mostraJogo(lin, col, saida);
}
