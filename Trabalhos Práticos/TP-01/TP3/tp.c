#include <stdio.h>
#include "indiceInvertido.h"
#include "hash.h"


int main() {

    int numeroDocumentos;
    scanf("%d", &numeroDocumentos);
    Chave chaves[NN];
    IndiceInvertido indiceInvertido;

    inicia(indiceInvertido);

    for(int i = 0; i < numeroDocumentos; i++){

        NomeDocumento nomeDocumento;
        scanf("%s ", nomeDocumento);

        int numeroChaves = pegarChaves(chaves);
        adicionarChaves(indiceInvertido, chaves, numeroChaves);


        for(int j = 0; j < numeroChaves; j++)
            insereDocumento(indiceInvertido, chaves[j], nomeDocumento);

    }

    imprime(indiceInvertido);





    return 0;
}
