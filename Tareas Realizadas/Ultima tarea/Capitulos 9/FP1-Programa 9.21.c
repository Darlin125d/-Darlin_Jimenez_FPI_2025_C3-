#include <stdio.h>

/* Examen de admision.
   El programa recibe un archivo de acceso directo con informacion de los
   alumnos que presentaron el examen de admision y genera datos para el
   departamento de control escolar.
*/

typedef struct {
    int clave;
    char nombre[20];
    int carrera;
    float promedio;
    float examen;
    char telefono[12];
} alumno;

float F1(FILE *);
void F2(FILE *, FILE *, FILE *, FILE *, FILE *, FILE *);
void F3(FILE *, FILE *, FILE *, FILE *, FILE *);

void main(void)
{
    float prom;
    FILE *ap, *c1, *c2, *c3, *c4, *c5;

    ap  = fopen("alu1.dat", "r");
    c1 = fopen("car1.dat", "w+");
    c2 = fopen("car2.dat", "w+");
    c3 = fopen("car3.dat", "w+");
    c4 = fopen("car4.dat", "w+");
    c5 = fopen("car5.dat", "w+");

    if (ap != NULL && c1 != NULL && c2 != NULL &&
        c3 != NULL && c4 != NULL && c5 != NULL) {

        prom = F1(ap);
        printf("\nPROMEDIO EXAMEN DE ADMISION: %.2f", prom);

        F2(ap, c1, c2, c3, c4, c5);
        F3(c1, c2, c3, c4, c5);

    } else {
        printf("\nEl o los archivos no se pudieron abrir");
    }

    fclose(ap);
    fclose(c1);
    fclose(c2);
    fclose(c3);
    fclose(c4);
    fclose(c5);
}

/* Calcula el promedio del examen de admision */
float F1(FILE *ap)
{
    alumno alu;
    float sum = 0;
    int count = 0;

    fread(&alu, sizeof(alumno), 1, ap);

    while (!feof(ap)) {
        sum += alu.examen;
        count++;
        fread(&alu, sizeof(alumno), 1, ap);
    }

    return sum / count;
}

/* Genera archivos con los alumnos admitidos por carrera */
void F2(FILE *ap, FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
{
    alumno alu;

    rewind(ap);
    fread(&alu, sizeof(alumno), 1, ap);

    while (!feof(ap)) {

        /* Condiciones de admision */
        if ((alu.examen >= 1300 && alu.promedio >= 8) ||
            (alu.examen >= 1400 && alu.promedio >= 7)) {

            switch (alu.carrera) {
                case 1: fwrite(&alu, sizeof(alumno), 1, c1); break;
                case 2: fwrite(&alu, sizeof(alumno), 1, c2); break;
                case 3: fwrite(&alu, sizeof(alumno), 1, c3); break;
                case 4: fwrite(&alu, sizeof(alumno), 1, c4); break;
                case 5: fwrite(&alu, sizeof(alumno), 1, c5); break;
            }
        }

        fread(&alu, sizeof(alumno), 1, ap);
    }
}

/* Calcula el promedio de examen de los alumnos admitidos por carrera */
void F3(FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
{
    alumno alu;
    float cal[5];
    float sum;
    int i, count;

    FILE *archs[5] = {c1, c2, c3, c4, c5};

    for (i = 0; i < 5; i++) {

        rewind(archs[i]);
        sum = 0;
        count = 0;

        fread(&alu, sizeof(alumno), 1, archs[i]);

        while (!feof(archs[i])) {
            sum += alu.examen;
            count++;
            fread(&alu, sizeof(alumno), 1, archs[i]);
        }

        if (count > 0)
            cal[i] = sum / count;
        else
            cal[i] = 0;
    }

    for (i = 0; i < 5; i++)
        printf("\nPromedio carrera %d: %.2f", i + 1, cal[i]);
}
