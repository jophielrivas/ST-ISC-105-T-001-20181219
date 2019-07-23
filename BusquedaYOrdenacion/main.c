#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int MAX = 1000, MIN = 0;
void CapturarValores(int[], int);
void MostrarValores(int[], int);
int BusquedaLineal(int[], int, int);
int BusquedaLinealRecursiva(int[], int, int, int);
int BusquedaBinaria(int[], int, int);
int BusquedaBinariaRecursiva(int[], int, int, int);
void GenerarValores(int[], int);
long GenerarValoresRecursivo(int[], int, int);
void MergeSortRecursivo(int[], int, int);
void Merge(int[], int, int, int[], int, int[], int);
void QuickSort(int [], int);
void QuickSortRec(int [], int, int);
int Particionar(int [], int, int);
void Swap(int [], int, int);
void SwapPunteros(int*, int*);


int main()
{
    srand(time(NULL));
    int n, destino, posicion;
    printf("Digite el tama%co del arreglo: ", 164);
    scanf("%d", &n);
    int arreglo[n];

    GenerarValores(arreglo, n);
    MostrarValores(arreglo, n);

    QuickSort(arreglo, n);
    MostrarValores(arreglo, n);

    MergeSortRecursivo(arreglo, 0, n-1);
    MostrarValores(arreglo, n);

    printf("Digite el valor que desea buscar: ");
    scanf("%d", &destino);

    posicion = BusquedaLineal(arreglo, n, destino);

    if(posicion >= 0)
        printf("Con busqueda lineal encontrado en: %d\n", posicion+1);
    else
        printf("El valor %d no existe en el listado", destino);

    posicion = BusquedaBinaria(arreglo, n, destino);

    if(posicion >= 0)
        printf("Con busqueda binaria encontrado en: %d\n", posicion+1);
    else
        printf("El valor %d no existe en el listado", destino);

    return 0;
}

void GenerarValores(int arreglo[], int tamano)
{
    long sumatoria;
    sumatoria = GenerarValoresRecursivo(arreglo, tamano, 0);

    printf("\nLa sumatoria de los aleatorios es: %ld\n", sumatoria);
}

long GenerarValoresRecursivo(int arreglo[], int tamano, int pos)
{
    if(pos >= tamano)
        return 0;

    arreglo[pos] = rand() % (MAX - MIN + 1) + MIN;

    return arreglo[pos] + GenerarValoresRecursivo(arreglo, tamano, pos+1);
}

void CapturarValores(int arreglo[], int tamano)
{
    int i;
    for(i=0; i<tamano; i++)
    {
        printf("%d: ", i+1);
        scanf("%d", &arreglo[i]);
    }
}

void MostrarValores(int arreglo[], int tamano)
{
    int i;
    printf("\nValores:\n");
    for(i=0; i<tamano; i++)
    {
        printf("%d\t", arreglo[i]);
    }
    printf("\n\n");

}

int BusquedaLineal(int arreglo[], int tamano, int destino)
{
    return BusquedaLinealRecursiva(arreglo, tamano, destino, 0);
}

int BusquedaLinealRecursiva(int arreglo[], int tamano, int destino, int pos)
{
    if(pos >= tamano)
        return -1;

    return arreglo[pos] == destino ? pos : BusquedaLinealRecursiva(arreglo, tamano, destino, pos+1);
}

int BusquedaBinaria(int arreglo[], int tamano, int destino)
{
    return BusquedaBinariaRecursiva(arreglo, destino, 0, tamano-1);
}

int BusquedaBinariaRecursiva(int arreglo[], int destino, int limI, int limS)
{
    int centro;
    if(limI>limS)
        return -1;

    centro = (float)limI/2 + (float)limS/2;

    if(arreglo[centro] == destino)
        return centro;
    else if(arreglo[centro]>destino)
        BusquedaBinariaRecursiva(arreglo, destino, limI, centro-1);
    else
        return BusquedaBinariaRecursiva(arreglo, destino, centro+1, limS);
}

void MergeSortRecursivo(int arreglo[], int limI, int limS)
{

    int i;
    if(limI == limS)
        return;

    int nuevoTamanoIzquierdo, nuevoTamanoDerecho;

    if(((limS - limI) + 1) % 2)
    {
        nuevoTamanoIzquierdo = ((limS - limI) / 2);
        nuevoTamanoDerecho = ((limS - limI) / 2) + 1;
    }
    else
        nuevoTamanoIzquierdo = nuevoTamanoDerecho = (limS - limI) / 2 + 1;

    int izquierdo[nuevoTamanoIzquierdo],derecho[nuevoTamanoDerecho];

    //copiando la mitad izquierda:
    for(i=limI; i<nuevoTamanoIzquierdo; i++)
    {
        izquierdo[i-limI] = arreglo[i];
    }

    //copiando a la derecha
    for(; i<=limS; i++)
    {
        derecho[i-limI-nuevoTamanoIzquierdo] = arreglo[i];
    }

    MergeSortRecursivo(izquierdo, 0, nuevoTamanoIzquierdo-1);
    MergeSortRecursivo(derecho,0,nuevoTamanoDerecho-1);

    Merge(arreglo,limI,limS,izquierdo,nuevoTamanoIzquierdo,derecho,nuevoTamanoDerecho);

}

void Merge(int arreglo[], int limI, int limS, int izquierdo[], int TamanoI, int derecho[], int TamanoR)
{
    int i = 0,j  = 0;

    while(i < TamanoI && j < TamanoR)
    {
        if(izquierdo[i] <= derecho[j])
            arreglo[limI] = izquierdo[i++];

        else
            arreglo[limI] = derecho[j++];

        limI++;
    }

    //copiando los remanentes:
    while(i<TamanoI)
        arreglo[limI++] = izquierdo[i++];

    while(j<TamanoR)
        arreglo[limI++] = derecho[j++];
}

void QuickSort(int arreglo[], int num)
{
    return QuickSortRec(arreglo, 0, num);
}

void QuickSortRec(int arreglo[], int limI, int limS)
{
    int indicePivote;

    if(limI>=limS)
        return;

    indicePivote = Particionar(arreglo, limI, limS);
    QuickSortRec(arreglo, limI, indicePivote-1);
    QuickSortRec(arreglo, indicePivote+1, limS);


}
int Particionar(int arreglo[], int limI, int limS)
{
    int pivote = arreglo[limI];
    int i = limI + 1;
    int j = i;

    for(; i<=limS; i++)
    {
        if(arreglo[i]< pivote)
        {
            Swap(arreglo, i, j);
            j++;
        }
    }
    SwapPunteros(&arreglo[limI], &arreglo[j-1]);
    return j-1;
}

void Swap(int arreglo[], int indiceInicio, int indiceFinal)
{
    int burbuja;
    burbuja = arreglo[indiceInicio];
    arreglo[indiceInicio] = arreglo[indiceFinal];
    arreglo[indiceFinal] = burbuja;
}


void SwapPunteros(int *a, int *b)
{
    int *burbuja = (int*)malloc(sizeof(int));
    *burbuja = *a;
    *a = *b;
    *b = *burbuja;
}
