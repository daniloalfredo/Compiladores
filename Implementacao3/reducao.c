#include "reducao.h"

char reducao_K(Lista* word)
{
	Node* ptr = word->begin->prox;

	Node* arg_A = ptr;
	if (arg_A == NULL)
		return 1;

	Node* arg_B = ptr->prox;
	if (arg_B == NULL)
		return 1;

	Node* tmp = word->begin;
	word->begin = arg_A;

	freeNode(tmp);

	arg_A->prox = arg_B->prox;

	return 0;
}

char reducao_S(Lista* word)
{

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

	Node* tmp = word->begin;
	freeNode(tmp);

	word->begin = arg_C->prox;

	Node* outarg_A = createArg(arg_A);
	Lista* aux = outarg_A->info.arg;
	aux->end->prox = arg_C;
	aux->end = arg_C;
	arg_C->prox = NULL;

	Node* outarg_B = createArg(arg_B);
	aux = outarg_B->info.arg;
	aux->end->prox = arg_C;
	aux->end = arg_C;

	tmp = word->begin;
	word->begin = outarg_A;
	outarg_A->prox = outarg_B;
	outarg_B->prox = tmp;

	return 0;
}

char reducao_I(Lista* word)
{
	Node* ptr = word->begin->prox;

	Node* arg_A = ptr;
	if (arg_A == NULL)
		return 1;

	Node* tmp = word->begin;
	freeNode(tmp);

	word->begin = arg_A;

	return 0;
}

char reducao_B(Lista* word)
{
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

	Node* tmp = word->begin;
	freeNode(tmp);

	word->begin = arg_A;
	Node* outarg_B = createArg(arg_B);
	Lista* aux = outarg_B->info.arg;
	aux->end->prox = arg_C;
	aux->end = arg_C;

	arg_A->prox = outarg_B;
	outarg_B->prox = arg_C->prox;
	arg_C->prox = NULL;

	return 0;
}

char reducao_C(Lista* word)
{
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

	Node* tmp = word->begin;
	freeNode(tmp);

	word->begin = arg_A;
	arg_A->prox = arg_C;
	tmp = arg_C->prox;
	arg_C->prox = arg_B;
	arg_B->prox = tmp;

	return 0;
}

char reducao_s(Lista* word)
{
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

	Node* tmp = word->begin;
	freeNode(tmp);

	word->begin = arg_A;
	Node* outarg_B = createArg(arg_B);
	Lista* aux = outarg_B->info.arg;
	aux->end->prox = arg_D;
	aux->end = arg_D;

	Node* outarg_C = createArg(arg_C);
	aux = outarg_C->info.arg;
	aux->end->prox = arg_D;
	aux->end = arg_D;

	arg_A->prox = outarg_B;
	outarg_B->prox = outarg_C;
	outarg_C->prox = arg_D->prox;
	arg_D->prox = NULL;

	return 0;
}

char reducao_b(Lista* word)
{
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

	Node* outarg_C = createArg(arg_C);

	Lista* aux = outarg_C->info.arg;
	aux->end->prox = arg_D;
	aux->end = arg_D;

	Node* tmp = word->begin;
	freeNode(tmp);
	word->begin = arg_A;
	arg_B->prox = outarg_C;
	outarg_C->prox = arg_D->prox;
	arg_D->prox = NULL;

	return 0;
}

char reducao_c(Lista* word)
{
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

	Node* outarg_B = createArg(arg_B);
	Lista* aux = outarg_B->info.arg;
	aux->end->prox = arg_D;
	aux->end = arg_D;

	Node* tmp = word->begin;
	freeNode(tmp);

	word->begin = arg_A;
	arg_A->prox = outarg_B;
	outarg_B->prox = arg_C;
	arg_C->prox = arg_D->prox;
	arg_D->prox = NULL;

	return 0;
}
