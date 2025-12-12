#include <stdio.h>

/* Programa que lee caracteres desde un archivo de texto. */

void main(void)
{
    char c;
    FILE *ar;

    ar = fopen("arc.txt", "r");

    if (ar != NULL)
    {
        /* Leemos el archivo caracter por caracter hasta llegar al final. */
        while (!feof(ar))
        {
            c = fgetc(ar);
            putchar(c);
        }

        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }
}
