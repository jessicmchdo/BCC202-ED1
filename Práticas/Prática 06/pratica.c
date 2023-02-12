#include "ordenacao.h"
#include <stdio.h>

int main ()
{

	int i, n, movimentos = 0;
	while(scanf("%d", &n), n)
	{
		//alocar o vetor
		int *vetor = alocaVetor(vetor, n);
		//preencher o 
		for ( i = 0; i < n; i++)
		{
			scanf("%d", &vetor[i]);
		}
		//ordenar o vetor e determinar o número de movimentos
		ordenacao(vetor, n, &movimentos);
		//imprimir o resultado
		if (movimentos % 2 != 0)
		{
			//printf("Movimentos = %d\n", movimentos);
			printf("Marcelo\n");
		} else {
			//printf("Movimentos = %d\n", movimentos);
			printf("Carlos\n");
		}
		
		//desalocar o vetor
		desalocaVetor(vetor);
	}

	return 0;
}
