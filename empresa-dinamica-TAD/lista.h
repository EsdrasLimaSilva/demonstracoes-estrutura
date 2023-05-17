#ifndef LIST_H
#define LIST_H

// define a estrutura nodo
typedef struct nodo Nodo;
struct nodo
{
    Nodo *pProximo;
    Nodo *pAnterior;
    void *pElemento;
};

// define a estrutura da lista
typedef struct lista Lista;
struct lista
{
    Nodo *pHead;
};

/**
 * Cria uma lista
 */
Lista *criarLista();

// adiciona um elemento na lista
void adicionar(Lista *pLista, Nodo *pNodo);

// remove um elemento da lista
void remover(Lista *pLista, Nodo *pNodo);

/**
 * Percorre toda a lista, chamando, para cada item, a função de mostrar elemento (passada como parâmetro através de um ponteiro)
 */
void mostrarLista(Lista *pLista, void (*mostarElemento)(void *pElemento));

#endif
