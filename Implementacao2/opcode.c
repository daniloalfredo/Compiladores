#include "opcode.h"

char reducao_K()
{
	int prox_parentese = 0;
	int inicioA = 1, inicioB = 0; 
	int terminoA = 0, terminoB = 0;
	int tamanhoA = 1, tamanhoB = 1;
	char reduziu = 0;
	int apontadorD = 0;
	int apontadorS = 0;

	
	//Achando o A
	if(ptrSrc[inicioA] == '(')
	{
		terminoA = buscar_prox_parentese(inicioA);
		tamanhoA = terminoA - inicioA + 1;
		inicioB = terminoA + 1;
	}
	else if(ptrSrc[inicioA] == 'K' || ptrSrc[inicioA] == 'S' || ptrSrc[inicioA] == 'I'
            || ptrSrc[inicioA] == 'B' || ptrSrc[inicioA] == 'C' || ptrSrc[inicioA] == 'B')
	{
		terminoA = inicioA;
		inicioB = terminoA + 1;
	}
	else
	{
		reduziu = 1;
	}

	//Achando o B se não reduziu
	if(!reduziu)
	{
		if(ptrSrc[inicioB] == '(')
		{
			terminoB = buscar_prox_parentese(inicioB);
			tamanhoB = terminoB - inicioB + 1;
		}
		else if(ptrSrc[inicioB] == 'K' || ptrSrc[inicioB] == 'S' || ptrSrc[inicioB] == 'I'
            || ptrSrc[inicioB] == 'B' || ptrSrc[inicioB] == 'C' || ptrSrc[inicioB] == 'B')
		{	
			terminoB = inicioB;
		}
		else
		{
			reduziu = 1;
		}

		if(!reduziu)
		{	
			apontadorS = inicioA;

			memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,tamanhoA*sizeof(char));
			apontadorD = apontadorD + tamanhoA ;
			apontadorS = terminoB + 1;

			memcpy(ptrDst+apontadorD,ptrSrc+apontadorS,strlen(ptrSrc+apontadorS-1)*sizeof(char));

			#if _COUNT_
				countK++;
			#endif
		}

	}

	return reduziu;
}


char reducao_S()
{
	int inicioA = 1,inicioB = 0, inicioC = 0;
	int terminoA = 0, terminoB = 0, terminoC = 0;
	int tamanhoA = 1, tamanhoB = 1, tamanhoC = 1;
	int reduziu = 0;
	int apontadorS = 0;
	int apontadorD = 0;

	//Achando A e copiando
	if(ptrSrc[inicioA] == '(')
	{
		terminoA = buscar_prox_parentese(inicioA);
		tamanhoA = terminoA - inicioA + 1;
		inicioB = terminoA+1;
	}
	else if(ptrSrc[inicioA] == 'K' || ptrSrc[inicioA] == 'S')
	{
		terminoA = inicioA;
		inicioB = terminoA+1;
	}
	else
	{
		reduziu = 1;
	}

	//Achando B
	if(ptrSrc[inicioB] == '(')
	{
		terminoB = buscar_prox_parentese(inicioB);
		tamanhoB = terminoB - inicioB + 1;
		inicioC = terminoB + 1;
	}
	else if(ptrSrc[inicioB] == 'K' || ptrSrc[inicioB] == 'S')
	{
		terminoB = inicioB;
		inicioC = terminoB + 1;
	}
	else
	{
		reduziu = 1;
	}

	//Achando C
	if(ptrSrc[inicioC] == '(')
	{
		terminoC = buscar_prox_parentese(inicioC);
		tamanhoC = terminoC - inicioC + 1;
	}
	else if(ptrSrc[inicioC] == 'K' || ptrSrc[inicioC] == 'S')
	{
		terminoC = inicioC;
	}
	else
	{
		reduziu = 1;
	}

	if(!reduziu)
	{
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
		
		memcpy(ptrDst + apontadorD,ptrSrc + apontadorS,strlen(ptrSrc + apontadorS-1)*sizeof(char));
		#if _COUNT_
			countS++;
		#endif	
	}

	return reduziu;
}

char reducao_C()
	int inicioA = 1,inicioB = 0, inicioC = 0;
	int terminoA = 0, terminoB = 0, terminoC = 0;
	int tamanhoA = 1, tamanhoB = 1, tamanhoC = 1;
	int reduziu = 0;
	int apontadorS = 0;
	int apontadorD = 0;

	//Achando A e copiando
	if(ptrSrc[inicioA] == '(')
	{
		terminoA = buscar_prox_parentese(inicioA);
		tamanhoA = terminoA - inicioA + 1;
		inicioB = terminoA+1;
	}
	else if(ptrSrc[inicioA] == 'K' || ptrSrc[inicioA] == 'S' || ptrSrc[inicioA] == 'I'
            || ptrSrc[inicioA] == 'B' || ptrSrc[inicioA] == 'C' || ptrSrc[inicioA] == 'B')
	{
		terminoA = inicioA;
		inicioB = terminoA+1;
	}
	else if((ptrSrc[inicioA] == 'S' || ptrSrc[inicioA] == 'B' || ptrSrc[inicioA] == 'C')
            && ptrSrc[inicioA + 1] == '\'')
	{
		terminoA = inicioA + 1;
		tamanhoA = 2;
	}
	else
	{
		reduziu = 1;
	}

	//Achando B
	if(ptrSrc[inicioB] == '(')
	{
		terminoB = buscar_prox_parentese(inicioB);
		tamanhoB = terminoB - inicioB + 1;
		inicioC = terminoB + 1;
	}
	else if(ptrSrc[inicioB] == 'K' || ptrSrc[inicioB] == 'S' || ptrSrc[inicioB] == 'I'
            || ptrSrc[inicioB] == 'B' || ptrSrc[inicioB] == 'C' || ptrSrc[inicioB] == 'B')
	{
		terminoB = inicioB;
		inicioC = terminoB+1;
	}
	else if((ptrSrc[inicioB] == 'S' || ptrSrc[inicioB] == 'B' || ptrSrc[inicioB] == 'C')
            && ptrSrc[inicioB + 1] == '\'')
	{
		terminoB = inicioB + 1;
		inicioC = terminoB+1;
		tamanhoB = 2;
	}
	else
	{
		reduziu = 1;
	}

	//Achando C
	if(ptrSrc[inicioC] == '(')
	{
		terminoC = buscar_prox_parentese(inicioC);
		tamanhoC = terminoC - inicioC + 1;
	}
	else if(ptrSrc[inicioC] == 'K' || ptrSrc[inicioC] == 'S' || ptrSrc[inicioC] == 'I'
            || ptrSrc[inicioC] == 'B' || ptrSrc[inicioC] == 'C' || ptrSrc[inicioC] == 'B')
	{
		terminoC = inicioC;
	}
	else if((ptrSrc[inicioC] == 'S' || ptrSrc[inicioC] == 'B' || ptrSrc[inicioC] == 'C')
            && ptrSrc[inicioC + 1] == '\'')
	{
		terminoC = inicioC + 1;
		tamanhoC = 2;
	}
	else
	{
		reduziu = 1;
	}	

	if(!reduziu){
		//copia A para dst
		apontadorS = inicioA;
		memcpy(ptrDst + apontadorD, ptrSrc + apontadorS, tamanhoA*sizeof(char));
		//copia C para Dst
		apontadorD += tamanhoA;
		apontadorS = inicioC;
		memcpy(ptrDst + apontadorD, ptrSrc + apontadorS, tamanhoC*sizeof(char));
		//copia B para dst
		apontadorD += tamanhoC;
		apontadorS = inicioB;
		memcpy(ptrDst + apontadorD, ptrSrc + apontadorS, tamanhoB*sizeof(char));
		//copia o resto da string pra dst
		apontadorS = terminoB + 1;
		apontadorD += tamanhoB;
		memcpy(ptrDst + apontadorD, ptrSrc + apontadorS, strlen(ptrSrc + apontadorS -1)*sizeof(char));
	}
	return reduziu;
}

char reducaoC2()
{
	int inicioA = 1,inicioB = 0, inicioC = 0, inicioD = 0;
	int terminoA = 0, terminoB = 0, terminoC = 0, terminoD = 0;
	int tamanhoA = 1, tamanhoB = 1, tamanhoC = 1, tamanhoD = 1;
	int reduziu = 0;
	int apontadorS = 0;
	int apontadorD = 0;
	//Achando A e copiando
	if(ptrSrc[inicioA] == '(')
	{
		terminoA = buscar_prox_parentese(inicioA);
		tamanhoA = terminoA - inicioA + 1;
		inicioB = terminoA+1;
	}
	else if(ptrSrc[inicioA] == 'K' || ptrSrc[inicioA] == 'S' || ptrSrc[inicioA] == 'I'
            || ptrSrc[inicioA] == 'B' || ptrSrc[inicioA] == 'C' || ptrSrc[inicioA] == 'B')
	{
		terminoA = inicioA;
		inicioB = terminoA+1;
	}
	else if((ptrSrc[inicioA] == 'S' || ptrSrc[inicioA] == 'B' || ptrSrc[inicioA] == 'C')
            && ptrSrc[inicioA + 1] == '\'')
	{
		terminoA = inicioA + 1;
		tamanhoA = 2;
	}
	else
	{
		reduziu = 1;
	}

	//Achando B
	if(ptrSrc[inicioB] == '(')
	{
		terminoB = buscar_prox_parentese(inicioB);
		tamanhoB = terminoB - inicioB + 1;
		inicioC = terminoB + 1;
	}
	else if(ptrSrc[inicioB] == 'K' || ptrSrc[inicioB] == 'S' || ptrSrc[inicioB] == 'I'
            || ptrSrc[inicioB] == 'B' || ptrSrc[inicioB] == 'C' || ptrSrc[inicioB] == 'B')
	{
		terminoB = inicioB;
		inicioC = terminoB+1;
	}
	else if((ptrSrc[inicioB] == 'S' || ptrSrc[inicioB] == 'B' || ptrSrc[inicioB] == 'C')
            && ptrSrc[inicioB + 1] == '\'')
	{
		terminoB = inicioB + 1;
		inicioC = terminoB+1;
		tamanhoB = 2;
	}
	else
	{
		reduziu = 1;
	}

	//Achando C
	if(ptrSrc[inicioC] == '(')
	{
		terminoC = buscar_prox_parentese(inicioC);
		tamanhoC = terminoC - inicioC + 1;
		inicioD = terminoC + 1;
	}
	else if(ptrSrc[inicioC] == 'K' || ptrSrc[inicioC] == 'S' || ptrSrc[inicioC] == 'I'
            || ptrSrc[inicioC] == 'B' || ptrSrc[inicioC] == 'C' || ptrSrc[inicioC] == 'B')
	{
		terminoC = inicioC;
		inicioD = terminoC+1;
	}
	else if((ptrSrc[inicioC] == 'S' || ptrSrc[inicioC] == 'B' || ptrSrc[inicioC] == 'C')
            && ptrSrc[inicioC + 1] == '\'')
	{
		terminoC = inicioC + 1;
		tamanhoC = 2;
		inicioD = terminoC + 1;
	}
	else
	{
		reduziu = 1;
	}
	//Achando D
	if(ptrSrc[inicioD] == '(')
	{
		terminoD = buscar_prox_parentese(inicioD);
		tamanhoD = terminoD - inicioD + 1;
	}
	else if(ptrSrc[inicioD] == 'K' || ptrSrc[inicioD] == 'S' || ptrSrc[inicioD] == 'I'
            || ptrSrc[inicioD] == 'B' || ptrSrc[inicioD] == 'C' || ptrSrc[inicioD] == 'B')
	{
		terminoD = inicioD;
	}
	else if((ptrSrc[inicioD] == 'S' || ptrSrc[inicioD] == 'B' || ptrSrc[inicioD] == 'C')
            && ptrSrc[inicioD + 1] == '\'')
	{
		terminoD = inicioD + 1;
		tamanhoD = 2;
	}
	else
	{
		reduziu = 1;
	}
	if (!reduziu)
	{
		apontadorS = inicioA;
		memcpy(ptrDst + apontadorD, ptrSrc + apontadorS, tamanhoA*sizeof(char));
		apontadorD += tamanhoA;
		
		ptrDst[apontadorD] = '(';
		apontadorD++;
		apontadorS = inicioB;
		memcpy(ptrDst+apontadorD, ptrSrc + apontadorS, tamanhoB*sizeof(char));

		apontadorD += tamanhoB;
		apontadorS = inicioD;
		memcpy(ptrDst + apontadorD, ptrSrc + apontadorS, tamanhoD*sizeof(char));

		apontadorD += tamanhoD;
		ptrDst[apontadorD] = ')';
		apontadorD++;
		apontadorS = inicioC;
		memcpy(ptrDst + apontadorD, ptrSrc + apontadorS, tamanhoC*sizeof(char));
		apontadorS = terminoC + 1;
		apontadorD += tamanhoC;
		memcpy(ptrDst + apontadorD, ptrSrc + apontadorS, strlen(ptrSrc + apontadorS - 1)*sizeof(char));				
	}
	return reduziu;
}