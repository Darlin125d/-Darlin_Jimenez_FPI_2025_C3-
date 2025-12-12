#include <stdio.h>

/* Ordena de menor a mayor.
   El programa ordena un archivo compuesto por estructuras de alumnos,
   tomando la matricula como referencia. Luego genera un nuevo archivo
   con los registros ordenados. */

typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void ordena(FILE *, FILE *);

void main(void)
{
    FILE *ar1, *ar2;

    ar1 = fopen("ad5.dat", "rb");
    ar2 = fopen("ad6.dat", "wb");

    if (ar1 != NULL && ar2 != NULL)
        ordena(ar1, ar2);
    else
        printf("\nNo se pudieron abrir los archivos");

    fclose(ar1);
    fclose(ar2);
}

void ordena(FILE *ap1, FILE *ap2)
{
    alumno alu;
    int tam, total, i;

    tam = sizeof(alumno);

    /* Ir al final para calcular la cantidad de registros */
    fseek(ap1, 0, SEEK_END);
    total = ftell(ap1) / tam;

    rewind(ap1);

    /* Recorrer los registros en orden inverso */
    for (i = total - 1; i >= 0; i--) {
        fseek(ap1, i * tam, SEEK_SET);
        fread(&alu, tam, 1, ap1);
        fwrite(&alu, tam, 1, ap2);
    }
}
