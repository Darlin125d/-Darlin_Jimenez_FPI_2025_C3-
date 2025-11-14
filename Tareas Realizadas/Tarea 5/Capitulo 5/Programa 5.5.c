#include <stdio.h>

/* Frecuencia de calificaciones.
   El programa, al recibir como datos las calificaciones de un grupo
   de 50 alumnos, obtiene la frecuencia de cada una de las calificaciones
   y escribe cuál es la frecuencia más alta.
*/

const int TAM = 50;

/* Prototipos */
void Lectura(int *, int);
void Frecuencia(int A[], int P, int B[], int T);
void Impresion(int *, int);
void Mayor(int *, int);

int main(void)
{
    int CAL[TAM], FRE[6] = {0};   /* Arreglo de calificaciones y arreglo de frecuencias */

    Lectura(CAL, TAM);           /* Leer calificaciones */
    Frecuencia(CAL, TAM, FRE, 6);/* Calcular frecuencias */

    printf("\nFrecuencia de Calificaciones\n");
    Impresion(FRE, 6);           /* Mostrar frecuencias */

    Mayor(FRE, 6);               /* Mostrar mayor frecuencia */

    return 0;
}

void Lectura(int VEC[], int T)
/* Lee el arreglo de calificaciones */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese la calificación (0 a 5) del alumno %d: ", I + 1);
        scanf("%d", &VEC[I]);
    }
}

void Impresion(int VEC[], int T)
/* Imprime el arreglo de frecuencias */
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nVEC[%d]: %d", I, VEC[I]);
}

void Frecuencia(int A[], int P, int B[], int T)
/* Calcula la frecuencia de cada calificación */
{
    int I;
    for (I = 0; I < P; I++)
        if (A[I] >= 0 && A[I] < 6)   /* Valida que la calificación sea correcta */
            B[A[I]]++;              /* Incrementa la frecuencia */
}

void Mayor(int *X, int T)
/* Obtiene la primera ocurrencia de la frecuencia mayor */
{
    int I, MFRE = 0, MVAL = X[0];

    for (I = 1; I < T; I++)
        if (MVAL < X[I])
        {
            MFRE = I;
            MVAL = X[I];
        }

    printf("\n\nMayor frecuencia de calificaciones: %d \tValor: %d\n", MFRE, MVAL);
}

