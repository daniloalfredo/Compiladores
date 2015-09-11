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
	else if(ptrSrc[inicioA] == 'K' || ptrSrc[inicioA] == 'S')
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
		else if(ptrSrc[inicioB] == 'K' || ptrSrc[inicioB] == 'S')
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
	else if(ptrSrc[inicioA] == 'K' || ptrSrc[inicioA] == 'S' || ptrSrc[inicioA] == 'C')
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
	else if(ptrSrc[inicioB] == 'K' || ptrSrc[inicioB] == 'S' || ptrSrc[inicioB] == 'C')
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
	else if(ptrSrc[inicioC] == 'K' || ptrSrc[inicioC] == 'S' || ptrSrc[inicioC] == 'C')
	{
		terminoC = inicioC;
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