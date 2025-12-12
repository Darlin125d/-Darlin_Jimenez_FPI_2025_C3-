#include <stdio.h>

/* Programa para guardar datos de alumnos usando una estructura
   y escribirlos en un archivo. */

typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void escribe(FILE *);

void main(void)
{
    FILE *ar = fopen("ad1.dat", "w");

    if (ar != NULL)
    {
        escribe(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir");
    }
}

void escribe(FILE *ap)
{
    alumno alu;
    int i = 0;
    int r;

    printf("\nDesea ingresar informacion de alumnos? (Si-1 No-0): ");
    scanf("%d", &r);

    while (r)
    {
        i++;

        printf("Matricula del alumno %d: ", i);
        scanf("%d", &alu.matricula);

        printf("Nombre del alumno %d: ", i);
        fflush(stdin);
        gets(alu.nombre);

        printf("Carrera del alumno %d: ", i);
        scanf("%d", &alu.carrera);

        printf("Promedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);

        /* Se guarda un registro completo en el archivo */
        fwrite(&alu, sizeof(alumno), 1, ap);

        printf("\nDesea registrar otro alumno? (Si-1 No-0): ");
        scanf("%d", &r);
    }
}
