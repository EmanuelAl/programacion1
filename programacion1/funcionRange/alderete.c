#include "alderete.h"
int getIntRange(char* mensaje,char* mensajeError,int min,int max,int intentos,int retornoError){
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
}
