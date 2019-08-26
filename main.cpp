#include <iostream>

using namespace std;
int sumar1(int a, int b);

int main()
{
    int numero1;
    int numero2;
    int suma;

    printf("ingrese un numero: ");
    scanf("%d",&numero1);
    printf("ingrese un numero: ");
    scanf("%d",&numero2);

    suma=sumar1(numero1,numero2);

    printf("la suma de la funcion es %d\n",suma);
    return 0;
}
int sumar1(int a, int b){
    int suma;

    suma=a+b;
    return suma;

}
