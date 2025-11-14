#include <stdio.h>

/* Cuadrado mágico.
   Genera un cuadrado mágico de orden N impar usando el método siamés.
*/

const int MAX = 50;

void Cuadrado(int [][MAX], int);
void Imprime(int [][MAX], int);

void main(void)
{
    int CMA[MAX][MAX], TAM;

    do
    {
        printf("Ingrese el tamano impar de la matriz (1-50): ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1 || TAM % 2 == 0);

    Cuadrado(CMA, TAM);
    Imprime(CMA, TAM);
}

/* ------------------------------------------------------ */
/* ----------- GENERAR EL CUADRADO MÁGICO ---------------- */
/* ------------------------------------------------------ */

void Cuadrado(int A[][MAX], int N)
{
    int I, J;

    /* Inicializar la matriz en 0 */
    for (I = 0; I < N; I++)
        for (J = 0; J < N; J++)
            A[I][J] = 0;

    int FIL = 0;
    int COL = N / 2;
    int IVAL;

    for (IVAL = 1; IVAL <= N * N; IVAL++)
    {
        A[FIL][COL] = IVAL;

        /* Si NO es múltiplo de N */
        if (IVAL % N != 0)
        {
            FIL = (FIL - 1 + N) % N;
            COL = (COL + 1) % N;
        }
        else
        {
            /* Si es múltiplo de N, bajar una fila */
            FIL = (FIL + 1) % N;
        }
    }
}

/* ------------------------------------------------------ */
/* ------------------- IMPRIMIR -------------------------- */
/* ------------------------------------------------------ */

void Imprime(int A[][MAX], int N)
{
    int I, J;

    printf("\nCuadrado magico de orden %d:\n\n", N);

    for (I = 0; I < N; I++)
    {
        for (J = 0; J < N; J++)
        {
            printf("%4d ", A[I][J]);
        }
        printf("\n");
    }
}
