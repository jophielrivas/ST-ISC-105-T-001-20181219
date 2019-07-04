#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main()
{
    Heap* miHeap;
    miHeap = Inicializar(1);
    float lista[10] = {5,10,20,35,2,8,15,100,9,1};
    for(int i=0;i<10;i++)
    {
        Insertar(miHeap, lista[i]);
    }

    printf("Top: %.2f\n",GetTop(miHeap));

    while(!isEmpty(miHeap))
    {
        printf("%.2f\n", Poll(miHeap));
    }
    return 0;
}
