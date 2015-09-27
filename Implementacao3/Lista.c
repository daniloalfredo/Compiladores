#include "Lista.h"

lista_elementos* novaLista(){
    lista_elementos* nova_lista = (lista_elementos*) malloc(sizeof(lista_elementos));
    nova_lista->comeco = NULL;
    nova_lista->fim = NULL;
    return nova_lista;
}

lista_elementos* copiaLista(lista_elementos* lista){
    lista_elementos* nova_lista = (lista_elementos*) malloc(sizeof(lista_elementos));
    nova_lista->comeco = lista->comeco;
    nova_lista->fim = lista->fim;
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
}

void deletarLista(lista_elementos* lista);
void inicializarLista(lista_elementos** lista);
void liberarLista(lista_elementos** lista);
void listaInsereDir(lista_elementos* lista, no_lista* no, elemento_lista valor);
void listaInsereEsq(lista_elementos* lista, no_lista* no, elemento_lista valor);
void insereFim(lista_elementos* lista, elemento_lista valor);
void insereInicio(lista_elementos* lista, elemento_lista valor);

elemento_lista removeElemento(lista_elementos* lista, no_lista* no);
elemento_lista removeFim(lista_elementos* lista);
elemento_lista removeInicio(lista_elementos* lista);
elemento_lista elementoInicioLista(lista_elementos* lista);
elemento_lista elementoFinalLista(lista_elementos* lista);
int listaVazia(lista_elementos* lista);

