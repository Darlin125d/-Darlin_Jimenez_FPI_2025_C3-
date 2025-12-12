#include <stdio.h>
#include <ctype.h>

/* Programa que analiza un archivo de texto y cuenta cuántas
   letras minúsculas y cuántas mayúsculas contiene. */

void minymay(FILE *);  /* Función que hace el conteo. */

void main(void)
{
    FILE *ar;

    ar = fopen("arc5.txt", "r");   /* Se intenta abrir el archivo. */

    if (ar != NULL)
    {
        minymay(ar);   /* Enviamos el archivo a la función para procesarlo */
        fclose(ar);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}

void minymay(FILE *arc)
/* Recorre el archivo caracter por caracter y suma cuántos son
   minúsculas y cuántos son mayúsculas. */
{
    int min = 0, may = 0;
    char p;

    while (!feof(arc))
    {
        p = fgetc(arc);

        if (islower(p))
            min++;
        else if (isupper(p))
            may++;
    }

    printf("\nLetras minusculas: %d", min);
    printf("\nLetras mayusculas: %d\n", may);
}
