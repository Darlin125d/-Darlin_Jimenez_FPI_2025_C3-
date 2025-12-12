#include <stdio.h>

/* Programa que guarda en un archivo la matricula y cinco calificaciones
   de varios alumnos ingresados por el usuario. */

void main(void)
{
    int i, j, n, mat;
    float cal;
    FILE *ar;

    printf("\nIngrese el numero de alumnos: ");
    scanf("%d", &n);

    ar = fopen("arc8.txt", "w");

    if (ar != NULL)
    {
        /* Primero guardamos la cantidad de alumnos. */
        fprintf(ar, "%d ", n);

        for (i = 0; i < n; i++)
        {
            printf("\nIngrese la matricula del alumno %d: ", i + 1);
            scanf("%d", &mat);
            fprintf(ar, "\n%d ", mat);

            /* Captura de cinco calificaciones para cada alumno. */
            for (j = 0; j < 5; j++)
            {
                printf("\nCalificacion %d: ", j + 1);
                scanf("%f", &cal);
                fprintf(ar, "%.2f ", cal);
            }
        }

        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }
}
