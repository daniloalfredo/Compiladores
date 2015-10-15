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

Node* createArg(Node* value)
{
	Node* out = (Node*) malloc(sizeof(Node)); //o nó será o argumento novo a ser criado
	out->tipo = list_t;
	Lista* output = (Lista*) malloc(sizeof(Lista)); //a lista conterá os elementos do argumento
	/*Node* comeco = (Node*) malloc(sizeof(Node)); //esse outro nó armazena o primeiro elemento do argumento, passado por parâmetro
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
	output->end = comeco;*/
	output->begin = value;
	output->end = value;
	value->prox = NULL;
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
	//free(lst->begin); free(lst->end);
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
