#include "lista.h"
#include <stdlib.h>

bool ListaInicia(Lista* pLista) {
    pLista->cabeca = (Celula*) malloc(sizeof(Celula));
    if (pLista->cabeca == NULL)
        return false;
    pLista->ultimo = pLista->cabeca;
    return true;
}

bool ListaEhVazia(Lista* pLista) {
    if(pLista->cabeca == pLista->ultimo)
        return true;
    return false;
}

bool ListaInsereFinal(Lista* pLista, Item item) {
    /* Preencher aqui */
    pLista->ultimo->prox = (Celula*)malloc(sizeof(Celula));
    pLista->ultimo = pLista->ultimo->prox;
    pLista->ultimo->item = item;
    pLista->ultimo->prox = NULL;
    return 1;
}

bool ListaInsereInicio(Lista* pLista, Item item) {
    /* Preencher aqui */

    Celula *pAux = pLista->cabeca->prox;
    pLista->cabeca->prox = (Celula*) malloc(sizeof(Celula));
    pLista->cabeca->prox->item = item;
    pLista->cabeca->prox->prox = pAux;

    return true;
}

bool ListaRetiraPrimeiro(Lista* pLista, Item* pItem) {
    /* Preencher aqui */
    if(ListaEhVazia(pLista))
        return false;
    
    Celula *pAux;
    pAux = pLista->cabeca->prox;
    *pItem = pAux->item;
    pLista->cabeca->prox = pAux->prox;
    free(pAux);
    return 1;
}

void ListaLibera(Lista* pLista) {
    /* Preencher aqui */

    if(ListaEhVazia(pLista)){
        free(pLista->cabeca);
        return;
    }
        
    Celula *pAux = pLista->cabeca->prox;
    Celula *pAux2;
    
    while(pAux != NULL){
        pAux2 = pAux->prox;
        free(pAux);
        pAux = pAux2; 
    }

    free(pLista->cabeca);
}