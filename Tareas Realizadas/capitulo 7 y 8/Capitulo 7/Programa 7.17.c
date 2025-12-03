#include <stdio.h>
#include <string.h>

/* Cadena invertida.
El programa obtiene la cadena invertida. */

char *inverso(char *); /* Prototipo de funcion. */

void main(void)
{
    char fra[50], aux[50];

    printf("\nIngrese la linea de texto: ");
    gets(fra);

    strcpy(aux, inverso(fra)); /* Copia el resultado de la funcion inverso */

    printf("\nEscribe la linea de texto en forma inversa: ");
    puts(aux);
}

char *inverso(char *cadena)
/* La funcion calcula el inverso de una cadena y regresa el resultado */
{
    int i = 0, j, lon;
    char cad;

    lon = strlen(cadena);
    j = lon - 1;

    /* intercambio hasta la mitad */
    while (i < (lon - 1) / 2)
    {
        cad = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = cad;

        i++;
        j--;
    }

    return cadena;
}
