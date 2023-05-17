#include <stdio.h>
#include "menu.h"

void mostrarMenu()
{
    puts("---------------- Menu ----------------");
    printf("[%d] Sair\n", SAIR);
    printf("[%d] Adicionar elemento\n", ADICIONAR);
    printf("[%d] Remover elemento\n", REMOVER);
    printf("[%d] Buscar elemento\n", BUSCAR);
    printf("[%d] Mostrar matriz\n", MOSTRAR);
    printf("[%d] Multiplicar matrizes\n", MULTIPLICAR);
    printf("[%d] Checar se é inversa\n\n", INVERSA);
}
