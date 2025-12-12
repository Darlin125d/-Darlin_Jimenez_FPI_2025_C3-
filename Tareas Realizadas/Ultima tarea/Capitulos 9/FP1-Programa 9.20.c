#include <stdio.h>

/* Escuela.
   El programa recibe un archivo de acceso directo con informacion de alumnos,
   y genera algunos datos estadisticos basicos. */

typedef struct {
    char materia[20];
    int calificacion;
} matcal;

typedef struct {
    int matricula;
    char nombre[20];
    matcal cal[5];    /* Arreglo de 5 materias */
} alumno;

/* Prototipos de funciones */
void F1(FILE *);
void F2(FILE *);
float F3(FILE *);

void main(void)
{
    float promedio;
    FILE *ap;

    ap = fopen("esc.dat", "rb");
    if (ap != NULL) {
        F1(ap);
        F2(ap);
        promedio = F3(ap);

        printf("\n\nPROMEDIO GENERAL MATERIA 4: %f\n", promedio);
        fclose(ap);
    } else {
        printf("\nEl archivo no se puede abrir\n");
    }
}

void F1(FILE *ap)
/* Imprime la matricula y el promedio general de cada alumno */
{
    alumno alu;
    int j;
    float sum, prom;

    printf("\nMATRICULA Y PROMEDIOS");

    fread(&alu, sizeof(alumno), 1, ap);
    while (!feof(ap)) {
        printf("\nMatricula: %d", alu.matricula);

        sum = 0;
        for (j = 0; j < 5; j++)
            sum += alu.cal[j].calificacion;

        prom = sum / 5;
        printf("\tPromedio: %f", prom);

        fread(&alu, sizeof(alumno), 1, ap);
    }
}

void F2(FILE *ap)
/* Imprime la matricula de los alumnos con calificacion mayor a 9 en la tercera materia */
{
    alumno alu;

    rewind(ap);
    printf("\n\nALUMNOS CON CALIFICACION MAYOR A 9 EN MATERIA 3");

    fread(&alu, sizeof(alumno), 1, ap);
    while (!feof(ap)) {
        if (alu.cal[2].calificacion > 9)
            printf("\nMatricula del alumno: %d", alu.matricula);

        fread(&alu, sizeof(alumno), 1, ap);
    }
}

float F3(FILE *ap)
/* Calcula el promedio general de la materia 4 */
{
    alumno alu;
    int contador = 0;
    float suma = 0, promedio;

    rewind(ap);
    fread(&alu, sizeof(alumno), 1, ap);

    while (!feof(ap)) {
        contador++;
        suma += alu.cal[3].calificacion;

        fread(&alu, sizeof(alumno), 1, ap);
    }

    promedio = suma / contador;
    return promedio;
}
