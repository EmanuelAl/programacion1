#ifndef __BICICLETA
#define __BICICLETA
typedef struct{
    int idBici;
    char nombre[50];
    char tipo[50];
    int tiempo;
}Bicicleta;
#endif

Bicicleta* bicicleta_new();
int bicicleta_setId(Bicicleta* this,int id);
int bicicleta_getId(Bicicleta* this,int* id);
int bicicleta_setNombre(Bicicleta* this,char* nombre);
int bicicleta_getNombre(Bicicleta* this,char* nombre);
int bicicleta_setTipo(Bicicleta* this,char* tipo);
int bicicleta_getTipo(Bicicleta* this,char* tipo);
int bicicleta_setTiempo(Bicicleta* this,int tiempo);
int bicicleta_getTiempo(Bicicleta* this,int* tiempo);

int bicicleta_esBMX(void* element);
int bicicleta_esPLAYERA(void* element);
int bicicleta_esMTB(void* element);
int bicicleta_esPASEO(void* element);
