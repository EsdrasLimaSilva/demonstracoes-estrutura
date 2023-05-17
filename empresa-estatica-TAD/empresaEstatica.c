#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "listaEstatica.h"
#include "empresaEstatica.h"

struct funcionario
{
    char nome[50];
    unsigned int matricula;
};

Funcionario *criarFuncionario(char *nome, unsigned int matricula)
{
    Funcionario *pFuncionario = (Funcionario *)malloc(sizeof(Funcionario));

    if (!pFuncionario)
        exit(EXIT_FAILURE);

    strcpy(pFuncionario->nome, nome);
    pFuncionario->matricula = matricula;

    return pFuncionario;
}

void adicionarFuncionario(Lista *pEmpresa)
{
    char nome[50];
    unsigned int matricula;

    // coletando os dados
    printf("Informe o nome: ");
    fgets(nome, 50, stdin);
    nome[strlen(nome) - 1] = '\0';

    printf("Informe a matricula: ");
    scanf("%u", &matricula);
    getchar();

    Funcionario *pFuncionario = criarFuncionario(nome, matricula);
    adicionar(pEmpresa, (void *)pFuncionario);
}

void *zerarFuncionario()
{
    Funcionario *pFuncionario = (Funcionario *)malloc(sizeof(Funcionario));
    if (!pFuncionario)
        exit(EXIT_FAILURE);

    return (void *)pFuncionario;
}

void mostrarFuncionario(void *pElemento)
{
    Funcionario *pFuncionario = (Funcionario *)pElemento;

    printf("Nome: %s\n", pFuncionario->nome);
    printf("Matricula: %u\n", pFuncionario->matricula);
}

void mostrarEmpresa(Lista *pEmpresa)
{
    mostrarLista(pEmpresa, mostrarFuncionario);
}

Lista *criarEmpresa()
{
    Lista *pEmpresa = criarLista();
    zerarLista(pEmpresa, zerarFuncionario);
    return pEmpresa;
}

int compararFuncionario(unsigned int matricula, void *pElemento)
{
    Funcionario *pFuncionario = (Funcionario *)pElemento;

    if (matricula == pFuncionario->matricula)
        return 1;

    return 0;
}

void removerFuncionario(unsigned int matricula, Lista *pEmpresa)
{
    removerElemento(pEmpresa, matricula, compararFuncionario);
}

void buscarFuncionario(unsigned int matricula, Lista *pEmpresa)
{
    int index = buscarElemento(pEmpresa, matricula, compararFuncionario);

    if (index != -1)
    {
        mostrarItem(pEmpresa, index, mostrarFuncionario);
    }
    else
    {
        printf("Nada encontrado\n");
    }
}
