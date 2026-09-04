#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main() {
    Aluno turma[MAX_ALUNOS];
    int quantidade = 0;
    int opcao, subOpcao, matricula;
    char nomeBusca[41];

    carregarDados(turma, &quantidade);

    do {
        printf("\n========== MENU GERENCIADOR ==========\n");
        printf("1  - Inserir Aluno(s)\n");
        printf("2  - Exibir Todos os Alunos\n");
        printf("3  - Buscar Aluno por Matricula (ID)\n");
        printf("4  - Buscar Aluno por Nome\n");
        printf("5  - Consultar Aprovados/Reprovados\n");
        printf("6  - Alterar Notas do Aluno\n");
        printf("7  - Alterar Dados do Aluno\n");
        printf("8  - Remover Aluno\n");
        printf("9  - Salvar Dados\n");
        printf("10 - Carregar Dados\n");
        printf("0  - Sair\n");
        printf("=======================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserirAlunos(turma, &quantidade);
                break;

            case 2:
                exibirAlunos(turma, quantidade);
                break;

            case 3:
                printf("\nDigite a matricula (ID) para busca: ");
                scanf("%d", &matricula);
                {
                    int idx = buscarAlunoPorMatricula(turma, quantidade, matricula);
                    if (idx != -1) {
                        exibirDadosAluno(turma[idx]);
                    } else {
                        printf("\nAluno nao encontrado.\n");
                    }
                }
                break;

            case 4:
                printf("\nDigite o nome (ou parte dele) para busca: ");
                fgets(nomeBusca, 41, stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
                buscarAlunoPorNome(turma, quantidade, nomeBusca);
                break;

            case 5:
                printf("\n1 - Consultar Aprovados\n2 - Consultar Reprovados\nOpcao: ");
                scanf("%d", &subOpcao);
                if (subOpcao == 1) {
                    consultarPorSituacao(turma, quantidade, "Aprovado");
                } else if (subOpcao == 2) {
                    consultarPorSituacao(turma, quantidade, "Reprovado");
                } else {
                    printf("\nOpcao invalida.\n");
                }
                break;

            case 6:
                alterarNotasAluno(turma, quantidade);
                break;

            case 7:
                alterarDadosAluno(turma, quantidade);
                break;

            case 8:
                removerAluno(turma, &quantidade);
                break;

            case 9:
                salvarDados(turma, quantidade);
                break;

            case 10:
                carregarDados(turma, &quantidade);
                break;

            case 0:
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}