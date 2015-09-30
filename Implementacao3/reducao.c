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
	//fazendo a redução
	if(arg_A->tipo == char_t)
	{
		//"deletando" a referência ao argumento B
		arg_A->prox = arg_B->prox;
		//freeNode(arg_B); //deletando de fato o argumento B da memória
	}
	//se o argumento A for uma lista
	else
	{
		Lista* tmp = arg_A->info.arg;
		Node* endTmp = tmp->end; //pegando o final de A
		word->begin = tmp->begin; //colocando a cabeça de A como a cabeça da lista principal
		endTmp->prox = arg_B->prox; //ligando o final de A com o resto da lista principal, "deletando" a referência ao argumento B no processo
		//freeNode(arg_B); //deletando de fato o argumento B da memória
	}
	return 0;
}