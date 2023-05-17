#include "lista.h"
#include "empresa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cria uma empresa
Lista *criarEmpresa()
{
    Lista *pEmpresa = criarLista();
    return pEmpresa;
}

// remove o funcionário da empresa
void removerFuncionario(unsigned int matricula, Lista *pEmpresa)
{
    Nodo *pNodo = pEmpresa->pHead;

    while (pNodo)
    {
        Funcionario *pFuncionario = (Funcionario *)pNodo->pElemento;

        // funcionario foi encontrado
        if (pFuncionario->matricula == matricula)
        {
            remover(pEmpresa, pNodo);
            break;
        }

        pNodo = pNodo->pProximo;
    }
}

void adicionarFuncionario(Lista *pEmpresa)
{
    // criando o nodo e checando se tudo deu certo
    Nodo *pNodo = (Nodo *)malloc(sizeof(Nodo));
    if (!pNodo)
        exit(EXIT_FAILURE);

    pNodo->pAnterior = pNodo->pProximo = NULL;

    // alocando memória para o funcionario e checando se tudo deu certo
    Funcionario *pFuncionario = (Funcionario *)malloc(sizeof(Funcionario));
    if (!pFuncionario)
    {
        free(pNodo);
        printf("Algo deu errado");
        exit(EXIT_FAILURE);
    }

    // coletando os dados do funcionário
    printf("Nome do funcinário: ");
    fgets(pFuncionario->nome, 50, stdin);
    pFuncionario->nome[strlen(pFuncionario->nome) - 1] = '\0';

    printf("Matrícula do funcionario: ");
    scanf("%u", &pFuncionario->matricula);
    getchar();

    // associando o elemento do nodo ao endereço de memória do funcionario
    pNodo->pElemento = pFuncionario;

    adicionar(pEmpresa, pNodo);
}

void mostrarFuncionario(void *pNodo)
{
    Funcionario *pFuncionario = (Funcionario *)pNodo;
    printf("Nome: %s\n", pFuncionario->nome);
    printf("Matrícula: %u\n\n", pFuncionario->matricula);
}

void mostrarEmpresa(Lista *pEmpresa)
{
    mostrarLista(pEmpresa, mostrarFuncionario);
}

void buscarFuncionario(char *nome, Lista *pEmpresa)
{
    Nodo *pAux = pEmpresa->pHead;
    unsigned short funcionarioEncontrado = 0;

    while (pAux && pAux->pProximo)
    {
        Funcionario *pFuncionario = (Funcionario *)pAux->pElemento;

        if (strcmp(nome, pFuncionario->nome))
        {
            printf("Nome: %s\n", pFuncionario->nome);
            printf("Matricula: %u\n", pFuncionario->matricula);
            funcionarioEncontrado = 1;
            break;
        }
    }

    if (!funcionarioEncontrado)
    {
        printf("Funcionário Inexistente!\n");
    }
}
