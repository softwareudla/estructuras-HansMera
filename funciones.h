#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_LIBROS 20
#define MAX_TITULO 100
#define MAX_AUTOR 50

struct Libro {
    int id;
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int anioPublicacion;
    char estado[15];
};

// Prototipos de funciones
int menu();
void registrarLibros(struct Libro *libros, int *cantidadLibros);
void mostrarLibros(struct Libro *libros);
void buscarLibroId(struct Libro *libros, int id);
void buscarLibroTitulo(struct Libro *libros, char *titulo);
int validarIdUnico(struct Libro *libros, int id, int cantidadLibros);
void actualizarEstadoLibro(struct Libro *libros);
void eliminarLibro(struct Libro *libros, int *cantidadLibros);

#endif