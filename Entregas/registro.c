#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 40

typedef struct {
    char nome[41];
    int matricula;
    float prova1;
    float prova2;
    float media; 
    int faltas;
    char situacao[12];
} Aluno;

void calcularSituacao(Aluno *aluno) {
    // Calcula a média das duas provas
    aluno->media = (aluno->prova1 + aluno->prova2) / 2.0;
    /* Verifica as duas condições para aprovação && significa "E".
       Então as duas condições precisam ser verdadeiras. */
    if (aluno->media >= 6.0 && aluno->faltas <= 20) {
        strcpy(aluno->situacao, "Aprovado");
    } else {
        // Se uma das condições não for atendida, está reprovado.
        strcpy(aluno->situacao, "Reprovado");
    }
}

void inserirAlunos(Aluno turma[], int *quantidade) {

    int n, i;

    // Verifica se a turma já chegou ao limite.
    if (*quantidade >= MAX_ALUNOS) {
        printf("\nA turma ja possui 40 alunos.\n");
        return;
    }

    // Pergunta quantos alunos serão inseridos.
    printf("\nQuantos alunos deseja inserir? ");
    scanf("%d", &n);
     
    // Verifica se a quantidade digitada é válida.
    if (n <= 0) {
        printf("Quantidade invalida.\n");
        return;
    }

    /* Verifica se a quantidade total ultrapassaria 40. */
    if (*quantidade + n > MAX_ALUNOS) {
        printf("Nao e possivel inserir tantos alunos. ");
        printf("A turma pode ter no maximo 40.\n");
        return;
    }

    for (i = 0; i < n; i++) {

        printf("\n--- Aluno %d ---\n", *quantidade + 1);

        // Lê o nome do aluno.
        printf("Nome: ");

        fgets(turma[*quantidade].nome, 41, stdin);

        turma[*quantidade].nome[
            strcspn(turma[*quantidade].nome, "\n")
        ] = '\0';

        // Lê a matrícula.
        printf("Matricula: ");
        scanf("%d", &turma[*quantidade].matricula);

        // Lê a nota da primeira prova.
        printf("Nota da Prova 1: ");
        scanf("%f", &turma[*quantidade].prova1);

        // Lê a nota da segunda prova.
        printf("Nota da Prova 2: ");
        scanf("%f", &turma[*quantidade].prova2);

        // Lê a quantidade de faltas.
        printf("Faltas: ");
        scanf("%d", &turma[*quantidade].faltas);

        // Retira o ENTER que ficou no teclado.
        getchar();

        /* Depois de ler os dados, chamamos a função calcularSituacao para calcular média e situação. */
        calcularSituacao(&turma[*quantidade]);

        /* Aumenta a quantidade de alunos cadastrados. */
        (*quantidade)++;
    }

    printf("\nAluno(s) inserido(s) com sucesso!\n");
}

void exibirAlunos(Aluno turma[], int quantidade) {

    int i;

    // Se não houver alunos, informa ao usuário.
    if (quantidade == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\n========== ALUNOS ==========\n");

    for (i = 0; i < quantidade; i++) {

        printf("\nAluno %d\n", i + 1);

        printf("Nome: %s\n", turma[i].nome);
        printf("Matricula: %d\n", turma[i].matricula);
        printf("Prova 1: %.2f\n", turma[i].prova1);
        printf("Prova 2: %.2f\n", turma[i].prova2);
        printf("Media: %.2f\n", turma[i].media);
        printf("Faltas: %d\n", turma[i].faltas);
        printf("Situacao: %s\n", turma[i].situacao);
    }
}

void salvarDados(Aluno turma[], int quantidade) {

    FILE *arquivo;
    int i;

    arquivo = fopen("alunos.dat", "wb");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo para salvar.\n");
        return;
    }

    fwrite(&quantidade, sizeof(int), 1, arquivo);

    for (i = 0; i < quantidade; i++) {
        fwrite(&turma[i], sizeof(Aluno), 1, arquivo);
    }

    // Fecha o arquivo depois de terminar a gravação.
    fclose(arquivo);

    printf("\nDados salvos com sucesso no arquivo alunos.dat!\n");
}

void carregarDados(Aluno turma[], int *quantidade) {

    FILE *arquivo;
    int i;

    arquivo = fopen("alunos.dat", "rb");

    if (arquivo == NULL) {
        printf("\nNao foi possivel abrir o arquivo. ");
        printf("Nenhum dado carregado.\n");
        return;
    }

    fread(quantidade, sizeof(int), 1, arquivo);

    /* Segurança: verifica se o arquivo possui mais de 40 alunos. */
    if (*quantidade > MAX_ALUNOS) {
        printf("\nArquivo possui uma quantidade invalida de alunos.\n");

        *quantidade = 0;

        fclose(arquivo);
        return;
    }

    for (i = 0; i < *quantidade; i++) {
        fread(&turma[i], sizeof(Aluno), 1, arquivo);
    }

    // Fecha o arquivo.
    fclose(arquivo);

    printf("\nDados carregados com sucesso!\n");
}

int main() {

    Aluno turma[MAX_ALUNOS];

    int quantidade = 0;

    // Guarda a opção escolhida no menu.
    int opcao;

    do {

        printf("\n========== MENU ==========\n");
        printf("1 - Inserir alunos\n");
        printf("2 - Exibir alunos\n");
        printf("3 - Salvar dados\n");
        printf("4 - Carregar dados\n");
        printf("5 - Sair\n");
        printf("==========================\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                // Chama a função para cadastrar alunos.
                inserirAlunos(turma, &quantidade);
                break;

            case 2:
                // Chama a função para exibir os alunos.
                exibirAlunos(turma, quantidade);
                break;

            case 3:
                // Salva os alunos no arquivo.
                salvarDados(turma, quantidade);
                break;

            case 4:
                // Carrega os alunos do arquivo.
                carregarDados(turma, &quantidade);
                break;

            case 5:
                // Encerra o programa.
                printf("\nPrograma encerrado.\n");
                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 5);

    return 0;
}
