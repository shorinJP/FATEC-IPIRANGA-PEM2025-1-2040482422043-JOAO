/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: ordenar dados com o BubbleSort   *
* Data - 15/05/2025                                      * 
* Autor: João Pedro Alves dos Santos                     *
*--------------------------------------------------------*/

#include <stdio.h>

void bubbleSort(int vetor[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
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

    bubbleSort(vetor, n);

    printf("Números ordenados (Bubble Sort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
