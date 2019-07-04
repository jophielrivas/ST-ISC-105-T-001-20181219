#include <stdlib.h>
#include "Colas.h"

const int TAM = 10;


Cola* InicializarCola()
{
    Cola *nuevaCola = (Cola*)malloc(sizeof(Cola));
    nuevaCola->Primerindice = 0;
    nuevaCola->Ultimoindice = -1;
    nuevaCola->tamano = TAM;
    nuevaCola->elementos = (float*)calloc(TAM,sizeof(float));
    nuevaCola->cantidad = 0;
    return nuevaCola;
}
short isEmpty(Cola *cola)
{
    return cola->cantidad == 0;
}

void enqueue(Cola *cola,float elemento )
{
    //Si no hay espacio, redimensionar el arreglo.
    verificarespacio(cola);

    cola->Ultimoindice++;
    if(cola->Ultimoindice >= cola->tamano)
        cola->Ultimoindice = 0;


    //cola->elementos+cola->Ultimoindice = (float*)malloc(sizeof(float));
    *(cola->elementos+cola->Ultimoindice) = elemento;
    cola->cantidad++;

}
int Tamanocola(Cola *cola)
{
    return cola->cantidad;
}
void verificarespacio(Cola *cola)
{
    int i;
    if(Tamanocola(cola) < cola->tamano)
        return;
    float *nuevoEspacio = (float*)malloc(cola->tamano * 2);

    i = cola->Primerindice;
    while( i != cola->Ultimoindice)
    {
        *(nuevoEspacio++) = *(cola->elementos + i++);

        if(i == cola->tamano)
        {
            i = 0;
        }
    }
    cola->elementos = nuevoEspacio - cola->cantidad;
    cola->Primerindice = 0;
    cola->Ultimoindice = cola->cantidad-1;
    cola->tamano = cola->tamano*2;
}
float dequeue(Cola *cola)
{
    if(isEmpty(cola))
        return 0;
    float respuesta = *(cola->elementos+cola->Primerindice);
    cola->Primerindice++;
    if(cola->Primerindice>= cola->tamano)
        cola->Primerindice = 0;
    cola->cantidad--;

    return respuesta;
}
float Getfront(Cola *cola)
{
    if(isEmpty(cola))
    return 0;

    return *(cola->elementos+cola->Primerindice);
}
