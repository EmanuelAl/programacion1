#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char auxId[50];
    char auxNombre[50];
    char auxHorasTrabajadas[50];
    char auxSueldo[50];

    int cant;
    if(pFile != NULL){
        while( !feof(pFile)){
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas ,auxSueldo);//devolvera la cantidad que pudo cargar
        if( cant == 4)//si pudo cargar los tres
        {
            id = atoi(auxId);//funcion que convierte el parametro ingresado a tipo int
            strcpy(auxNombre, auxNombre);
            sueldo = atoi(auxSueldo);//funcion que convierte el parametro ingresado a tipo float
            sueldo = atoi(auxSueldo)
            auxEmpleado = newEmpleadoParam(id, nombre, sueldo);

            if( auxEmpleado != NULL)
            {
                *(lista + tam) = auxEmpleado;//guarda el puntero en una posicion de la lista
                tam++;

                if((lista = agrandarLista(lista, tam + 1 )) == NULL)
                {
                    printf("No se pudo agrandar la lista");

                }
        }
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
