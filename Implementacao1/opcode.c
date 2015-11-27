#include "opcode.h"

int encontra_parametro (int* inicio, int* tamanho, int* termino) {
    switch( ptrSrc[*inicio] ){
        case 'K':
        case 'S':
            *termino = *inicio;
            break;

        case '(':
            *termino = buscar_prox_parentese(*inicio, 1);
            *tamanho = *termino - *inicio + 1;
            break;

        default: return 0;
            break;
    }

    return 1;
}

char reducao_K()
{
	int inicioA = 1, inicioB = 0;
	int terminoA = 0, terminoB = 0;
	int tamanhoA = 1, tamanhoB = 1;

	register int apontadorD = 0;
	register int apontadorS = 0;

	register int encontrou;

	encontrou = encontra_parametro(&inicioA,&tamanhoA,&terminoA);
	if(!encontrou)
        return 1;

    inicioB = terminoA + 1;
    encontrou = encontra_parametro(&inicioB,&tamanhoB,&terminoB);
    if(!encontrou)
        return 1;

    apontadorS = inicioA;
    memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoA*sizeof(char));
    
    apontadorD = apontadorD + tamanhoA ;
	apontadorS = terminoB + 1;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,((tamanho_entrada-tamanhoA-tamanhoB))*sizeof(char));
	tamanho_entrada = tamanho_entrada - 1 - tamanhoB;

	return 0;
}


char reducao_S()
{
	int inicioA = 1,inicioB = 0, inicioC = 0;
	int terminoA = 0, terminoB = 0, terminoC = 0;
	int tamanhoA = 1, tamanhoB = 1, tamanhoC = 1;

	register int apontadorS = 0;
	register int apontadorD = 0;

	register int encontrou;

	encontrou = encontra_parametro(&inicioA,&tamanhoA,&terminoA);
	if(!encontrou)
        return 1;

    inicioB = terminoA + 1;
    encontrou = encontra_parametro(&inicioB,&tamanhoB,&terminoB);
    if(!encontrou)
        return 1;

    inicioC = terminoB + 1;
    encontrou = encontra_parametro(&inicioC,&tamanhoC,&terminoC);
    if(!encontrou)
        return 1;

    apontadorS = inicioA;
    //ptrDst[apontadorD] = '(';

    //apontadorD++;
    memcpy(ptrDst + apontadorD, ptrSrc+apontadorS,tamanhoA*sizeof(char));

    apontadorD = apontadorD + tamanhoA;
    apontadorS = inicioC;
    memcpy(ptrDst + apontadorD, ptrSrc + apontadorS,tamanhoC*sizeof(char));

    apontadorD = apontadorD + tamanhoC;
    apontadorS = inicioB;
    //ptrDst[apontadorD] = ')';

    //apontadorD++;
    ptrDst[apontadorD] = '(';

    apontadorD++;
    apontadorS = inicioB;
    memcpy(ptrDst + apontadorD, ptrSrc+apontadorS,tamanhoB*sizeof(char));

    apontadorD = apontadorD + tamanhoB;
    apontadorS = inicioC;
    memcpy(ptrDst + apontadorD, ptrSrc + apontadorS,tamanhoC*sizeof(char));

    apontadorD = apontadorD + tamanhoC;
    apontadorS = inicioC + tamanhoC;
    ptrDst[apontadorD] = ')';

    apontadorD++;
    memcpy(ptrDst + apontadorD,ptrSrc + apontadorS,(tamanho_entrada-tamanhoA-tamanhoB-tamanhoC)*sizeof(char));
    tamanho_entrada = tamanho_entrada + 1 + tamanhoC;

	return 0;
}
