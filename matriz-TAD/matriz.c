#include <stdio.h>

#include "matriz.h"

int calcK(int linha, int coluna, int C)
{
    int i = linha - 1;
    int j = coluna - 1;

    return i * C + j;
}

void zerarMatriz(int *pMatriz, int tamanho)
{
    for (size_t i = 0; i < tamanho; i++)
        *(pMatriz + i) = 0.0;
}

void mostrarMatriz(int *pMatriz, int linhas, int colunas)
{
    for (size_t i = 1; i <= linhas; i++)
    {
        for (size_t j = 1; j <= colunas; j++)
            printf("%d ", buscar(pMatriz, i, j, colunas));

        printf("\n");
    }
}

int buscar(int *pMatriz, int linha, int coluna, int C)
{

    int k = calcK(linha, coluna, C);
    return *(pMatriz + k);
}

void adicionarElemento(int *pMatriz, int C)
{

    int num;
    printf("Informe um número: ");
    scanf("%d", &num);
    getchar();

    int linha, coluna;
    printf("Informe a linha e a coluna: ");
    scanf("%d%d", &linha, &coluna);
    getchar();

    int k = calcK(linha, coluna, C);
    *(pMatriz + k) = num;

    printf("Número %d adicionado!\n", num);
}

void removerElemento(int *pMatriz, int C)
{
    int linha, coluna;
    printf("Informe a linha e a coluna: ");
    scanf("%d%d", &linha, &coluna);
    getchar();

    int k = calcK(linha, coluna, C);
    int num = *(pMatriz + k);
    *(pMatriz + k) = 0;

    printf("Elemento %d removido\n", num);
}

void buscarElemento(int *pMatriz, int C)
{
    int linha, coluna;
    printf("Informe a linha e a coluna: ");
    scanf("%d%d", &linha, &coluna);
    getchar();

    int num = buscar(pMatriz, linha, coluna, C);

    printf("\nNúmero na posição (%d, %d) -> %d\n\n", linha, coluna, num);
}

int checarIdentidade(int *pMatriz, int linhas, int colunas)
{

    if (linhas != colunas)
        return 0;

    for (size_t i = 1; i <= linhas; i++)
    {
        for (size_t j = 1; j <= colunas; j++)
        {

            int elemento = buscar(pMatriz, i, j, colunas);

            if ((i == j && elemento != 1) || (i != j && elemento != 0))
                return 0;
        }
    }

    return 1;
}

int checarInversa(int *pMatA, int linhasA, int colunasA, int *pMatB, int linhasB, int colunasB)
{
    int matC[linhasA * colunasB];
    multiplicarMatrizes(matC, pMatA, linhasA, colunasA, pMatB, linhasB, colunasB);

    int identidade = checarIdentidade(matC, linhasA, colunasB);

    return identidade;
}

void multiplicarMatrizes(int *pMatC, int *pMatA, int linhasA, int colunasA, int *pMatB, int linhasB, int colunasB)
{
    if (colunasA == linhasB)
    {

        // multiplicando as duas matrizes
        for (size_t i = 1; i <= linhasA; i++)
        {
            for (size_t j = 1; j <= colunasB; j++)
            {

                int num = 0;

                for (size_t k = 1; k <= colunasA; k++)
                    num += buscar(pMatA, i, k, colunasA) * buscar(pMatB, k, j, colunasB);

                pMatC[calcK(i, j, colunasB)] = num;
            }
        }
    }
    else
    {
        printf("Matrizes incompatíveis! Número de linhas em A não é igual ao número de colunas de B");
    }
}
