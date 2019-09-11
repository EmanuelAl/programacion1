#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20];
    char apellido[20];
    char nombreCompleto[]= {};
    char auxCad[100];
    int i;

    printf("ingrese apellido ");
    fflush(stdin);
    gets(auxCad);
    /* printf("ingrese apellido");
     gets(apellido);*/

    while(strlen(auxCad)> 19)
    {
        printf("Error. ingrese apellido ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(apellido,auxCad);

    printf("ingrese nombre ");
    gets(auxCad);
    while(strlen(auxCad)> 19)
    {
        printf("Error. ingrese nombre ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(nombre,auxCad);

    /*printf("%s ",apellido);
    printf("%s ",nombre);*/

    strcpy(nombreCompleto,apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr(nombreCompleto);

    nombreCompleto[0] = toupper(nombreCompleto[0]);//

    while(nombreCompleto[i] != '\0')
    {
        if(nombreCompleto[i] == ' ')
        {
            nombreCompleto[i+1] = toupper(nombreCompleto[i]);//toupper pasa a mayuscula la inicial(en este caso el apellido
        }
        i++;
    }


    printf("%s",nombreCompleto);

    return 0;
}
