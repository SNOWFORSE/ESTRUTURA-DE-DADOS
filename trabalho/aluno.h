#ifndef ALUNO_H
#define ALUNO_H

#define MAX_ALUNOS 40

typedef struct {
    char nome[41];
    int matricula; // ID do aluno
    float prova1;
    float prova2;
    float media;
    int faltas;
    char situacao[12];
} Aluno;

// Função auxiliar
void calcularSituacao(Aluno *aluno);

// Create (aluno_create.c)
void inserirAlunos(Aluno turma[], int *quantidade);

// Read (aluno_read.c)
void exibirDadosAluno(Aluno aluno);
void exibirAlunos(Aluno turma[], int quantidade);
int buscarAlunoPorMatricula(Aluno turma[], int quantidade, int matricula);
void buscarAlunoPorNome(Aluno turma[], int quantidade, const char *nome);
void consultarPorSituacao(Aluno turma[], int quantidade, const char *situacao);

// Update (aluno_update.c)
void alterarNotasAluno(Aluno turma[], int quantidade);
void alterarDadosAluno(Aluno turma[], int quantidade);

// Delete (aluno_delete.c)
void removerAluno(Aluno turma[], int *quantidade);

// Arquivos (aluno_arquivo.c)
void salvarDados(Aluno turma[], int quantidade);
void carregarDados(Aluno turma[], int *quantidade);

#endif