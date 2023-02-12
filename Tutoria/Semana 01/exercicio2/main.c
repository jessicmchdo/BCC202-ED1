#include "recursividade.h"

int main(){
    TLista lista;
    TItem x;

    TLista_FazVazia(&lista);

    while(scanf("%d", &x.numero) != EOF){
        TLista_Insere(&lista, x);
    }

    printf("%d\n", recursividade(&lista, lista.pPrimeiro->pProx));

    return 0;
}