#include <stdio.h>

/* Este programa combina dos archivos ordenados por matricula
   y genera un tercer archivo manteniendo ese mismo orden. */

void mezcla(FILE *, FILE *, FILE *);

void main(void)
{
    FILE *f1, *f2, *out;

    f1 = fopen("arc9.dat", "r");
    f2 = fopen("arc10.dat", "r");
    out = fopen("arc11.dat", "w");

    if (f1 != NULL && f2 != NULL && out != NULL)
    {
        mezcla(f1, f2, out);
        fclose(f1);
        fclose(f2);
        fclose(out);
    }
    else
    {
        printf("No se pueden abrir los archivos");
    }
}

void mezcla(FILE *a, FILE *b, FILE *r)
/* Mezcla registros de dos archivos ordenados por matricula. */
{
    int i;
    int matA, matB;
    float calA[3], calB[3], temp;
    int readA = 1, readB = 1;

    while ( ( !feof(a) || !readA ) && ( !feof(b) || !readB ) )
    {
        if (readA)
        {
            fscanf(a, "%d", &matA);
            for (i = 0; i < 3; i++)
                fscanf(a, "%f", &calA[i]);
            readA = 0;
        }

        if (readB)
        {
            fscanf(b, "%d", &matB);
            for (i = 0; i < 3; i++)
                fscanf(b, "%f", &calB[i]);
            readB = 0;
        }

        if (matA < matB)
        {
            fprintf(r, "%d\t", matA);
            for (i = 0; i < 3; i++)
                fprintf(r, "%f\t", calA[i]);
            fputc('\n', r);
            readA = 1;
        }
        else
        {
            fprintf(r, "%d\t", matB);
            for (i = 0; i < 3; i++)
                fprintf(r, "%f\t", calB[i]);
            fputc('\n', r);
            readB = 1;
        }
    }

    /* Copia lo que quede pendiente en el archivo A */
    if (!readA)
    {
        fprintf(r, "%d\t", matA);
        for (i = 0; i < 3; i++)
            fprintf(r, "%f\t", calA[i]);
        fputc('\n', r);

        while (!feof(a))
        {
            fscanf(a, "%d", &matA);
            fprintf(r, "%d\t", matA);
            for (i = 0; i < 3; i++)
            {
                fscanf(a, "%f", &temp);
                fprintf(r, "%f\t", temp);
            }
            fputc('\n', r);
        }
    }

    /* Copia lo que quede pendiente en el archivo B */
    if (!readB)
    {
        fprintf(r, "%d\t", matB);
        for (i = 0; i < 3; i++)
            fprintf(r, "%f\t", calB[i]);
        fputc('\n', r);

        while (!feof(b))
        {
            fscanf(b, "%d", &matB);
            fprintf(r, "%d\t", matB);
            for (i = 0; i < 3; i++)
            {
                fscanf(b, "%f", &temp);
                fprintf(r, "%f\t", temp);
            }
            fputc('\n', r);
        }
    }
}
