#include <stdio.h>

#ifndef MENU_H
#define MENU_H

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
