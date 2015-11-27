#ifndef LISTA_H
	#define LISTA_H

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "entrada.h"

	typedef enum {char_t, list_t} element_type;

	struct lista; 

	typedef union elemento_union
	{
		char letra;
		struct lista* arg;
	} elemento_t;

	typedef struct node
	{
		element_type tipo; 
		elemento_t info;
		struct node* prox;
	} Node;

	typedef struct lista{
		Node* begin;
		Node* end;
	} Lista;

	int fimPar(int K, char src[]);
	Node* criaNo(char c, element_type tipo,int comP, int fimP, char src[]);
	Lista* criaLista(int i, int j, char src[]);
	void imprimeLista(Lista* inicio);
	void insertFront(Lista* word, Node* arg);
	void insertBack(Lista* word, Node* arg);
	void shiftRight(Lista* word);
	void removeParentese(Lista* word);
	Lista* cloneList(Lista* dolly);
	Node* createArg(Node* value);
	void freeList(Lista* lst);
	void freeNode(Node* no); 
	void printNode(Node* no);
	Node* cpyNode(Node* no);
#endif