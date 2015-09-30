#include "lista.h"

/*Função para achar o final do parentese*/
int fimPar(int pos_inicial, char src[])
{
	int i = 0;
	int cont_parentese = 1;
	register int pos_final = 0;

	for(i = pos_inicial + 1; src[i] != '\0'; i++)
	{
		if(src[i] == '(')
		{
			cont_parentese++;
		}
		else if(src[i] == ')')
		{
			cont_parentese--;
			if(cont_parentese == 0) {
                pos_final = i;
                break;
			}
		}
	}

	return pos_final;
}

/*Função para criar o nó*/
Node* criaNo(char c, element_type tipo, int comP, int fimP, char src[])
{
	Node* no = (Node*) malloc (sizeof(Node));
	if(tipo == char_t)
	{
		no->tipo = tipo;
		no->info.letra = c;
		//no->baixo = NULL;
		no->prox = NULL;
	}
	else
	{
		no->tipo = tipo;
		no->info.arg = criaLista(comP+1, fimP-1, src);
		//no->baixo = criaLista(comP+1,fimP-1,src);
		no->prox = NULL;
	}
}

/* inserção no fim da lista*/
Lista* criaLista(int i, int j, char src[])
{
	Lista* inicio = (Lista*) malloc (sizeof(Lista));
	inicio->begin = NULL; inicio->end = NULL;
	int k = 0;

	for (k = i;k <= j; k++)
	{
		if(src[k] != '(')
		{
			if(inicio->begin==NULL)
			{
				inicio->begin = criaNo(src[k],char_t,0,0,src);
			}
			else
			{
				Node* ptr;
				for(ptr = inicio->begin;ptr->prox != NULL;ptr = ptr->prox);
				ptr->prox = criaNo(src[k],char_t,0,0,src);
				inicio->end = ptr->prox;
			}
		}
		else
		{
			int comP, fimP;
			comP = k;
			fimP = fimPar(k,src);
			
			if(inicio->begin==NULL){
				inicio->begin = criaNo(0,list_t,comP,fimP,src);
			}
			else
			{
				Node* ptr = NULL;
				for(ptr = inicio->begin ;ptr->prox != NULL;ptr = ptr->prox);
				ptr->prox = criaNo(0,list_t,comP,fimP,src);
				inicio->end = ptr->prox;
			}
			k = fimP;
		}
	}
	return inicio;	
}

void imprimeLista(Lista* inicio)
{
	Node* ptr = inicio->begin;
	while(ptr != NULL)
	{
		if(ptr->tipo == char_t)
		{
			printf("%c",ptr->info.letra);
		}
		else
		{
			printf("(");
			imprimeLista(ptr->info.arg);
			printf(")");
		}
		ptr = ptr->prox;
	}
}

//insere o no value na frente da lista
void insertFront(Lista* word, Node* value)
{
	element_type tipo = value->tipo;
	Node* no = (Node*) malloc(sizeof(Node));
	no->tipo = tipo;
	if (tipo == char_t){
		no->info.letra = value->info.letra;
	}
	else
		no->info.arg = value->info.arg;
	no->prox = word->begin;
	word->begin = no;
}

void insertBack(Lista* word, Node* value)
{
	element_type tipo = value->tipo;
	Node* no = (Node*) malloc(sizeof(Node));
	no->tipo = tipo;
	if (tipo == char_t){
		no->info.letra = value->info.letra;
	}
	else
		no->info.arg = value->info.arg;
	no->prox = NULL;
	word->end->prox = no;
	word->end = no;	
}

void shiftRight(Lista* word)
{
	Node* tmp = word->begin;
	word->begin = tmp->prox;
	//freeNode(tmp);	
}