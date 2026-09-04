#include <stdio.h>
#include "aluno.h"

void salvarDados(Aluno turma[], int quantidade) {
    FILE *arquivo = fopen("alunos.dat", "wb");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo para salvar.\n");
        return;
    }

    fwrite(&quantidade, sizeof(int), 1, arquivo);
    fwrite(turma, sizeof(Aluno), quantidade, arquivo);

    fclose(arquivo);
    printf("\nDados salvos com sucesso no arquivo alunos.dat!\n");
}

void carregarDados(Aluno turma[], int *quantidade) {
    FILE *arquivo = fopen("alunos.dat", "rb");

    if (arquivo == NULL) {
        printf("\nNenhum arquivo 'alunos.dat' encontrado para carregar.\n");
        return;
    }

    fread(quantidade, sizeof(int), 1, arquivo);

    if (*quantidade > MAX_ALUNOS) {
        printf("\nErro: quantidade registrada no arquivo excede o limite.\n");
        *quantidade = 0;
        fclose(arquivo);
        return;
    }

    fread(turma, sizeof(Aluno), *quantidade, arquivo);

    fclose(arquivo);
    printf("\nDados carregados com sucesso!\n");
}