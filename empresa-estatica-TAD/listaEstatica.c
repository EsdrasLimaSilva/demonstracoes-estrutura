#include <stdlib.h>
#include <stdio.h>

#include "listaEstatica.h"
#include "empresaEstatica.h"

struct lista
{
    void *elementos[TAMANHO_LISTA];
    unsigned int quantidade;
};

Lista *criarLista()
{
    Lista *pLista = (Lista *)malloc(sizeof(Lista));
    if (!pLista)
        exit(EXIT_FAILURE);

    return pLista;
}

void zerarLista(Lista *pLista, void *(*zerarElemento)(void))
{
    pLista->quantidade = 0;

    void *pElementoZerado = zerarElemento();

    for (size_t i = 0; i < TAMANHO_LISTA; i++)
    {
        pLista->elementos[i] = pElementoZerado;
    }
}

void adicionar(Lista *pLista, void *pElemento)
{
    pLista->elementos[pLista->quantidade] = pElemento;
    pLista->quantidade += 1;
}

void mostrarItem(Lista *pLista, int indexElemento, void (*mostrarElemento)(void *pElemento))
{
    mostrarElemento(pLista->elementos[indexElemento]);
}

void mostrarLista(Lista *pLista, void (*mostrarElemento)(void *pElemento))
{
    if (!pLista->quantidade)
        printf("Vazio!\n");

    for (size_t i = 0; i < pLista->quantidade; i++)
    {
        mostrarElemento(pLista->elementos[i]);
        printf("\n");
    }
}

int buscarElemento(Lista *pLista, unsigned int parametro, int (*compararElemento)(unsigned int parametro, void *pElemento))
{
    if (!pLista->quantidade)
        return -1;

    // buscando o elemento
    for (int i = 0; i < pLista->quantidade; i++)
    {
        int comp = compararElemento(parametro, pLista->elementos[i]);

        if (comp)
            return i;
    }

    return -1;
}

void removerElemento(Lista *pLista, unsigned int parametro, int (*compararElemento)(unsigned int parametro, void *pElemento))
{
    int indice = buscarElemento(pLista, parametro, compararElemento);

    if (indice != -1)
    {
        free(pLista->elementos[indice]);

        if (indice < pLista->quantidade - 1)
        { // realocando todos os itens

            for (size_t i = indice + 1; i < pLista->quantidade; i++)
                pLista->elementos[i - 1] = pLista->elementos[i];
        }

        pLista->quantidade -= 1;
    }
    else
    {
        printf("Nada encontrado\n");
    }
}
