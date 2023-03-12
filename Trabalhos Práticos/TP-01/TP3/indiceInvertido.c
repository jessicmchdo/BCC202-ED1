#include "indiceInvertido.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inicia(IndiceInvertido indiceInvertido){
    
    for (int i = 0; i < M; i++)
        memcpy(indiceInvertido[i].chave, VAZIO, N);
    
}

//insere um documento baseado na chave no TAD IndiceInvertido.
bool insereDocumento(IndiceInvertido indiceInvertido, Chave chave, NomeDocumento nomeDocumento){

    int indice = h(chave, M);
    if (chaveEhVazia(indiceInvertido[indice].chave))
        return false;


    while(strcmp(indiceInvertido[indice % M].chave, chave)){
        indice++;
        printf("Loop INFINITO INSERE DOCUMENTO\n");

    }
    
    strcpy(indiceInvertido[indice].documentos[indiceInvertido[indice % M].n++], nomeDocumento);    
    
    return true;
}

//retorna o índice de uma chave no TAD IndiceInvertido
int busca(IndiceInvertido indiceInvertido, Chave x){
    int j = 0;
    int ini = h(x, M); //?

    while (strcmp(indiceInvertido[(ini + j) % M].chave, VAZIO) != 0 &&
            strcmp(indiceInvertido[(ini + j) % M].chave, x) != 0 &&
            j < M)
        j++;
    
    if (strcmp(indiceInvertido[(ini + j) % M].chave, x) == 0)
        return (ini + j) % M;
    
    return -1;
}

//baseado em uma ou mais chaves, retorna o nome dos documentos que contêm todas as
//chaves no índice invertido presente no TAD IndiceInvertido.
int consulta(IndiceInvertido indiceInvertido, Chave* x, int , NomeDocumento* nomeDocumento);

//imprime o índice invertido presente no TAD IndiceInvertido.
void imprime(IndiceInvertido indiceInvertido){
    
    for( int i = 0; i < M; i++){

        if(chaveEhVazia(indiceInvertido[i].chave))
            continue;

        printf("%s", indiceInvertido[i].chave);
        printf(" - ");

        for( int j = 0; j < indiceInvertido[i].n; j++){
            if ( j <  indiceInvertido[i].n - 1)
                printf("%s ", indiceInvertido[i].documentos[j]);
            else
                printf("%s", indiceInvertido[i].documentos[j]);
        }

        printf("\n");

    }

}

void sort(NomeDocumento* nomeDocumento, int);

void adicionarChaves(IndiceInvertido indiceInvertido, Chave *chaves, int qtdChaves){


    for (int i = 0; i < qtdChaves; i++){

        bool chaveDuplicada = false;

        int indice = h(chaves[i], M);
        
        while(!chaveEhVazia(indiceInvertido[indice % M].chave)){

            if(!strcmp(indiceInvertido[indice % M].chave, chaves[i])){
                chaveDuplicada = true;
                break;
            }

            indice++;
        }

        if(chaveDuplicada)
            continue;

        strcpy(indiceInvertido[indice % M].chave, chaves[i]);
    }
    
}

//verifica se a chave é vazia
int chaveEhVazia(Chave chave){

    if(!strcmp(chave, VAZIO))
        return 1;

    return 0;
}