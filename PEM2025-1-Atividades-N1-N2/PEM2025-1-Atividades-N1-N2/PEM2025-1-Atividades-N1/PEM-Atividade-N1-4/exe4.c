/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa:Gerenciando uma Árvore de         *
* Diretórios                                             *
* Data - 23/03/2025                                      * 
* Autor: João Pedro Alves dos Santos                     *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void listar_diretorios(const char *caminho, int nivel) {
    struct dirent *entrada;
    DIR *diretorio = opendir(caminho);

    if (diretorio == NULL) {
        perror("Erro ao abrir diretório");
        return;
    }

    while ((entrada = readdir(diretorio)) != NULL) {
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0) {
            continue;
        }

        for (int i = 0; i < nivel; i++) {
            printf("  ");
        }
        printf("%s\n", entrada->d_name);

        if (entrada->d_type == DT_DIR) {
            char novo_caminho[1024];
            snprintf(novo_caminho, sizeof(novo_caminho), "%s/%s", caminho, entrada->d_name);
            listar_diretorios(novo_caminho, nivel + 1);
        }
    }

    closedir(diretorio);
}

int main() {
    const char *caminho_inicial = "./";
    listar_diretorios(caminho_inicial, 0);
    return 0;
}
