#include <stdio.h>

/* Ordenamiento.
El programa ordena un arreglo unidimensional de n
elementos de tipo entero.
*/

/* Prototipos de funciones. */
void Lectura(int *, int);
void Ordena(int *, int);
void Imprime(int *, int);

void main(void)
{
    int I, N, X[100];

    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &N);

    if (N > 1)
    {
        Lectura(X, N);
        Ordena(X, N);
        Imprime(X, N);
    }
    else
        printf("\nEl arreglo debe tener más de un elemento.");
}


/* ---- FUNCION LECTURA ----
   La función Lectura se utiliza para leer un arreglo unidimensional
   de N elementos de tipo entero.
*/
void Lectura(int A[], int N)
{
    int I;

    for (I = 0; I < N; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}


/* ---- FUNCION ORDENA ----
   Esta función ordena un arreglo unidimensional de T elementos
   de tipo entero usando el método de intercambio.
*/
void Ordena(int A[], int T)
{
    int I, J, AUX;

    for (I = 0; I < T - 1; I++)
        for (J = I + 1; J < T; J++)
            if (A[I] > A[J])
            {
                AUX = A[I];
                A[I] = A[J];
                A[J] = AUX;
            }
}


/* ---- FUNCION IMPRIME ----
   La función Imprime escribe un arreglo unidimensional de T elementos.
*/
void Imprime(int A[], int T)
{
    int I;

    for (I = 0; I < T; I++)
        printf("\nA[%d]: %d", I, A[I]);
}
