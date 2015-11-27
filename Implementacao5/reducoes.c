#include "reducoes.h"

int reducao_K(int posRaizPilha)
{
	Cell* argumento_A = pilha[posPilhaLivre - 1]->right;
	if(argumento_A == NULL)
		return 1;
	Cell* argumento_B = pilha[posPilhaLivre - 2];
	if(argumento_B == NULL)
		return 1;

	if((posPilhaLivre - 2 - posRaizPilha) != 0)
	{
		Cell* argumento_C = pilha[posPilhaLivre - 3];
		if(argumento_C != NULL)
			argumento_C->left = argumento_A;
	}
	else
		ptrRaiz = argumento_A;

	pop(2);
	push(argumento_A);
	return 0;
}

int reducao_S(int posRaizPilha)
{
	if(estadoHeap(3))
	{
		printf("\nChamando o garbege...\n");
		int index_root=0;
		for (index_root = 0; index_root < HEAP_SIZE; index_root++)
		{
			if(ptrRaiz == &heap[index_root])
				break;
		}
		
		index_root = garbage_collector(index_root);
		ptrRaiz = &heap[index_root];
		esvaziarPilha();
		push(ptrRaiz);
		pop(1);
	}

	Cell* aux = createCell(0,0,'@');
	//printf("dalee\n");
	aux->left = createCell(0,0,'@');
	//printf("dale1\n");
	aux->right = createCell(0,0,'@');
	//printf("dale2\n");

	//printf("ptrRaizreducao = %p\n", *ptrRaiz);
	Cell* argumento_A = pilha[posPilhaLivre - 1]->right;
	if(argumento_A == NULL)
		return 1;
	//printf("Achou A\n");
	Cell* argumento_B = pilha[posPilhaLivre - 2]->right;
	if(argumento_B == NULL)
		return 1;
	//printf("Achou B\n");
	Cell* argumento_C = pilha[posPilhaLivre - 3]->right;
	if(argumento_C == NULL)
		return 1;
	//printf("Achou C\n");
	aux->left->left = argumento_A;
	aux->left->right = argumento_C;
	aux->right->left = argumento_B;
	aux->right->right = argumento_C;
	
	if((posPilhaLivre - 3 - posRaizPilha) != 0)
	{
		Cell* argumento_D = pilha[posPilhaLivre - 4];
		if(argumento_D != NULL)
			argumento_D->left = aux;
	}
	else
		ptrRaiz = aux;

	pop(3);
	push(aux);
	return 0;
}

int reducao_I(int posRaizPilha)
{
	//printf("\nhuhuhuhu\n");
	//printf("posPilhaLivre=%d\n",posPilhaLivre);
	Cell* argumento_A = pilha[posPilhaLivre - 1]->right;
	if(argumento_A == NULL)
		return 1;
	
	if((posPilhaLivre - 1 - posRaizPilha) != 0)
	{
		Cell* argumento_B = pilha[posPilhaLivre - 2];
		if(argumento_B != NULL)
			argumento_B->left = argumento_A;
	}
	else
		ptrRaiz = argumento_A;

	pop(1);
	push(argumento_A);
	return 0;
}


int reducao_B(int posRaizPilha)
{
	if(estadoHeap(2))
	{
		printf("\nChamando o garbege...\n");
		int index_root=0;
		for (index_root = 0; index_root < HEAP_SIZE; index_root++)
		{
			if(ptrRaiz == &heap[index_root])
				break;
		}
		index_root = garbage_collector(index_root);
		ptrRaiz = &heap[index_root];
		esvaziarPilha();
		push(ptrRaiz);
		pop(1);
	}

	Cell* aux = createCell(0,0,'@');
	aux->right = createCell(0,0,'@');

	Cell* argumento_A = pilha[posPilhaLivre - 1]->right;
	if(argumento_A == NULL)
		return 1;
	Cell* argumento_B = pilha[posPilhaLivre - 2]->right;
	if(argumento_B == NULL)
		return 1;
	Cell* argumento_C = pilha[posPilhaLivre - 3]->right;
	if(argumento_C == NULL)
		return 1;
	
	aux->left = argumento_A;
	aux->right->left = argumento_B;
	aux->right->right = argumento_C;

	if((posPilhaLivre - 3 - posRaizPilha) != 0)
	{
		Cell* argumento_D = pilha[posPilhaLivre - 4];
		if(argumento_D != NULL)
			argumento_D->left = aux;
	}
	else
		ptrRaiz = aux;
	
	pop(3);
	push(aux);
	return 0;
	
}

int reducao_C(int posRaizPilha)
{
	if(estadoHeap(2))
	{
		printf("\nChamando o garbege...\n");
		int index_root=0;
		for (index_root = 0; index_root < HEAP_SIZE; index_root++)
		{
			if(ptrRaiz == &heap[index_root])
				break;
		}
		index_root = garbage_collector(index_root);
		ptrRaiz = &heap[index_root];
		esvaziarPilha();
		push(ptrRaiz);
		pop(1);
	}
	Cell* aux = createCell(0,0,'@');
	aux->left = createCell(0,0,'@');

	Cell* argumento_A = pilha[posPilhaLivre - 1]->right;
	if(argumento_A == NULL)
		return 1;
	Cell* argumento_B = pilha[posPilhaLivre - 2]->right;
	if(argumento_B == NULL)
		return 1;
	Cell* argumento_C = pilha[posPilhaLivre - 3]->right;
	if(argumento_C == NULL)
		return 1;

	aux->right = argumento_B;
	aux->left->right = argumento_C;
	aux->left->left = argumento_A;
	
	if((posPilhaLivre - 3 - posRaizPilha) != 0)
	{
		Cell* argumento_D = pilha[posPilhaLivre - 4];
		if(argumento_D != NULL)
			argumento_D->left = aux;
	}
	else
		ptrRaiz = aux;
	
	pop(3);
	push(aux);
	return 0;

}

int reducao_s(int posRaizPilha)
{
	if(estadoHeap(4))
	{
		printf("\nChamando o garbege...\n");
		int index_root=0;
		for (index_root = 0; index_root < HEAP_SIZE; index_root++)
		{
			if(ptrRaiz == &heap[index_root])
				break;
		}
		index_root = garbage_collector(index_root);
		ptrRaiz = &heap[index_root];
		esvaziarPilha();
		push(ptrRaiz);
		pop(1);
	}
	Cell* aux = createCell(0,0,'@');
	aux->left = createCell(0,0,'@');
	aux->left->right = createCell(0,0,'@');
	aux->right = createCell(0,0,'@');

	Cell* argumento_A = pilha[posPilhaLivre - 1]->right;
	if(argumento_A == NULL)
		return 1;
	Cell* argumento_B = pilha[posPilhaLivre - 2]->right;
	if(argumento_B == NULL)
		return 1;
	Cell* argumento_C = pilha[posPilhaLivre - 3]->right;
	if(argumento_C == NULL)
		return 1;
	Cell* argumento_D = pilha[posPilhaLivre - 4]->right;
	if(argumento_D == NULL)
		return 1;

	aux->left->left = argumento_A;
	aux->left->right->left = argumento_B;
	aux->left->right->right = argumento_D;
	aux->right->left = argumento_C;
	aux->right->right = argumento_D;

	if((posPilhaLivre - 4 - posRaizPilha) != 0)
	{
		Cell* argumento_E = pilha[posPilhaLivre - 5];
		if(argumento_E != NULL)
			argumento_E->left = aux;
	}
	else
		ptrRaiz = aux;

	pop(4);
	push(aux);
	return 0;
}


int reducao_b(int posRaizPilha)
{
	if(estadoHeap(3))
	{
		printf("\nChamando o garbege...\n");
		int index_root=0;
		for (index_root = 0; index_root < HEAP_SIZE; index_root++)
		{
			if(ptrRaiz == &heap[index_root])
				break;
		}
		index_root = garbage_collector(index_root);
		ptrRaiz = &heap[index_root];
		esvaziarPilha();
		push(ptrRaiz);
		pop(1);
	}
	Cell* aux = createCell(0,0,'@');
	aux->left = createCell(0,0,'@');
	aux->right = createCell(0,0,'@');

	Cell* argumento_A = pilha[posPilhaLivre - 1]->right;
	if(argumento_A == NULL)
		return 1;
	Cell* argumento_B = pilha[posPilhaLivre - 2]->right;
	if(argumento_B == NULL)
		return 1;
	Cell* argumento_C = pilha[posPilhaLivre - 3]->right;
	if(argumento_C == NULL)
		return 1;
	Cell* argumento_D = pilha[posPilhaLivre - 4]->right;
	if(argumento_D == NULL)
		return 1;
	//printf("Passei\n");
	aux->left->left = argumento_A;
	aux->left->right = argumento_B;
	aux->right->left = argumento_C;
	aux->right->right = argumento_D;

	if((posPilhaLivre - 4 - posRaizPilha) != 0)
	{
		Cell* argumento_E = pilha[posPilhaLivre - 5];
		if(argumento_E != NULL)
			argumento_E->left = aux;
	}
	else
		ptrRaiz = aux;

	pop(4);
	push(aux);
	return 0;
}

int reducao_c(int posRaizPilha)
{
	if(estadoHeap(3))
	{
		printf("\nChamando o garbege...\n");
		int index_root=0;
		for (index_root = 0; index_root < HEAP_SIZE; index_root++)
		{
			if(ptrRaiz == &heap[index_root])
				break;
		}
		index_root = garbage_collector(index_root);
		ptrRaiz = &heap[index_root];
		esvaziarPilha();
		push(ptrRaiz);
		pop(1);
	}
	Cell* aux = createCell(0,0,'@');
	aux->left = createCell(0,0,'@');
	aux->left->right = createCell(0,0,'@');

	Cell* argumento_A = pilha[posPilhaLivre - 1]->right;
	if(argumento_A == NULL)
		return 1;
	Cell* argumento_B = pilha[posPilhaLivre - 2]->right;
	if(argumento_B == NULL)
		return 1;
	Cell* argumento_C = pilha[posPilhaLivre - 3]->right;
	if(argumento_C == NULL)
		return 1;
	Cell* argumento_D = pilha[posPilhaLivre - 4]->right;
	if(argumento_D == NULL)
		return 1;

	aux->left->left = argumento_A;
	aux->left->right->left = argumento_B;
	aux->left->right->right = argumento_D;
	aux->right = argumento_C;
	
	if((posPilhaLivre - 4 - posRaizPilha) != 0)
	{
		Cell* argumento_E = pilha[posPilhaLivre - 5];
		if(argumento_E != NULL)
			argumento_E->left = aux;
	}
	else
		ptrRaiz = aux;

	pop(4);
	push(aux);
	return 0;
}

int reducao_F(int posRaizPilha)
{
	Cell* argumento_A = pilha[posPilhaLivre - 1]->right;
	if (argumento_A == NULL)
		return 1;
	Cell* argumento_B = pilha[posPilhaLivre - 2]->right;
	if(argumento_B == NULL)
		return 1;

	if((posPilhaLivre - 2 - posRaizPilha) != 0)
	{
		Cell* argumento_C = pilha[posPilhaLivre - 3];
		if(argumento_C != NULL)
			argumento_C->left = argumento_B;
	}
	else
		ptrRaiz = argumento_B;

	pop(2);
	push(argumento_B);
	return 0;
}

int reducao_Y(int posRaizPilha)
{
	if(estadoHeap(2))
	{
		printf("\nChamando o garbege...\n");
		int index_root=0;
		for (index_root = 0; index_root < HEAP_SIZE; index_root++)
		{
			if(ptrRaiz == &heap[index_root])
				break;
		}
		index_root = garbage_collector(index_root);
		ptrRaiz = &heap[index_root];
		esvaziarPilha();
		push(ptrRaiz);
		pop(1);
	}
	Cell* aux = createCell(0,0,'@');
	aux->right = createCell(0,0,'@');

	Cell* argumento_Y = pilha[posPilhaLivre];
	if(argumento_Y == NULL)
		return 1;
	Cell* argumento_A = pilha[posPilhaLivre - 1]->right;
	if(argumento_A == NULL)
		return 1;

	aux->left = argumento_A;
	aux->right->left = argumento_Y;
	aux->right->right = argumento_A;

	if((posPilhaLivre - 1 - posRaizPilha) != 0)
	{
		Cell* argumento_B = pilha[posPilhaLivre - 2];
		if(argumento_B != NULL)
			argumento_B->left = aux;
	}
	else
		ptrRaiz = aux;
	
	pop(1);
	push(aux);
	return 0;
	
}

int reducao_aritmetica(int posRaizPilha, char operador)
{
	Cell* auxPosRaiz = ptrRaiz;
	Cell* argumento_A = pilha[posPilhaLivre - 1]->right;
	if(argumento_A == NULL)
		return 1;
	else if(argumento_A->id == 0)
	{
		if(argumento_A->elemento.op == '@')
		{
			int aux1 = posRaizPilha;
			int aux2 = posPilhaLivre;
			argumento_A = mg(argumento_A,posPilhaLivre);
			posRaizPilha = aux1;
			posPilhaLivre = aux2;
			ptrRaiz	= auxPosRaiz;
		}
	}
	// printf("A = %d\n",argumento_A->elemento.num);
	Cell* argumento_B = pilha[posPilhaLivre - 2]->right;
	if(argumento_B == NULL)
		return 1;
	else if(argumento_B->id == 0)
	{
		if(argumento_B->elemento.op == '@')
		{
			int aux1 = posRaizPilha;
			int aux2 = posPilhaLivre;
			argumento_B = mg(argumento_B,posPilhaLivre);
			posRaizPilha = aux1;
			posPilhaLivre = aux2;
			ptrRaiz	= auxPosRaiz;	
		}
	}
	// printf("B = %d\n",argumento_B->elemento.num);
	if(estadoHeap(1))
	{
		printf("\nChamando o garbege...\n");
		int index_root=0;
		for (index_root = 0; index_root < HEAP_SIZE; index_root++)
		{
			if(ptrRaiz == &heap[index_root])
				break;
		}
		index_root = garbage_collector(index_root);
		ptrRaiz = &heap[index_root];
		esvaziarPilha();
		push(ptrRaiz);
		pop(1);
	}

	Cell* aux = createCell(1,0,0);
	switch(operador){
		case '+':
			aux->id = 1;
			aux->elemento.num = (argumento_A->elemento.num + argumento_B->elemento.num);
			break;

		case '-':
			aux->id = 1;
			aux->elemento.num = (argumento_A->elemento.num - argumento_B->elemento.num);
			break;
		
		case '*':
			aux->id = 1;
			aux->elemento.num = (argumento_A->elemento.num * argumento_B->elemento.num);
			break;
		
		case '/':
			aux->id = 1;
			aux->elemento.num = (argumento_A->elemento.num / argumento_B->elemento.num);
			break;
		
		case '^':
			aux->id = 1;
			aux->elemento.num = (pow(argumento_A->elemento.num, argumento_B->elemento.num));
			break;
	}
	
	if((posPilhaLivre - 2 - posRaizPilha) > 0)
	{
		//printf("huhuhu\n" );
		Cell* argumento_C = pilha[posPilhaLivre - 3];
		if(argumento_C != NULL)
			argumento_C->left = aux;
	}
	else
		ptrRaiz = aux;
	
	//printf("Resultado = %d\n",ptrRaiz->elemento.num );
	pop(2);
	push(aux);
	
	return 1;
}

int reducao_logica(int posRaizPilha, char operador)
{
	Cell* auxPosRaiz = ptrRaiz;
	Cell* argumento_A = pilha[posPilhaLivre - 1]->right;
	if(argumento_A == NULL)
		return 1;
	else if(argumento_A->id == 0)
	{
		if(argumento_A->elemento.op == '@')
		{
			int aux1 = posRaizPilha;
			int aux2 = posPilhaLivre;
			argumento_A = mg(argumento_A,posPilhaLivre);
			posRaizPilha = aux1;
			posPilhaLivre = aux2;
			ptrRaiz	= auxPosRaiz;
		}
	}
	// printf("A = %d\n",argumento_A->elemento.num);
	Cell* argumento_B = pilha[posPilhaLivre - 2]->right;
	if(argumento_B == NULL)
		return 1;
	else if(argumento_B->id == 0)
	{
		if(argumento_B->elemento.op == '@')
		{
			int aux1 = posRaizPilha;
			int aux2 = posPilhaLivre;
			argumento_B = mg(argumento_B,posPilhaLivre);
			posRaizPilha = aux1;
			posPilhaLivre = aux2;
			ptrRaiz	= auxPosRaiz;	
		}
	}
	// printf("B = %d\n",argumento_B->elemento.num);
	if(estadoHeap(1))
	{
		printf("\nChamando o garbege...\n");
		int index_root=0;
		for (index_root = 0; index_root < HEAP_SIZE; index_root++)
		{
			if(ptrRaiz == &heap[index_root])
				break;
		}
		index_root = garbage_collector(index_root);
		ptrRaiz = &heap[index_root];
		esvaziarPilha();
		push(ptrRaiz);
		pop(1);
	}

	Cell* aux = createCell(1,0,0);
	switch(operador){
		case '>':
			aux->id = 0;
			if (argumento_A->elemento.num > argumento_B->elemento.num)
			{
				aux->elemento.op = 'K';
			}
			else
			{
				aux->elemento.op = 'F';
			}
			break;
			
		case '<':
			aux->id = 0;
			if (argumento_A->elemento.num < argumento_B->elemento.num){
				aux->elemento.op = 'K';
			}
			else
			{
				aux->elemento.op = 'F';
			}
			break;

		case '=':
			aux->id = 0;
			if (argumento_A->elemento.num == argumento_B->elemento.num)
			{
				aux->elemento.op = 'K';
			}
			else
			{
				aux->elemento.op = 'F';
			}
			break;
	}
	
	if((posPilhaLivre - 2 - posRaizPilha) > 0)
	{
		//printf("huhuhu\n" );
		Cell* argumento_C = pilha[posPilhaLivre - 3];
		if(argumento_C != NULL)
			argumento_C->left = aux;
	}
	else
		ptrRaiz = aux;
	
	//printf("Resultado = %d\n",ptrRaiz->elemento.num );
	pop(2);
	push(aux);
	
	return 0;
}