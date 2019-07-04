#include <stdio.h>
#include <stdlib.h>
#ifndef _Nodos
#define _Nodos

typedef struct
{
    int valor;
    struct Nodo* siguiente;
} Nodo;

typedef struct
{
    Nodo* Top;
    int TamanoPila;
}Pila;

Nodo* IniciaNodo(int x, Nodo* enlace);
Pila* IniciaPila(Pila *nuevaPila);
short isEmpty(Pila* pila);
void Push(Pila* pila, float valor);
float Pop(Pila* pila);
float Peek(Pila* pila);
#endif // _Nodos
