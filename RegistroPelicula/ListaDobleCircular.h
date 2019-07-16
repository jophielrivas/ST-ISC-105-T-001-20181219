#include <stdlib.h>
#ifndef _LISTANODOCIRCULARH
#define _LISTANODOCIRCULARH

typedef struct
{
    int id;
    char *Titulo;
    int Anyo;
    char *Clasificacion;
    float Calificacion;
    float Duracion;
    int CantidadGeneros;
    char **Generos;
    char *Sinopsis;
} Pelicula;

typedef struct sNodo
{
    Pelicula data;
    struct sNodo *anterior;
    struct sNodo *siguiente;
}Nodo;

typedef struct
{
    Nodo *Cabeza;
    int Cantidad;
}Lista;

Lista* InicializarLista();
void AgregarPelicula(Pelicula, Nodo*);
void EliminarPelicula(Lista*, Nodo*);
void InsertarPelicula(Lista*, Pelicula, int);
Nodo* BuscarPorAnyo(Lista*, int);
Nodo* BuscarPorId(Lista*, int);
void Intercambiar(Nodo*, Nodo*);
Nodo* CopiarNodo(Nodo*);

#endif // _LISTANODOCIRCULARH
