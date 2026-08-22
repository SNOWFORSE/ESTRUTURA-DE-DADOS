#include <stdio.h>
#include "produto.h"
#include <stdlib.h>

// Lê o arquivo e retorna um array dinâmico
Produto* ler_produtos(const char *filename, int *quantidade_lida) {
    FILE *arquivo = fopen(filename, "rb");
    if (arquivo == NULL) {
        *quantidade_lida = 0;
        return NULL;
    }
    // Descobre o tamanho total do arquivo em bytes
    fseek(arquivo, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivo);
    rewind(arquivo); // Volta o cursor para o início do arquivo

    // Calcula a quantidade de produtos existentes no arquivo
    *quantidade_lida = tamanho_arquivo / sizeof(Produto);

    if (*quantidade_lida == 0) {
        fclose(arquivo);
        return NULL;
    }

    // Aloca espaço de memoria para o array
    Produto *array_produtos = (Produto*) malloc((*quantidade_lida) * sizeof(Produto));
    if (array_produtos == NULL) {
        printf("Erro: Memoria insuficiente.\n");
        fclose(arquivo);
        *quantidade_lida = 0;
        return NULL;
    }

    printf("1 - Memória salva\n");
    // Lê todos os produtos de uma vez para dentro do array
    fread(array_produtos, sizeof(Produto), *quantidade_lida, arquivo);
    printf("2 - Conteúdo do arquivo salvo no array");
    fclose(arquivo);

    return array_produtos;
}

void imprime_estoque(Produto *produtos, int tamanho) {
    printf("\n---ESTOQUE--\n");
    if (produtos==NULL){
        printf("estoque vazio");
        return 0;
    }
    for(int i=0;i < tamanho; i++){
        printf("ID: %d, Nome: %s, Valor: %.2f, Quantidade: %d\n", 
            produtos[i].id,
            produtos[i].nome,
            produtos[i].valor,
            produtos[i].quantidade);
    }
}

int main(){
  int quantidade_lida = 0;
  Produto *p = ler_produtos (ARQUIVO_ESTOQUE, &quantidade_lida);
  imprime_estoque(p, quantidade_lida);

  if(p != NULL){
    free(p);
  }

}
