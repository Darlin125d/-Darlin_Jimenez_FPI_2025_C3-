#include <stdio.h>

/* Programa para actualizar alumnos.
   El usuario indica que registro quiere modificar y escribe
   el nuevo promedio. El programa carga ese registro y lo actualiza
   directamente en el archivo. */

typedef struct {
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void modifica(FILE *);

void main(void)
{
    FILE *ar;

    if ((ar = fopen("ad1.dat", "r+")) != NULL)
        modifica(ar);
    else
        printf("\nNo se pudo abrir el archivo");

    fclose(ar);
}

void modifica(FILE *ap)
{
    int d;
    alumno alu;

    printf("\nIngrese el numero de registro que desea modificar: ");
    scanf("%d", &d);

    /* Como el primer registro esta en la posicion 0, el registro n
       se encuentra en (n-1). */
    fseek(ap, (d - 1) * sizeof(alumno), 0);

    /* Leemos el registro ubicado en la posicion seleccionada. */
    fread(&alu, sizeof(alumno), 1, ap);

    printf("\nIngrese el promedio correcto del alumno: ");
    scanf("%f", &alu.promedio);

    /* Volvemos a la posicion exacta para escribir el registro modificado. */
    fseek(ap, (d - 1) * sizeof(alumno), 0);

    /* Guardamos el registro actualizado. */
    fwrite(&alu, sizeof(alumno), 1, ap);
}
