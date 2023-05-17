
#ifndef MATRIZ_H
#define MATRIZ_H

// calcula a posição k no vetor linear
int calcK(int linha, int coluna, int quantidadeColunas);

// zera todas as posições da matriz
void zerarMatriz(int *pMatriz, int tamanho);

// mostra toda a matriz
void mostrarMatriz(int *pMatriz, int linhas, int colunas);

// busca e retorna um elemento específico
int buscar(int *pMatriz, int linha, int coluna, int C);

// adiciona um elemento na matriz
void adicionarElemento(int *pMatriz, int C);

// remove um elemento da matriz
void removerElemento(int *pMatriz, int C);

// mostra um único elemento
void buscarElemento(int *pMatriz, int C);

// checa se uma matriz é identidade e retorna 1 para verdadeiro e 0 para falso
int checarIdentidade(int *pMatriz, int linhas, int colunas);

// checa se uma matriz B é inversa de uma matriz A
int checarInversa(int *pMatA, int linhasA, int colunasA, int *pMatB, int linhasB, int colunasB);

// multiplica matriz A * matriz B e coloca o resultado na matriz C
void multiplicarMatrizes(int *pMatC, int *pMatA, int linhasA, int colunasA, int *pMatB, int linhasB, int colunasB);

#endif
