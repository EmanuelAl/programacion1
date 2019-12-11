#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Bicicleta.h"
#include "parser.h"
/** \brief Carga los datos de las bicicletas desde el archivo indicado (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayList LinkedList* puntero a la lista con la cual se trabajará
 * \return int (-1)Error: si el puntero a la lista es NULL o el puntero al path es NULL
                (1) si se pudo realizar la operación
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    int todoOk=-1;
    FILE* pFile=fopen(path, "r");//modo lectura

    if(pFile!=NULL && path!=NULL && pArrayList!=NULL){


        todoOk= parser_BicicletaFromText(pFile,pArrayList);
    }else{
        printf("el archivo no existe");
    }
    fclose(pFile);

    return todoOk;
}


/** \brief Listar Bicicletas
 *

 * \param pArrayList LinkedList*
 * \return int (-1)Error: si el puntero a la lista es NULL
                (1) si todo sale bien
 *
 */
int controller_ListBicicletas(LinkedList* pArrayList)
{
    int todoOk = -1;
    char nombre[50];
    char tipo[50];
    int tiempo;
    int id;


    Bicicleta* bicicleta;

    if(pArrayList != NULL)
    {
        if(ll_isEmpty(pArrayList)==1){//pregunta si esta vacia la lista

            printf(" no hay datos que mostrar \n ");

        }else if(ll_isEmpty(pArrayList)==0){//si no esta vacia muestra los datos

            printf("\n\n ID \t  NOMBRE \t TIPO \t\t TIEMPO  \n\n");

            for(int i=0; i < ll_len(pArrayList); i++)
            {
            bicicleta = ll_get(pArrayList,i);//obtengo el elemento
            bicicleta_getNombre(bicicleta, nombre);
            bicicleta_getId(bicicleta,&id);
            bicicleta_getTipo(bicicleta,tipo);
            bicicleta_getTiempo(bicicleta,&tiempo);


            printf("%d  %15s %15s %10d \n", id, nombre, tipo, tiempo);
                }
                todoOk=1;
        }

    }
    return todoOk;
}
/** \brief Guarda los datos de las bicicletas en el archivo que sea indicado (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayList LinkedList* puntero a la lista con la cual se trabajará
 * \return int (-1)Error: si el puntero a la lista es NULL o el puntero al path es NULL
                (1) si se pudo realizar la operación
 *
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayList)
{

    FILE* pArchivo;
    Bicicleta* bicicletaAux;

    int retorno = -1;

    int* auxiliarID;
    char* auxiliarNombre;
    int* auxiliarTiempo;
    char* auxiliarTipo;

    if(pArrayList != NULL && path != NULL)
    {
        retorno = 1;
        auxiliarID = malloc(sizeof(int));
        auxiliarNombre = malloc(sizeof(char)*100);
        auxiliarTipo = malloc(sizeof(int));
        auxiliarTiempo = malloc(sizeof(int));

        pArchivo = fopen(path, "w");//modo escritura
        fprintf(pArchivo,"id,nombre,tipo,tiempo\n");

        for(int i=0; i< ll_len(pArrayList); i++)
        {
            bicicletaAux = ll_get(pArrayList,i);
            //fwrite(cachorroAux, sizeof(Cachorro),1,pArchivo);

            bicicleta_getNombre(bicicletaAux, auxiliarNombre);
            bicicleta_getId(bicicletaAux,auxiliarID);
            bicicleta_getTipo(bicicletaAux,auxiliarTipo);
            bicicleta_getTiempo(bicicletaAux,auxiliarTiempo);

            fprintf(pArchivo,"%d,%s,%s,%d\n",*auxiliarID,auxiliarNombre,auxiliarTipo,*auxiliarTiempo);

        }

        free(auxiliarNombre); free(auxiliarID); free(auxiliarTipo); free(auxiliarTiempo);
        fclose(pArchivo);
    }
    return retorno;
}
