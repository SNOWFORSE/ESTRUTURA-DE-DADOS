#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTOS 100
#define TAM_STRING 50

// Estrutura que define a Lista
typedef struct {
    char dados[MAX_ELEMENTOS][TAM_STRING];
    int quantidade;
} Lista;

// 3. Criar / Inicializar Lista
void criarLista(Lista *l) {
    l->quantidade = 0;
    printf("\n[SISTEMA] Lista criada/inicializada com sucesso!\n");
}

// 4. Contar elementos da lista
int contarElementos(Lista *l) {
    return l->quantidade;
}

// 1. Inserir elemento (no final da lista)
int inserirElemento(Lista *l, const char *elemento) {
    if (l->quantidade >= MAX_ELEMENTOS) {
        return 0; // FALHA: Lista cheia
    }
    
    strcpy(l->dados[l->quantidade], elemento);
    l->quantidade++;
    return 1; // SUCESSO
}

// 2. Retirar elemento por valor (remove a primeira ocorrência encontrada)
int retirarElemento(Lista *l, const char *elemento) {
    int i, j;
    int posicao = -1;

    // Busca o elemento na lista
    for (i = 0; i < l->quantidade; i++) {
        if (strcmp(l->dados[i], elemento) == 0) {
            posicao = i;
            break;
        }
    }

    // Elemento não encontrado
    if (posicao == -1) {
        return 0; // FALHA
    }

    // Desloca os elementos à esquerda para preencher o espaço mantendo a ordem
    for (j = posicao; j < l->quantidade - 1; j++) {
        strcpy(l->dados[j], l->dados[j + 1]);
    }

    l->quantidade--;
    return 1; // SUCESSO
}

// 5. Exibir o conteúdo da lista
void exibirLista(Lista *l) {
    if (l->quantidade == 0) {
        printf("\n---> A lista esta vazia.\n");
        return;
    }

    printf("\n--- CONTEUDO DA LISTA (%d elementos) ---\n", l->quantidade);
    for (int i = 0; i < l->quantidade; i++) {
        printf("[%d] %s\n", i + 1, l->dados[i]);
    }
    printf("----------------------------------------\n");
}

// Função auxiliar para limpar a quebra de linha do fgets
void removerQuebraLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Programa Principal (Interface com o usuário)
int main() {
    Lista minhaLista;
    int opcao;
    char buffer[TAM_STRING];
    int listaCriada = 0;

    do {
        printf("\n================ MENU ================\n");
        printf("1. Criar / Reinicializar Lista\n");
        printf("2. Inserir Elemento\n");
        printf("3. Retirar Elemento\n");
        printf("4. Contar Elementos\n");
        printf("5. Exibir Conteudo\n");
        printf("0. Sair\n");
        printf("======================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o caractere '\n' do buffer do teclado

        switch (opcao) {
            case 1:
                criarLista(&minhaLista);
                listaCriada = 1;
                break;

            case 2:
                if (!listaCriada) {
                    printf("\n[AVISO] Crie a lista primeiro (Opcao 1)!\n");
                    break;
                }
                printf("Digite a string a ser inserida: ");
                fgets(buffer, TAM_STRING, stdin);
                removerQuebraLinha(buffer);

                if (inserirElemento(&minhaLista, buffer)) {
                    printf("[SUCESSO] \"%s\" inserido com sucesso!\n", buffer);
                } else {
                    printf("[ERRO] Nao foi possivel inserir. Lista cheia!\n");
                }
                break;

            case 3:
                if (!listaCriada) {
                    printf("\n[AVISO] Crie a lista primeiro (Opcao 1)!\n");
                    break;
                }
                if (contarElementos(&minhaLista) == 0) {
                    printf("\n[AVISO] A lista ja esta vazia!\n");
                    break;
                }
                printf("Digite a string a ser removida: ");
                fgets(buffer, TAM_STRING, stdin);
                removerQuebraLinha(buffer);

                if (retirarElemento(&minhaLista, buffer)) {
                    printf("[SUCESSO] \"%s\" removido da lista!\n", buffer);
                } else {
                    printf("[ERRO] Elemento \"%s\" nao encontrado na lista.\n", buffer);
                }
                break;

            case 4:
                if (!listaCriada) {
                    printf("\n[AVISO] Crie a lista primeiro (Opcao 1)!\n");
                    break;
                }
                printf("\nTotal de elementos na lista: %d\n", contarElementos(&minhaLista));
                break;

            case 5:
                if (!listaCriada) {
                    printf("\n[AVISO] Crie a lista primeiro (Opcao 1)!\n");
                    break;
                }
                exibirLista(&minhaLista);
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
