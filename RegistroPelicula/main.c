#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "conio.c"
#include "ListaDobleCircular.h"


typedef enum
{
    Salir = 0,
    Agregar = 1,
    Modificar = 2,
    Eliminar = 3,
    Insertar = 4,
    Explorar = 5,
    Buscar = 6,
    Ordenar = 7
} eSeleccionMenu;

eSeleccionMenu MostrarMenu();
void MostrarMarco();
void CapturarPelicula(Lista *listado,  Nodo *aModificar, short esInicio);
void ExplorarPeliculas(Lista *listado, Nodo*);
void MostrarMarcoTresColumnas();
void MostrarPeliculaEnColumna(Pelicula aMostrar, int numeroColumna);
void MostrarSinopsis (int col, int fila, int limite, char* texto);
const int COL2 = 26, COL3 = 52, LIMCOLUMNA = 24;
void ModificarPelicula(Lista *listado);
void BorrarPelicula(Lista*);
void BuscarPeliculaPorAnyo(Lista*);
void OrdenarPeliculasPorAnyo(Lista*);

int main()
{
    Lista *listadoPeliculas = InicializarLista();
    eSeleccionMenu opcionActual;
    do
    {
       opcionActual = MostrarMenu();

       switch(opcionActual)
       {
            case Agregar:
                CapturarPelicula(listadoPeliculas, NULL, 0);
                break;
            case Modificar:
                ModificarPelicula(listadoPeliculas);
                break;
            case Eliminar:
                BorrarPelicula(listadoPeliculas);
                break;
            case Insertar:
                CapturarPelicula(listadoPeliculas, NULL, 1);
                break;
            case Explorar:
                ExplorarPeliculas(listadoPeliculas, NULL);
                break;
            case Buscar:
                BuscarPeliculaPorAnyo(listadoPeliculas);
                break;
            case Ordenar:
                OrdenarPeliculasPorAnyo(listadoPeliculas);
                break;
       }
    }while(opcionActual != Salir);



    return 0;
}

void MostrarMarco()
{
    int i;
    system("cls");

    printf("%c", 201);
    for(i = 0; i < 63; i++)
        printf("%c", 205);
    printf("%c\n", 187);
    for(i = 0; i < 3; i++)
        printf("%c\t\t\t\t\t\t\t\t%c\n", 186, 186);
    printf("%c", 186);
    for(i = 0; i < 63; i++)
        printf("%c", 205);
    printf("%c\n", 186);
    for(i = 0; i < 19; i++)
        printf("%c\t\t\t\t\t\t\t\t%c\n", 186, 186);
    printf("%c", 200);
    for(i = 0; i < 63; i++)
        printf("%c", 205);
    printf("%c\n", 188);

}

eSeleccionMenu MostrarMenu()
{
    char seleccion;

    do
    {
        MostrarMarco();
        gotoxy(22,3);
        printf("Gesti%cn de Pel%cculas",162, 161);
        gotoxy(5, 7);
        printf("1: Agregar una pel%ccula.", 161);
        gotoxy(5, 9);
        printf("2: Modificar una pel%ccula dado un ID.", 161);
        gotoxy(5, 11);
        printf("3: Eliminar una pel%ccula dado un ID.", 161);
        gotoxy(5, 13);
        printf("4: Agregar una pel%ccula en orden de a%co.", 161, 164);
        gotoxy(5, 15);
        printf("5: Explorar las pel%cculas registardas.", 161);
        gotoxy(5, 17);
        printf("6: Buscar una pel%ccula por a%co.", 161, 164);
        gotoxy(5, 19);
        printf("7: Ordenar las pel%cculas.", 161);
        gotoxy(5, 21);
        printf("0: Salir.", 161);

        fflush(stdin);
        _setcursortype(0);
        seleccion = getch() - 48;

    }while(seleccion<0 || seleccion>7);

    _setcursortype(1);
    return seleccion;

}


void CapturarPelicula(Lista *listado, Nodo *aModificar, short enOrden)
{
    short generosSeleccionados[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int seleccion, i, j=0;
    Pelicula nuevaPelicula;
    system("cls");
    MostrarMarco();
    gotoxy(10,3);
    if(aModificar == NULL)
        printf("Agregando nueva pel%cula al final de la lista.", 161);
    else
        printf("Modificando Pel%ccula Existente.", 161);
    gotoxy(5,7);
    printf("Id: ");
    if(aModificar != NULL)
    {
        printf("%d", aModificar->data.id);
        nuevaPelicula.id = aModificar->data.id;
    }
    else
        scanf("%d", &nuevaPelicula.id);

    gotoxy(5,9);
    printf("T%ctulo (hasta 100 letras): ", 161);
    nuevaPelicula.Titulo = (char*)malloc(100);
    fflush(stdin);
    gets(nuevaPelicula.Titulo);
    gotoxy(5, 11);
    printf("A%co: ", 164);
    scanf("%d", &nuevaPelicula.Anyo);
    gotoxy(5, 13);

    do
    {
        printf("Seleccione una clasificaci%cn: \n\t\t", 162);
        printf("1: G (prop%csito general)\n\t\t", 162);
        printf("2: PG (supervisi%cn parental)\n\t\t", 162);
        printf("3: PG-13 (no apta para menores de 13 a%cos.)\n\t\t", 164);
        printf("4: R (restringido para mayor de edad)\n\t\t");
        printf("5: NC-17 (solo adultos)\n\t\t");
        printf("Seleccione: ");
        seleccion = getch() - 48;
    }while(seleccion < 1 || seleccion > 5);
    nuevaPelicula.Clasificacion = (char*)calloc(6, sizeof(char));
    switch(seleccion)
    {
        case 1:
            strcpy(nuevaPelicula.Clasificacion, "G");
            break;
        case 2:
            strcpy(nuevaPelicula.Clasificacion, "PG");
            break;
        case 3:
            strcpy(nuevaPelicula.Clasificacion, "PG-13");
            break;
        case 4:
            strcpy(nuevaPelicula.Clasificacion, "R");
            break;
        case 5:
            strcpy(nuevaPelicula.Clasificacion, "NC-17");
            break;
    }
    gotoxy(5, 21);
    printf("Calificaci%cn: ", 162);
    scanf("%f", &nuevaPelicula.Calificacion);
    gotoxy(5, 23);
    printf("Duraci%cn (minutos): ", 162);
    scanf("%f", &nuevaPelicula.Duracion);

    do
    {
        do
        {
            system("CLS");
            MostrarMarco();
            gotoxy(10,3);
            printf("Agregando nueva pel%cula al final de la lista.", 161);


            gotoxy(5, 7);
            printf("Seleccione los g%cneros de la pel%cula:\n\t", 130, 161);
            printf("1: Acci%cn\t", 162);
            printf("2: Aventura\t");
            printf("3: Comedia\n\t");
            printf("4: Drama\t");
            printf("5: Terror\t");
            printf("6: Musical\n\t");
            printf("7: C. ficci%cn\t", 162);
            printf("8: Suspenso\t");
            printf("9: Infantil\n\n\t");
            printf("0: Salir\n\n\t");
            printf("Seleccione: ");
            fflush(stdin);
            seleccion = getch() - 48;
        }while(seleccion < 0 || seleccion > 9);

        if(seleccion != 0 && generosSeleccionados[seleccion - 1] > 0)
        {
            generosSeleccionados[seleccion - 1] = 0;
            j--;
        }
        else if(seleccion != 0 && generosSeleccionados[seleccion - 1] <= 0)
        {
            generosSeleccionados[seleccion - 1] = 1;
            j++;
        }
    }while(seleccion != 0);

    nuevaPelicula.CantidadGeneros = j;
    nuevaPelicula.Generos = (char**)malloc(sizeof(char*)*j);

    for(i=0, j=0; i<9; i++)
    {
        if(generosSeleccionados[i])
        {
            *(nuevaPelicula.Generos+j) = (char*)calloc(20, sizeof(char));

            switch(i)
            {
                case 0:
                    strcpy(*(nuevaPelicula.Generos+j), "Accion");
                    break;
                case 1:
                    strcpy(*(nuevaPelicula.Generos+j), "Aventura");
                    break;
                case 2:
                    strcpy(*(nuevaPelicula.Generos+j), "Comedia");
                    break;
                case 3:
                    strcpy(*(nuevaPelicula.Generos+j), "Drama");
                    break;
                case 4:
                    strcpy(*(nuevaPelicula.Generos+j), "Terror");
                    break;
                case 5:
                    strcpy(*(nuevaPelicula.Generos+j), "Musical");
                    break;
                case 6:
                    strcpy(*(nuevaPelicula.Generos+j), "Ciencia Ficcion");
                    break;
                case 7:
                    strcpy(*(nuevaPelicula.Generos+j), "Suspenso");
                    break;
                case 8:
                    strcpy(*(nuevaPelicula.Generos+j), "Infantil");
                    break;
            }
            j++;
        }
    }



    printf("\n\n\tSinopsis (hasta 200 letras): ");
    nuevaPelicula.Sinopsis = (char*)malloc(200);
    fflush(stdin);
    gets(nuevaPelicula.Sinopsis);



    if(aModificar == NULL && !enOrden)
        AgregarPelicula(nuevaPelicula, listado->Cabeza->anterior);

    else if(aModificar == NULL && enOrden)
    {
        Nodo *despuesDe = BuscarPorAnyo(listado, nuevaPelicula.Anyo);
        AgregarPelicula(nuevaPelicula, despuesDe);
    }
    else
    {
        aModificar->data = nuevaPelicula;

    }

}

void ExplorarPeliculas(Lista *listado, Nodo *aConsultar)

{

    char seleccion;

    Nodo *nodoActual;

    if(aConsultar == NULL)

        nodoActual = listado->Cabeza->siguiente;

    else

        nodoActual = aConsultar;



    do

    {

        MostrarMarcoTresColumnas();



        if(nodoActual->data.id == -1) // if(listado->Cantidad == 0)

        {

            printf("No hay pel%cculas registradas.", 161);

            break;

        }

        MostrarPeliculaEnColumna(nodoActual->data, 2);

        if(nodoActual->anterior->data.id == -1)

            MostrarPeliculaEnColumna(nodoActual->anterior->anterior->data, 1);

        else

            MostrarPeliculaEnColumna(nodoActual->anterior->data, 1);



        if(nodoActual->siguiente->data.id == -1)

            MostrarPeliculaEnColumna(nodoActual->siguiente->siguiente->data, 3);

        else

            MostrarPeliculaEnColumna(nodoActual->siguiente->data, 3);

        fflush(stdin);

        gotoxy(1, 25);

        printf("X: Salir. A: Anterior. D: Siguiente.");

        seleccion = getch();

        if(tolower(seleccion) == 'a')

        {

            nodoActual = nodoActual->anterior;

            if(nodoActual->data.id == -1)

                nodoActual = nodoActual->anterior;

        }

        else if(tolower(seleccion) == 'd')

        {

            nodoActual = nodoActual->siguiente;

            if(nodoActual->data.id == -1)

                nodoActual = nodoActual->siguiente;

        }

    }while(tolower(seleccion) != 'x');

}



void MostrarPeliculaEnColumna(Pelicula aMostrar, int numeroColumna)

{

    int colActual, i=0;

    if(numeroColumna <= 1)

        colActual = 1;

    else if(numeroColumna == 2)

        colActual = COL2;

    else

        colActual = COL3;



    gotoxy(colActual + 1, 3);

    printf("%4.4d - %.*s", aMostrar.id, LIMCOLUMNA, aMostrar.Titulo);



    gotoxy(colActual + 1, 5);

    printf("%4d - %.1f/10",

           aMostrar.Anyo, aMostrar.Calificacion);

    gotoxy(colActual + 1, 6);

    printf("%.1fmins.", aMostrar.Duracion);

    gotoxy(colActual + 1, 7);

    printf("Clasif.: %.20s", aMostrar.Clasificacion);

    gotoxy(colActual + 1, 9);

    while(i < aMostrar.CantidadGeneros)

    {

        printf("%.*s", LIMCOLUMNA, *(aMostrar.Generos+i));

        i++;

        gotoxy(colActual + 1, 9 + i);

    }

    gotoxy(colActual + 1, 10 + i);

    MostrarSinopsis(colActual + 1, 10+i, LIMCOLUMNA, aMostrar.Sinopsis);

}

void MostrarMarcoTresColumnas()
{
        int i;
    system("cls");
    printf("%c",201);

    for(i = 0; i < 24; i++)
        printf("%c",205);
    printf("%c",203);

    for(i = 0; i < 25; i++)
        printf("%c",205);
    printf("%c",203);

    for(i = 0; i < 25; i++)
        printf("%c",205);
    printf("%c\n",187);

    for(i = 2; i < 24; i++)
    {
        gotoxy(0,i);
        printf("%c",186);
        gotoxy(COL2,i);
        printf("%c",186);
        gotoxy(COL3,i);
        printf("%c",186);
        gotoxy(78,i);
        printf("%c\n",186);
    }
    printf("%c",200);

    for(i = 0; i < 24; i++)
        printf("%c",205);
    printf("%c",202);

    for(i = 0; i < 25; i++)
        printf("%c",205);
    printf("%c",202);

    for(i = 0; i < 25; i++)
        printf("%c",205);
    printf("%c\n",188);
}


void MostrarSinopsis (int col, int fila, int limite, char* texto)
{
    int i = 0, tamano = strlen(texto);
    char *nuevoTexto = (char*)calloc(sizeof(char*), tamano);
    strcpy(nuevoTexto, texto);
    while(tamano > 0)
    {
        gotoxy(col, fila + i);
        printf("%.*s", limite, nuevoTexto);
        nuevoTexto = strcpy(nuevoTexto, nuevoTexto + limite);

        i++;
        tamano -= limite;
    }
    gotoxy(col, fila+i);
}


void ModificarPelicula(Lista *listado)
{
    int idPeli;
    Nodo *nodoActual;
    system("cls");
    MostrarMarco();
    gotoxy(10, 3);
    printf("Modificando Pel%ccula Existente.", 161);
    gotoxy(5, 7);
    printf("Digite el ID: ");
    scanf("%d", &idPeli);
    nodoActual = BuscarPorId(listado, idPeli);

    if(nodoActual == NULL)
    {
        gotoxy(5, 9);
        printf("Esta pel%ccula no existe. Presione cualquier tecla para continuar.", 161);
        fflush(stdin);
        getch();
        return;
    }
    CapturarPelicula(listado, nodoActual, 0);
}

void BorrarPelicula(Lista *listado)
{
    int idPeli;
    Nodo *nodoActual;
    system("cls");
    MostrarMarco();
    gotoxy(10, 3);
    printf("Eliminando Pel%ccula Existente.", 161);
    gotoxy(5, 7);
    printf("Digite el ID: ");
    scanf("%d", &idPeli);
    nodoActual = BuscarPorId(listado, idPeli);

    if(nodoActual == NULL)
    {
        gotoxy(5, 9);
        printf("Esta pel%ccula no existe. Presione cualquier tecla para continuar.", 161);
        fflush(stdin);
        getch();
        return;
    }
    EliminarPelicula(listado, nodoActual);
}

void BuscarPeliculaPorAnyo(Lista* listado)
{
    int anyo;
    Nodo *nodoActual;
    system("cls");
    MostrarMarco();
    gotoxy(10, 3);
    printf("Buscando Pel%ccula Existente por A%co.", 161, 164);
    gotoxy(5, 7);

    do{
        printf("Digite el a%co: ", 164);
        scanf("%d", &anyo);
        if(anyo<0)
            printf("El a%co no puede ser negativo.", 164);
    }while(anyo<0);

    nodoActual = BuscarPorAnyo(listado, anyo);

    if(nodoActual == -1)
    {
        gotoxy(5, 9);
        printf("Esta lista est%c vac%ca. Presione cualquier tecla para continuar.", 160, 161);
        fflush(stdin);
        getch();
        return;
    }

    ExplorarPeliculas(listado, nodoActual);
}

void OrdenarPeliculasPorAnyo(Lista *listado)
{
    OrdenarPeliculaSeleccion(listado);
}
