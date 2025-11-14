#include <stdio.h>

/* Ordenación por selección directa. */
const int MAX = 100;

/* Prototipos de funciones */
void Lectura(int *, int);
void Ordena(int *, int);
void Imprime(int *, int);

void main(void)
{
    int TAM, VEC[MAX];

    /* Verifica que el tamaño del arreglo sea correcto */
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


/* ---- Lectura ---- */
void Lectura(int A[], int T)
/* Lee un arreglo unidimensional de T elementos */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}


/* ---- Imprime ---- */
void Imprime(int A[], int T)
/* Escribe el arreglo ya ordenado */
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nA[%d]: %d", I, A[I]);
}


/* ---- Ordena ---- */
void Ordena(int A[], int T)
/* Ordena usando el método de selección directa */
{
    int I, J, MEN, L;

    for (I = 0; I < T - 1; I++)
    {
        MEN = A[I];
        L = I;

        for (J = I + 1; J < T; J++)
        {
            if (A[J] < MEN)
            {
                MEN = A[J];
                L = J;
            }
        }

        A[L] = A[I];
        A[I] = MEN;
    }
}
