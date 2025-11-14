#include <stdio.h>

/* Simétrico.
   El programa, al recibir como dato un arreglo bidimensional cuadrado,
   determina si el mismo es simétrico.
*/

const int MAX = 100;

/* Prototipos de funciones */
void Lectura(int [][MAX], int);
int Simetrico(int [][MAX], int);

void main(void)
{
    int MAT[MAX][MAX], N, RES;

    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &N);
    }
    while (N > MAX || N < 1);  /* Verificación del tamaño */

    Lectura(MAT, N);

    RES = Simetrico(MAT, N);

    if (RES)
        printf("\nEl arreglo bidimensional es simétrico");
    else
        printf("\nEl arreglo bidimensional no es simétrico");
}


/* ============================================================= */
/* =======================   FUNCIONES   ======================== */
/* ============================================================= */

void Lectura(int A[][MAX], int T)
/* Lee una matriz cuadrada de T × T elementos */
{
    int I, J;

    for (I = 0; I < T; I++)
        for (J = 0; J < T; J++)
        {
            printf("Fila: %d\tColumna: %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
}


int Simetrico(int A[][MAX], int T)
/* Determina si la matriz es simétrica.
   Recorre únicamente la parte triangular inferior (sin diagonal). */
{
    int I = 0, J, F = 1;

    while (I < T && F)
    {
        J = 0;

        while (J < I && F)
        {
            if (A[I][J] == A[J][I])
                J++;
            else
                F = 0;
        }

        I++;
    }

    return F;
}
