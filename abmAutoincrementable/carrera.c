#include "carrera.h"

void mostrarCarreras(eCarrera carreras[],int tam)
{

    printf(" ID        Descripcion \n");
    for(int i=0; i<tam; i++)
    {

        mostrarCarrera(carreras[i]);
    }

}
void mostrarCarrera(eCarrera carrera)
{

    printf(" %d    %s \n",carrera.id,carrera.descripcion);
}
