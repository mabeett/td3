/*
 * Programa de anexo. Se presenta por pantalla cada uno de los argumentos
 * que recibe.
 * En caso de no recibir argumentos se muestra por la salida de error un
 * mensaje y se retorna 1.
**/

#include <stdio.h>

int main(int arg_count, char **arg_values)
{
    int i, ret;

    printf("Hola Mundo!\n");
    printf(" Análisis de argumentos:\n");
    printf("  arg_count vale %d\n", arg_count);

    for (i = 0; i < arg_count; i++) {
        printf("  arg_values[%d] vale '%s'.\n", i, arg_values[i]);
    }

    printf("Adios Mundo!\n");

    /* Si no se enviaron argumentos retornar 1, sino 0
     * Este programa espera argumentos, entonces si el usuario no los envía
     * se retorna -1
     **/
    if (arg_count == 1) {
        fprintf(stderr, "Por favor invoque a este programa con argumentos\n");
        ret = 1;
    } else {
        ret = 0;
    }

    return ret;
}
