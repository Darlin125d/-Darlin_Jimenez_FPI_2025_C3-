#include <stdio.h>

/* Programa que cuenta cuántas veces aparece un caracter dentro
   de un archivo de texto. El usuario indica el caracter y el
   programa realiza la búsqueda. */

int cuenta(char);  /* Prototipo de la función que realizará el conteo. */

void main(void)
{
    int res;
    char car;

    printf("Ingrese el caracter que desea buscar en el archivo: ");
    car = getchar();

    res = cuenta(car);

    if (res != -1)
        printf("\nEl caracter '%c' aparece %d veces en el archivo.\n", car, res);
    else
        printf("No se pudo abrir el archivo.\n");
}

int cuenta(char car)
/* Busca el caracter dentro de arc.txt y devuelve la cantidad encontrada.
   Si no se puede abrir el archivo, regresa -1. */
{
    int con = 0;
    char p;
    FILE *ar;

    ar = fopen("arc.txt", "r");  /* Archivo en modo lectura */

    if (ar != NULL)
    {
        /* Leemos caracter por caracter hasta que termine el archivo */
        while (!feof(ar))
        {
            p = getc(ar);
            if (p == car)
                con++;
        }
        fclose(ar);
        return con;
    }
    else
    {
        /* Si falló la apertura, devolvemos -1 */
        return -1;
    }
}
