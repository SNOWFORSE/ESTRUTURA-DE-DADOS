/*Faça um programa que  implementa uma lista com vetores de strings, conforme o exemplo visto em sala, com as seguintes operações:
1. Inserir elemento 
2. Retirar Elemento
3. Criar Lista
4. Contar elementos da lista
5. Exibir o conteúdo da lista

A interface com o usuário deve ser feita pelo programa principal, passando os parâmetros para as funções que implementam as operações sobre a lista.
Enviar o arquivo fonte em C, funcionando.
*/

#include <stdio.h>

int main (){

    int op;
    int opcao;
    int item;

    do {
        printf("==========================");
        printf("1 - Inserir um Item na Lista");
        printf("2 - Imprimir Lista");
        printf("3 - Retirar Item da Lista");
        printf("4 - Tamanho da Lista");
        printf("0 - Encerrar Programa\n");
        printf("\nOpção: ");
        printf("===========================");
        sscanf(opcao, "%d", &op);
    }while(op);
    
    switch(op){
        case 1:
            //insereLista
            break;
        case 2:
            //imprimirLista
            break;
        case 3:
            break;
        case 4:
    }
}
