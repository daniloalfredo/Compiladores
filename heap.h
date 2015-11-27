#ifndef HEAP_H
	#define HEAP_H

	#include <stdio.h>
	#include <stdlib.h>
	//Tamanho do HEAP_SIZE do K e S de 1000
	//#define HEAP_SIZE 154000
	#define HEAP_SIZE 5300000
	//#define HEAP_SIZE 150000
    //Tamanho do HEAP_SIZE de Turner de 1000
	//#define HEAP_SIZE 69000
	//#define HEAP_SIZE 80000
	//Tamanho do HEAP_SIZE de FAB1
	//#define HEAP_SIZE 9900000
	//#define HEAP_SIZE 80000

	typedef union elemento_union
	{
		char op;
		int num;
	} elemento_t;

	typedef struct cell
	{
		struct cell* foward_pointer;
		char id;
		elemento_t elemento;
		char memoria;
		struct cell* left;
		struct cell* right;
	}Cell;

	extern Cell heap[HEAP_SIZE];
	extern int posArray;
	extern int posHeapLivre;
	extern int ultimaPosHeap;
	extern int primeiraPosHeap;
	extern int heapAtual;
	extern Cell* ptrRaiz;

	//void copiaCell(Cell* cp_pointer, int hp_pointer);
	//void cheney (Cell** ptrRaiz, int inicioHeap);
	//void garbage_collector(Cell** ptrRaiz);
	int estadoHeap(int quant);
	Cell* createCell(int identificador, int inteiro, char c);
	Cell* createHeap(char src[]);

#endif