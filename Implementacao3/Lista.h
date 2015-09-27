#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

struct Lista_elementos;

typedef enum {
    tipo_char,
    tipo_lista
} TIPO_ELEMENTO;

typedef union Uniao_elementos {
    char operador;
    struct Lista_elementos* lista;
} uniao_elementos;

typedef struct Elemento_lista {
    TIPO_ELEMENTO tipo;
    uniao_elementos elemento;
} elemento_lista;

typedef struct No_lista {
   elemento_lista valor;
   struct No_lista* prox;
   struct No_lista* antr;
} no_lista;

typedef struct Lista_elementos {
    no_lista* comeco;
    no_lista* fim;
} lista_elementos;

lista_elementos* novoLista();
lista_elementos* copiaLista(lista_elementos* lista);
lista_elementos* removeElementoLista(lista_elementos* lista, no_lista* no);

void comutarListas(lista_elementos* lista1, lista_elementos* lista2);
void concatena_lista(lista_elementos* lista1, lista_elementos* lista2);
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

#endif // LISTA_H
