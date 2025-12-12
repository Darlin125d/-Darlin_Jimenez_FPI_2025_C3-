
#include <stdio.h>
#include <stdlib.h>

/* El programa revisa cada linea de un archivo de texto.
   Si la linea inicia con un numero real, este se suma y luego
   se calcula el promedio de todos los valores encontrados. */

void sumypro(FILE *);

void main(void)
{
    FILE *ap;

    ap = fopen("arc2.txt", "r");
    /* Se intenta abrir el archivo en modo lectura */

    if (ap != NULL)
    {
        sumypro(ap);
        fclose(ap);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }
}

void sumypro(FILE *ap1)
/* La funcion analiza cada cadena del archivo. Si al convertirla con atof
   se obtiene un numero valido (distinto de 0), se suma y se lleva cuenta
   de cuantos valores reales se han encontrado. */
{
    char cad[30];
    int cont = 0;
    float sum = 0.0, valor;

    while (!feof(ap1))
    {
        fgets(cad, 30, ap1);  /* Lectura de cada linea */
        valor = atof(cad);    /* atof intenta interpretar la cadena como numero */

        if (valor)            /* Considera solo valores distintos de cero */
        {
            cont++;
            sum += valor;
        }
    }

    printf("\nSuma: %.2f", sum);

    if (cont)
        printf("\nPromedio: %.2f", sum / cont);
}
