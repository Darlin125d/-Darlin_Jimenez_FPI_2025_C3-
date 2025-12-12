#include <stdio.h>
#include <ctype.h>

/* El programa abre un archivo de texto y revisa todas sus lineas
   para contar cuantas letras minusculas y mayusculas contiene. */

void minymay(FILE *);

void main(void)
{
    FILE *ap;

    ap = fopen("arc.txt", "r");
    /* Se intenta abrir el archivo en modo lectura */

    if (ap != NULL)
    {
        minymay(ap);
        fclose(ap);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }
}

void minymay(FILE *ap1)
/* Esta funcion lee el archivo linea por linea usando fgets y
   suma las letras minusculas y mayusculas encontradas. */
{
    char cad[30];
    int i, mi = 0, ma = 0;

    while (!feof(ap1))
    {
        fgets(cad, 30, ap1);

        i = 0;
        while (cad[i] != '\0')
        {
            if (islower(cad[i]))
                mi++;
            else if (isupper(cad[i]))
                ma++;

            i++;
        }
    }

    printf("\n\nNumero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d", ma);
}
