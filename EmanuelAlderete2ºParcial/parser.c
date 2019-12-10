#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Cachorro.h"

/** \brief Parsea los datos los datos de los cachorros desde el archivo cachorros.csv (modo texto).
 *
* \param FILE* pFile puntero al archivo
 * \param pArrayListCachorro LinkedList* puntero a la lista con la cual se trabajará
 * \return int (-1)Error: si el puntero a la lista es NULL o el puntero al archivo es NULL
                (1) si se pudo realizar la operación
 *
 */
int parser_CachorroFromText(FILE* pFile, LinkedList* pArrayListCachorro)
{
    int todoOk=-1;
    Cachorro* auxCachorro;
    char auxId[30];
    char auxNombre[30];
    char auxDias[30];
    char auxRaza[30];
    char auxReservado[30];
    char auxGenero[10];

//    char nombre[30];

    int cant;
  //  int r;
    if(pFile != NULL && pArrayListCachorro!=NULL)
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxDias,auxRaza,auxReservado,auxGenero);
        while( !feof(pFile))
        {
            cant = fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", auxId, auxNombre, auxDias,auxRaza,auxReservado,auxGenero);
            printf(" %s  %s %s %s %s %s %d \n ",auxId,auxNombre,auxDias,auxRaza,auxReservado,auxGenero,cant);
             //devolvera la cantidad que pudo cargar
            if( cant == 6)//si pudo cargar los 6
            {
                auxCachorro = cachorro_new();
                cachorro_setId(auxCachorro,atoi(auxId));
                cachorro_setNombre(auxCachorro,auxNombre);
                cachorro_setDias(auxCachorro,atoi(auxDias));
                cachorro_setRaza(auxCachorro,auxRaza);
                cachorro_setReservado(auxCachorro,auxReservado);
                cachorro_setGenero(auxCachorro,auxGenero);
                ll_add(pArrayListCachorro,auxCachorro);
                //strcpy(nombre, auxNombre);
                /*
                auxCachorro = cachorro_newParametros(auxId, auxNombre,auxDias,auxRaza,auxReservado,auxGenero);

                if( auxCachorro != NULL)
                {
                    r = ll_add(pArrayListCachorro,auxCachorro);//guarda el puntero en una posicion de la lista
                    if(r==0)
                    {
                        printf(" Se agrego a la lista con exito\n ");
                        todoOk=1;
                    }
                    else if(r==-1)
                    {
                        printf(" No se pudo agregar elemento a la lista\n ");
                    }
                }*/
            }
        }
        fclose(pFile);
        todoOk=1;
    }else{
        printf("Archivo vacio");
    }
    return todoOk;
}
