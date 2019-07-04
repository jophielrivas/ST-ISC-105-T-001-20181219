#include <stdlib.h>
#include <stdio.h>
#include "Colas.h"
#include <conio.c>



typedef enum
{
    Encolar= 1,
    Decolar= 2,
    MostrarTodo = 3,
    Salir = 4,

} eOpcionesMenu;

typedef enum
{
    Arriba,
    Abajo,
    Izquierda,
    Derecha,
    Enter,
    Ninguno = -1,
}eFlecha;

eOpcionesMenu MostrarMenu();

int main()
{
    float nuevoValor;
    eOpcionesMenu opcionSeleccionada;
    char opcion;
    Cola *nuevaCola = InicializarCola();



    do
    {
        opcionSeleccionada = MostrarMenu();
        switch(opcionSeleccionada)
        {
        case Encolar:
            printf("Digite un valor(0 para salir): ");
            scanf("%f",&nuevoValor);
            if(nuevoValor !=0)
            enqueue(nuevaCola,nuevoValor);
            break;

        case Decolar:
            if(!isEmpty(nuevaCola))
                printf("%.2f\t",dequeue(nuevaCola));

             fflush(stdin);
             getch();
            break;
        case MostrarTodo:
            printf("\n\n");
            while(!isEmpty(nuevaCola))
                printf("%.2f\t",dequeue(nuevaCola));
            fflush(stdin);
            getch();
            break;
        case Salir:
            nuevoValor = 0;
            break;
        }


    }
    while(nuevoValor !=0);
    return 0;
}

eOpcionesMenu MostrarMenu()
{
    eOpcionesMenu seleccion = Encolar;
    _setcursortype(0);
    fflush(stdin);
    do
    {
        textbackground(BLACK);
        clrscr();
        textbackground(seleccion == Encolar ? WHITE : BLACK );
        printf("\t1: Agregar valor.\n");
        textbackground(seleccion == Decolar ? WHITE : BLACK );
        printf("\t2: Mostrar valor.\n");
        textbackground(seleccion == MostrarTodo ? WHITE : BLACK );
        printf("\t3: Mostrar todos los valores.\n");
        textbackground(seleccion == Salir ? WHITE : BLACK );
        printf("\t4: Salir.\n");

        switch(CapturarFlecha())
        {
        case Arriba:
            seleccion == Encolar ? seleccion = Salir : seleccion--;
            break;
        case Abajo:
            seleccion == Salir ? seleccion = Encolar : seleccion++;
            break;
        case Enter:
            return seleccion;
        default:
            continue;
        }

    }while(1);

}

eFlecha CapturarFlecha()
{
    fflush(stdin);
    if (getch() == 13)
        return Enter;
    switch(getch())
    {
        case 72:
            return Arriba;
            break;
        case 80:
            return Abajo;
            break;
        case 77:
            return Derecha;
        case 75:
            return Izquierda;
        default:
            return Ninguno;
    }
    getch();
}
