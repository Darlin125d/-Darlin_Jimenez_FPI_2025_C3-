#include <stdio.h>

/* Búsqueda secuencial en arreglos desordenados. */

const int MAX = 100;      /* Tamaño máximo del arreglo. */

/* Prototipos de funciones. */
void Lectura(int *, int);
int Busca(int *, int, int);

void main(void)
{
    int RES, ELEF, TAM, VEC[MAX];

    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &TAM);

    while (TAM < 1 || TAM > MAX)
    {
        printf("Tamano incorrecto. Ingrese nuevamente: ");
        scanf("%d", &TAM);
    }

    /* Se llama a la función que lee el arreglo */
    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELEF);

    RES = Busca(VEC, TAM, ELEF);  /* Se llama a la función Busca */

    if (RES != -1)
        printf("\nEl elemento se encuentra en la posicion %d", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");
}


/* ---- FUNCION LECTURA ---- */
/* La función Lectura se utiliza para leer un arreglo unidimensional de T elementos de tipo entero. */
void Lectura(int A[], int T)
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento No. %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}


/* ---- FUNCION BUSCA ---- */
/* La función Busca localiza en el arreglo el elemento determinado.
   Si el elemento está en el arreglo, regresa la posición correspondiente.
   En caso contrario regresa -1. */
int Busca(int A[], int T, int ELE)
{
    int I = 0;

    while (I < T)
    {
        if (A[I] == ELE)
            return I;   /* Regresa la posición */

        I++;
    }

    return -1;          /* No se encontró */
}
