#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define QUANTIDADE_FUNCIONARIOS 50

// enum de opções
enum OPCOES
{
    SAIR = 0,
    ADICIONAR,
    REMOVER,
    BUSCAR,
    MOSTRAR
};

// estrutura do funcionário
typedef struct funcionario
{
    char nome[50];
    unsigned int matricula;
} Funcionario;

// estrutura da empresa
typedef struct empresa
{
    Funcionario *funcionarios[QUANTIDADE_FUNCIONARIOS];
    unsigned int quantidade;

} Empresa;

/*=========== protótipos ===========*/

// limpar a tela
void limparTela();

// adicionar um funcionário na empresa
void adicionarFuncionario(Empresa *pEmpresa);

// coleta os dados e cria um funcionário
Funcionario *criarFuncionario(void);

// mostra todos os funcionários
void mostrarEmpresa(Empresa *pEmpresa);

// mostra um único funcionário
void mostrarFuncionario(int index, Empresa *pEmpresa);

// remove um funcionário específico da empresa
void removerFuncionario(char *nome, Empresa *pEmpresa);

// busca um funcionário e retorna o seu índex ou -1 se nada for encontrado
int buscarFuncionario(char *nome, Empresa *pEmpresa);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Empresa *pEmpresa = (Empresa *)malloc(sizeof(Empresa));
    pEmpresa->quantidade = 0;

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
            puts("============ Adicionar Funcionário ===============");
            adicionarFuncionario(pEmpresa);
            break;
        case REMOVER:
            puts("============= Remover Funcionário =============");
            char nome[50];

            printf("Informe o nome: ");
            fgets(nome, 50, stdin);
            nome[strlen(nome) - 1] = '\0';

            removerFuncionario(nome, pEmpresa);

            break;
        case BUSCAR:
        {
            puts("================= Buscar Funcionário =============");

            char nome[50];
            printf("Informe o nome: ");
            fgets(nome, 50, stdin);
            nome[strlen(nome) - 1] = '\0';

            int index = buscarFuncionario(nome, pEmpresa);

            if (index != -1)
                mostrarFuncionario(index, pEmpresa);
            else
                printf("Funcionário não encontrado\n");

            break;
        }
        case MOSTRAR:
            puts("=============== Empresa =================");
            mostrarEmpresa(pEmpresa);
            break;
        }

        printf("\n\tPressione ENTER para continuar");
        getchar();

    } while (operacao != 0);
}

void limparTela()
{
    printf("\033[2J\033[H");
}

Funcionario *criarFuncionario(void)
{
    Funcionario *pFuncionario = (Funcionario *)malloc(sizeof(Funcionario));

    if (!pFuncionario)
        exit(EXIT_FAILURE);

    char nome[50];
    unsigned int matricula;

    printf("Nome: ");
    fgets(nome, 50, stdin);
    nome[strlen(nome) - 1] = '\0';

    printf("Matrícula: ");
    scanf("%u", &matricula);
    getchar();

    // atribuinto os valores ao funcionário
    strcpy(pFuncionario->nome, nome);
    pFuncionario->matricula = matricula;

    return pFuncionario;
}

void adicionarFuncionario(Empresa *pEmpresa)
{
    Funcionario *pFuncionario = criarFuncionario();

    if (pEmpresa->quantidade == QUANTIDADE_FUNCIONARIOS)
    {
        printf("Empresa cheia!\n");
    }
    else
    {

        pEmpresa->funcionarios[pEmpresa->quantidade] = pFuncionario;
        pEmpresa->quantidade += 1;
    }
}

void mostrarEmpresa(Empresa *pEmpresa)
{
    if (pEmpresa->quantidade)
    {

        for (size_t i = 0; i < pEmpresa->quantidade; i++)
            mostrarFuncionario(i, pEmpresa);
    }
    else
    {
        printf("Empresa sem funcionários!\n");
    }
}

int buscarFuncionario(char *nome, Empresa *pEmpresa)
{
    if (!pEmpresa->quantidade)
        return -1;

    for (int i = 0; i < pEmpresa->quantidade; i++)
        if (!strcmp(pEmpresa->funcionarios[i]->nome, nome))
            return i;

    return -1;
}

void removerFuncionario(char *nome, Empresa *pEmpresa)
{
    if (pEmpresa->quantidade)
    {
        int index = buscarFuncionario(nome, pEmpresa);

        if (index != -1)
        {
            free(pEmpresa->funcionarios[index]);

            if (index < pEmpresa->quantidade - 1)
                for (size_t i = index + 1; i < pEmpresa->quantidade; i++)
                    pEmpresa->funcionarios[i - 1] = pEmpresa->funcionarios[i];

            pEmpresa->quantidade--;
        }
        else
            printf("Funcionário não encontrado\n");
    }
    else
        printf("Empresa sem funcionários\n");
}

void mostrarFuncionario(int index, Empresa *pEmpresa)
{
    printf("Nome: %s\n", pEmpresa->funcionarios[index]->nome);
    printf("Matrícula: %u\n", pEmpresa->funcionarios[index]->matricula);
    printf("Índex: %d\n\n", index);
}
