#include <stdio.h>
#include <stdlib.h>

int main()
{
    char auxChar;
    FILE* f= fopen("archivo.txt", "r");// creamos un archivo para escritura
    char mensaje[30] = "Esto es un mensaje";

    char cadena[30];
    if( f == NULL ){
        printf("No se pudo abrir el archivo\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    //fwrite(mensaje, sizeof(char),strlen(mensaje), f);
    //fprintf(f,"%s",mensaje);//funcion para escribir en el archivo
    //fscanf(f,"%s", cadena);
    while(!feof(f)){// mientras no llegue al final del archivo

        // fgets(cadena,29,f);
        //printf("%s", cadena);
        //printf("%c", auxChar);
        fread(cadena,sizeof(char), 29,f);
        printf("%s", cadena);
    }



    fclose(f);// cierra el archivo

    return 0;
}
