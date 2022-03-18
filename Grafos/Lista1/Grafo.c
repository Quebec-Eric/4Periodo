#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Grafo.h"

///inicio struc grafo
struct grafo
{
    int ponderado;
    int vertices;
    int grauMaximo;
    int **arestas;
    float **pesos;
    int *grau;
};
//fim struct grafo


//Incio criarGrafo
//Passagem de parametro int int int
//Return ponteiro de grafico
Grafo *criarGrafo(int vertice, int grau, int ponderado)
{

    Grafo *novoGrafico;
    
    novoGrafico = (Grafo *)malloc(sizeof(struct grafo));
    if (novoGrafico != NULL)
    {
        //vicular variaves 
        novoGrafico->vertices = vertice;
        novoGrafico->grauMaximo = grau;
        novoGrafico->ponderado = ponderado;
        
        //criacao da coluna na memora com o tamanho senndo referente ao grau maximo
        novoGrafico->grau = (int *)calloc(vertice, sizeof(int *)); // usei calloc pois nao quero lixo e so quero 0
        if (novoGrafico->grau != NULL)
        {
             //criacao da linhas referete a coluna na memoria
            novoGrafico->arestas = (int **)malloc(vertice * sizeof(int *));
            if (novoGrafico->arestas != NULL)
            {
                // se o grafo for ponderado criamos uma sub lista na memoria onde iremos vencular esse peso com a aresta
                for (int i = 0; i < novoGrafico->vertices; i++)
                {
                    novoGrafico->arestas[i] = (int *)malloc(vertice * sizeof(int *));
                    if (novoGrafico->arestas[i] == NULL)
                    {

                        printf("Erro a criar as arestas dos vertices do seu grafico linha 27");
                        return 0;
                    }
                }

                if (novoGrafico->ponderado == 1)
                {
                    novoGrafico->pesos = (float **)malloc(vertice * sizeof(float *));
                    if (novoGrafico->pesos != NULL)
                    {

                        for (int i = 0; i < vertice; i++)
                        {

                            novoGrafico->pesos[i] = (float *)malloc(grau * sizeof(float));
                            if (novoGrafico->pesos[i] == NULL)
                            {

                                printf("Erro a criar as arestas dos vertices do seu grafico linha 52");
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    return novoGrafico;
}
//fim criacaoDoGRafo



//Inicio colocaValores
//passagem de paragemto ponteiro de GRafo , int , int , int , float
//return it para ser utilizado como confirmacao se foi ou nao possivel incluir o valor 
int colocarValores(Grafo *grafo, int vertice1, int verticd2, int retornoE, float peso)
{
    if (grafo == NULL)
        return 0;
    if (vertice1 < 0 || vertice1 >= grafo->vertices)
        return 0;
    if (verticd2 < 0 || verticd2 >= grafo->vertices)
        return 0;

    //alocando os valores na eferencia onde o vertice1 se referencia     
    grafo->arestas[vertice1][grafo->grau[vertice1]] = verticd2;
    if (grafo->ponderado)
        grafo->pesos[vertice1][grafo->grau[vertice1]] = peso;//se for ponderado colocarmos o peso em uma lista subjacete
    grafo->grau[vertice1]++;

    if (retornoE == 1)
        colocarValores(grafo, vertice1, verticd2, 0, peso);
    return 1;
}

//Inicio imprimeGrafoLista
//Passagem de paragemto ponteiro de Grafo
//return Void
void imprimeGrafoLista(Grafo *grafico)
{
    if (grafico == NULL)
    {
        return;
    }
    //colocar os valores de referencias que estao sendo referenciados pelo vertice 
    for (int i = 0; i < grafico->vertices; i++)
    {
        printf("%d: ", i);
        //acessar os valores no locar adjacete 
        for (int j = 0; j < grafico->grau[i]; j++)
        {
            // se for o valor for ponderado iresmos colocar o primeiro valor da arestas  e depois com o peso de cada local
            if (grafico->ponderado)
                printf("V[%d] Peso(%.2f), ", grafico->arestas[i][j], grafico->pesos[i][j]);
            else
                printf("[%d], ", grafico->arestas[i][j]);// se nao for colocar somete os valores da primeira lista de adjacencia
                 //printf("--> ");
        }
        printf("\n");
    }
}
//fim ImprimeGRafoLista



//Inicio imprimeGrafomatriz 
//passagem de parametro ponteiro de Grafo
// return Void
void imprimeGrafomatriz(Grafo *grafico)
{
    if (grafico == NULL)
    {
        return;
    }

    printf("   ");
    //criar uma imagem ilustrativa
    for (int i = 0; i < grafico->vertices; i = i + 1)
    {
         
        printf("%d\t", i);
    }
    printf("\n");

    //Inicio acessar os valores
    for (int i = 0; i < grafico->vertices; i = i + 1)
    {
        printf("%d: ", i);
        
        //inicio tratar os dados da lista para colocar na matriz
        int *arr = bolha(grafico->arestas[i], grafico->grau[i], 5);

         //acessar os dados do vetor   
        for (int j = 0; j < grafico->vertices; j = j + 1)
        {
            //  printf("%d\t", arr[j]);
            
            if (arr[j] == j && arr[j] != 0)
            {
                // printf("%d\t", arr[j]);
                printf("1 \t");
            }
            else
            {
                printf("0 \t");
            }
        }

        printf("\n");
    }
}
// Fim imprimeGrafomatriz


//Inicio Bolha -Tratamento da lista adjacete
//parametros array , int , int
//retur poteiro d array
int *bolha(int *arrayDesordenado, int tamanho, int tamanhoGeral)
{
    int valor = 0;
    if (tamanho < 4)
    {

        for (int i = tamanho; i < tamanhoGeral; i++)
        {
            arrayDesordenado[i] = 0;
        }

        for (int i = 0; i < tamanhoGeral; i++)
        {
            // printf("%d ", arrayDesordenado[i]);
            int maiorNumero = arrayDesordenado[i];
            int valor = arrayDesordenado[maiorNumero];
            arrayDesordenado[maiorNumero] = maiorNumero;
            arrayDesordenado[i] = valor;
        }
    }
    return arrayDesordenado;
}
//Fim bolha

//Iicio coleta Lixo
//passgme de parametros  ponteirp deGrafico
//retur Void 
void coletarLixo(Grafo *grafico)
{
    if (grafico != NULL)
    {
        for (int i = 0; i < grafico->vertices; i++)
        {
            free(grafico->arestas[i]);
        }
        free(grafico->arestas);

        if (grafico->ponderado)
        {

            for (int i = 0; i < grafico->vertices; i++)
            {
                free(grafico->pesos[i]);
            }
            free(grafico->pesos);
        }
        free(grafico->grau);
        //free(grafico->vertices);
        free(grafico);
        if (grafico == NULL)
        {
            printf("Grafico desalocado da memoria");
        }
    }

}
//fim ColetaLixo
