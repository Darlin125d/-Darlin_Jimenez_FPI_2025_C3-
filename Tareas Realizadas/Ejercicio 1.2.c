#include <Stdio.h>

 /* Invierte datos
 El programa al recicibir como dato un conjunto de datos de entrada,
 invierte el orden de los mismos cuando los imprime.

  A, B, C Y D: Variables de tipo enteros */

  void main(void)

   {
    int A, B, C, D;
    printf("Ingrese cuantro datos de tipo entero: ");
    scanf("%d %d %d %d", &A, &B, &C, &D );
    printf("\n %d %d %d %d", D, C, B, A);
   }
