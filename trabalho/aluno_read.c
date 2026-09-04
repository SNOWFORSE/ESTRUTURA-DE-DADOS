#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "aluno.h"

void exibirDadosAluno(Aluno aluno) {
    printf("\n----------------------------------\n");
    printf("Matricula (ID): %d\n", aluno.matricula);
    printf("Nome          : %s\n", aluno.nome);
    printf("Prova 1       : %.2f\n", aluno.prova1);
    printf("Prova 2       : %.2f\n", aluno.prova2);
    printf("Media         : %.2f\n", aluno.media);
    printf("Faltas        : %d\n", aluno.faltas);
    printf("Situacao      : %s\n", aluno.situacao);
    printf("----------------------------------\n");
}

void exibirAlunos(Aluno turma[], int quantidade) {
    int i;

    if (quantidade == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\n========== LISTA DE ALUNOS ==========\n");
    for (i = 0; i < quantidade; i++) {
        exibirDadosAluno(turma[i]);
    }
}

int buscarAlunoPorMatricula(Aluno turma[], int quantidade, int matricula) {
    int i;
    for (i = 0; i < quantidade; i++) {
        if (turma[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

void buscarAlunoPorNome(Aluno turma[], int quantidade, const char *nome) {
    int i, encontrados = 0;

    for (i = 0; i < quantidade; i++) {
        if (strstr(turma[i].nome, nome) != NULL) {
            exibirDadosAluno(turma[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("\nNenhum aluno encontrado com o nome informado.\n");
    }
}

void consultarPorSituacao(Aluno turma[], int quantidade, const char *situacao) {
    int i, encontrados = 0;

    printf("\n========== ALUNOS: %sS ==========\n", situacao);
    for (i = 0; i < quantidade; i++) {
        if (strcasecmp(turma[i].situacao, situacao) == 0) {
            exibirDadosAluno(turma[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("\nNenhum aluno cadastrado com a situacao '%s'.\n", situacao);
    }
}