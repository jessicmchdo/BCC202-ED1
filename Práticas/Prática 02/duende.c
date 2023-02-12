#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duende.h"

struct duende {
    int idade;
    char nome[20];
    ESCALADO escalado;
};

struct time {
    Duende lider;
    Duende confeiteiro;
    Duende entregador;
    Duende embrulhador;
};

// Manter como especificado
void lerQuantidade(int *qtdDuendes){
    scanf("%d", qtdDuendes);
}

// Manter como especificado
Duende *alocaDuendes(int qtdDuendes){
    Duende *duendes;
    duendes = malloc (qtdDuendes * sizeof(Duende));

    return duendes;
}

// Manter como especificado
Time *alocaTimes(int qtdTimes){
    Time *times;
    times = malloc (qtdTimes * sizeof(Time));

    return times;
}

// Manter como especificado
void desalocaDuendes(Duende **duendes){
    free(*duendes);
}

// Manter como especificado
void desalocaTimes(Time **times){
    free(*times);
}

// Manter como especificado
void lerDuendes(Duende *duendes, int qtdDuendes){
    for(int i = 0; i < qtdDuendes; i++){
        scanf("%s", duendes[i].nome);
        scanf("%d", &duendes[i].idade);
    }
}

// Manter como especificado
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes){
    int i, index;
    int qtdTime = qtdDuendes/4;
    // Escalando os lideres
    for (i=0; i<qtdTime; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);// Bucar o proximo mais velho disponivel
        duendes[index].escalado = 1;// Marca o duende como escalado
        strcpy(times[i].lider.nome, duendes[index].nome);// Copiar o nome do duende encontrado como lider de um time
        times[i].lider.idade = duendes[index].idade;// Copiar a idade do duende encontrado como lider de um time
    }

    // Escalando os confeiteiros
    for (i=0; i<qtdTime; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);// Bucar o proximo mais velho disponivel
        duendes[index].escalado = 1;// Marca o duende como escalado
        strcpy(times[i].confeiteiro.nome, duendes[index].nome);// Copiar o nome do duende encontrado como confeiteiro de um time
        times[i].confeiteiro.idade = duendes[index].idade;// Copiar a idade do duende encontrado como confeiteiro de um time
    }

    // Escalando os entregador
    for (i=0; i<qtdTime; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);// Bucar o proximo mais velho disponivel
        duendes[index].escalado = 1;// Marca o duende como escalado
        strcpy(times[i].entregador.nome, duendes[index].nome);// Copiar o nome do duende encontrado como entregador de um time
        times[i].entregador.idade = duendes[index].idade;// Copiar a idade do duende encontrado como entregador de um time
    }

    // Escalando os embrulhador
    for (i=0; i<qtdTime; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);// Bucar o proximo mais velho disponivel
        duendes[index].escalado = 1;// Marca o duende como escalado
        strcpy(times[i].embrulhador.nome, duendes[index].nome);// Copiar o nome do duende encontrado como embrulhador de um time
        times[i].embrulhador.idade = duendes[index].idade;// Copiar a idade do duende encontrado como embrulhador de um time
    }
}

int proximoMaisVelho(Duende *duendes, int qtdDuendes){
    int indice = 0;
    int maisVelho = 0;

    for (int i = 0; i < qtdDuendes; i++)
    {
        if (maisVelho < duendes[i].idade && duendes[i].escalado == NAO)
        {
            indice = i;
            maisVelho = duendes[i].idade;
        }
        
    }
    
    return indice;
}

// Manter como especificado
void printTimes(Time *times, int qtdTimes){
    for (int i=0; i<qtdTimes; i++) {
        printf("Time %d\n", i+1);
        printf("PILOTO > %s %d\n", times[i].lider.nome, times[i].lider.idade);
        printf("CONFEI > %s %d\n", times[i].confeiteiro.nome, times[i].confeiteiro.idade);
        printf("ENTREG > %s %d\n", times[i].entregador.nome, times[i].entregador.idade);
        printf("EMBRUL > %s %d\n\n", times[i].embrulhador.nome, times[i].embrulhador.idade);
    }
}
