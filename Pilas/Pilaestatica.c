#include <stdio.h>
#include <string.h>
#include "Pilaestatica.h"

const int TAM = 100;

Pila* IniciarPila()
{
    Pila *nuevaPila = (Pila*)malloc(TAM * sizeof(Pila));
    nuevaPila->PosicionActual = 0;
    nuevaPila->TamanoPila = TAM;
    nuevaPila->Pila = (float*)malloc(TAM * sizeof(float));
    return nuevaPila;
}

void VerificarEspacio(Pila *pila)
{
    if(pila->PosicionActual + 1 < pila->TamanoPila)
        return;

    pila->Pila = (float*)realloc(pila->Pila, pila->TamanoPila + 100);
    pila->TamanoPila = pila->TamanoPila + 100;
}

void Push(Pila *pila, float elemento)
{
    VerificarEspacio(pila);
    *(pila->Pila+pila->PosicionActual) = elemento;
    pila->PosicionActual++;
}

float Pop(Pila *pila)
{
    float valor = *(pila->Pila+pila->PosicionActual-1);
    pila->PosicionActual--;
    return valor;
}

int Size(Pila *pila)
{
    return pila->PosicionActual;
}

short isEmpty(Pila *pila)
{
     return pila->PosicionActual==0;
}

float Peek(Pila *pila)
{
    float valor = Pop(pila);
    Push(pila, valor);
    return valor;
}
