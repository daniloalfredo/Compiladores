#ifndef PILHA_H
	#define PILHA_H

	#include <stdio.h>
	#include <stdlib.h>
	#include "heap.h"
	#define PILHA_SIZE 1000

	extern Cell* pilha[PILHA_SIZE];
	extern int posPilhaLivre;

	char pop(int times);
	void push(Cell* cell);
	
#endif