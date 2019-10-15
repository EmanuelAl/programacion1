
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "input.h"

 int esNumerica(char* cadena)
{
    int ret=-1;
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]<'0' || cadena[i]>'9')
                break;
            i++;
        }
        if(cadena[i]=='\0')
            ret=1;
    }
    return ret;
}
 int getInt(int* pResultado)
{
    int ret=-1;
    char buffer[8];
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';
    if(esNumerica(buffer))
    {
        *pResultado = atoi(buffer);
        ret=1;
    }
    return ret;
}
int getNumeroIntentos(int* pResultado,
                  char* mensaje,
                  char* mensajeError,
                  int minimo,
                  int maximo,
                  int reintentos)
{
    int ret;
    int num;
    while(reintentos>0)
    {
        printf(mensaje);
        if(getInt(&num)==1)
        {
            if(num<=maximo && num>=minimo)
                break;
        }
        reintentos--;
        printf(mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }
    else
    {
        ret=0;
        *pResultado = num;
    }
    return ret;
}
int getNumero(int* pResultado,
                  char* mensaje,
                  char* mensajeError,
                  int minimo,
                  int maximo)
{
    int ret=-1;
    int num;
    int flag=0;
    while(flag==0)
    {
        printf(mensaje);
        if(getInt(&num)==1)
        {
            if(num<=maximo && num>=minimo){
                 printf(mensajeError);
            }else{
                flag=1;
            }
        }

    }
        *pResultado = num;
        ret=0;
    return ret;
}
char getChar (char mensaje[])
{
    char auxiliarChar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &auxiliarChar);
    return auxiliarChar;
}

/*int getInt (char mensaje[])
{
    int auxiliarInt;
    printf("%s", mensaje);
    scanf("%d", &auxiliarInt);
    return auxiliarInt;
}*/

float getFloat(char mensaje[])
{
    float auxiliarFloat;
    printf("%s", mensaje);
    scanf("%f", &auxiliarFloat);
    return auxiliarFloat;
}

int esNumerico (char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        return 0;
        i++;
    }
    return 1;
}
int esOpcionNumerico (char str[],char minimo,char maximo)
{
    int i=0;
    while (str[i] != '\0')
    {
        if (str[i] < minimo || str[i] > maximo)
        return 0;
        i++;
    }
    return 1;
}


int esSoloLetras(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
    }
    return 1;
}

int esAlfaNumerico(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        return 0;
        i++;
    }
    return 1;
}

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", mensaje);
    gets(input);
}

int getStringLetras(char mensaje[], char input[])
{
    char auxiliar[256];
    getString(mensaje, auxiliar);
    if(esSoloLetras(auxiliar))
    {
        strcpy(input, auxiliar);
        return 1;
    }

    return 0;
}

int getStringNumeros(char mensaje[], char input[])
{
    char auxiliar[256];
    getString(mensaje, auxiliar);
    if(esNumerico(auxiliar))
    {
        strcpy(input, auxiliar);
        return 1;
    }

    return 0;
}

int getAlfaNumerico(char mensaje[], char input[])
{
    char auxiliar[256];
    getString(mensaje, auxiliar);
    if(esAlfaNumerico(auxiliar))
    {
        strcpy(input,auxiliar);
        return 1;
    }
    return 0;
}
unsigned int verifica(void)
{
char letra;
printf("\nIngrese opcion...S/N?");
letra=toupper(getche());
while(!((letra=='S')||(letra=='N')))
{
printf("\nHa ingresado opci¢n no valida...Reintente el ingreso(S/N)... ");
letra=toupper(getche());
}
return (letra=='S');
}

char  verificarOpcionSoloLetras(void)
{
char letra;
printf("\nIngrese opcion: \n");
letra=toupper(getche());
while((letra!= ' ') && (letra <  'a' || letra > 'i') && (letra < 'A' || letra > 'I'))
{
printf("\nHa ingresado opcion no valida...Reintente el ingreso...\n ");
letra=toupper(getche());
}
return letra;
}
