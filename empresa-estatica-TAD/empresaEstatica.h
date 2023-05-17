#ifndef EMPRESA_H
#define EMPRESA_H

#include "structs.h"

Funcionario *criarFuncionario(char *nome, unsigned int matricula);

void adicionarFuncionario(Lista *pEmpresa);

Lista *criarEmpresa();

void mostrarEmpresa(Lista *pEmpresa);

void *zerarFuncionario();

// compara uma matrícula com um funcionário e retorna 1(verdadeiro) ou 0(falso)
int compararFuncionario(unsigned int matricula, void *pElemento);

void removerFuncionario(unsigned int matricula, Lista *pEmpresa);

void buscarFuncionario(unsigned int matricula, Lista *pEmpresa);

#endif
