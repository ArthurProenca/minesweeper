#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void traduz(char *tratada, int lin, int col, char *saida){
    for(int i=0; i<(lin+2)*(col+2); i++){



        if(i < col+2 || i > (lin+1)*(col+2) || i%(col+2) == 0 || i%(col+2) == col+1){
            saida[i] = 0;
        }
        else{
            
        if(tratada[i] == '*'){
            saida[i] = '*';
        }
        else{
            int cont = 0;
            if(tratada[i+col] == '*'){
                cont++;
            }
            if(tratada[i-col] == '*'){
                cont++;
            }
            if(tratada[i+1] == '*'){
                cont++;
            }
            if(tratada[i-1] == '*'){
                cont++;
            }
            if(tratada[i+col+1] == '*'){
                cont++;
            }
            if(tratada[i+col-1] == '*'){
                cont++;
            }
            if(tratada[i-col+1] == '*'){
                cont++;
            }
            if(tratada[i-col-1] == '*'){
                cont++;
            }
            saida[i] = cont + '0';
        }
        }
    }
}

void ext (char *aux){
    printf("%s", aux);
}

int main(int argc, char *argv[])
{
    int lin, col;

    scanf("%d %d", &lin, &col);
    printf("[[[%d]]] ", (lin+2) * (col+2));
    

    char field [lin * col];


    //fill border with 0
    char tratada[(lin+2) * (col+2)];
    int size = (lin+2) * (col+2);
    for (int i = 0; i < size; i++)
    {
        if(i < col+2 || i > (lin+1)*(col+2) || i%(col+2) == 0 || i%(col+2) == col+1){
            tratada[i] = '.';
            printf("[%d]", i);
        }
        else{
            scanf(" %c", &tratada[i]);
            printf("%d\n", i);
        }
        
    }


    char saida[lin+2 * col+2];
    traduz(tratada, lin, col, saida);


    printf("\n");
    for(int i =0; i< lin+2; i++){
        for(int j=0; j<col+2; j++){
            printf("%c", saida[i*(col+2)+j]);
        }
        printf("\n");
    }
}
