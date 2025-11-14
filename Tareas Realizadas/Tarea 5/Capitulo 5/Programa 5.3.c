#include <stdio.h>
/* Apuntadores, variables y valores. */

int main(void)
{
    int X = 3, Y = 7, Z[5] = {2, 4, 6, 8, 10};

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    int *IX;               /* IX representa un apuntador a un entero. */

    IX = &X;               /* IX apunta a X. */
    Y = *IX;               /* Y toma el valor de X, ahora vale 3. */
    *IX = 1;               /* X se modifica, ahora vale 1. */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = &Z[2];            /* IX apunta al tercer elemento del arreglo Z. */
    Y = *IX;               /* Y = Z[2] (6). */
    *IX = 15;              /* Z[2] = 15. */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    X = *IX + 5;           /* X = 15 + 5 = 20. */
    *IX = *IX - 5;         /* Z[2] = 10. */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    ++*IX;                 /* Z[2] = 11. */
    *IX += 1;              /* Z[2] = 12. */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    X = *(IX + 1);         /* X = Z[3] = 8. */
    Y = *IX;               /* Y = Z[2] = 12. */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = IX + 1;           /* IX apunta a Z[3]. */
    Y = *IX;               /* Y = Z[3] = 8. */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = IX + 4;           /* IX sale fuera del arreglo. ERROR intencional del libro. */
    Y = *IX;               /* Y toma un valor basura. */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = &X;               /* IX apunta a X. */
    IX = IX + 1;           /* IX cae en memoria incorrecta. */
    X = *IX;               /* X toma un valor basura. */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d\n",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    return 0;
}
