#include<stdio.h>

int main(int arg_c, char ** arg_v)
{
	int i;
	printf("Hola Mundo!\n");

	for (i=1 ; i < arg_c ; i++)
		printf("Argumento número %d es %s\n", i, arg_v[i]);

	if (i==1)
		printf("Intente ejecutar \"%s dos palabras\"\n", arg_v[0]);
	return 0;
}
