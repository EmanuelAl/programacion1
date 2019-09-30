#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct{
int id;
char descripcion[20];

}eComida;

#endif // COMIDA_H_INCLUDED
void mostrarComidas(eComida comidas[], int tam);
void mostrarComida(eComida comidas);
int cargarDescComida(int id, eComida comidas[], int tam, char desc[]);
