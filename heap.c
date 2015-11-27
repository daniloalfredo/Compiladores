#include "heap.h"

int posArray = 0;
int posHeapLivre = 0;
int heapAtual = 0;
Cell* ptrRaiz = NULL;

int estadoHeap(int quant)
{
	/*if(heapAtual == 0)
	{
		//if((posHeapLivre + quant - 1) > ((HEAP_SIZE/2)-1))
		if((posHeapLivre + quant - 1) > ((HEAP_SIZE)-1))
			return 1;
	}
	else
	{
		if((posHeapLivre + quant - 1) > (HEAP_SIZE-1))
			return 1;
	}
	return 0 ;*/
	return 0;
}

void printHeap(Cell* raiz){
	
	Cell* r = raiz;
	if(r != NULL)
	{
		printHeap(r->left);
		if(r->right!=NULL)
		{
			if(r->right->elemento.op=='@')	printf("(");
				printHeap(r->right);
			if(r->right->elemento.op=='@')	printf(")");
		}
		if(r->id == 0)
		{
			if(r->elemento.op!='@')
				printf("%c",r->elemento.op);
		}	
		else
			printf("%d",r->elemento.num);
	}
}

void copy_cell(Cell* from, Cell* to){
    to->foward_pointer = NULL;
    to->id = from->id;
    if(to->id == 0)
        to->elemento.op = from->elemento.op;
    else
        to->elemento.num = from->elemento.num;

    to->left = from->left;
	to->right = from->right;
    posHeapLivre++;
}

unsigned int cheney (long unsigned int root_from, long unsigned int root_to, long unsigned int size_heaps){
   	printf("Entrando no cheney...\n");
    posHeapLivre = root_to;
    Cell* cp_pointer = &heap[root_from];
    Cell* hp_pointer = cp_pointer;
    Cell* new_heap_pos = NULL;

    long unsigned int i = root_to;
    unsigned int decrement = 0;
    short int nbreak = -1;

    copy_cell(cp_pointer, &heap[i]);
    cp_pointer->foward_pointer = &heap[i];
    cp_pointer = &heap[i];

    for(; i < root_to + size_heaps; i++){
    //	printf("i = %d\n",i);
        if(cp_pointer->left != NULL && cp_pointer->left->foward_pointer == NULL){
            new_heap_pos = &heap[2*i+1-(root_to+decrement)];
            copy_cell(cp_pointer->left, new_heap_pos);
            cp_pointer->left->foward_pointer = new_heap_pos;
            heap[i].left = new_heap_pos;
            hp_pointer = heap[i].left;
        }
        else{
            if(cp_pointer->left != NULL)
                heap[i].left = cp_pointer->left->foward_pointer;
            else
                heap[i].left = NULL;
            decrement += 1;
        }
        if(cp_pointer->right != NULL && cp_pointer->right->foward_pointer == NULL){
            new_heap_pos = &heap[2*i+2-(root_to+decrement)];
            copy_cell(cp_pointer->right, new_heap_pos);
            cp_pointer->right->foward_pointer = new_heap_pos;
            heap[i].right = new_heap_pos;
            hp_pointer = heap[i].right;
        }
        else {
            if(cp_pointer->right != NULL)
                heap[i].right = cp_pointer->right->foward_pointer;
            else
                heap[i].right = NULL;
            decrement += 1;
        }

        cp_pointer = &heap[i+1];
        if(hp_pointer == cp_pointer) nbreak = i+1;
        if(nbreak == i) break;
    }
    printf("Saindo do cheney...\n");
    return root_to;
}

unsigned int garbage_collector(long unsigned int index_root)
{
	printf("Entrando no garbage...\n");
    if(heapAtual == 0){
    	heapAtual = 1;
        return cheney(index_root, HEAP_SIZE/2, HEAP_SIZE/2-1);
    }
    heapAtual = 0;
    printf("Saindo do garbage...\n");
    return cheney(index_root, 0, HEAP_SIZE/2-1);
}

Cell* createCell(int identificador, int inteiro, char c)
{
	Cell* newCell;

	if(identificador == 0)
	{
		heap[posHeapLivre].elemento.op = c;
		heap[posHeapLivre].id = identificador;
	}
	else
	{
		heap[posHeapLivre].elemento.num = inteiro;
		heap[posHeapLivre].id = identificador;
	}
	heap[posHeapLivre].foward_pointer = NULL;
	heap[posHeapLivre].left = NULL;
	heap[posHeapLivre].right = NULL;
	newCell = &heap[posHeapLivre];
	posHeapLivre++;
	return newCell;
}

Cell* createHeap(char src[])
{
	int fim = 0;
	Cell* raiz  = NULL;
	raiz = createCell(0,0,'@'); 
	Cell* newCell = NULL;
	while(!fim)
	{
		switch (src[posArray])
		{
			case 'K':
					newCell = createCell(0,0,'K');
					posArray++;
					break;
			case 'S':
					newCell = createCell(0,0,'S');
					posArray++;
					break;
			case 'I':
					newCell = createCell(0,0,'I');
					posArray++;
					break;
			case 'B':
					newCell = createCell(0,0,'B');
					posArray++;
					break;
			case 'C':
					newCell = createCell(0,0,'C');
					posArray++;
					break;
			case 's':
					newCell = createCell(0,0,'s');
					posArray++;
					break;
			case 'b':
					newCell = createCell(0,0,'b');
					posArray++;
					break;
			case 'c':
					newCell = createCell(0,0,'c');
					posArray++;
					break;
			case 'Y':
					newCell = createCell(0,0,'Y');
					posArray++;
					break;
			case '+':
					newCell = createCell(0,0,'+');
					posArray++;
					break;
			case '-':
					newCell = createCell(0,0,'-');
					posArray++;
					break;
			case '*':
					newCell = createCell(0,0,'*');
					posArray++;
					break;
			case '/':
					newCell = createCell(0,0,'/');
					posArray++;
					break;
			case '=':
					newCell = createCell(0,0,'=');
					posArray++;
					break;
			case '>':
					newCell = createCell(0,0,'>');
					posArray++;
					break;
			case '<':
					newCell = createCell(0,0,'<');
					posArray++;
					break;
			case '^':
					newCell = createCell(0,0,'^');
					posArray++;
					break;
			case 'H': //head
					newCell = createCell(0,0,'H');
					posArray++;
					break;
			case 'T': //tail
					newCell = createCell(0,0,'T');
					posArray++;
					break;
			case ':': //cons
					newCell = createCell(0,0,':');
					posArray++;
					break;
			case '#': //lista vazia
					newCell = createCell(0,0,'#');
					posArray++;
					break;
			case '$':
					posArray++;
					char stringAux[10];
					int cont = 0; 
					while(src[posArray] != '$')
					{
						stringAux[cont] = src[posArray];
						posArray++;
						cont++;
					}
					posArray++;
					int valor = atoi(stringAux);
					newCell = createCell(1,valor,0);
					break;
			case '(':
					if(src[posArray+2] == ')')
					{
						newCell = createCell(0,0,src[posArray+1]);
						posArray=posArray+3;
						printf("wewe" );
					}
					else
					{
						posArray++;
						newCell = createHeap(src);
					}
					break;
			case ')':
					posArray++;
					fim = 1;
					break;
			case '\0':
					fim = 1;
					break;
			default:
					newCell = createCell(0,0,src[posArray]);
					posArray++;
		}

		if (fim != 1) 
		{
			if(raiz->left == NULL)
			{
				raiz->left = newCell;
			}
			else if(raiz->right == NULL)
			{
				raiz->right = newCell;
			}
			else
			{
				Cell* newRaiz = createCell(0,0,'@');
				newRaiz->left = raiz;
				newRaiz->right = newCell;
				raiz = newRaiz;
			}
		}
	}
	//printf("%d\n",posHeapLivre);
	ptrRaiz = raiz;
	return raiz;
}