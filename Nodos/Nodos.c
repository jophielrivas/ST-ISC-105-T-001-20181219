#include <stdio.h>
#include <stdlib.h>
#include "Nodos.h"

Pila* IniciaPila(Pila *nuevaPila)
{
    nuevaPila = (Pila*)malloc(sizeof(Pila));
    nuevaPila->TamanoPila = 0;
    nuevaPila->Top = NULL;
    return nuevaPila;
}

Nodo* IniciaNodo(int x, Nodo* enlace)
{
    Nodo* nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = x;
    nuevo->siguiente = enlace;
    return nuevo;
}


short isEmpty(Pila* pila)
{
    return pila->TamanoPila == 0;
}

float Peek(Pila* pila)
{
    return pila->Top->valor;
}

void Push(Pila* pila, float dato)
{
    pila->Top = IniciaNodo(dato, pila->Top);
    pila->TamanoPila++;

    return pila;
}

float Pop(Pila* pila)
{
    Nodo* ultim = pila->Top;
    int valor = pila->Top->valor;
    if(pila->Top->siguiente != NULL)
        pila->Top = ultim->siguiente;
    free(ultim);
    pila->TamanoPila--;
    return valor;

}
