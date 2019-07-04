#include <stdio.h>
#ifndef _NodosColas
#define _NodosColas

typedef struct
{
    int valor;
    struct Nodo* siguiente;
} Nodo;

typedef struct
{
    Nodo* IndiceInicial;
    Nodo* IndiceFinal;
    int Size;
}Cola;

Cola* IniciaCola();
Nodo* IniciaNodo(float dato);
void enqueue(Cola* cola, float dato);
float dequeue(Cola* cola);
short isEmpty(Cola* cola);

#endif // _NodosColas
