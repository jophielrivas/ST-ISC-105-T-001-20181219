#include <stdio.h>
#include <stdlib.h>

/*Realice un programa que, utlizando punteros permita desde una función capturar el tamaño de un arreglo, y desde otra capture
dichos valores en el arreglo. Los valores deben ser positivos. Al final, deberán imprimir los valores.

Puede modificar elprograma anterior para que ordene los elementos del arreglo, empleando sistaxis de punteros con el algoritmo de
ordenación por inserción. */

void espacio(int *size);
void valores(int *array, int *size);
void imprimir(int *array, int *size);
void ordenarinsercion(int *size, int *array);


int main()
{
    int *size;
    size= (int*) malloc(sizeof (int));
    espacio(size);
    int *array= calloc(*size, sizeof(int));
    valores(array, size);
    imprimir(array, size);
    ordenarinsercion(size, array);
    printf("\nOrdenado mediante inserci%cn:\n", 162);
    imprimir(array, size);
    return 0;
}

void espacio(int *size)
{
    do{
        printf("Ingrese el tama%co de la funci%cn: ", 164, 162);
        scanf("%d", size);
    } while(*size<=0);


}

void valores(int *array, int *size)
{
    int i;
    for(i=0; i<*size; i++)
    {
        do{
            printf("Introduzca el valor %d: ", i+1);
            scanf("%d", (array+i));
        }while(*(array+1)<0);
    }

}

void imprimir(int *array, int *size)
{
    int j;
    for(j=0; j<*size; j++)
        printf("%d\t", *(array+j));
}

void ordenarinsercion(int *size, int *array)
{
    int i, j, valoractual;

    for(i=1; i<*size; i++)
    {
        valoractual= *(array+i);
        j=i-1;
        while(j>=0 && *(array+j)>valoractual)
        {
            *(array+j+1)= *(array+j);
            j--;
        }
        *(array+j+1)= valoractual;
    }

}

