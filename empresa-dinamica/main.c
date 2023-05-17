#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* enum de opções */
enum OPCOES
{
    SAIR = 0,
    ADICIONAR,
    REMOVER,
    BUSCAR,
    MOSTRAR
};

/* estrutura do funcionário */
typedef struct funcionario
{
    char nome[50];
    unsigned int matricula;
} Funcionario;

/* estrutura do nó */
typedef struct nodo
{

    struct nodo *pAnterior;
    Funcionario funcionario;
    struct nodo *pProximo;

} Nodo;

/* estrutura da empresa */
typedef struct empresa
{

    Nodo *pHead;

} Empresa;

/* ==================== protótipos ======================= */

/* limpar a tela */
void limparTela();

/* cria uma empresa e retorna um ponteiro */
Empresa *criarEmpresa();

/* adiciona um funcionário na empresa */
void adicionarFuncionario(Empresa *pEmpresa);

/* coleta os dados e cria um funcionário */
Nodo *criarNodo();

/* mostra todos os funcionários */
void mostrarEmpresa(Empresa *pEmpresa);

/* mostra um único funcionário */
void mostrarFuncionario(Nodo *pNodo);

/* remove um funcionário */
void removerFuncionario(unsigned int matricula, Empresa *pEmpresa);

Nodo *buscarFuncionario(char *nome, Empresa *pEmpresa);

int main()
{
    Empresa *pEmpresa = criarEmpresa();
    int operacao;

    do
    {
        limparTela();
        puts("---------------- Menu ----------------");
        printf("[%d] Sair\n", SAIR);
        printf("[%d] Adicionar funcionario\n", ADICIONAR);
        printf("[%d] Remover funcionario\n", REMOVER);
        printf("[%d] Buscar funcionário: \n", BUSCAR);
        printf("[%d] Mostrar funcionarios\n\n", MOSTRAR);

        printf("Operacao: ");
        scanf("%d", &operacao);
        getchar(); // coletando o caractee de nova linha

        limparTela();

        switch (operacao)
        {
        case SAIR:
            printf("Até mais\n");
            break;
        case ADICIONAR:
            puts("=========== Adicionar Funcionário =============");
            adicionarFuncionario(pEmpresa);
            break;
        case REMOVER:
        {
            puts("=========== Remover Funcionário =============");
            unsigned int matricula;
            printf("Matrícula: ");
            scanf("%u", &matricula);
            getchar();

            removerFuncionario(matricula, pEmpresa);
            break;
        }
        case BUSCAR:
        {
            puts("=========== Buscar Funcionário =============");

            char nome[50];
            printf("Nome: ");
            fgets(nome, 50, stdin);
            nome[strlen(nome) - 1] = '\0';

            Nodo *pNodo = buscarFuncionario(nome, pEmpresa);
            printf("\n");

            if (pNodo)
                mostrarFuncionario(pNodo);

            break;
        }
        case MOSTRAR:
            puts("=========== Funcionários =============");
            mostrarEmpresa(pEmpresa);
            break;
        default:
            puts("Operação inválida!\n");
        }

        printf("\n\tPressione ENTER para continuar");
        getchar();

    } while (operacao != 0);
}

/*============================== Definições ====================================*/
void limparTela()
{
    printf("\033[2J\033[H");
}

Empresa *criarEmpresa()
{
    Empresa *pEmpresa = (Empresa *)malloc(sizeof(Empresa));
    if (!pEmpresa)
        exit(EXIT_FAILURE);

    pEmpresa->pHead = NULL;

    return pEmpresa;
}

Nodo *criarNodo()
{
    Nodo *pNodo = (Nodo *)malloc(sizeof(Nodo));
    if (!pNodo)
        exit(EXIT_FAILURE);

    pNodo->pAnterior = pNodo->pProximo = NULL;

    // coletando os dados
    char nome[50];
    unsigned int matricula;

    printf("Nome: ");
    fgets(nome, 50, stdin);
    nome[strlen(nome) - 1] = '\0';

    printf("Matrícula: ");
    scanf("%u", &matricula);
    getchar(); // coletando o caractere de nova linha

    strcpy(pNodo->funcionario.nome, nome);
    pNodo->funcionario.matricula = matricula;

    return pNodo;
}

void adicionarFuncionario(Empresa *pEmpresa)
{
    Nodo *pNodo = criarNodo();

    if (!pEmpresa->pHead)
    { // empresa sem funcionários

        pEmpresa->pHead = pNodo;
    }
    else
    {
        Nodo *pAux = pEmpresa->pHead;

        while (pAux->pProximo)
            pAux = pAux->pProximo;

        pNodo->pAnterior = pAux;
        pAux->pProximo = pNodo;
    }
}

void mostrarFuncionario(Nodo *pNodo)
{
    printf("Nome: %s\n", pNodo->funcionario.nome);
    printf("Matrícula: %u\n\n", pNodo->funcionario.matricula);
}

void mostrarEmpresa(Empresa *pEmpresa)
{
    Nodo *pAux = pEmpresa->pHead;

    if (!pAux)
        printf("\tEmpresa sem funcionários\n");

    while (pAux)
    {
        mostrarFuncionario(pAux);
        pAux = pAux->pProximo;
    }
}

Nodo *buscarFuncionario(char *nome, Empresa *pEmpresa)
{
    if (pEmpresa->pHead)
    {

        Nodo *pAux = pEmpresa->pHead;

        while (pAux)
        {
            if (!strcmp(pAux->funcionario.nome, nome))
                return pAux;

            pAux = pAux->pProximo;
        }
    }

    printf("\n\tNada encontrado!\n");
    return NULL;
}

void removerFuncionario(unsigned int matricula, Empresa *pEmpresa)
{

    Nodo *pAux = pEmpresa->pHead;
    bool funcionarioEncontrado = false;

    if (pAux)
    { // se a lista não estiver vazia
        while (pAux)
        {
            if (pAux->funcionario.matricula == matricula)
            {
                funcionarioEncontrado = true;
                break;
            }

            pAux = pAux->pProximo;
        }
    }
    else
        printf("\n\tSem funcionários!\n");

    if (funcionarioEncontrado)
    {
        if (!pAux->pAnterior) // remover do início da lista
            pEmpresa->pHead = pAux->pProximo;

        if (pAux->pProximo)
            pAux->pProximo->pAnterior = pAux->pAnterior;

        if (pAux->pAnterior)
            pAux->pAnterior->pProximo = pAux->pProximo;

        free(pAux);
    }
    else
    {
        printf("\n\tFuncionário inexistente\n;");
    }
}
