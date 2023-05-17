#ifndef EMPRESA_H
#define EMPRESA_H

#include "lista.h"

/*
Estrutura do funcionario
*/
typedef struct funcionario Funcionario;
struct funcionario
{
    char nome[50];
    unsigned int matricula;
};

// cria uma lista(empresa) de funcionários
Lista *criarEmpresa();

// adiciona funcionario na lista da empresa
void adicionarFuncionario(Lista *pEmpresa);

// remove funcionario da empresa
void removerFuncionario(unsigned int matricula, Lista *pEmpresa);

// mostra um único funcionario
void mostrarFuncionario(void *pNodo);

// mostra toda a lista de funcionarios
void mostrarEmpresa(Lista *pEmpresa);

// busca um funcionário e mostra ele
void buscarFuncionario(char *nome, Lista *pEmpresa);

#endif
