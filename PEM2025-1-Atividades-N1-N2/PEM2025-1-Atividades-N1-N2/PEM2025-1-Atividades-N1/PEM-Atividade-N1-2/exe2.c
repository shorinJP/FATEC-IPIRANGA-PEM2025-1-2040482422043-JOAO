/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: controlar estoque                *
* Data - 23/03/2025                                      * 
* Autor: João Pedro Alves dos Santos                     *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define RUAS 3
#define GONDOLAS 10
#define PRODUTO_MAX 20

typedef struct {
    char codigo[10];
    int ocupado;
} Produto;

Produto estoque[RUAS][GONDOLAS];

void estocarProduto(int rua, int gondola, char codigo[]) {
    if (estoque[rua][gondola].ocupado) {
        printf("Erro: A gôndola %d da Rua %d já está ocupada por %s.\n", gondola + 1, rua + 1, estoque[rua][gondola].codigo);
    } else {
        strcpy(estoque[rua][gondola].codigo, codigo);
        estoque[rua][gondola].ocupado = 1;
        printf("Produto %s estocado na Rua %d, Gôndola %d.\n", codigo, rua + 1, gondola + 1);
    }
}

void retirarProduto(int rua, int gondola) {
    if (!estoque[rua][gondola].ocupado) {
        printf("Erro: A gôndola %d da Rua %d está vazia.\n", gondola + 1, rua + 1);
    } else {
        printf("Produto %s retirado da Rua %d, Gôndola %d.\n", estoque[rua][gondola].codigo, rua + 1, gondola + 1);
        estoque[rua][gondola].ocupado = 0;
        strcpy(estoque[rua][gondola].codigo, "");
    }
}

void exibirEstoque() {
    printf("\nEstado Atual do Estoque:\n");
    for (int i = 0; i < RUAS; i++) {
        printf("Rua %d:\n", i + 1);
        for (int j = 0; j < GONDOLAS; j++) {
            if (estoque[i][j].ocupado) {
                printf("Gôndola %d: %s\n", j + 1, estoque[i][j].codigo);
            } else {
                printf("Gôndola %d: Vazia\n", j + 1);
            }
        }
    }
}

int main() {
    memset(estoque, 0, sizeof(estoque));
    
    estocarProduto(0, 9, "S123");
    estocarProduto(1, 5, "A456");
    retirarProduto(0, 9);
    exibirEstoque();
    
    return 0;
}
