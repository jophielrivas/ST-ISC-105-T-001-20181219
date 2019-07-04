#include <stdlib.h>
#include <stdio.h>
#include "NodosPeroColas.h"


int main()
{

    float nuevoValor;
    int opcionSeleccionada;
    char opcion;
    Cola *nuevaCola = IniciaCola();

    do
    {
        //system("cls");
        printf("Menu: \n");
        printf("Encolar= 1\n");
        printf("Decolar= 2\n");
        printf("MostrarTodo = 3\n");
        printf("Salir = 4\n\n");
        printf("Elija: ");
        scanf("%d",&opcionSeleccionada);

        switch(opcionSeleccionada)
        {
        case 1:
            do{
                printf("Digite un valor(0 para salir): ");
                scanf("%f",&nuevoValor);
                if(nuevoValor !=0)
                enqueue(nuevaCola,nuevoValor);
            }while(nuevoValor != 0);
            break;

        case 2:
            if(!isEmpty(nuevaCola)){
                printf("%.2f\t\n",dequeue(nuevaCola));
                system("pause");
            }
            break;

        case 3:
            printf("\n\n");
            while(!isEmpty(nuevaCola))
                printf("%.2f\t\n\n",dequeue(nuevaCola));
            system("pause");
            break;

        case 4:
            printf("Adi%cs :D\n", 162);
            system("pause");
            break;
        }
    system("cls");
    }
    while(opcionSeleccionada != 4);
    return 0;
}
