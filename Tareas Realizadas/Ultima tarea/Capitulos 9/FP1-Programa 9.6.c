#include <stdio.h>

/* Programa que lee desde un archivo la matricula y cinco calificaciones
   de cada alumno, y muestra su promedio en pantalla. */

void main(void)
{
    int i, j, n, mat;
    float cal, pro;
    FILE *ar;

    ar = fopen("arc9.txt", "r");

    if (ar != NULL)
    {
        /* Leemos la cantidad de alumnos almacenada en el archivo. */
        fscanf(ar, "%d", &n);

        for (i = 0; i < n; i++)
        {
            fscanf(ar, "%d", &mat);
            printf("%d\t", mat);

            pro = 0;

            /* Leemos las cinco calificaciones del alumno. */
            for (j = 0; j < 5; j++)
            {
                fscanf(ar, "%f", &cal);
                pro += cal;
            }

            printf("\t %.2f ", pro / 5);
            printf("\n");
        }

        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }
}
