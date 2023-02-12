#include "pilha.h"

bool PilhaInicia(Pilha* pPilha) {
    /* Preencher aqui */
    return ListaInicia(pPilha);
}
/* insere no mesmo lugar que remove */
bool PilhaPush(Pilha* pPilha, Item item) {
    /* Preencher aqui */
    return ListaInsereInicio(pPilha, item);

}
/* retira do mesmo lugar que insere */
bool PilhaPop(Pilha* pPilha, Item* pItem) {
    /* Preencher aqui */
    return ListaRetiraPrimeiro(pPilha, pItem);
 }

bool PilhaEhVazia(Pilha* pPilha) {
    /* Preencher aqui */
    return ListaEhVazia(pPilha);
}

void PilhaLibera(Pilha* pPilha) {
    /* Preencher aqui */
    ListaLibera(pPilha);
}