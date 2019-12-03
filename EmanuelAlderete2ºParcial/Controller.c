#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Cachorro.h"

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

        printf("\n\n ID \t  NOMBRE \t DIAS \t RAZA \t RESERVADO \t GENERO \n\n");

        for(int i=0; i < ll_len(pArrayListCachorro); i++)
        {
            cachorro = ll_get(pArrayListCachorro,i);//obtengo el elemento
            cachorro_getNombre(cachorro, nombre);
            cachorro_getId(cachorro,&id);
            cachorro_getDias(cachorro,&dias);
            cachorro_getRaza(cachorro,raza);
            cachorro_getReservado(cachorro,reservado);
            cachorro_getGenero(cachorro,genero);

            printf("%d  %20s %20d %20s %20s %20s \n", id, nombre, dias, raza,reservado,genero);
        }
        todoOk=1;
    }
    return todoOk;
}
