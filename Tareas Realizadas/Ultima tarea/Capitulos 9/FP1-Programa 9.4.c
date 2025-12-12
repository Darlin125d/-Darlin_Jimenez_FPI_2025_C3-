#include <stdio.h>

/* Programa que lee lineas de texto desde un archivo y las muestra en pantalla. */

void main(void)
{
    char cad[50];
    FILE *ap;

    ap = fopen("arc.txt", "r");

    if (ap != NULL)
    {
        /* Leemos lineas mientras el archivo no llegue al final. */
        while (!feof(ap))
        {
            fgets(cad, 50, ap);  /* Se leen hasta 49 caracteres o hasta encontrar un salto de linea. */
            puts(cad);           /* Se imprime la linea leida. */
        }

        fclose(ap);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }
}
