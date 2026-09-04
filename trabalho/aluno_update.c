#include <stdio.h>
#include <string.h>
#include "aluno.h"

void alterarNotasAluno(Aluno turma[], int quantidade) {
    int matricula, idx;

    printf("\nDigite a matricula (ID) do aluno: ");
    scanf("%d", &matricula);

    idx = buscarAlunoPorMatricula(turma, quantidade, matricula);

    if (idx == -1) {
        printf("\nAluno nao encontrado!\n");
        return;
    }

    printf("\nAlterando notas do aluno: %s\n", turma[idx].nome);
    printf("Nova Prova 1: ");
    scanf("%f", &turma[idx].prova1);
    printf("Nova Prova 2: ");
    scanf("%f", &turma[idx].prova2);

    calcularSituacao(&turma[idx]);
    printf("\nNotas atualizadas e situacao recalculada com sucesso!\n");
}

void alterarDadosAluno(Aluno turma[], int quantidade) {
    int matricula, idx;

    printf("\nDigite a matricula (ID) do aluno a ser alterado: ");
    scanf("%d", &matricula);
    getchar();

    idx = buscarAlunoPorMatricula(turma, quantidade, matricula);

    if (idx == -1) {
        printf("\nAluno nao encontrado!\n");
        return;
    }

    printf("\n--- Alterando dados de: %s ---\n", turma[idx].nome);

    printf("Novo Nome: ");
    fgets(turma[idx].nome, 41, stdin);
    turma[idx].nome[strcspn(turma[idx].nome, "\n")] = '\0';

    printf("Nova Prova 1: ");
    scanf("%f", &turma[idx].prova1);

    printf("Nova Prova 2: ");
    scanf("%f", &turma[idx].prova2);

    printf("Novas Faltas: ");
    scanf("%d", &turma[idx].faltas);
    getchar();

    calcularSituacao(&turma[idx]);
    printf("\nDados do aluno atualizados com sucesso!\n");
}