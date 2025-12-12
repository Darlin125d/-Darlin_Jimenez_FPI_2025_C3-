#include <stdio.h>

/* Incrementa salarios.
   El programa revisa las ventas anuales de cada empleado y actualiza
   su salario si supera el millon de pesos. */

typedef struct {
    int clave;
    int departamento;
    float salario;
    float ventas[12];
} empleado;

void incrementa(FILE *);

void main(void)
{
    FILE *ar = fopen("ad5.dat", "r+");

    if (ar != NULL)
    {
        incrementa(ar);

        /* Ejemplo de uso de rewind: coloca el apuntador al inicio.
           Aqui no es necesario, solo se muestra su uso. */
        rewind(ar);

        fclose(ar);
    }
    else
    {
        printf("\nNo se puede abrir el archivo");
    }
}

void incrementa(FILE *ap)
{
    empleado emple;
    int i, j, tam;
    float suma;

    /* Se obtiene el tamano de la estructura */
    tam = sizeof(empleado);

    /* Se lee el primer registro */
    fread(&emple, sizeof(empleado), 1, ap);

    while (!feof(ap))
    {
        /* Posicion actual en bytes / tamano del bloque */
        i = ftell(ap) / tam;

        suma = 0;
        for (j = 0; j < 12; j++)
        {
            suma += emple.ventas[j];
        }

        if (suma > 1000000)
        {
            /* Aumentar salario */
            emple.salario = emple.salario * 1.10;

            /* Volver al inicio del registro que acabamos de leer */
            fseek(ap, (i - 1) * tam, 0);

            fwrite(&emple, sizeof(empleado), 1, ap);

            /* Asegura que el apuntador quede bien posicionado
               para la siguiente lectura */
            fseek(ap, i * tam, 0);
        }

        /* Leer el siguiente registro */
        fread(&emple, sizeof(empleado), 1, ap);
    }
}
