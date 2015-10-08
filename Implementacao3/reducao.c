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
	//shiftRight(word);
	Node* tmp = word->begin;
	word->begin = arg_A;
	//DEBUG_PRINT("Dando free em K");
	freeNode(tmp);
	arg_A->prox = arg_B->prox;
	//DEBUG_PRINT("dando free em B");
	//freeNode(arg_B);	
	return 0;
}

char reducao_S(Lista* word)
{
	int i;
	DEBUG_PRINT("Comeco da reducao\n");
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
	Node* tmp = word->begin; freeNode(tmp);
	word->begin = arg_C->prox;
	DEBUG_PRINT("Liberou S\n");
 
	//aqui cria-se os dois argumentos de saída (AC) e (BC)
	Node* outarg_A = createArg(arg_A); //saída -> (A)
	Lista* aux = outarg_A->info.arg;
	aux->end->prox = arg_C;
	aux->end = arg_C;
	arg_C->prox = NULL;

	Node* outarg_B = createArg(arg_B); //saída -> (B)
	aux = outarg_B->info.arg;
	aux->end->prox = arg_C;
	aux->end = arg_C;
	//freeNode(arg_A); freeNode(arg_B); 


	//insertBack(outarg_A->info.arg, arg_C); //saída -> (AC)
	//insertBack(outarg_B->info.arg, arg_C); //saída -> (BC)
	//freeNode(arg_C); 
	DEBUG_PRINT("Liberou A, B, C, atualizou argumentos\n");

	/*for (i = 0; i < 3; i++)
	{
		shiftRight(word); //retira A, B e C da string
	}*/

	//insere os novos argumentos
	tmp = word->begin;
	word->begin = outarg_A;	
	outarg_A->prox = outarg_B;
	outarg_B->prox = tmp;
	
	//insertFront(word, outarg_B); //saída = (BC)->resto da string
	//insertFront(word, outarg_A); //saída = (AC)->(BC)->resto da string
	//freeNode(outarg_A); freeNode(outarg_B);
	DEBUG_PRINT("Fim da reducao\n");
	return 0;
}

char reducao_I(Lista* word)
{
	Node* ptr = word->begin->prox;
	//pegando o argumento a
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

	Node* tmp = word->begin;
	freeNode(tmp);
	word->begin = arg_A;
	Node* outarg_B = createArg(arg_B);
	Lista* aux = outarg_B->info.arg;
	aux->end->prox = arg_C;
	aux->end = arg_C;
//	insertBack(outarg_B->info.arg, arg_C);
	arg_A->prox = outarg_B;
	outarg_B->prox = arg_C->prox;
	arg_C->prox = NULL;
	//freeNode(arg_C);

	/*shiftRight(word); //tira o caractere B
	Node* outarg_A = cpyNode(arg_A); //Saída -> A
	Node* outarg_B = createArg(arg_B); //saída -> (B)
	insertBack(outarg_B->info.arg, arg_C); //saída -> (BC)

	for(i = 0; i < 3; i++)
	{
		shiftRight(word);
	}

	//insere os novos argumentos
	insertFront(word, outarg_B); //saída = (BC)->resto da string
	insertFront(word, outarg_A);*/
	return 0;
}

char reducao_C(Lista* word)
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

	Node* tmp = word->begin;
	freeNode(tmp);
	word->begin = arg_A;
	arg_A->prox = arg_C;
	tmp = arg_C->prox;
	arg_C->prox = arg_B;
	arg_B->prox = tmp;
	
	/*shiftRight(word);

	Node* outarg_A = cpyNode(arg_A);
	Node* outarg_B = cpyNode(arg_C);
	Node* outarg_C = cpyNode(arg_B);

	for (i = 0; i < 3; i++)
		shiftRight(word);

	insertFront(word, outarg_C);
	insertFront(word, outarg_B);
	insertFront(word, outarg_A);
*/
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

	Node* tmp = word->begin;
	freeNode(tmp);
	word->begin = arg_A;
	//shiftRight(word); //retira o s
	//Node* outarg_A = cpyNode(arg_A); //Saída -> A
	Node* outarg_B = createArg(arg_B); //saída -> (B)
	Lista* aux = outarg_B->info.arg;
	aux->end->prox = arg_D;
	aux->end = arg_D;

	Node* outarg_C = createArg(arg_C); //saída -> (C)
	aux = outarg_C->info.arg;
	aux->end->prox = arg_D;
	aux->end = arg_D;	
	//insertBack(outarg_C->info.arg, arg_D); //saída -> (CD)
	
	arg_A->prox = outarg_B;
	outarg_B->prox = outarg_C;
	outarg_C->prox = arg_D->prox;
	arg_D->prox = NULL;

	//insertBack(outarg_B->info.arg, arg_D); //saída -> (BD)
	//freeNode(arg_D);
	/*for(i = 0; i < 4; i++)
	{
		shiftRight(word);
	}	
	insertFront(word, outarg_C);//saída -> (CD) -> resto da string
	insertFront(word, outarg_B); //saída -> (BD)->(CD)->resto da string
	insertFront(word, outarg_A); //saída -> A->(BD)->(CD)->resto da string
	*/
	return 0;
}

char reducao_b(Lista* word)
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
	Node* arg_D = arg_C->prox;
	if (arg_D == NULL)
		return 1;

	//shiftRight(word); //tira o caractere b
	//Node* outarg_A = cpyNode(arg_A);
	//Node* outarg_B = cpyNode(arg_B);
	Node* outarg_C = createArg(arg_C);
	//insertBack(outarg_C->info.arg, arg_D); //saída -> (BC)
	Lista* aux = outarg_C->info.arg;
	aux->end->prox = arg_D;
	aux->end = arg_D;

	Node* tmp = word->begin;
	freeNode(tmp);
	word->begin = arg_A;
	arg_B->prox = outarg_C;
	outarg_C->prox = arg_D->prox;
	arg_D->prox = NULL;
	//freeNode(arg_D);

	/*for(i = 0; i < 4; i++)
	{
		shiftRight(word);
	}*/

	
	/*word->begin = arg_D->prox;
	insertFront(word,outarg_C);
	insertFront(word,outarg_B);
	insertFront(word,outarg_A);

	freeNode(arg_A); freeNode(arg_B); freeNode(arg_C); freeNode(arg_D);*/
	return 0;
}

char reducao_c(Lista* word)
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
	Node* outarg_B = createArg(arg_B);
	Lista* aux = outarg_B->info.arg;
	aux->end->prox = arg_D;
	aux->end = arg_D;
	//insertBack(outarg_B->info.arg, arg_D);

	Node* tmp = word->begin; freeNode(tmp);
	word->begin = arg_A;
	arg_A->prox = outarg_B;
	outarg_B->prox = arg_C;
	arg_C->prox = arg_D->prox;
	arg_D->prox = NULL;
	//freeNode(arg_D);
	
	//shiftRight(word);

	/*Node* outarg_A = createArg(arg_A);
	Node* outarg_C = createArg(arg_C);

	//for (i = 0; i < 4; i++)
	//	shiftRight(word);

	word->begin = arg_D->prox;
	insertFront(word, outarg_C);
	insertFront(word, outarg_B);
	insertFront(word, outarg_A);

	freeNode(arg_A); freeNode(arg_B); freeNode(arg_C); freeNode(arg_D);*/
	return 0;
}