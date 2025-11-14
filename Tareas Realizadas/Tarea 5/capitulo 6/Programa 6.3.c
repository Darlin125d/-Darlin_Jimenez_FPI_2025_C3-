#include <stdio.h>

/* Universidad.
   El programa, al recibir información sobre el número de alumnos
   que han ingresado a sus ocho diferentes carreras en los dos
   semestres lectivos de los últimos cinco años, obtiene información
   útil para el departamento de escolar.
*/

const int F = 8, C = 2, P = 5;
/* F = carreras, C = semestres, P = años */

/* Prototipos */
void Lectura(int [][C][P], int, int, int);
void Funcion1(int [][C][P], int, int, int);
void Funcion2(int [][C][P], int, int, int);
void Funcion3(int [][C][P], int, int, int);

void main(void)
{
    int UNI[F][C][P];

    Lectura(UNI, F, C, P);

    Funcion1(UNI, F, C, P);
    Funcion2(UNI, F, C, P);

    /* Se usa 6 como clave de Ingeniería en Computación */
    Funcion3(UNI, 6, C, P);
}


/* ============================================================= */
/* ======================= FUNCIONES ============================ */
/* ============================================================= */

void Lectura(int A[][C][P], int FI, int CO, int PR)
{
    int K, I, J;

    for (K = 0; K < PR; K++)
        for (I = 0; I < FI; I++)
            for (J = 0; J < CO; J++)
            {
                printf("Año: %d\tCarrera: %d\tSemestre: %d: ",
                        K + 1, I + 1, J + 1);
                scanf("%d", &A[I][J][K]);
            }
}


/* ------------------------------------------------------------- */
/* Funcion1: Año con mayor ingreso total                         */
/* ------------------------------------------------------------- */
void Funcion1(int A[][C][P], int FI, int CO, int PR)
{
    int K, I, J;
    int MAY = 0, AO = -1;
    int SUM;

    for (K = 0; K < PR; K++)
    {
        SUM = 0;

        for (I = 0; I < FI; I++)
            for (J = 0; J < CO; J++)
                SUM += A[I][J][K];

        if (SUM > MAY)
        {
            MAY = SUM;
            AO = K;
        }
    }

    printf("\nAño con mayor ingreso: Año %d con %d alumnos.\n", AO + 1, MAY);
}


/* ------------------------------------------------------------- */
/* Funcion2: Carrera con menor ingreso total en 5 años           */
/* ------------------------------------------------------------- */
void Funcion2(int A[][C][P], int FI, int CO, int PR)
{
    int I, J, K;
    int MEN = 999999, CAR = -1;
    int SUM;

    for (I = 0; I < FI; I++)
    {
        SUM = 0;

        for (K = 0; K < PR; K++)
            for (J = 0; J < CO; J++)
                SUM += A[I][J][K];

        if (SUM < MEN)
        {
            MEN = SUM;
            CAR = I;
        }
    }

    printf("La carrera con menos ingresos es la carrera %d con %d alumnos.\n",
           CAR + 1, MEN);
}


/* ------------------------------------------------------------- */
/* Funcion3: Total de alumnos de la carrera 6 en 5 años          */
/* ------------------------------------------------------------- */
void Funcion3(int A[][C][P], int CR, int CO, int PR)
{
    int K, J;
    int SUM = 0;

    /* CR ya es el número de la carrera (6) → índice = CR - 1 */
    for (K = 0; K < PR; K++)
        for (J = 0; J < CO; J++)
            SUM += A[CR - 1][J][K];

    printf("Total de alumnos de la carrera %d en los 5 años: %d\n", CR, SUM);
}
