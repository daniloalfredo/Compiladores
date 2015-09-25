#include "opcode.h"

int encontra_parametro (int* inicio, int* tamanho, int* termino) {
    switch( ptrSrc[*inicio] ){
        case 'K':
        case 'S':
        case 'I':
        case 'B':
        case 'C':
        case 's':
        case 'b':
        case 'c':
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
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,(tamanho_entrada-tamanhoA-tamanhoB)*sizeof(char));
	tamanho_entrada = tamanho_entrada - tamanhoB - 1;

	#if _COUNT_
		countK++;
	#endif

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

    apontadorS = inicioA;
	ptrDst[apontadorD] = '(';
				
	apontadorD++;
	memcpy(ptrDst + apontadorD, ptrSrc+apontadorS,tamanhoA*sizeof(char));
			
	apontadorD = apontadorD + tamanhoA;
	apontadorS = inicioC;
	memcpy(ptrDst + apontadorD, ptrSrc + apontadorS,tamanhoC*sizeof(char));
				
	apontadorD = apontadorD + tamanhoC;
	apontadorS = inicioB;
	ptrDst[apontadorD] = ')';
				
	apontadorD++;
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
	tamanho_entrada = tamanho_entrada + 4 + tamanhoC - 1;

	#if _COUNT_
		countS++;
	#endif	

	return 0;
}

char reducao_I()
{
	char reduziu = 0;
	int inicioA = 1;

	if(ptrSrc[1] != '\0')
	{
		memcpy(ptrDst, ptrSrc + 1, tamanho_entrada*sizeof(char));
		tamanho_entrada = tamanho_entrada - 1;
	}
	else
	{
		reduziu = 1;
	}

	return reduziu;
}

char reducao_B()
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

   //f
	apontadorS = inicioA;
	apontadorD = 0;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoA*sizeof(char));
	//f(
	apontadorD = apontadorD + tamanhoA;
	ptrDst[apontadorD] = '(';

	//f(g
	apontadorD = apontadorD + 1;
	apontadorS = inicioB;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoB*sizeof(char));

	//f(gx
	apontadorD = apontadorD + tamanhoB;
	apontadorS = inicioC;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoC*sizeof(char));

	//f(gx)
	apontadorD = apontadorD + tamanhoC;
	ptrDst[apontadorD] = ')';

	//f(gx)todo o resto
	apontadorD = apontadorD + 1;
	apontadorS = terminoC + 1;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,(tamanho_entrada-tamanhoA-tamanhoB-tamanhoC)*sizeof(char));
	tamanho_entrada = tamanho_entrada - 1 + 2;

	return 0;
}

char reducao_C()
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

    //f
	apontadorD = 0;
	apontadorS = inicioA;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoA*sizeof(char));

	//fy
	apontadorD = apontadorD + tamanhoA;
	apontadorS = inicioC;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoC*sizeof(char));

	//fyx
	apontadorD = apontadorD + tamanhoC;
	apontadorS = inicioB;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoB*sizeof(char));

	//fyxtodo o resto
	apontadorD = apontadorD + tamanhoB;
	apontadorS = terminoC + 1;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,(tamanho_entrada-tamanhoA-tamanhoB-tamanhoC)*sizeof(char));
	tamanho_entrada = tamanho_entrada - 1;

	return 0;
}

char reducao_s()
{
	int inicioA = 1,inicioB = 0, inicioC = 0, inicioD = 0;
	int terminoA = 0, terminoB = 0, terminoC = 0, terminoD = 0;
	int tamanhoA = 1, tamanhoB = 1, tamanhoC = 1, tamanhoD = 0;

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

    inicioD = terminoC + 1;
    encontrou = encontra_parametro(&inicioD,&tamanhoD,&terminoD);
    if(!encontrou)
        return 1;

	//a
	apontadorD = 0;
	apontadorS = inicioA;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoA*sizeof(char));
	//printf("dst1 =%s\n",ptrDst);
	
	//a(
	apontadorD = tamanhoA;
	ptrDst[apontadorD] = '(';
	//printf("dst2 =%s\n",ptrDst);
	
	//a(b
	apontadorD = apontadorD + 1;
	apontadorS = inicioB;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoB*sizeof(char));
	//printf("dst3 =%s\n",ptrDst);
	
	//a(bd
	apontadorD = apontadorD + tamanhoB;
	apontadorS = inicioD;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoD*sizeof(char));
	//printf("dst4 =%s\n",ptrDst);
	
	//a(bd)
	apontadorD = apontadorD + tamanhoD;
	ptrDst[apontadorD] = ')';
	//printf("dst5 =%s\n",ptrDst);
	
	//a(bd)(
	apontadorD = apontadorD + 1;
	ptrDst[apontadorD] = '(';
	//printf("dst6 =%s\n",ptrDst);

	//a(bd)(c
	apontadorD = apontadorD + 1;
	apontadorS = inicioC;
	memcpy(ptrDst+apontadorD, ptrSrc+apontadorS,tamanhoC*sizeof(char));
	//printf("dst7 =%s\n",ptrDst);
	
	//a(bd)(cd
	apontadorD = apontadorD + tamanhoC;
	apontadorS = inicioD;
	memcpy(ptrDst+apontadorD, ptrSrc+apontadorS,tamanhoD*sizeof(char));
	//printf("dst8 =%s\n",ptrDst);
	
	//a(bd)(cd)
	apontadorD = apontadorD + tamanhoD;
	ptrDst[apontadorD] = ')';
	//printf("dst9 =%s\n",ptrDst);

	////a(bd)(cd)todo o resto
	apontadorD = apontadorD + 1;
	apontadorS = terminoD + 1;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,(tamanho_entrada-tamanhoA-tamanhoB-tamanhoC-tamanhoD)*sizeof(char));
	tamanho_entrada = tamanho_entrada - 1 + tamanhoD + 4;
	
	return 0;
}

char reducao_b()
{
	int inicioA = 1,inicioB = 0, inicioC = 0, inicioD = 0;
	int terminoA = 0, terminoB = 0, terminoC = 0, terminoD = 0;
	int tamanhoA = 1, tamanhoB = 1, tamanhoC = 1, tamanhoD = 0;

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

    inicioD = terminoC + 1;
    encontrou = encontra_parametro(&inicioD,&tamanhoD,&terminoD);
    if(!encontrou)
        return 1;

    //a
	apontadorD = 0;
	apontadorS = inicioA;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoA*sizeof(char));
	//printf("dst1 =%s\n",ptrDst);
	
	//ab
	apontadorD = tamanhoA;
	apontadorS = inicioB;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoB*sizeof(char));
	//printf("dst2 =%s\n",ptrDst);

	//ab(
	apontadorD = apontadorD + tamanhoB;
	ptrDst[apontadorD] = '(';
	//printf("dst3 =%s\n",ptrDst);
				
	//ab(c
	apontadorD = apontadorD + 1;
	apontadorS = inicioC;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoC*sizeof(char));
	//printf("dst4 =%s\n",ptrDst);
				
	//ab(cd
	apontadorD = apontadorD + tamanhoC;
	apontadorS = inicioD;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoD*sizeof(char));
	//printf("dst5 =%s\n",ptrDst);
				
	//ab(cd)
	apontadorD = apontadorD + tamanhoD;
	ptrDst[apontadorD] = ')';
	////printf("dst6 =%s\n",ptrDst);

	////a(bd)(cd)todo o resto
	apontadorD = apontadorD + 1;
	apontadorS = terminoD + 1;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,(tamanho_entrada-tamanhoA-tamanhoB-tamanhoC-tamanhoD)*sizeof(char));
	tamanho_entrada = tamanho_entrada - 1 + 2;

	return 0;
}

char reducao_c()
{
	int inicioA = 1,inicioB = 0, inicioC = 0, inicioD = 0;
	int terminoA = 0, terminoB = 0, terminoC = 0, terminoD = 0;
	int tamanhoA = 1, tamanhoB = 1, tamanhoC = 1, tamanhoD = 0;

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

    inicioD = terminoC + 1;
    encontrou = encontra_parametro(&inicioD,&tamanhoD,&terminoD);
    if(!encontrou)
        return 1;

    //a
	apontadorD = 0;
	apontadorS = inicioA;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoA*sizeof(char));
	////printf("dst1 =%s\n",ptrDst);
	
	//a(
	apontadorD = tamanhoA;
	ptrDst[apontadorD] = '(';
	//printf("dst2 =%s\n",ptrDst);
	
	//a(b
	apontadorD = apontadorD + 1;
	apontadorS = inicioB;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoB*sizeof(char));
	//printf("dst3 =%s\n",ptrDst);
	
	//a(bd
	apontadorD = apontadorD + tamanhoB;
	apontadorS = inicioD;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoD*sizeof(char));
	//printf("dst4 =%s\n",ptrDst);
	
	//a(bd)
	apontadorD = apontadorD + tamanhoD;
	ptrDst[apontadorD] = ')';
	//printf("dst5 =%s\n",ptrDst);
					
	apontadorD = apontadorD + 1;
	apontadorS = inicioC;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoC*sizeof(char));
	//printf("dst6 =%s\n",ptrDst);

	////a(bd)(cd)todo o resto
	apontadorD = apontadorD + tamanhoC;
	apontadorS = terminoD + 1;
	memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,(tamanho_entrada-tamanhoA-tamanhoB-tamanhoC-tamanhoD)*sizeof(char));
	tamanho_entrada = tamanho_entrada - 1 + 2;

	return 0;
}
