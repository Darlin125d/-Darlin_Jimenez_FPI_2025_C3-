#include <stdio.h>

/* Ordenación por inserción directa. */
const int MAX = 100;

/* Prototipos de funciones */
void Lectura(int *, int);
void Ordena(int *, int);
void Imprime(int *, int);

void main(void)
{
    int TAM, VEC[MAX];

    /* Se verifica que el tamaño del arreglo sea correcto */
    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);
    Ordena(VEC, TAM);
    Imprime(VEC, TAM);
}


/* ---- FUNCIÓN LECTURA ---- */
void Lectura(int A[], int T)
/* Lee un arreglo unidimensional de T elementos. */
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}


/* ---- FUNCIÓN IMPRIME ---- */
void Imprime(int A[], int T)
/* Escribe un arreglo unidimensional ordenado. */
{
    int I;

    for (I = 0; I < T; I++)
        printf("\nA[%d]: %d", I, A[I]);
}


/* ---- FUNCIÓN ORDENA ---- */
void Ordena(int A[], int T)
/* Método de inserción directa para ordenar los elementos. */
{
    int AUX, L, I;

    for (I = 1; I < T; I++)
    {
        AUX = A[I];
        L = I - 1;

        while (L >= 0 && AUX < A[L])
        {
            A[L + 1] = A[L];
            L--;
        }

        A[L + 1] = AUX;
    }
}
