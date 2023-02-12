#include "automato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum //Valor da vida para a célula
{
    MORTO = 0,
    VIVO = 1
} VIDA;

struct automatoCelular //O TAD a ser utilizado na resolução
{
    VIDA vida;
};

void lerDimensao(int *dimensao) //Lê a dimensão da tabela e salva em uma variável
{
    scanf("%d", dimensao);
}

AutomatoCelular **alocarReticulado(int dimensao) //Aloca dinâmicamente a matriz de reticulado utilizando a dimensão
{
    AutomatoCelular **automatoCelular = malloc(dimensao * sizeof(AutomatoCelular *));

    for (int i = 0; i < dimensao; i++)
    {
        automatoCelular[i] = malloc(dimensao * sizeof(AutomatoCelular));
    }

    return automatoCelular;
}

void desalocarReticulado(AutomatoCelular ***automatoCelular, int dimensao) //Desaloca o espaço reservado para a matriz de reticulado
{
    for (int i = 0; i < dimensao; i++)
    {
        free((*automatoCelular)[i]);
    }
    free(*automatoCelular);
}

void leituraReticulado(AutomatoCelular **automatoCelular, int dimensao) //Lê os valores da matriz de reticulado
{
    int vidaReticulado;

    for (int i = 0; i < dimensao; i++) //Repetição para percorrer a matriz
    {
        for (int j = 0; j < dimensao; j++)
        {
            scanf("%d", &vidaReticulado);
            automatoCelular[i][j].vida = vidaReticulado;
        }
    }
}

AutomatoCelular **copiaAutomato(AutomatoCelular **automatoCelular, int dimensao){ //Cria uma cópia da matriz de reticulado para salvar seus dados originais


    AutomatoCelular **copia;
    copia = alocarReticulado(dimensao); //Faz a sua alocação dinâmica

    for(int i = 0; i < dimensao; i++){ //Percorre a matriz e copia índice por índice
        for(int j = 0; j < dimensao; j++){
            copia[i][j].vida = automatoCelular[i][j].vida; 
        }
    }

    return copia;

}

AutomatoCelular **evoluirReticulado(AutomatoCelular **automatoCelular, int dimensao) //Checa o estado da célula e retorna a próxima geração do reticulado
{
    //Cópia da matriz de reticulado para não influenciar a comparação das células adjacentes
    AutomatoCelular **CopiaAutomatoCelular; 
    CopiaAutomatoCelular = copiaAutomato(automatoCelular, dimensao);

    for (int i = 0; i < dimensao; i++) //Loop para percorrer a matriz
    {
        for (int j = 0; j < dimensao; j++)
        {

            int contadorCelular = 0; //Contador de células vivas
            //Tratamento exceção para impedir acesso de índices não alocados
            int x0 = i - 1;
            int y0 = j - 1;
            int xf = i + 1;
            int yf = j + 1;

            
            if (x0 < 0) 
                x0 = 0;

            if (y0 < 0) 
                y0 = 0;

            if(xf >= dimensao)
                xf = dimensao - 1;

            if(yf >= dimensao)
                yf = dimensao - 1;

            for (int k = x0; k <= xf; k++) //Loop para percorrer células adjacentes
            {
                for (int l = y0; l <= yf; l++)
                {
                    if (!(k == i && l == j)) //Checa se não é a célula atual
                    {
                        if (CopiaAutomatoCelular[k][l].vida == VIVO)
                        {
                            contadorCelular++;
                        }
                    }
                }
            }

            //Verificação da condição para aplicação das regras
            // celula renasce
            if (automatoCelular[i][j].vida == MORTO && contadorCelular == 3)
            {
                automatoCelular[i][j].vida = VIVO;
            } // solidão
            else if (automatoCelular[i][j].vida == VIVO && contadorCelular < 2)
            {
                automatoCelular[i][j].vida = MORTO;
            } // continua viva
            else if (automatoCelular[i][j].vida == VIVO && (contadorCelular == 2  || contadorCelular == 3))
            {
                automatoCelular[i][j].vida = VIVO;
            } //sufocamento
            else if (automatoCelular[i][j].vida == VIVO && contadorCelular > 3)
            {
                automatoCelular[i][j].vida = MORTO;
            }

        }
    }



    desalocarReticulado(&CopiaAutomatoCelular, dimensao); //Chama a função para desalocar a cópia da matriz de reticulado
    return automatoCelular;
}


void imprimeReticulado(AutomatoCelular **automatoCelular, int dimensao) //Imprime a matriz de reticulado na tela
{
    for (int i = 0; i < dimensao; i++) //Repetição para percorrer a matriz
    {
        for (int j = 0; j < dimensao; j++)
        {
            printf("%d ", automatoCelular[i][j].vida);
        }
        printf("\n");
    }
}


