#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"
#include "entrada.h"
#include "reducao.h"

char src[ARRAY_SIZE] = "K(ab)(ba)";

int main() 
{
	Lista * inicio = NULL; /* declara uma lista não iniciada */
	int tam = strlen(src);
	int reduziu = 0;
	inicio = criaLista(0, tam,src);
	imprimeLista(inicio);
	printf("\n");
	while(!reduziu)
	{
		switch(inicio->begin->info.letra)
		{
			case 'K':
				reduziu = reducao_K(inicio);
				break;
			default: reduziu = 1;
		}
	}
	imprimeLista(inicio);
	printf("\n");
	return 0 ;
}