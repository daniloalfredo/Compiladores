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
	return no;
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
//insere o no value na frente da lista
void insertFront(Lista* word, Node* value)
{
	Node* no = cpyNode(value);
	no->prox = word->begin;
	word->begin = no;
}

void insertBack(Lista* word, Node* value)
{
	Node* no = cpyNode(value);
	no->prox = NULL;
	word->end->prox = no;
	word->end = no;	
}

void shiftRight(Lista* word)
{
	Node* tmp = word->begin;
	word->begin = tmp->prox;
	freeNode(tmp);	
}

void removeParentese(Lista* word)
{
	Node* tmp = word->begin;
	if (tmp->tipo == char_t)
		return;
	else 
	{
		Lista* arg = tmp->info.arg;
		word->begin = arg->begin;
		arg->end->prox = tmp->prox;
		if (tmp->prox == NULL)
			word->end = arg->end;
		free(arg);
		removeParentese(word);
	}		 
}

Lista* cloneList(Lista* dolly)
{
	Lista* clone = (Lista*)malloc(sizeof(Lista));
	clone->begin = clone->end = NULL;
	Node* ptr = dolly->begin;
	while(ptr!=NULL)
	{
		Node* tmp = ptr;
		if (tmp->tipo == char_t)
		{
			if(clone->begin != NULL)
			{
				Node* aux = (Node*)malloc(sizeof(Node));
				aux->tipo = tmp->tipo;
				aux->info.letra = tmp->info.letra;
				aux->prox = NULL;
				clone->end->prox = aux;
				clone->end = aux;
			}
			else
			{
				clone->begin = (Node*) malloc (sizeof(Node));
				clone->begin->tipo = tmp->tipo;
				clone->begin->prox = NULL;
				clone->begin->info.letra = tmp->info.letra;
				clone->end = clone->begin;
			}
			//DEBUG_PRINT("inseriu letra\n");
		}
		else
		{
			if(clone->begin != NULL)
			{
				Node* aux = (Node*) malloc(sizeof(Node));
				aux->tipo = tmp->tipo;
				aux->info.arg = cloneList(tmp->info.arg);
				aux->prox = NULL;
				clone->end->prox = aux;
				clone->end = aux;
			}
			else
			{
				clone->begin = (Node*)malloc(sizeof(Node));
				clone->begin->tipo = tmp->tipo;
				clone->begin->info.arg = cloneList(tmp->info.arg);
				clone->begin->prox = NULL;
				clone->end = clone->begin;
			}
			//DEBUG_PRINT("inseriu lista\n");
		}
		ptr = ptr->prox; 
	}
	return clone;
}

Node* createArg(elemento_t value, element_type tipo)
{
	Node* out = (Node*) malloc(sizeof(Node)); //o nó será o argumento novo a ser criado
	out->tipo = list_t;
	Lista* output = (Lista*) malloc(sizeof(Lista)); //a lista conterá os elementos do argumento
	Node* comeco = (Node*) malloc(sizeof(Node)); //esse outro nó armazena o primeiro elemento do argumento, passado por parâmetro
	if (tipo == char_t)
	{
		comeco->info.letra = value.letra;
		comeco->tipo = tipo;
	}
	else
	{
		comeco->info.arg = cloneList(value.arg);
		comeco->tipo = tipo;
	}
	output->begin = comeco;
	output->end = comeco;
	out->info.arg = output; 
	out->prox = NULL;
	return out;
}

void freeList(Lista* lst){
	Node* ptr = lst->begin;
	while(ptr != NULL){
		Node* tmp = ptr;
		ptr = ptr->prox;
		if (tmp->tipo == char_t)
			free(tmp);
		else
			freeList(tmp->info.arg);
	}
	free(lst);
}

void freeNode(Node* no){
	if (no->tipo == list_t)
	{
		freeList(no->info.arg);
		free(no);
	}
	else
		free(no);
}

void printNode(Node* no)
{
	if (no->tipo == list_t)
	{
		imprimeLista(no->info.arg);
	}
	else
		printf("%c", no->info.letra);
}

Node* cpyNode(Node* no)
{
	Node* output = (Node*) malloc(sizeof(Node));
	output->tipo = no->tipo;
	if (output->tipo == list_t)
	{
		output->info.arg = cloneList(no->info.arg);
	}
	else
		output->info.letra = no->info.letra;
	output->prox = NULL;
	return output;
}