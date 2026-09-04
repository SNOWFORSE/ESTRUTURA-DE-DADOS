#include <stdio.h>
#include "aluno.h"

void removerAluno(Aluno turma[], int *quantidade) {
    int matricula, idx, i;

    printf("\nDigite a matricula (ID) do aluno que deseja remover: ");
    scanf("%d", &matricula);

    idx = buscarAlunoPorMatricula(turma, *quantidade, matricula);

    if (idx == -1) {
        printf("\nAluno nao encontrado!\n");
        return;
    }

    for (i = idx; i < *quantidade - 1; i++) {
        turma[i] = turma[i + 1];
    }

    (*quantidade)--;
    printf("\nAluno removido com sucesso!\n");
}