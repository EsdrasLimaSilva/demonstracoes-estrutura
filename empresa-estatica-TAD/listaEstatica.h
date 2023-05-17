#ifndef LISTA_H
#define LISTA_H

#include "structs.h"

Lista *criarLista();

void adicionar(Lista *pLista, void *pElemento);

void remover(Lista *pLista, unsigned int matricula);

void zerarLista(Lista *pLista, void *(*zerarElemento)(void));

void mostrarItem(Lista *pLista, int indexElemento, void (*mostrarElemento)(void *pElemento));

void mostrarLista(Lista *pLista, void (*mostrarElemento)(void *pElemento));

int buscarElemento(Lista *pLista, unsigned int parametro, int (*compararElemento)(unsigned int parametro, void *pElemento));

void removerElemento(Lista *pLista, unsigned int parametro, int (*compararElemento)(unsigned int parametro, void *pElemento));

#endif
