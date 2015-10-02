#include "reducao.h"

char reducao_K(Lista* word)
{
	char reduziu = 0;
	shiftRight(word);
	Node* ptr = word->begin;
	//pegando o argumento a
	Node* arg_A = ptr;
	if (arg_A == NULL)
		return 1;
	//pegando o argumento b
	Node* arg_B = ptr->prox;
	if (arg_B == NULL)
		return 1;
	arg_A->prox = arg_B->prox;
	//freeNode(arg_B);
	return 0;
}

char reducao_S(Lista* word)
{
	shiftRight(word); //tira o caractere S 
	int i = 0;
	Node* ptr = word->begin;
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
	//aqui cria-se os dois argumentos de saída (AC) e (BC)
	Node* outarg_A = createArg(arg_A->info, arg_A->tipo); //saída -> (A)
	Node* outarg_B = createArg(arg_B->info, arg_B->tipo); //saída -> (B)
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