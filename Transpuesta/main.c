#include <stdio.h>
#include <stdlib.h>

void Capmatriz(int filas, int columnas, int matr[filas][columnas]);
void Mosmatriz(int filas, int columnas, int matr[filas][columnas]);
void Mosmatrizinversa(int filas, int columnas, int matr[filas][columnas]);

int main()
{

    const int COL = 3, FIL = 2;
    int matriz [FIL][COL];

    Capmatriz(FIL, COL, matriz);
    Mosmatriz(FIL, COL, matriz);
    Mosmatrizinversa(FIL,COL,matriz);

    return 0;
}

void Capmatriz(int filas, int columnas, int matr[filas][columnas])
{
    int i,j;

    for(i=0; i < filas; i++)
    {
        for(j=0; j < columnas; j++)
        {
            printf("Digite el valor de %d,%d: ",i,j);
            scanf("%d",*(matr+i)+j);
        }
    }
}

void Mosmatriz(int filas, int columnas, int matr[filas][columnas])
{
    int i,j;

    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            printf("%d \t ", matr[i][j]);

        }
        printf("\n");
        printf("\n");
    }

}

void Mosmatrizinversa(int filas, int columnas, int matr[filas][columnas])
{
    int i, j;

    for(j=0; j<columnas; j++)
    {
        for (i=0 ; i<filas ; i++)
        {
            printf("%d \t",matr[i][j]);
        }
        printf("\n");
        printf("\n");
    }


}

