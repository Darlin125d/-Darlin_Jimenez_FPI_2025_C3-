#include <stdio.h>

/* Programa que agrega caracteres al final del archivo libro.txt.
   El usuario escribe texto por teclado y cada caracter se va
   almacenando en el archivo hasta que presiona Enter. */

void main(void)
{
    char p1;
    FILE *ar;

    ar = fopen("libro.txt", "a");
    /* El archivo se abre en modo 'a', que permite anadir contenido al final. */

    if (ar != NULL)
    {
        /* Leemos caracteres uno por uno hasta que el usuario presione Enter. */
        while ((p1 = getchar()) != '\n')
            fputc(p1, ar);

        fclose(ar);
    }
    else
        printf("No se puede abrir el archivo");
}
