#include <stdio.h>

/* Diagonal principal.
   El programa, al recibir como dato una matriz cuadrada de tipo entero,
   escribe únicamente los elementos de la diagonal principal.
*/

const int TAM = 10;

/* Prototipos de funciones */
void Lectura(int [][TAM], int);
void Imprime(int [][TAM], int);

void main(void)
{
    int MAT[TAM][TAM];

    Lectura(MAT, TAM);
    Imprime(MAT, TAM);
}


/* ---- Lectura ---- */
void Lectura(int A[][TAM], int F)
/* Lee una matriz cuadrada de F x F elementos */
{
    int I, J;

    for (I = 0; I < F; I++)
        for (J = 0; J < F; J++)
        {
            printf("Ingrese el elemento %d %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
}


/* ---- Imprime ---- */
void Imprime(int A[][TAM], int F)
/* Escribe únicamente los elementos de la diagonal principal */
{
    int I, J;

    for (I = 0; I < F; I++)
        for (J = 0; J < F; J++)
            if (I == J)
                printf("\nDiagonal %d %d: %d", I, J, A[I][J]);
}
