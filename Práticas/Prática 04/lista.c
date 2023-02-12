#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {
    pLista->pPrimeiro = (TCelula*) malloc (sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
//semelhante ao visto em aula
}

//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
//semelhante ao visto em aula
return(pLista->pPrimeiro == pLista->pUltimo);
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {
//semelhante ao visto em aula
    pLista->pUltimo->pProx = (TCelula*)malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx = NULL;
    return 1;
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
//semelhante ao visto em aula
    if(TLista_EhVazia(pLista)){
        return 0;
    }

    TCelula *pAux;
    pAux = pLista->pPrimeiro->pProx;
    *pX = pAux->item;
    pLista->pPrimeiro->pProx = pAux->pProx;
    free(pAux);
    return 1;
}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {
//semelhante ao visto em aula
    if(TLista_EhVazia(pLista)){
        return;
    }
    
    TCelula *pAux = pLista->pPrimeiro->pProx;
    while(pAux != NULL){
        printf("%s ", pAux->item.nome);
        pAux = pAux->pProx;
    }
    printf("\n");
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {
//preencher
    TCelula *pAux = pLista->pPrimeiro->pProx;
    TCelula *pAux2;
    
    while(pAux != NULL){
        pAux2 = pAux->pProx;
        free(pAux);
        pAux = pAux2; 
    }

    free(pLista->pPrimeiro);
}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){
//preencher
    TCelula *pAux = pLista2->pPrimeiro->pProx;
    pLista1->pUltimo->pProx = pAux;
    pLista1->pUltimo = pLista2->pUltimo;

    free(pLista2->pPrimeiro);
}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
//preencher
    
    TCelula *pAux = pLista1->pPrimeiro;

    while (strcmp(pAux->pProx->item.nome, str))
    {
        pAux = pAux->pProx;
    }
    TCelula *pAux2 = pAux->pProx;
    pAux->pProx = pLista2->pPrimeiro->pProx;
    pLista2->pUltimo->pProx = pAux2;

    free(pLista2->pPrimeiro);
}
