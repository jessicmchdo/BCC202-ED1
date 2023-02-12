#include "duende.h"
#include <stdio.h>
#include <stdlib.h>



typedef enum { NAO=0, SIM } ESCALADO;

struct duende {
    char nome[20];
    int idade;
    ESCALADO escalado;
};

// Manter como especificado
void lerQuantidade(int *qtd) { 
    /* Le a quantidade de duendes que serao inseridos */
    /* PREENCHER AQUI */ 
    scanf("%d", qtd);

}

// Manter como especificado
Duende *alocaDuendes(int n) { 
    /* Aloca n de Duendes*/
    /* PREENCHER AQUI */ 

    Duende *duendes;
    duendes = malloc (n * sizeof(Duende));

    return duendes;
}

// Manter como especificado
Duende *copiaDuende(Duende *duendes, int i) {
    /* Aloca um novo duende baseado nos dados de um outro duende */ 
    /* PREENCHER AQUI */ 
    Duende *novoDuendes = (Duende*)malloc (sizeof(Duende));
    *novoDuendes = duendes[i];
    
    return novoDuendes;
}

// Manter como especificado
void desalocaDuendes(Duende **duendes){
    /* Desaloca um vetor ou um unico duende alocado dinamicamente */
    /* PREENCHER AQUI */ 

    free(*duendes);
}

// Manter como especificado
void lerDuendes(Duende *duendes, int n) {
    /* Lê os dados de n de Duendes */
    /* PREENCHER AQUI */ 
    for (int i = 0; i < n; i++)
    {
        scanf("%s", duendes[i].nome);
        scanf("%d", &duendes[i].idade);
    }
    

}

//ordem de complexidade: f(n) = n
// Manter como especificado
int proximoMaisVelho(Duende *duendes, int n) {
    /* Pega o próximo duende mais velho que ainda nao foi escalado */
    /* PREENCHER AQUI */ 

    int indice = 0;
    int maisVelho = 0;

    for (int i = 0; i < n; i++)
    {
        if (maisVelho < duendes[i].idade  && duendes[i].escalado == NAO)
        {
            indice = i;
            maisVelho = duendes[i].idade;
        }
        
    }
    return indice;    
}

// Manter como especificado
void escalarDuende(Duende *duendes, int index) {
    /* Dado um vetor de duendes, "seta" como escalado um duende */
    /* PREENCHER AQUI */ 

    duendes[index].escalado = 1;
}

// Manter como especificado
void printDuende(Duende *duende) {
    /* Imprime os dados de um duende e um \n no final */
    /* PREENCHER AQUI */

    printf("%s %d", duende->nome, duende->idade);
    printf("\n");
}