#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Este programa lee lineas desde un archivo de texto y,
   cada vez que encuentra la palabra "mexico" con la inicial
   en minuscula, la corrige a "Mexico" y guarda el resultado
   en un archivo diferente. */

void cambia(FILE *, FILE *);

void main(void)
{
    FILE *origen, *destino;

    origen = fopen("arc.txt", "r");   /* Se abre el archivo original para lectura */
    destino = fopen("arc1.txt", "w"); /* Se abre el archivo destino para escritura */

    if (origen != NULL && destino != NULL)
    {
        cambia(origen, destino);
        fclose(origen);
        fclose(destino);
    }
    else
    {
        printf("No se pueden abrir los archivos");
    }
}

void cambia(FILE *in, FILE *out)
/* Esta funcion revisa cada linea del archivo recibido y corrige
   la palabra "mexico" si aparece con la inicial en minuscula. */
{
    char linea[30];
    char buffer[30];
    char *pos;

    while (!feof(in))
    {
        /* Se lee la linea completa */
        fgets(linea, 30, in);

        /* Copiamos la linea porque vamos a modificarla */
        strcpy(buffer, linea);

        /* Busca la palabra "mexico" dentro de la linea */
        pos = strstr(buffer, "mexico");

        /* Mientras siga encontrando ocurrencias... */
        while (pos != NULL)
        {
            pos[0] = 'M';  /* Cambiamos la primera letra a mayuscula */

            /* Busca la siguiente ocurrencia en la linea ya modificada */
            pos = strstr(buffer, "mexico");
        }

        /* Escribe la linea corregida en el archivo de salida */
        fputs(buffer, out);
    }
}
