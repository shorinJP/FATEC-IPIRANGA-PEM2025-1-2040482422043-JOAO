/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: xxxxxxxxxxxxxxxxxx               *
* Data - dd/mm/aaaa                                      * 
* Autor: xxxxxxxxxxxxxxxxx;xxxxxxxxxxxxxxxxx             *
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

void inicializarEstoque(Produto (*estoque)[GONDOLAS]);
void estocarProduto(Produto (*estoque)[GONDOLAS], int rua, int gondola, char *codigo);
void retirarProduto(Produto (*estoque)[GONDOLAS], int rua, int gondola);
void exibirEstoque(Produto (*estoque)[GONDOLAS]);

int main() {
    Produto estoque[RUAS][GONDOLAS];
    inicializarEstoque(estoque);
    
    estocarProduto(estoque, 0, 9, "S123");
    estocarProduto(estoque, 1, 5, "A456");
    retirarProduto(estoque, 0, 9);
    exibirEstoque(estoque);
    
    return 0;
}

void inicializarEstoque(Produto (*estoque)[GONDOLAS]) {
    for (int i = 0; i < RUAS; i++) {
        for (int j = 0; j < GONDOLAS; j++) {
            estoque[i][j].ocupado = 0;
            strcpy(estoque[i][j].codigo, "");
        }
    }
}

void estocarProduto(Produto (*estoque)[GONDOLAS], int rua, int gondola, char *codigo) {
    Produto *p = &estoque[rua][gondola];
    if (p->ocupado) {
        printf("Erro: A gôndola %d da Rua %d já está ocupada por %s.\n", gondola + 1, rua + 1, p->codigo);
    } else {
        strcpy(p->codigo, codigo);
        p->ocupado = 1;
        printf("Produto %s estocado na Rua %d, Gôndola %d.\n", codigo, rua + 1, gondola + 1);
    }
}

void retirarProduto(Produto (*estoque)[GONDOLAS], int rua, int gondola) {
    Produto *p = &estoque[rua][gondola];
    if (!p->ocupado) {
        printf("Erro: A gôndola %d da Rua %d está vazia.\n", gondola + 1, rua + 1);
    } else {
        printf("Produto %s retirado da Rua %d, Gôndola %d.\n", p->codigo, rua + 1, gondola + 1);
        p->ocupado = 0;
        strcpy(p->codigo, "");
    }
}

void exibirEstoque(Produto (*estoque)[GONDOLAS]) {
    printf("\nEstado Atual do Estoque:\n");
    for (int i = 0; i < RUAS; i++) {
        printf("Rua %d:\n", i + 1);
        for (int j = 0; j < GONDOLAS; j++) {
            Produto *p = &estoque[i][j];
            printf("Gôndola %d: %s\n", j + 1, p->ocupado ? p->codigo : "Vazia");
        }
    }
}
