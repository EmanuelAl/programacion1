
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "imput.h"


int getInt (char mensaje[])
{
    int auxiliarInt;
    printf("%s", mensaje);
    scanf("%d", &auxiliarInt);
    return auxiliarInt;
}


char getChar (char mensaje[])
{
    char auxiliarChar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &auxiliarChar);
    return auxiliarChar;
}


float getFloat(char mensaje[])
{
    float auxiliarFloat;
    printf("%s", mensaje);
    scanf("%f", &auxiliarFloat);
    return auxiliarFloat;
}




int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
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


int isAlphaNumeric(char str[])
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
void concatenar(char destino[],char str1[],char str2[]){

int i=0;
int j=0;
    while(str1[i]!='\0'){
        destino[i]=str1[i];
        i++;
    }

    destino[i]='.';
    i++;
    while(str2[j]!='\0'){
        destino[i+j]=str2[j];
        j++;
    }
    destino[i+j]='\0';
}
char validar(){
   char letra;
printf(" confirma salir? s/n \n");
fflush(stdin);
scanf("%c",&letra);
while(!((letra=='S')||(letra=='N') ||(letra=='s')||(letra=='n')))
{
printf("\n Ha ingresado opcion no valida...Reintente el ingreso(S/N)\n ");
fflush(stdin);
scanf("%c",&letra);
}
if(letra=='s' || letra=='S'){
    letra='s';
}else if(letra=='s' || letra=='S'){
    letra='n';
}
return letra ;

}
