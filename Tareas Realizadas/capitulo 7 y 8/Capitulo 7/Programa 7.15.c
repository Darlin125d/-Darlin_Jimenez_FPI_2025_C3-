#include <stdio.h>
#include <ctype.h>

/* Decodifica.
El programa decodifica una cadena de caracteres compuesta por numeros y letras. */

void interpreta(char *); /* Prototipo de funcion. */

void main(void)
{
    char cad[50];

    printf("\nIngrese la cadena de caracteres: ");
    gets(cad);

    interpreta(cad);
}

void interpreta(char *cadena)
/* Esta funcion se utiliza para decodificar la cadena de caracteres. */
{
    int i = 0, j, k;

    while (cadena[i] != '\0')
    {
        if (isalpha(cadena[i]))   /* Verifica si es una letra */
        {
            k = cadena[i - 1] - '0';
            /* Convierte el caracter numero anterior a entero restando el ascii de '0' */

            for (j = 0; j < k; j++)
                putchar(cadena[i]);
        }
        i++;
    }
}
