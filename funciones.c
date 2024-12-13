#include <stdio.h>
#include <math.h>
#include "funciones.h"
#include <string.h>

int menu() {
    int opcion;
    printf("\n--- BIBLIOTECA ---\n");
    printf("1. Registrar Libro\n");
    printf("2. Mostrar Libros\n");
    printf("3. Buscar Libro por ID\n");
    printf("4. Buscar Libro por Título\n");
    printf("5. Actualizar Estado de Libro\n");
    printf("6. Eliminar Libro\n");
    printf("7. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    return opcion;
}

void registrarLibros(struct Libro *libros, int *cantidadLibros) {
    if (*cantidadLibros >= MAX_LIBROS) {
        printf("La biblioteca está llena. No se pueden agregar más libros.\n");
        return;
    }

    struct Libro nuevoLibro;
    int i = *cantidadLibros;
    nuevoLibro.id = (i * 10)+1000;
                printf("El ID de tu libro es: %d\n", nuevoLibro.id);

    printf("Ingrese título (máx 100 caracteres): ");
    scanf(" %[^\n]", nuevoLibro.titulo);

    printf("Ingrese autor (máx 50 caracteres): ");
    scanf(" %[^\n]", nuevoLibro.autor);

    printf("Ingrese año de publicación: ");
    scanf("%d", &nuevoLibro.anioPublicacion);
    while (nuevoLibro.anioPublicacion < 0 || nuevoLibro.anioPublicacion > 2024) {
        printf("Año inválido. Ingrese nuevamente: ");
        scanf("%d", &nuevoLibro.anioPublicacion);
    }

    strcpy(nuevoLibro.estado, "Disponible");

    libros[*cantidadLibros] = nuevoLibro;
    (*cantidadLibros)++;
    printf("Libro registrado exitosamente.\n");
}

void mostrarLibros(struct Libro *libros) {
    printf("\n--- LISTA DE LIBROS ---\n");
    printf("ID\tTítulo\t\t\tAutor\t\t\tAño\t\tEstado\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < 20; i++) {
        if (libros[i].id != 0) {
            printf("%d\t%-20s\t%-20s\t%d\t\t%s\n", 
                libros[i].id, 
                libros[i].titulo, 
                libros[i].autor, 
                libros[i].anioPublicacion, 
                libros[i].estado);
        }
    }
}

void buscarLibroId(struct Libro *libros, int id) {
    for (int i = 0; i < 20; i++) {
        if (libros[i].id == id) {
            printf("\n--- LIBRO ENCONTRADO ---\n");
            printf("ID: %d\n", libros[i].id);
            printf("Título: %s\n", libros[i].titulo);
            printf("Autor: %s\n", libros[i].autor);
            printf("Año: %d\n", libros[i].anioPublicacion);
            printf("Estado: %s\n", libros[i].estado);
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void buscarLibroTitulo(struct Libro *libros, char *titulo) {
    int buscado = 0;
    for (int i = 0; i < 20; i++) {
        if (strcmp(libros[i].titulo, titulo)== 0) {
            printf("\n--- LIBRO ENCONTRADO ---\n");
            printf("ID: %d\n", libros[i].id);
            printf("Título: %s\n", libros[i].titulo);
            printf("Autor: %s\n", libros[i].autor);
            printf("Año: %d\n", libros[i].anioPublicacion);
            printf("Estado: %s\n", libros[i].estado);
            buscado = 1;
        }
    }
    if (buscado != 0) {
        printf("El libro no se encontro\n");
    }
    return;
}

void actualizarEstadoLibro(struct Libro *libros) {
    int id;
    printf("Ingrese el ID del libro a actualizar: ");
    scanf("%d", &id);

    for (int i = 0; i < 20; i++) {
        if (libros[i].id == id) {
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
            } else {
                strcpy(libros[i].estado, "Disponible");
            }
            printf("Estado actualizado exitosamente.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void eliminarLibro(struct Libro *libros, int *cantidadLibros) {
     printf("\n--- LISTA DE LIBROS ---\n");
    printf("ID\tTítulo\t\t\tAutor\t\t\tAño\t\tEstado\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < 20; i++) {
        if (libros[i].id != 0) {
            printf("%d\t%-20s\t%-20s\t%d\t\t%s\n", 
                libros[i].id, 
                libros[i].titulo, 
                libros[i].autor, 
                libros[i].anioPublicacion, 
                libros[i].estado);
        }
    }
    int id;
    printf("Ingrese el ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < *cantidadLibros; i++) {
        if (libros[i].id == id) {
            // Mover los elementos siguientes para llenar el espacio
            for (int j = i; j < *cantidadLibros - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*cantidadLibros)--;
            printf("Libro eliminado exitosamente.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}