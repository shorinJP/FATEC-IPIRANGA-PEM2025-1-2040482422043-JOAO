/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Ordenar dados usando o Insertion *
* Data - 15/05/2025                                      * 
* Autor: João Pedro Alves dos Santos                     *
*--------------------------------------------------------*/

#include <stdio.h>

void insertionSort(int vetor[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

int main() {
    int n;

    printf("Quantos números deseja ordenar? ");
    scanf("%d", &n);

    int vetor[n];

    printf("Digite %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    insertionSort(vetor, n);

    printf("Números ordenados (Insertion Sort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
