#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

// Manter como especificado
int *alocaVetor(int *vetor, int n)
{
    vetor = malloc(n * sizeof(int));

    return vetor;
}

// Manter como especificado
int *desalocaVetor(int *vetor)
{
    free(vetor);
    return vetor;
}

void ordenacao(int *vetor, int n, int *movimentos)
{   
    *movimentos = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (vetor[j] < vetor[j- 1])
            {
                int aux = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j-1] = aux;
                *movimentos = *movimentos + 1;
            }
        }
        if (*movimentos == 0)
        {
            return;
        }
        
    }
}
