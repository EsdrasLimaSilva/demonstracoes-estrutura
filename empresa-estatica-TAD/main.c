#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "listaEstatica.h"
#include "empresaEstatica.h"
#include "menuEstatica.h"

int main(void)
{
	// ajustando a localidade
	setlocale(LC_ALL, "Portuguese");

	Lista *pEmpresa = criarEmpresa();
	int operacao;

	do
	{
		printf("\033[2J\033[H"); // limpando a tela
		mostrarMenu();
		printf("Operacação: ");
		scanf("%d", &operacao);
		getchar(); // coletando caractere de nova linha

		printf("\033[2J\033[H"); // limpando a tela
		printf("\n");

		switch (operacao)
		{
		case SAIR:
			printf("Até mais\n");
			break;
		case ADICIONAR:
			adicionarFuncionario(pEmpresa);
			break;
		case REMOVER:
		{
			// colentando a matrícula do funcionário
			unsigned int matricula;
			printf("Informe a matricula do funcionario: ");
			scanf("%u", &matricula);
			getchar(); // coletando caractere de nova linha

			printf("\n");

			// 	// removendo o funcionário
			removerFuncionario(matricula, pEmpresa);
			break;
		}
		case BUSCAR:
		{
			unsigned int matricula;

			printf("Informe a matrícula: ");
			scanf("%u", &matricula);
			getchar();

			printf("\n");

			buscarFuncionario(matricula, pEmpresa);

			break;
		}
		case MOSTRAR:
			mostrarEmpresa(pEmpresa);
			break;
		}

		printf("\n\tPressione ENTER para continuar\n");
		getchar();
	} while (operacao != 0);

	return EXIT_SUCCESS;
}
