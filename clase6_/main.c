#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*char nombre[10];
    char auxCad[100];
    int cant;

    printf("ingrese nombre: ");
    gets(auxCad);

    while( strlen(auxCad) > 9)  //strlen nos devuelve el largo del string que le pasamos como parametro
    {
        printf("Error. nombre demasiado largo");
        gets(auxCad);

    }
    //strcpy(nombre,auxCad );//copia una cadena al vector nombre

    strncpy(nombre,"juan ignacio alberto",6);

    printf("%s \n",nombre);*/

    char n1[10] = "Juan";
    char n2[10]= "Juana";
    int x;

    x= strcmp(n1,n2);//compara y devuelve 1 0-1 si es igual o no el tamaño del largo de la cadena
    printf("%d \n",x);

    //funciones a investigar : stricmp,strcat,strlur(? y strupr

    return 0;
}
