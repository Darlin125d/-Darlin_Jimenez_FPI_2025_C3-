#include <stdio.h>

/* Este programa abre un archivo con informacion de alumnos y,
   por medio de una funcion, muestra la matricula y el promedio
   de cada uno. */

void promedio(FILE *); /* Prototipo de funcion. */

void main(void)
{
    FILE *ar = fopen("arc9.txt", "r");

    if (ar != NULL)
    {
        promedio(ar);
        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }
}

void promedio(FILE *ar1)
{
    int i, j, n, mat;
    float pro, cal;

    /* Primer dato: cantidad de alumnos. */
    fscanf(ar1, "%d", &n);

    for (i = 0; i < n; i++)
    {
        fscanf(ar1, "%d", &mat);  /* Matricula */
        printf("%d\t", mat);

        pro = 0;

        /* Cinco calificaciones */
        for (j = 0; j < 5; j++)
        {
            fscanf(ar1, "%f", &cal);
            pro += cal;
        }

        printf("\t %.2f \n", pro / 5);
    }
}
