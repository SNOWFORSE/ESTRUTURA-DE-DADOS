#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTOS 100
#define TAM_STRING 50

typedef struct {
    char dados[MAX_ELEMENTOS][TAM_STRING];
    int quantidade;
} Lista;


void inicializarLista(Lista *l) {// aqui cria a lista sem o usuario precisar de uma opção para criar
    l->quantidade = 0;
}

int contarElementos(Lista *l) {
    return l->quantidade;
}

int inserirElemento(Lista *l, char *elemento) {
    if (l->quantidade >= MAX_ELEMENTOS) {
        return 0;
    }
    
    strcpy(l->dados[l->quantidade], elemento);
    l->quantidade++;
    return 1;
}

int retirarElemento(Lista *l, char *elemento) {
    int i, j;
    int posicao = -1;

    for (i = 0; i < l->quantidade; i++) {//for para retirar elementos da lista ferozmente
        if (strcmp(l->dados[i], elemento) == 0) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        return 0;
    }

    for (j = posicao; j < l->quantidade - 1; j++) {
        strcpy(l->dados[j], l->dados[j + 1]);
    }

    l->quantidade--;
    return 1;
}

void exibirLista(Lista *l) {
    if (l->quantidade == 0) {
        printf("\nA lista esta vazia!\n");//se o usuario abrir a lista sem colocar nenhuma string dentro cai nesse if
        return;
    }

    printf("\n--- CONTEUDO DA LISTA (%d elementos) ---\n", l->quantidade);
    for (int i = 0; i < l->quantidade; i++) {
        printf("[%d] %s\n", i + 1, l->dados[i]);
    }
    printf("---------------------------------------\n");
}

void removerQuebraLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {//começo do codigo boladao
    Lista minhaLista;
    inicializarLista(&minhaLista);

    int opcao;
    char buffer[TAM_STRING];

    do {
        printf("1 - Inserir Elemento\n");
        printf("2 - Retirar Elemento\n");
        printf("3 - Contar Elementos\n");
        printf("4 - Exibir Conteudo\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Digite a string a ser inserida: ");
                fgets(buffer, TAM_STRING, stdin);
                removerQuebraLinha(buffer);

                if (inserirElemento(&minhaLista, buffer)) {
                    printf("\"%s\" inserido com sucesso!\n", buffer);
                } else {
                    printf("Nao foi possivel inserir. Lista cheia!\n");
                }
                break;

            case 2:
                if (contarElementos(&minhaLista) == 0) {
                    printf("\nA lista ja esta vazia!\n");
                    break;
                }
                printf("Digite a string a ser removida: ");
                fgets(buffer, TAM_STRING, stdin);
                removerQuebraLinha(buffer);

                if (retirarElemento(&minhaLista, buffer)) {
                    printf("\"%s\" removido da lista!\n", buffer);
                } else {
                    printf("Elemento \"%s\" nao encontrado na lista.\n", buffer);
                }
                break;

            case 3:
                printf("\nTotal de elementos na lista: %d\n", contarElementos(&minhaLista));
                break;

            case 4:
                exibirLista(&minhaLista);
                break;

            case 0:
                printf("\nSaindo do programa!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
