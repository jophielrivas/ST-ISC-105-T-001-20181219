#include <stdlib.h>
#include "ListaDobleCircular.h"


Lista* InicializarLista()
{
    Lista *nuevaLista = (Lista*)malloc(sizeof(Lista));
    nuevaLista->Cantidad = 0;
    nuevaLista->Cabeza = (Nodo*)malloc(sizeof(Nodo));
    nuevaLista->Cabeza->data.id = -1;
    nuevaLista->Cabeza->siguiente = nuevaLista->Cabeza;
    nuevaLista->Cabeza->anterior = nuevaLista->Cabeza;
    return nuevaLista;
}

void AgregarPelicula(Pelicula elemento, Nodo *despuesDe)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->data = elemento;
    nuevo->siguiente = despuesDe->siguiente;
    nuevo->anterior = despuesDe;
    despuesDe->siguiente->anterior = nuevo;
    despuesDe->siguiente = nuevo;
}

Nodo* BuscarPorId(Lista *listado, int id)
{
    Nodo *nodoActual = listado->Cabeza->siguiente;

    while(nodoActual->data.id != -1)
    {
        if(nodoActual->data.id == id)
            return nodoActual;
        nodoActual = nodoActual->siguiente;
    }

    return NULL;
}

void EliminarPelicula(Lista *listado, Nodo *aEliminar)
{
    if(aEliminar->data.id == -1)
        return;
    aEliminar->anterior->siguiente = aEliminar->siguiente;
    aEliminar->siguiente->anterior = aEliminar->anterior;

    free(aEliminar);
}

Nodo* BuscarPorAnyo(Lista *listado, int anyo)
{
    Nodo *nodoActual = listado->Cabeza->siguiente;

    while(nodoActual->data.id != -1)
    {
        if(nodoActual->data.Anyo > anyo)
            return  nodoActual->anterior;

        nodoActual = nodoActual->siguiente;
    }
    return nodoActual->anterior;
}

Nodo* CopiarNodo(Nodo *original)
{
    Nodo *copia = (Nodo*)malloc(sizeof(Nodo));

    copia->data = original->data;
    copia->anterior = original->anterior;
    copia->siguiente = original->siguiente;
}

void Intercambiar(Nodo *primero, Nodo *segundo)
{
    Nodo *auxPrimero = CopiarNodo(primero);

    primero->anterior->siguiente = segundo;
    primero->anterior = segundo->anterior;
    primero->siguiente->anterior = segundo;
    primero->siguiente = segundo->siguiente;
    segundo->siguiente = auxPrimero->siguiente;
    segundo->anterior->siguiente = primero;
    segundo->anterior = auxPrimero->anterior;
    primero->siguiente->anterior = primero;

    free(auxPrimero);
}



void InsertarPelicula(Lista*, Pelicula, int);

Lista* OrdenarPeliculaSeleccion(Lista* listado)
{
    Nodo *nodoActual = listado->Cabeza->siguiente;
    Nodo *nodoMenor;
    Nodo *temporal;

    while(nodoActual->data.id != -1)
    {
        nodoMenor = nodoActual;
        temporal = nodoActual->siguiente;
        while(temporal->data.id != -1)
        {
            if(temporal->data.Anyo < nodoMenor->data.Anyo)
            {
                nodoMenor = temporal;
            }
            temporal = temporal->siguiente;
        }
        Intercambiar(nodoActual, nodoMenor);
        nodoActual = nodoActual->siguiente;
    }
}
