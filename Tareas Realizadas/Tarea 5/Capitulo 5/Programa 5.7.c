#include <stdio.h>

/* Arreglo sin elementos repetidos.
   El programa, al recibir como dato un arreglo unidimensional desordenado
   de N elementos, obtiene como salida ese mismo arreglo pero sin repetidos.
*/

/* Prototipos */
void Lectura(int *, int);
void Imprime(int *, int);
void Elimina(int *, int *);    /* El tamaño se pasa por referencia */

int main(void)
{
    int TAM, ARRE[100];

    /* Verificación del tamaño con do-while */
    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);

    Lectura(ARRE, TAM);

    Elimina(ARRE, &TAM);   /* Se pasa TAM por referencia */

    Imprime(ARRE, TAM);

    return 0;
}

void Lectura(int A[], int T)
/* Lee un arreglo unidimensional de T elementos */
{
    int I;
    printf("\n");
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

void Imprime(int A[], int T)
/* Imprime el arreglo resultante sin elementos repetidos */
{
    int I;
    for (I = 0; I < T; I++)
        printf("\nA[%d]: %d", I, A[I]);
}

void Elimina(int A[], int *T)
/* Elimina elementos repetidos desplazando el arreglo */
{
    int I = 0, K, L;

    while (I < (*T - 1))
    {
        K = I + 1;

        while (K <= (*T - 1))
        {
            if (A[I] == A[K])
            {
                /* Desplazamiento a la izquierda */
                for (L = K; L < (*T - 1); L++)
                    A[L] = A[L + 1];

                *T = *T - 1;   /* Disminuye el tamaño */
            }
            else
            {
                K++;
            }
        }

        I++;
    }
}
