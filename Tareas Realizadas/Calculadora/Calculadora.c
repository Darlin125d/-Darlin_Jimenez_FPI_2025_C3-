#include <stdio.h>   // incluye la librería estándar para usar printf, scanf, etc.
#include <math.h>    // incluye funciones matemáticas (por ejemplo pow o sqrt)

int main() {         // función principal donde empieza el programa
    int menu = -1;   // variable para guardar la opción del menú principal

    // mensaje de bienvenida al inicio del programa
    printf("=====================================\n");
    printf("         CALCULADORA D               \n");
    printf("=====================================\n");

    // ciclo principal que se repetirá hasta que el usuario elija salir (0)
    while (menu != 0) {

        // muestra el menú principal
        printf("\nMenu principal\n");
        printf("1. Operaciones basicas\n");
        printf("2. Numeros complejos\n");
        printf("3. Matrices\n");
        printf("0. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &menu);   // lee la opción que el usuario digite

        // ----------------------------------------------------------
        //              SECCIÓN 1: OPERACIONES BÁSICAS
        // ----------------------------------------------------------
        if (menu == 1) {
            int op = -1;     // guarda la operación a realizar
            double a, b, r;  // a y b son los números, r es el resultado

            while (op != 0) {   // bucle para repetir las operaciones hasta volver
                // muestra las operaciones disponibles
                printf("\nOperaciones basicas\n");
                printf("1. Sumar\n");
                printf("2. Restar\n");
                printf("3. Multiplicar\n");
                printf("4. Dividir\n");
                printf("0. Volver\n");
                printf("Elija una opcion: ");
                scanf("%d", &op);   // lee la operación

                if (op == 0) break;  // si elige 0, sale de este menú

                // pide los dos números al usuario
                printf("Digite el primer numero: ");
                scanf("%lf", &a);   // lee un número de tipo double
                printf("Digite el segundo numero: ");
                scanf("%lf", &b);

                // realiza la operación según la opción elegida
                if (op == 1) {
                    r = a + b;                      // suma
                    printf("Resultado: %.2lf\n", r);
                } else if (op == 2) {
                    r = a - b;                      // resta
                    printf("Resultado: %.2lf\n", r);
                } else if (op == 3) {
                    r = a * b;                      // multiplicación
                    printf("Resultado: %.2lf\n", r);
                } else if (op == 4) {
                    if (b == 0) {                   // verificación de división por 0
                        printf("No se puede dividir entre 0\n");
                    } else {
                        r = a / b;                  // división
                        printf("Resultado: %.2lf\n", r);
                    }
                } else {
                    printf("Opcion no valida\n");   // si no elige una opción válida
                }
            }
        }

        // ----------------------------------------------------------
        //              SECCIÓN 2: NÚMEROS COMPLEJOS
        // ----------------------------------------------------------
        else if (menu == 2) {
            int op = -1;                  // guarda la opción de operación
            double a1, b1, a2, b2;        // partes reales e imaginarias de los números
            double r1, r2, d;             // resultados y denominador para la división

            while (op != 0) {
                // muestra el submenú
                printf("\nNumeros complejos\n");
                printf("1. Sumar\n");
                printf("2. Restar\n");
                printf("3. Multiplicar\n");
                printf("4. Dividir\n");
                printf("0. Volver\n");
                printf("Elija una opcion: ");
                scanf("%d", &op);

                if (op == 0) break;   // salir del submenú

                // pedir al usuario las partes reales e imaginarias de ambos números
                printf("Primer numero (parte real): ");
                scanf("%lf", &a1);
                printf("Primer numero (parte imaginaria): ");
                scanf("%lf", &b1);
                printf("Segundo numero (parte real): ");
                scanf("%lf", &a2);
                printf("Segundo numero (parte imaginaria): ");
                scanf("%lf", &b2);

                // según la opción, se calcula el resultado
                if (op == 1) {
                    // suma: (a1 + b1i) + (a2 + b2i)
                    r1 = a1 + a2;
                    r2 = b1 + b2;
                } else if (op == 2) {
                    // resta
                    r1 = a1 - a2;
                    r2 = b1 - b2;
                } else if (op == 3) {
                    // multiplicación de complejos
                    r1 = a1 * a2 - b1 * b2;
                    r2 = a1 * b2 + b1 * a2;
                } else if (op == 4) {
                    // división de complejos: (a1 + b1i) / (a2 + b2i)
                    d = a2 * a2 + b2 * b2;  // denominador (a2² + b2²)
                    if (d == 0) {           // si el divisor es 0, error
                        printf("No se puede dividir entre 0\n");
                        continue;           // vuelve al inicio del submenú
                    }
                    r1 = (a1 * a2 + b1 * b2) / d;
                    r2 = (b1 * a2 - a1 * b2) / d;
                } else {
                    printf("Opcion no valida\n");
                    continue;
                }

                // muestra el número complejo resultante
                printf("Resultado: %.2lf + %.2lfi\n", r1, r2);
            }
        }

        // ----------------------------------------------------------
        //              SECCIÓN 3: MATRICES
        // ----------------------------------------------------------
        else if (menu == 3) {
            int op = -1;                // opción de operación
            int n, m;                   // tamaño de las matrices
            int i, j, k;                // contadores para los bucles
            double A[10][10], B[10][10], R[10][10];  // matrices A, B y resultado R

            while (op != 0) {
                // submenu de matrices
                printf("\nMatrices\n");
                printf("1. Sumar\n");
                printf("2. Restar\n");
                printf("3. Multiplicar\n");
                printf("0. Volver\n");
                printf("Elija una opcion: ");
                scanf("%d", &op);

                if (op == 0) break;

                // pide dimensiones
                printf("Filas: ");
                scanf("%d", &n);
                printf("Columnas: ");
                scanf("%d", &m);

                // llenar matriz A
                printf("Matriz A:\n");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        printf("A[%d][%d]: ", i+1, j+1);
                        scanf("%lf", &A[i][j]);
                    }
                }

                // llenar matriz B
                printf("Matriz B:\n");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        printf("B[%d][%d]: ", i+1, j+1);
                        scanf("%lf", &B[i][j]);
                    }
                }

                // operaciones con matrices
                if (op == 1) {
                    // suma de matrices
                    for (i = 0; i < n; i++) {
                        for (j = 0; j < m; j++) {
                            R[i][j] = A[i][j] + B[i][j];
                        }
                    }
                } else if (op == 2) {
                    // resta de matrices
                    for (i = 0; i < n; i++) {
                        for (j = 0; j < m; j++) {
                            R[i][j] = A[i][j] - B[i][j];
                        }
                    }
                } else if (op == 3) {
                    // multiplicación de matrices
                    if (n != m) {  // solo se permiten cuadradas para simplificar
                        printf("Solo se pueden multiplicar si son cuadradas\n");
                        continue;
                    }
                    for (i = 0; i < n; i++) {
                        for (j = 0; j < m; j++) {
                            R[i][j] = 0; // inicializa el elemento
                            for (k = 0; k < n; k++) {
                                R[i][j] += A[i][k] * B[k][j];
                            }
                        }
                    }
                } else {
                    printf("Opcion no valida\n");
                    continue;
                }

                // muestra la matriz resultado
                printf("Resultado:\n");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        printf("%.2lf ", R[i][j]);
                    }
                    printf("\n");  // salto de línea al final de cada fila
                }
            }
        }

        // ----------------------------------------------------------
        //              SALIR DEL PROGRAMA
        // ----------------------------------------------------------
        else if (menu == 0) {
            printf("Adios!\n");   // mensaje al salir
        }

        // si el usuario escribe algo incorrecto
        else {
            printf("Opcion incorrecta\n");
        }
    }

    return 0;  // fin del programa
}
