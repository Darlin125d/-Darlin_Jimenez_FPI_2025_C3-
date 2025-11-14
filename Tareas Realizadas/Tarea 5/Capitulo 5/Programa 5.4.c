#include <stdio.h>

/* Producto de vectores.
   El programa calcula el producto de dos vectores y almacena
   el resultado en otro arreglo unidimensional.
*/

const int MAX = 10;   /* Tamaño de los arreglos */

/* Prototipos */
void Lectura(int VEC[], int T);
void Imprime(int VEC[], int T);
void Producto(int *X, int *Y, int *Z, int T);

int main(void)
{
    int VE1[MAX], VE2[MAX], VE3[MAX];
    /* Se declaran tres arreglos enteros de 10 elementos */

    Lectura(VE1, MAX);
    /* Se llama función Lectura. El arreglo se pasa por referencia. */

    Lectura(VE2, MAX);

    Producto(VE1, VE2, VE3, MAX);
    /* Se calcula el producto de los arreglos */

    printf("\nProducto de los Vectores");
    Imprime(VE3, MAX);

    return 0;
}

void Lectura(int VEC[], int T)
/* Lee un arreglo unidimensional de T elementos */
{
    int I;
    printf("\n");
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &VEC[I]);
    }
}

void Imprime(int VEC[], int T)
/* Imprime un arreglo unidimensional de T elementos */
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nVEC[%d]: %d", I + 1, VEC[I]);
}

void Producto(int *X, int *Y, int *Z, int T)
/* Calcula el producto de dos arreglos de T elementos */
{
    int I;
    for (I = 0; I < T; I++)
        Z[I] = X[I] * Y[I];
}
