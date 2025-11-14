#include <stdio.h>

/* Ordenamiento – Método de Selección.
   El programa ordena un arreglo unidimensional de N elementos
   de tipo entero utilizando el método de selección.
*/

/* Prototipos de funciones. */
void Lectura(int *, int);
void Ordena(int *, int);
void Imprime(int *, int);

void main(void)
{
    int N, A[100];

    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &N);

    if (N > 1)
    {
        Lectura(A, N);
        Ordena(A, N);
        Imprime(A, N);
    }
    else
        printf("\nEl arreglo debe tener más de un elemento.");
}


/* ---- FUNCION LECTURA ----
   La función Lectura se utiliza para leer N elementos de tipo entero.
*/
void Lectura(int A[], int T)
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}


/* ---- FUNCION ORDENA ----
   Esta función ordena un arreglo unidimensional de T elementos
   utilizando el método de selección.
*/
void Ordena(int A[], int T)
{
    int I, J, MIN, AUX;

    for (I = 0; I < T - 1; I++)
    {
        MIN = I;

        for (J = I + 1; J < T; J++)
            if (A[J] < A[MIN])
                MIN = J;

        AUX = A[I];
        A[I] = A[MIN];
        A[MIN] = AUX;
    }
}


/* ---- FUNCION IMPRIME ----
   La función Imprime escribe un arreglo unidimensional ya ordenado.
*/
void Imprime(int A[], int T)
{
    int I;

    for (I = 0; I < T; I++)
        printf("\nA[%d]: %d", I, A[I]);
}
