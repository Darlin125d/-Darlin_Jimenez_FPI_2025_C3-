#include <stdio.h>

/* Programa que guarda varias cadenas en un archivo de texto. */

void main(void)
{
    char cad[50];
    int res;
    FILE *ar;

    ar = fopen("arc.txt", "w");

    if (ar != NULL)
    {
        printf("\nDesea ingresar una cadena? Si-1 No-0: ");
        scanf("%d", &res);

        while (res)
        {
            fflush(stdin);
            printf("Ingrese la cadena: ");
            gets(cad);

            fputs(cad, ar);

            printf("\nDesea ingresar otra cadena? Si-1 No-0: ");
            scanf("%d", &res);

            if (res)
                fputs("\n", ar); /* Agregamos salto de linea solo cuando sigue otra cadena */
        }

        fclose(ar);
    }
    else
        printf("No se puede abrir el archivo");
}
