#include "Lista.h"

inline int listaVazia(lista_elementos* lista){
    if(lista->comeco == NULL)
        return 1;
    return 0;
}

lista_elementos* novaLista(){
    lista_elementos* nova_lista = (lista_elementos*) malloc(sizeof(lista_elementos));
    nova_lista->comeco = NULL;
    nova_lista->fim = NULL;
    return nova_lista;
}

lista_elementos* copiaLista(lista_elementos* lista){
    if(!listaVazia(lista))
        return NULL;

    lista_elementos* nova_lista = (lista_elementos*) malloc(sizeof(lista_elementos));
    lista_elementos* temp = lista;
    lista_elementos* temp2 = nova_lista;

    temp2->comeco = (no_lista*) malloc(sizeof(no_lista));
    temp2->comeco->antr = temp->comeco->antr;
    temp2->comeco->valor = temp->comeco->valor;

    do{
        if(temp->comeco->prox != NULL){
            temp2->comeco->prox = (no_lista*) malloc(sizeof(no_lista));
            temp2->comeco = temp2->comeco->prox;
            temp->comeco = temp->comeco->prox;
        }

        temp2->comeco->antr = temp->comeco->antr;
        temp2->comeco->valor = temp->comeco->valor;

    } while(temp->comeco != lista->fim);

    return nova_lista;
}

lista_elementos* removeElementoLista(lista_elementos* lista, no_lista* no){
    no_lista* temp = lista->comeco;

    while(temp != no && temp != lista->fim)
        temp = temp->prox;

    if(temp != no)
        exit(1);

    temp->antr->prox = temp->prox;
    temp->prox->antr = temp->antr;
    free(temp);
    return lista;
}

void comutarListas(lista_elementos* lista1, lista_elementos* lista2){
    lista_elementos* temp = lista1;
    lista1 = lista2;
    lista2 = temp;
}

void concatena_lista(lista_elementos* lista1, lista_elementos* lista2){
    lista1->fim->prox = lista2->comeco;
    lista2->comeco->antr = lista1->fim;
    lista1->fim = lista2->fim;
    lista2 = NULL;
}

// Consertar para se valor for uma lista
void deletarLista(lista_elementos* lista){
    no_lista* temp = lista->comeco;
    no_lista* temp2 = temp;
    while(temp != lista->fim){
        temp2 = temp;
        temp = temp->prox;
        free(temp2);
    }
    free(temp);
    lista->comeco = NULL;
    lista->fim = NULL;
}

//void inicializarLista(lista_elementos** lista);
//void liberarLista(lista_elementos** lista);

void listaInsereDir(lista_elementos* lista, no_lista* no, elemento_lista valor);
void listaInsereEsq(lista_elementos* lista, no_lista* no, elemento_lista valor);

void insereFim(lista_elementos* lista, elemento_lista valor){
    no_lista* novo = (no_lista*) malloc(sizeof(no_lista));
    novo->valor = valor;
    novo->prox = NULL;
    if(!listaVazia(lista)){
        novo->antr = lista->fim;
        lista->fim->prox = novo;
    }
    else{
        novo->antr = NULL;
        lista->comeco = novo;
    }
    lista->fim = novo;
}

void insereInicio(lista_elementos* lista, elemento_lista valor){
    no_lista* novo = (no_lista*) malloc(sizeof(no_lista));
    novo->valor = valor;
    novo->antr = NULL;
    if(!listaVazia(lista)){
        novo->prox = lista->comeco;
        lista->comeco->antr = novo;
    }
    else{
        novo->prox = NULL;
        lista->fim = novo;
    }
    lista->comeco = novo;
}

elemento_lista removeElemento(lista_elementos* lista, no_lista* no);
elemento_lista removeFim(lista_elementos* lista);
elemento_lista removeInicio(lista_elementos* lista);

elemento_lista elementoInicioLista(lista_elementos* lista){
    return lista->comeco->valor;
}

elemento_lista elementoFinalLista(lista_elementos* lista){
    return lista->fim->valor;
}


