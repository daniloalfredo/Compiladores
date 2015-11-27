#include "parentese.h"

// Recebe como parametro a posicao inicial do parentese encontrado e
// o tipo (1 para apenas encontrar a posição final, 2 para encontrar a posição final e remover os parenteses
inline int buscar_prox_parentese(int pos_inicial, int tipo)
{
	int i = 0;
	int cont_parentese = 1;
	register int pos_final = 0;

	for(i = pos_inicial + 1; i <= ARRAY_SIZE; i++)
	{
		if(ptrSrc[i] == '(')
		{
			cont_parentese++;
		}
		else if(ptrSrc[i] == ')')
		{
			cont_parentese--;
			if(cont_parentese == 0) {
                pos_final = i;
                break;
			}
		}
	}

    //Se era um parametro entao retorna a posição do parentese final
	if(tipo == 1) {
        return pos_final;
	}
	//Se esta procurando um operador entao remove os parenteses inicial e final
    else {
        memcpy(ptrDst,ptrSrc+pos_inicial+1,(pos_final - 1));
        memcpy(ptrDst + pos_final - 1,ptrSrc+pos_final + 1,(tamanho_entrada-pos_final)*sizeof(char));
        tamanho_entrada -= 2;
    }

	return -1;
}
