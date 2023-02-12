#include "lista.h"

void TLista_Inicia (TLista * pLista ) {
    pLista->pPrimeiro = (TCelula*) malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
}

int TLista_EhVazia ( TLista * pLista ) {
    return(pLista->pPrimeiro == pLista->pUltimo);
}

int TLista_Insere_Fim ( TLista *pLista, char x) {
    pLista->pUltimo->pProx = (TCelula*)malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->item.letra = x;
    pLista->pUltimo->pProx = NULL;
    return 1;
}

int TLista_Insere_Inicio ( TLista *pLista, char x){
    
    
    if (TLista_EhVazia(pLista))
    {
        pLista->pPrimeiro->pProx = (TCelula*) malloc(sizeof(TCelula));
        pLista->pPrimeiro->pProx->item.letra = x;
        pLista->pUltimo = pLista->pPrimeiro->pProx;
        pLista->pPrimeiro->pProx->pProx = NULL;
    }
    else{
        TCelula *pAux;
        pAux = pLista->pPrimeiro->pProx;
        pLista->pPrimeiro->pProx = (TCelula*) malloc(sizeof(TCelula));
        pLista->pPrimeiro->pProx->item.letra = x;
        pLista->pPrimeiro->pProx->pProx = NULL;
    }
    return 1;
}

void TLista_Esvazia (TLista * pLista){
     TCelula *pAux = pLista->pPrimeiro->pProx;
    TCelula *pAux2 = pAux;
    
    while(pAux != NULL){
        pAux2 = pAux->pProx;
        free(pAux);
        pAux = pAux2; 
    }

    free(pLista->pPrimeiro);
}

void TLista_Imprime ( TLista * pLista ){

    if(TLista_EhVazia(pLista)){
        return;
    }
    
    TCelula *pAux = pLista->pPrimeiro->pProx;
    
    while(pAux != NULL){
        printf("%c", pAux->item.letra);
        pAux = pAux->pProx;
    }
    printf("\n");
}

int list_append(TLista *pLista, TLista *pNovaLista){
    TCelula *pAux = pLista->pPrimeiro->pProx;
    pNovaLista->pUltimo->pProx = pAux;
    pNovaLista->pUltimo = pLista->pUltimo;
    return 1;
}