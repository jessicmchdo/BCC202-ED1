#ifndef HASH_ABERTO
#define HASH_ABERTO

#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Os cabeçalhos de todas as funções e os TADs podem ser alterados */

#define VAZIO " !!!!!!!!!!!!!!!!!!!!\0 "

typedef struct {
    int n; // numero de documentos
    Chave chave;
    NomeDocumento documentos[ND];
} Item;

typedef Item IndiceInvertido[M];

/* Funções */ 
// void alocaIndice(IndiceInvertido);
// void desalocaIndice(IndiceInvertido);
void inicia(IndiceInvertido); //ok
bool insereDocumento(IndiceInvertido, Chave, NomeDocumento);
int busca(IndiceInvertido, Chave); 
int consulta(IndiceInvertido, Chave*, int, NomeDocumento*);
void imprime(IndiceInvertido);

void sort(NomeDocumento*, int);


void adicionarChaves(IndiceInvertido, Chave*, int);

int chaveEhVazia(Chave);

#endif // !HASH_ABERTO
