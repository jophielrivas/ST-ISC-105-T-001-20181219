#include <stdio.h>
#include <stdlib.h>
#include "Nodos.h"

void MostrarEncabezadoHistograma();
void MostrarElementoHistograma(int, float, float);
void MostrarPieHistograma(int, float);

int main()
{
    Pila *pila;
    int cantidad = 0;
    float nuevoValor, total = 0;

    pila= IniciaPila(pila);

    do
    {
        printf("Digite un valor (-1 para terminar): ");
        scanf("%f", &nuevoValor);

        if(nuevoValor >= 0)
        {
            Push(pila, nuevoValor);
            total += nuevoValor;
        }
    }
    while(nuevoValor >= 0);

    MostrarEncabezadoHistograma();
    do
    {
        cantidad++;
        nuevoValor = Pop(pila);
        MostrarElementoHistograma(cantidad,
                                  nuevoValor,
                                  nuevoValor/total*100);
        printf("\n");
    }while(!isEmpty(pila));

    return 0;
}

void MostrarEncabezadoHistograma()
{
    system("cls");
    printf("HISTOGRAMA\n\n");
    printf("No.:\tValor:\tProporci%cn:\n", 162);
}

void MostrarElementoHistograma(int secuencia, float valor, float proporcion)
{
    int cantidadCaracteres = (int)proporcion;
    printf("%d\t%.2f\t",secuencia,valor);

    while(cantidadCaracteres-- > 0)
        printf("%c", 219);

    printf(" %.2f%%", proporcion);
}

void MostrarPieHistograma(int cantidad, float total)
{
    printf("Se han mostrado %d elmentos. Total: %.2f", cantidad, total);
}
