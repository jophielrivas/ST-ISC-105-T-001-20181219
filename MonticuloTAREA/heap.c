#include <stdlib.h>
#include <math.h>
#include "heap.h"

Heap* Inicializar(short esMin)
{
    const int altura = 10;
    Heap* nuevoHeap = (Heap*)malloc(sizeof(Heap));
    nuevoHeap->altura = altura;
    nuevoHeap->tamano = pow(2, altura) - 1;
    nuevoHeap->esMin = esMin;
    nuevoHeap->posicionActual = 0;
    nuevoHeap->elementos = (float*)calloc(nuevoHeap->tamano, sizeof(float));
    return nuevoHeap;
}

void VerificarEspacio(Heap* heap)
{
    if(heap->posicionActual < heap -> tamano)
        return;
    heap->altura++;
    heap->tamano = pow(2, heap->altura);
    heap->elementos = (float*)realloc(heap->elementos, heap->tamano*(sizeof(float)));
}

void Insertar(Heap* heap, float elemento)
{
    VerificarEspacio(heap);
    *(heap->elementos + heap->posicionActual++) = elemento;
    HeapifyUp(heap, heap->posicionActual - 1);
}

int IndicePadre(int indice)
{
    int result = (indice-1)/2;
    return result < 0 ? 0: result;
}

int IndiceHijoIzquierdo(Heap* heap, int indice)
{
    int result = (indice*2+1);
    return result < heap->posicionActual ? result : -1;
}

int IndiceHijoDerecho(Heap* heap, int indice)
{
    int result = (indice*2+2);
    return result < heap->posicionActual ? result : -1;
}

void Swap(float* desde, float* hasta)
{
    float burbuja = *desde;
    *desde = *hasta;
    *hasta = burbuja;
}

void HeapifyUp(Heap* heap, int indice)
{
    if(indice == 0)
        return;
    int indicePadre = IndicePadre(indice);
    if(heap->esMin && *(heap->elementos + indicePadre) < *(heap->elementos+indice))
        return;
    if(!heap->esMin && *(heap->elementos + indicePadre) > *(heap->elementos+indice))
        return;

    Swap(heap->elementos + indicePadre, heap->elementos + indice);

    HeapifyUp(heap, indicePadre);
}

void HeapifyDown(Heap* heap,int indice)
{
    int indiceMenor = IndiceHijoIzquierdo(heap, indice);
    int indiceDerecho = IndiceHijoDerecho(heap, indice);
    if(indiceMenor < 0)
        return;
    if(indiceDerecho >= 0 && *(heap->elementos+indiceMenor) > *(heap->elementos+indiceDerecho))
        indiceMenor = indiceDerecho;

    if(!(heap->esMin) && *(heap->elementos+indice) < *(heap->elementos+indiceMenor))
        return;

    Swap(heap->elementos+indice,heap->elementos+indiceMenor);
    HeapifyDown(heap, indiceMenor);
}

float GetTop(Heap* heap)
{
    return *(heap->elementos);
}

float Poll(Heap* heap)
{
    if(heap->posicionActual == 0)
    {
        return *(heap->elementos);
    }

    float raiz = GetTop(heap);

    Swap(heap->elementos, heap->elementos + --(heap->posicionActual));

    HeapifyDown(heap, 0);

    return raiz;
}

int Size(Heap* heap)
{
    return heap->posicionActual;
}

short isEmpty(Heap* heap)
{
    return heap->posicionActual == 0;
}
