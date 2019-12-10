#ifndef __CACHORRO
#define __CACHORRO
typedef struct{
    int id;
    char nombre[50];
    int dias;
    char raza[50];
    char reservado[10];
    char genero[10];

}Cachorro;

#endif
Cachorro* cachorro_new();
Cachorro* cachorro_newParametros(char* idStr,char* nombreStr,char* dias,char* raza,char* reservado,char*genero);
int cachorro_setId(Cachorro* this,int id);
int cachorro_getId(Cachorro* this,int* id);
int cachorro_setNombre(Cachorro* this,char* nombre);
int cachorro_getNombre(Cachorro* this,char* nombre);
int cachorro_setDias(Cachorro* this,int dias);
int cachorro_getDias(Cachorro* this,int* dias);
int cachorro_setRaza(Cachorro* this,char* raza);
int cachorro_getRaza(Cachorro* this,char* raza);
int cachorro_setReservado(Cachorro* this,char* reservado);
int cachorro_getReservado(Cachorro* this,char* reservado);
int cachorro_setGenero(Cachorro* this,char* genero);
int cachorro_getGenero(Cachorro* this,char* genero);

int cachorro_esMenor45Dias(void* element);
int cachorro_esMacho(void* element);
int cachorro_esCallejero(void* element);
