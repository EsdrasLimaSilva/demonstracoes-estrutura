#include "lista.h"
#include "empresa.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
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

			// removendo o funcionário
			removerFuncionario(matricula, pEmpresa);
			break;
		}
		case BUSCAR:
		{
			char nome[50];
			printf("Insira o nome do funcionário: ");
			fgets(nome, 50, stdin);

			printf("\n");

			buscarFuncionario(nome, pEmpresa);

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
