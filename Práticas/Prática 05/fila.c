#include "fila.h"
#include "pilha.h"
#include <stdlib.h>

bool FilaInicia(Fila* pFila) {
    /* Preencher aqui */
    return ListaInicia(pFila);    
}

bool FilaEnfileira(Fila* pFila, Item item) {
    /* Preencher aqui */
    return ListaInsereFinal(pFila, item);
}

bool FilaDesinfeleira(Fila* pFila, Item* pItem) {
    /* Preencher aqui */
    return ListaRetiraPrimeiro(pFila, pItem);
}

bool FilaEhVazia(Fila* pFila) {
    /* Preencher aqui */
    return ListaEhVazia(pFila);
}

void FilaLibera(Fila* pFila) {
    /* Preencher aqui */
    ListaLibera(pFila);
    
}

bool FilaInverte(Fila* pFila) {
    /* Preencher aqui */
    if(FilaEhVazia(pFila)) return true;
    
    Pilha pilhaNova;
    PilhaInicia(&pilhaNova);

    Celula *pAux = pFila->cabeca->prox;

    while(pAux != NULL){
        PilhaPush(&pilhaNova, pAux->item);
        pAux = pAux->prox;
    }

   
    pFila->cabeca->prox = pilhaNova.cabeca->prox;
    pFila->ultimo = pilhaNova.ultimo;
    
    free(pilhaNova.cabeca);
    
    return true;
}
