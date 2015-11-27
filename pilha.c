#include "pilha.h"

int posPilhaLivre = 0;

char pop(int times)
{
	char operador;
	int i;
	for(i = 0; i < times; i++)
	{
		if(pilha[posPilhaLivre - 1]->id == 0)
			operador = pilha[posPilhaLivre - 1]->elemento.op;
		else
			operador = pilha[posPilhaLivre - 1]->elemento.num;
		posPilhaLivre--;
		//printf("\nposPilhaLivre no pop= %d\n",posPilhaLivre );
	}

	return operador;
}

void push(Cell* cell)
{
	Cell* celula = cell;
	pilha[posPilhaLivre] = celula;
	posPilhaLivre++;
	while(celula->left != NULL)
	{
		celula = celula->left;
		pilha[posPilhaLivre] = celula;
		//printf("posPilhaLivre: %d\n", posPilhaLivre);
		posPilhaLivre++;
		//printf("1");
	}
}

void esvaziarPilha(int posPilhaRaiz)
{
	posPilhaLivre = posPilhaRaiz;
}

void imprimePilha(int times)
{
	int i;
	for(i = 0; i < times; i++)
		printf("%c",pilha[i]->elemento.op);
	printf("\n");
}