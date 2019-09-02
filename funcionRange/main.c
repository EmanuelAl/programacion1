#include <stdio.h>
#include <stdlib.h>
#include "alderete.h"
//int getIntRange(char* mensaje,char* mensajeError,int min,int max,int, int);

int main()
{

    printf("%d",getIntRange("Ingrese edad ","Error. Ingrese edad ",18,65,3,-1));
    return 0;
}
/*int getIntRange(char* mensaje,char* mensajeError,int min,int max,int intentos,int retornoError){
    int numero;
    int cont=1;
    printf("%s",mensaje);
    scanf("%d",&numero);

    while(numero<min || numero>max){
        printf("%s",mensajeError);
        scanf("%d",&numero);
        cont++;
    if(cont==intentos){
        return retornoError;
    }
    }
    return numero;
}*/
