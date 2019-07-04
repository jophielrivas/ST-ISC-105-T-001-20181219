#include <stdlib.h>

#ifndef _Colash
#define _Colash

typedef struct
{
    float *elementos;
    int tamano;
    int Primerindice;
    int Ultimoindice;
    int cantidad;
}Cola;

Cola* InicializarCola();
void enqueue(Cola*,float);
short isEmpty(Cola*);
float Getfront(Cola*);

int Tamanocola(Cola*);
void verificarespacio(Cola*);
float dequeue(Cola*);

#endif // _Colash
