#include "reducao.h"

char reducao_K(Lista* word)
{
	Node* ptr = word->begin->prox;
	//pegando o argumento a
	Node* arg_A = ptr;
	if (arg_A == NULL)
		return 1;
	//pegando o argumento b
	Node* arg_B = ptr->prox;
	if (arg_B == NULL)
		return 1;
	shiftRight(word);
	arg_A->prox = arg_B->prox;
	//freeNode(arg_B);
	return 0;
}

char reducao_S(Lista* word)
{
	int i;
	Node* ptr = word->begin->prox;
	//pega os argumentos A, B e C
	Node* arg_A = ptr; 
	if (arg_A == NULL)
		return 1;
	Node* arg_B = arg_A->prox;
	if (arg_B == NULL)
		return 1;
	Node* arg_C = arg_B->prox;
	if (arg_C == NULL)
		return 1;

	shiftRight(word); //tira o caractere S 
	//aqui cria-se os dois argumentos de saída (AC) e (BC)
	Node* outarg_A = createArg(arg_A->info, arg_A->tipo); //saída -> (A)
	Node* outarg_B = createArg(arg_B->info, arg_B->tipo); //saída -> (B)
	//printf("%d\n", outarg_A->tipo); printf("%d\n", outarg_B->tipo);
	//printNode(outarg_A);
	//printf("\n"); printNode(outarg_B); printf("\n");
	
	insertBack(outarg_A->info.arg, arg_C); //saída -> (AC)
	insertBack(outarg_B->info.arg, arg_C); //saída -> (BC)

	for (i = 0; i < 3; i++)
	{
		shiftRight(word); //retira A, B e C da string
	}
	//insere os novos argumentos
	insertFront(word, outarg_B); //saída = (BC)->resto da string
	insertFront(word, outarg_A); //saída = (AC)->(BC)->resto da string
	return 0;
}

char reducao_s(Lista* word)
{
	int i;
	Node* ptr = word->begin->prox;
	Node* arg_A = ptr;
	if (arg_A == NULL)
		return 1;
	Node* arg_B = arg_A->prox;
	if (arg_B == NULL)
		return 1;
	Node* arg_C = arg_B->prox;
	if (arg_C == NULL)
		return 1;
	Node* arg_D = arg_C->prox;
	if (arg_D == NULL)
		return 1;

	shiftRight(word); //retira o s
	Node* outarg_A = cpyNode(arg_A); //Saída -> A
	Node* outarg_B = createArg(arg_B->info, arg_B->tipo); //saída -> (B)
	Node* outarg_C = createArg(arg_C->info, arg_C->tipo); //saída -> (C)
	insertBack(outarg_B->info.arg, arg_D); //saída -> (BD)
	insertBack(outarg_C->info.arg, arg_D); //saída -> (CD)

	for(i = 0; i < 4; i++)
	{
		shiftRight(word);
	}	
	insertFront(word, outarg_C);//saída -> (CD) -> resto da string
	insertFront(word, outarg_B); //saída -> (BD)->(CD)->resto da string
	insertFront(word, outarg_A); //saída -> A->(BD)->(CD)->resto da string
	return 0;
}