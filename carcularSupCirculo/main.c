#include <stdio.h>
#include <stdlib.h>

float  calcularSupCirculo( float radio);
int main()
{   float r;
    float sup;
    printf("ingrese radio: ");
    scanf("%f",&r);
    sup=calcularSupCirculo(r);
    printf("la superficie es %.2f \n\n",sup);
    return 0;
}
float calcularSupCirculo( float radio){
float sup;
sup=radio*3.14;

return sup;
}
