#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATOS 50
#define TOP_CANDIDATOS 15

typedef struct {
    char nome[100];
    float notasPE[4];
    float notasAC[5];
    float notasPP[10];
    float notasEB[3];
    float notaFinal;
} Candidato;

float calcularSomaCentral(float notas[], int tamanho) {
    float soma = 0.0, max = notas[0], min = notas[0];
    int i;
    
    for (i = 0; i < tamanho; i++) {
        soma += notas[i];
        if (notas[i] > max) max = notas[i];
        if (notas[i] < min) min = notas[i];
    }
    
    soma -= (max + min);
    return soma;
}

int comparar(const void *a, const void *b) {
    Candidato *c1 = (Candidato *)a;
    Candidato *c2 = (Candidato *)b;
    return (c2->notaFinal > c1->notaFinal) - (c1->notaFinal > c2->notaFinal);
}

int main() {
    Candidato candidatos[MAX_CANDIDATOS];
    int numCandidatos, i, j;

    printf("Quantos candidatos deseja cadastrar? (máx %d): ", MAX_CANDIDATOS);
    scanf("%d", &numCandidatos);
    if (numCandidatos > MAX_CANDIDATOS) numCandidatos = MAX_CANDIDATOS;

    for (i = 0; i < numCandidatos; i++) {
        printf("\nDigite o nome do candidato %d: ", i + 1);
        scanf(" %[^"]s", candidatos[i].nome);
        
        printf("\nDigite as 4 notas da Prova Escrita: ");
        for (j = 0; j < 4; j++) scanf("%f", &candidatos[i].notasPE[j]);
        
        printf("Digite as 5 notas da Análise Curricular: ");
        for (j = 0; j < 5; j++) scanf("%f", &candidatos[i].notasAC[j]);
        
        printf("Digite as 10 notas da Prova Prática: ");
        for (j = 0; j < 10; j++) scanf("%f", &candidatos[i].notasPP[j]);
        
        printf("Digite as 3 notas da Entrevista: ");
        for (j = 0; j < 3; j++) scanf("%f", &candidatos[i].notasEB[j]);
        
        float PE = calcularSomaCentral(candidatos[i].notasPE, 4);
        float AC = calcularSomaCentral(candidatos[i].notasAC, 5);
        float PP = calcularSomaCentral(candidatos[i].notasPP, 10);
        float EB = calcularSomaCentral(candidatos[i].notasEB, 3);
        
        candidatos[i].notaFinal = (PE * 0.3) + (AC * 0.1) + (PP * 0.4) + (EB * 0.2);
    }

    qsort(candidatos, numCandidatos, sizeof(Candidato), comparar);

    printf("\nTop %d candidatos:\n", TOP_CANDIDATOS);
    for (i = 0; i < (numCandidatos < TOP_CANDIDATOS ? numCandidatos : TOP_CANDIDATOS); i++) {
        printf("%d. %s - Nota Final: %.2f\n", i + 1, candidatos[i].nome, candidatos[i].notaFinal);
    }

    return 0;
}
