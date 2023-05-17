#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "matriz.h"
#include "menu.h"

int main()
{

    int linhas, colunas, operacao;

    printf("Informe o número de linhas e colunas da matriz: ");
    scanf("%d%d", &linhas, &colunas);

    int tamanho = linhas * colunas;
    int mat[tamanho];
    zerarMatriz(mat, tamanho);

    do
    {
        system("clear"); // limpa a tela
        mostrarMenu();

        printf("Operação: ");
        scanf("%d", &operacao);
        getchar();

        system("clear");

        switch (operacao)
        {
        // opções (SAIR, ADICIONAR e etc) estão no enum opções no arquivo menu.h
        case SAIR:
            break;
        case ADICIONAR:
            puts("=========== Adicionar Elemento ============");

            // mostrando a matriz antes de adicionar um elemento
            puts("Matriz: ");

            mostrarMatriz(mat, linhas, colunas);
            printf("\n\n");

            // adicionando um elemento na matriz
            adicionarElemento(mat, colunas);
            break;
        case BUSCAR:
        {
            puts("=========== Buscar Elemento ============");

            // buscando e mostrando um elemento na matriz
            buscarElemento(mat, colunas);
            break;
        }
        case REMOVER:
            puts("=========== Remover Elemento ============");
            // removendo um elemento da matriz
            removerElemento(mat, colunas);
            break;
        case MOSTRAR:
            puts("============== Matriz =================");
            mostrarMatriz(mat, linhas, colunas);
            break;
        case MULTIPLICAR:
        {
            // pega dois exemplos de matrizes e multiplica eles
            puts("============== Multiplicar =================");
            int matA[6] = {1, 2, 3, 4, 5, 6};
            int matB[6] = {7,
                           8,
                           9,
                           10,
                           11,
                           12};
            int matC[4];

            // mulciplicando as matrizes
            multiplicarMatrizes(matC, matA, 2, 3, matB, 3, 2);

            // mostrando as matrizes A e B e o produto delas
            printf("Matriz A: \n");
            mostrarMatriz(matA, 2, 3);

            printf("\n\nMatriz B: \n");
            mostrarMatriz(matB, 3, 2);

            printf("\n\nMatriz produto: \n");
            mostrarMatriz(matC, 2, 2);

            break;
        }
        case INVERSA:
        {
            puts("============== Checando se é inversa =================");
            int matA[] = {2, 1, 5, 3};
            int matB[] = {3, -1, -5, 2};

            // verificando se B é uma matriz inversa de A
            int inversa = checarInversa(matA, 2, 2, matB, 2, 2);

            // mostrando as matrizes A e B
            printf("Matriz A: \n");
            mostrarMatriz(matA, 2, 3);

            printf("\n\nMatriz B: \n");
            mostrarMatriz(matB, 3, 2);

            if (inversa)
                printf("B é inversa de A\n");
            else
                printf("B não é inversa de A\n");

            break;
        }
        default:
            printf("Operação inválida\n");
        }

        printf("\n\tPressione ENTER para continuar");
        getchar();

    } while (operacao != 0);
}
