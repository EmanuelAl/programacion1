#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    FILE* pFile=NULL;
    pFile=fopen(path,"r");//modo lectura
    if(pFile!=NULL){
        parser_EmployeeFromText(pFile,pArrayListEmployee);
        todoOk=1;
    }
    fclose(pFile);

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    FILE* pFile=NULL;
    pFile=fopen(path,"r");//modo lectura
    if(pFile!=NULL){
        parser_EmployeeFromText(pFile,pArrayListEmployee);
        todoOk=1;
    }
    fclose(pFile);

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* aux;

    int todoOk = -1;

    int* auxId;
    char* auxNombre;
    int* auxSalario;
    int* auxHoras;

    if(pArrayListEmployee != NULL && path != NULL)
    {

        auxId = malloc(sizeof(int));
        auxNombre = malloc(sizeof(char)*100);
        auxSalario = malloc(sizeof(int));
        auxHoras = malloc(sizeof(int));

        f = fopen(path, "w");
        fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");

        for(int i=0; i< ll_len(pArrayListEmployee); i++)
        {
            aux = ll_get(pArrayListEmployee,i);
            employee_getId(aux,auxId);
            employee_getSueldo(aux,auxSalario);
            employee_getNombre(aux, auxNombre);
            employee_getHorasTrabajadas(aux,auxHoras);
            fprintf(f,"%d,%s,%d,%d\n",*auxId,auxNombre,*auxSalario,*auxHoras);

            todoOk=1;
        }

        free(auxNombre); free(auxId); free(auxSalario); free(auxHoras);
        fclose(f);
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
        FILE* f=NULL;
        Employee* auxEmployee;

    int todoOk = -1;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        f = fopen(path,"wb");

        for(int i=0; i< ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee,i);//obtengo cada elemento del array
            fwrite(auxEmployee, sizeof(Employee),1,f);
        }
        todoOk=1;

    }
     fclose(f);
    return todoOk;
}

