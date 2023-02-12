#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int carta;
} TItem;

typedef struct celula {
    TItem item;
    struct celula *pProx;
} TCelula;

typedef struct {
    TCelula *pPrimeiro, *pUltimo;
} TLista;

// inicializa as variáveis da lista
void TLista_Inicia(TLista *pLista);

// retorna se a lista está vazia
int TLista_EhVazia(TLista *pLista);

// insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x);

// retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX);

// imprime os elementos da lista
void TLista_Imprime(TLista *pLista);

// remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista);

int main() {

    int n, i, contador;
    TLista pLista, descartadas;
    TItem numero;

    while (scanf("%d", &n), n) {

        TLista_Inicia(&pLista);

        for(i = 1; i <= n; i++) {
            numero.carta = i;
            TLista_InsereFinal(&pLista, numero);
        }

        contador = n;

        TLista_Inicia(&descartadas);

        while(contador >= 2) {

            // printf("\n---TESTE---\n");

            TLista_RetiraPrimeiro(&pLista, &numero);
            TLista_InsereFinal(&descartadas, numero);

            // TLista_Imprime(&pLista);

            TLista_RetiraPrimeiro(&pLista, &numero);
            TLista_InsereFinal(&pLista, numero);

            contador--;

        }

        printf ("Discarded cards: ");
        TLista_Imprime(&descartadas);
        TLista_Esvazia(&descartadas);

        printf("Remaining card: ");
        TLista_Imprime(&pLista);
        TLista_Esvazia(&pLista);
    }

    return 0;
}

void TLista_Inicia(TLista *pLista) {

    pLista->pPrimeiro = (TCelula*) malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
}

int TLista_EhVazia(TLista *pLista) {
    return (pLista->pPrimeiro == pLista->pUltimo);
}

int TLista_InsereFinal(TLista *pLista, TItem x) {

    pLista->pUltimo->pProx = (TCelula*) malloc(sizeof(TCelula));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx = NULL;

    return 1;
}

int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {

    if(TLista_EhVazia(pLista)) {
        return 0;
    }

    TCelula *pAux;
    pAux = pLista->pPrimeiro->pProx;
    *pX = pAux->item;

    pLista->pPrimeiro->pProx = pAux->pProx;

    free(pAux);

    if(pLista->pPrimeiro->pProx == NULL) {
        pLista->pUltimo = pLista->pPrimeiro;
    }

    return 1;
}

void TLista_Imprime(TLista *pLista) {

    if(TLista_EhVazia(pLista)) {
        return;
    }

    TCelula *pAux = pLista->pPrimeiro->pProx;

    while(pAux != NULL) {

        printf("%d", pAux->item.carta);

        if(pAux->pProx != NULL) {
            printf(", ");
        }

        pAux = pAux->pProx;
    }

    printf("\n");
}

void TLista_Esvazia(TLista *pLista) {

    TCelula *pAux = pLista->pPrimeiro->pProx;
    TCelula *pAux2 = pAux;

    while(pAux != NULL) {

        pAux2 = pAux2->pProx;

        free(pAux);

        pAux = pAux2;
    }

    free(pLista->pPrimeiro);
}