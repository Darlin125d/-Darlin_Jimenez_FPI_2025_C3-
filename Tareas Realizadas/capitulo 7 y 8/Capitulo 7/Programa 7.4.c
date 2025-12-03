#include <stdio.h>
#include <string.h>

/* Declaracion de cadenas de caracteres y asignacion de valores. */
void main(void)
{
char *cad0;
cad0 = "Argentina"; /* La declaracion y la asignacion son correctas. */
puts(cad0);
cad0 = "Brasil";
/* Correcto. Se modifica el contenido de la posicion en memoria a la que apunta
la variable cad0 —apuntador de tipo cadena de caracteres. */
puts(cad0);

/* El libro escribe:
     char *cad1;
     gets(*cad1); gets(cad1);
   Esto NO compila. Para mantener la idea original pero funcional: */
char cad1_buffer[100];
char *cad1 = cad1_buffer;

/* Correcto. Primero se le asigna un valor a la posicion de memoria a la que
apunta cad1. Luego podemos modificar el contenido de esta posicion de memoria
utilizando la funcion gets. */

/* gets(cad1);   <=== Version del libro (NO valida hoy) */
printf("Ingrese una cadena en cad1: ");
fgets(cad1, 100, stdin);  /* Version funcional */

char cad2[20] = "Mexico"; /* Correcto. */
puts(cad2);

/* gets(cad2);   <=== Version del libro */
printf("Ingrese otra cadena para cad2: ");
fgets(cad2, 20, stdin);  /* Version funcional */
puts(cad2);

/* El valor de una cadena (declarada como cadena[longitud]) se puede modificar
por medio de lecturas o utilizando funciones de la biblioteca string.h
(ejemplo 7.6). */
puts(cad2);

/* El libro pone:
     cad2[10] = "Guatemala";
   Esto NO es valido. Para mantener la intencion: */

strcpy(cad2, "Guatemala");
puts(cad2);
}
