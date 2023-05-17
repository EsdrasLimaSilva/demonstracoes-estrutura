#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista *criarLista()
{
    Lista *pLista = (Lista *)malloc(sizeof(Lista));
    pLista->pHead = NULL;

    return pLista;
}

void remover(Lista *pLista, Nodo *pNodo)
{
    if (!pNodo->pAnterior)
    { // remove do início da lista
        pLista->pHead = pNodo->pProximo;
    }

    if (pNodo->pProximo)
        pNodo->pProximo->pAnterior = pNodo->pAnterior;

    if (pNodo->pAnterior)
    {
        printf("Oi meu chapa\n");
        pNodo->pAnterior->pProximo = pNodo->pProximo;
    }

    free(pNodo->pElemento);
    free(pNodo);
}

void adicionar(Lista *pLista, Nodo *pNodo)
{
    Nodo *pAux = pLista->pHead;

    if (!pAux)
    { // lista vazia
        pLista->pHead = pNodo;
    }
    else
    { // lista preenchida

        while (pAux->pProximo)
            pAux = pAux->pProximo;

        pAux->pProximo = pNodo;
        pNodo->pAnterior = pAux;
    }
}

void mostrarLista(Lista *pLista, void (*mostrarElemento)(void *pElemento))
{
    Nodo *pAux = pLista->pHead;

    if (pAux)
        mostrarElemento(pAux->pElemento);
    else
        printf("Lista vazia!\n");

    while (pAux && pAux->pProximo)
    {
        pAux = pAux->pProximo;
        mostrarElemento(pAux->pElemento);
    }
}
