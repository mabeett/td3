/* 
 * Ejercicio 1 del TP Memoria compartida
 * Tipica implementacion de una memoria compartida
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define MEM_COM "MEM_COM"       //nombre
#define MENSAJE "INFORMACION PARA OTRO PROCESO\n"

int main()
{

    int fd, error, leido, largo;
    int *ptr;
    char buff[1024];
    struct stat sb;

// --- Crea la memoria compartida, y obtiene el descriptor
    fd = shm_open(MEM_COM, O_RDWR | O_CREAT, 0777);
    if (fd == -1) {
        printf("\nError en shm_open\n");
        exit(-1);
    }
// --- Se dimensiona la memoria y se pone a cero
    largo = 1024;
    error = ftruncate(fd, largo);
    if (error == -1) {
        printf("\nError en ftruncate\n");
        exit(-1);
    }
    // --- Se mapea la memoria compartida al espacio de memoria del proceso
    //    Devuelve un puntero al �rea reservada
    ptr = mmap(NULL, 10, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == (void *)-1) {
        printf("\nError en mmap\n");
        exit(-1);
    }

    printf("Direccion de memoria local donde arranca la memoria %p\n", ptr);

    printf("Hacer >$ls /dev/shm \n");

    sleep(10);

    // --- Copia Mensaje en la memoria
    memcpy(ptr, MENSAJE, sizeof(MENSAJE));

    printf("MENSAJE copiado en memoria\n");

    printf("Hacer >$cat /dev/shm/MEM_COM\n");

    sleep(10);

// --- Lee el estado de la memoria y se guarda en la estructura sb
//     el tama�o del archivo es el campo st_size
    error = fstat(fd, &sb);
    if (error == -1) {
        printf("\nError en fstat\n");
        exit(-1);
    }
// -- Copia  de la memoria compartida en buff
    memcpy(buff, ptr, sb.st_size);
    printf("\nLeido de memoria compartida: %s", buff);

///////////// vuelve a leer ////////////////////////////////
// --- Lee el estado de la memoria y se guarda en la estructura sb
//     el tama�o del archivo es el campo st_size
    error = fstat(fd, &sb);
    if (error == -1) {
        printf("\nError en fstat\n");
        exit(-1);
    }
// -- Lee de la memoria compartida y se imprime por pantalla
    write(0, "\nLeido por segunda vez de la memoria: ",
          sizeof("\nLeido por segunda vez de la memoria: "));
    largo = write(STDOUT_FILENO, ptr, sb.st_size);

/*
// --- Borrar memoria compartida
        error = shm_unlink(MEM_COM);
        if (error == -1) {
                printf("\nError en shm_unlink\n");
                exit(-1);
        }

        printf("\nObjeto de memoria borrado\n");

*/

    exit(0);
}
