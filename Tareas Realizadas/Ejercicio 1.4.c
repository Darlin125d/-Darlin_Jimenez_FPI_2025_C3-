#include <stdio.h>

 /* Superficie del triángulo.
 El programa, al recibir como datos la base y la altura de un triangulom
 calcula la superficie.

 BAS, ALT Y SUP variable de tipop real. */

 void main (void)
 {
     float BAS, ALT, SUP;
     printf("ingrese la base y la altura del triangulo: ");
     scanf("%f %f", &BAS, &ALT);
     SUP = BAS * ALT / 2;
     printf("\nLa superficie del triangulo es: %5.2f", SUP);
 }

