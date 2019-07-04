#include <stdio.h>
#include <stdlib.h>
#include "NodosPeroColas.h"

Cola* IniciaCola()
{
    Cola* nuevaCola = (Cola*) malloc(sizeof(Cola));
    nuevaCola->Size = 0;
    nuevaCola->IndiceInicial = NULL;
    nuevaCola->IndiceFinal = NULL;
    return nuevaCola;
}

Nodo* IniciaNodo(float dato)
{
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo->valor = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void enqueue(Cola* cola, float dato)
{
    Nodo* sust;
    if(cola->IndiceInicial == NULL)
    {
        cola->IndiceInicial = IniciaNodo(dato);
        cola->IndiceFinal = cola->IndiceInicial;
    }
    else
    {
        sust = cola->IndiceFinal;
        cola->IndiceFinal->siguiente = IniciaNodo(dato);
        cola->IndiceFinal = sust->siguiente;
    }
    cola->Size++;
}
float dequeue(Cola* cola)
{
    float dato = cola->IndiceInicial->valor;
    Nodo* sacado = cola->IndiceInicial;
    cola->IndiceInicial = sacado->siguiente;
    cola->Size--;
    free(sacado);
    return dato;
}

short isEmpty(Cola* cola)
{
    return cola->Size == 0;
}
