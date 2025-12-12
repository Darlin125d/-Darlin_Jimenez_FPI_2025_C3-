#include <stdio.h>
#include <stdlib.h>
#include <string.h> // necesario para strcspn

typedef struct {
    char marca[50];
    char modelo[50];
    int ano;       // sin tilde
    float precio;
} Vehiculo;

void agregarVehiculo() {
    Vehiculo v;
    FILE *archivo = fopen("vehiculos.txt", "a"); // modo append

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("\n--- Agregar Vehículo ---\n");

    getchar(); // limpiar buffer antes de fgets

    printf("Marca: ");
    fgets(v.marca, 50, stdin);
    v.marca[strcspn(v.marca, "\n")] = 0; // quitar salto de línea

    printf("Modelo: ");
    fgets(v.modelo, 50, stdin);
    v.modelo[strcspn(v.modelo, "\n")] = 0;

    printf("Año: ");
    scanf("%d", &v.ano);

    printf("Precio: ");
    scanf("%f", &v.precio);

    fprintf(archivo, "%s,%s,%d,%.2f\n", v.marca, v.modelo, v.ano, v.precio);
    fclose(archivo);

    printf("Vehículo agregado correctamente.\n");
}

void listarVehiculos() {
    FILE *archivo = fopen("vehiculos.txt", "r");
    Vehiculo v;

    if (archivo == NULL) {
        printf("No hay vehículos registrados.\n");
        return;
    }

    printf("\n--- Lista de Vehículos ---\n");
    while (fscanf(archivo, "%49[^,],%49[^,],%d,%f\n", v.marca, v.modelo, &v.ano, &v.precio) == 4) {
        printf("Marca: %s | Modelo: %s | Año: %d | Precio: %.2f\n",
               v.marca, v.modelo, v.ano, v.precio);
    }

    fclose(archivo);
}

int main() {
    int opcion;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Agregar vehículo\n");
        printf("2. Listar vehículos\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarVehiculo();
                break;
            case 2:
                listarVehiculos();
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 3);

    return 0;
}
