#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Cachorro.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListCachorro)
{
    int todoOk=-1;
    FILE* pFile= pFile=fopen(path, "r");//modo lectura

    if(pFile!=NULL && path!=NULL && pArrayListCachorro!=NULL){


        todoOk= parser_CachorroFromText(pFile,pArrayListCachorro);
    }else{
        printf("el archivo no existe");
    }
    fclose(pFile);

    return todoOk;
}


/** \brief Listar empleados
 *

 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListCachorro(LinkedList* pArrayListCachorro)
{
    int todoOk = -1;
    char nombre[50];
    char raza[50];
    char reservado[50];
    char genero[10];
    int id;

    int dias;


    Cachorro* cachorro;

    if(pArrayListCachorro != NULL)
    {

        printf("\n\n ID \t  NOMBRE \t DIAS \t\t RAZA \t RESERVADO \t GENERO \n\n");

        for(int i=0; i < ll_len(pArrayListCachorro); i++)
        {
            cachorro = ll_get(pArrayListCachorro,i);//obtengo el elemento
            cachorro_getNombre(cachorro, nombre);
            cachorro_getId(cachorro,&id);
            cachorro_getDias(cachorro,&dias);
            cachorro_getRaza(cachorro,raza);
            cachorro_getReservado(cachorro,reservado);
            cachorro_getGenero(cachorro,genero);

            printf("%d  %15s %10d %15s %10s %10s \n", id, nombre, dias, raza,reservado,genero);
        }
        todoOk=1;
    }
    return todoOk;
}
int controller_saveAsText(char* path, LinkedList* pArrayListCachorro)
{

    FILE* pArchivo;
    Cachorro* cachorroAux;

    int retorno = -1;

    int* auxiliarID;
    char* auxiliarNombre;
    int* auxiliarDias;
    char* auxiliarRaza;
    char* auxiliarReservado;
    char* auxiliarGenero;

    if(pArrayListCachorro != NULL && path != NULL)
    {
        retorno = 1;
        auxiliarID = malloc(sizeof(int));
        auxiliarNombre = malloc(sizeof(char)*100);
        auxiliarDias = malloc(sizeof(int));
        auxiliarRaza = malloc(sizeof(char)*100);
        auxiliarReservado= malloc(sizeof(char)*100);
        auxiliarGenero = malloc(sizeof(char)*100);

        pArchivo = fopen(path, "w");//modo escritura
        fprintf(pArchivo,"id,nombre,dias,raza,reservado,genero\n");

        for(int i=0; i< ll_len(pArrayListCachorro); i++)
        {
            cachorroAux = ll_get(pArrayListCachorro,i);
            //fwrite(cachorroAux, sizeof(Cachorro),1,pArchivo);
            cachorro_getId(cachorroAux,auxiliarID);
            cachorro_getNombre(cachorroAux,auxiliarNombre);
            cachorro_getDias(cachorroAux, auxiliarDias);
            cachorro_getRaza(cachorroAux,auxiliarRaza);
            cachorro_getReservado(cachorroAux,auxiliarReservado);
            cachorro_getGenero(cachorroAux,auxiliarGenero);

            fprintf(pArchivo,"%d,%s,%d,%s,%s,%s\n",*auxiliarID,auxiliarNombre,*auxiliarDias,auxiliarRaza,auxiliarReservado,auxiliarGenero);

        }

        free(auxiliarNombre); free(auxiliarID); free(auxiliarDias); free(auxiliarRaza);free(auxiliarReservado);free(auxiliarGenero);
        fclose(pArchivo);
    }
    return retorno;
}
