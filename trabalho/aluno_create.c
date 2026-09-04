#include <stdio.h>
#include <string.h>
#include "aluno.h"

void calcularSituacao(Aluno *aluno) {
    aluno->media = (aluno->prova1 + aluno->prova2) / 2.0;

    if (aluno->media >= 6.0 && aluno->faltas <= 20) {
        strcpy(aluno->situacao, "Aprovado");
    } else {
        strcpy(aluno->situacao, "Reprovado");
    }
}

void inserirAlunos(Aluno turma[], int *quantidade) {
    int n, i;

    if (*quantidade >= MAX_ALUNOS) {
        printf("\nA turma ja possui o limite de %d alunos.\n", MAX_ALUNOS);
        return;
    }

    printf("\nQuantos alunos deseja inserir? ");
    scanf("%d", &n);
    getchar();

    if (n <= 0) {
        printf("Quantidade invalida.\n");
        return;
    }

    if (*quantidade + n > MAX_ALUNOS) {
        printf("Nao e possivel inserir tantos alunos. Vagas restantes: %d\n", MAX_ALUNOS - *quantidade);
        return;
    }

    for (i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", *quantidade + 1);

        printf("Nome: ");
        fgets(turma[*quantidade].nome, 41, stdin);
        turma[*quantidade].nome[strcspn(turma[*quantidade].nome, "\n")] = '\0';

        printf("Matricula (ID): ");
        scanf("%d", &turma[*quantidade].matricula);

        printf("Nota da Prova 1: ");
        scanf("%f", &turma[*quantidade].prova1);

        printf("Nota da Prova 2: ");
        scanf("%f", &turma[*quantidade].prova2);

        printf("Faltas: ");
        scanf("%d", &turma[*quantidade].faltas);
        getchar();

        calcularSituacao(&turma[*quantidade]);

        (*quantidade)++;
    }

    printf("\nAluno(s) inserido(s) com sucesso!\n");
}