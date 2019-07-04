#include <stdlib.h>

#ifndef _Heap
#define _Heap

typedef struct
{
    int altura;
    int tamano;
    int posicionActual;
    short esMin;
    float* elementos;
}Heap;

Heap* Inicializar(short esMin);
void VerificarEspacio(Heap* heap);
void Insertar(Heap* heap, float elemento);
int IndicePadre(int indice);
int IndiceHijoIzquierdo(Heap* heap, int indice);
int IndiceHijoDerecho(Heap* heap, int indice);
void Swap(float* desde, float* hasta);
void HeapifyUp(Heap* heap, int indice);
void HeapifyDown(Heap* heap, int indice);
float GetTop(Heap* heap);
float Poll(Heap* heap);
int Size(Heap* heap);
short isEmpty(Heap* heap);


#endif // _Heap
