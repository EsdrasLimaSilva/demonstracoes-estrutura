#ifndef MENU_H
#define MENU_H

#include <stdio.h>

enum OPCOES
{
	SAIR = 0,
	ADICIONAR,
	REMOVER,
	BUSCAR,
	MOSTRAR
};

// mostra o menu para o usuario
void mostrarMenu();

#endif
