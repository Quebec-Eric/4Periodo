#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Grafo.h"

struct grafo
{
    int ponderado;
    int vertices;
    int grauMaximo;
    int **arestas;
    float **pesos;
    int *grau;
};

Grafo *criarGrafo(int vertice, int grau, int ponderado)
{

    Grafo *novoGrafico;
    novoGrafico = (Grafo *)malloc(sizeof(struct grafo));
    if (novoGrafico != NULL)
    {
        novoGrafico->vertices = vertice;
        novoGrafico->grauMaximo = grau;
        novoGrafico->ponderado = ponderado;
        novoGrafico->grau = (int *)calloc(vertice, sizeof(int *)); // usei calloc pois nao quero lixo e so quero 0
        if (novoGrafico->grau != NULL)
        {
            novoGrafico->arestas = (int **)malloc(vertice * sizeof(int *));
            if (novoGrafico->arestas != NULL)
            {

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

int colocarValores(Grafo *grafo, int vertice1, int verticd2, int retornoE, float peso)
{
    if (grafo == NULL)
        return 0;
    if (vertice1 < 0 || vertice1 >= grafo->vertices)
        return 0;
    if (verticd2 < 0 || verticd2 >= grafo->vertices)
        return 0;

    grafo->arestas[vertice1][grafo->grau[vertice1]] = verticd2;
    if (grafo->ponderado)
        grafo->pesos[vertice1][grafo->grau[vertice1]] = peso;
    grafo->grau[vertice1]++;

    if (retornoE == 1)
        colocarValores(grafo, vertice1, verticd2, 0, peso);
    return 1;
}

void imprimeGrafoLista(Grafo *grafico)
{
    if (grafico == NULL)
    {
        return;
    }

    for (int i = 0; i < grafico->vertices; i++)
    {
        printf("%d: ", i);
        for (int j = 0; j < grafico->grau[i]; j++)
        {
            if (grafico->ponderado)
                printf("%d(%.2f), ", grafico->arestas[i][j], grafico->pesos[i][j]);
            else
                printf("%d, ", grafico->arestas[i][j]);
        }
        printf("\n");
    }
}

void imprimeGrafomatriz(Grafo *grafico)
{
    if (grafico == NULL)
    {
        return;
    }

    for (int i = 0; i < grafico->vertices; i = i + 1)
    {
        printf("\t%d", i);
    }
    printf("\n");
    for (int i = 0; i < grafico->vertices; i = i + 1)
    {
        printf("%d: ", i);
        int *arr = bolha(grafico->arestas[i], grafico->grau[i], 5);

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
