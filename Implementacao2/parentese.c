#include "parentese.h"

int buscar_prox_parentese(int pos_inicial)
{
	int i = 0;
	int cont_parentese = 1;
	int ultimo_parentese = 0;

	for(i = pos_inicial + 1; i <= ARRAY_SIZE; i++)
	{
		if(ptrSrc[i] == '(')
		{
			cont_parentese++;
		}
		else if(ptrSrc[i] == ')')
		{
			cont_parentese--;
			if(cont_parentese == 0)
			{
				return i;
			}
		}
	}

	return -1;
}

void remover_parentese(int pos1, int pos2)
{
	memcpy(ptrDst,ptrSrc+pos1+1,(pos2 - 1));
	memcpy(ptrDst + pos2 - 1,ptrSrc+pos2 + 1,strlen(ptrSrc+pos2)*sizeof(char));	
}