#include <stdio.h>
#include <math.h>
#include "funciones.h"
#include <string.h>

int main (int argc, char *argv[]) { 
    struct Libro libros[20] = {0};  // Inicializar con ceros
    int opc; 
    int i = 0;
    
    do { 
        opc = menu(); 
        switch (opc) { 
            case 1: 
                registrarLibros(libros, &i);
                i++; 
                break; 
            case 2: 
                mostrarLibros(libros); 
                break; 
            case 3: 
                {
                    int id;
                    printf("Ingrese el id del libro a buscar: "); 
                    scanf("%d", &id); 
                    buscarLibroId(libros, id); 
                }
                break; 
            case 4: 
                {
                    char titulo[100]; 
                    printf("Ingrese el titulo del libro a buscar: ");
                    fflush(stdin);
                    fgets(titulo, 40, stdin);
                    titulo[strcspn(titulo, "\n")] = 0;  // Remove newline character
                    buscarLibroTitulo(libros, titulo);
                }
                break; 
            case 5:
                {
                    actualizarEstadoLibro(libros);
                }
                break;
            case 6:
                {
                    eliminarLibro(libros, &i);
                }
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida\n");
                break;
        }
    } while (opc != 7);  // 7 es la condición de salida

    return 0;
}