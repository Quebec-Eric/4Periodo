#include <stdlib.h>
#include <stdio.h>
#include "Grafo.h"

void demonstracao();
Grafo *criacaoDoGRafo();
int inserirNoGrafo(Grafo *grafico);

int ponderado = 0;
int main()
{
  demonstracao();
  Grafo *grafo = criacaoDoGRafo();
  int retornarVerdade = inserirNoGrafo(grafo);
  if (retornarVerdade != 1)
  {
    printf("\nErro ao incluir valor\n");
  }

  coletarLixo(grafo);

  return 0;
}

void demonstracao()
{

  printf("Nosso modelo de grafo\n");
  printf("-----------------------\n");
  printf("Entrada para a criacao de nosso grafo == \n");
  printf("Entre  se ele e ponderado ou nao \n\n");
}

Grafo *criacaoDoGRafo()
{
  int ponderado = 0;
  printf("\nSe for ponderado digite 1 se nao digite 0");
  if (scanf("%d", &ponderado) < 0)
  {
    printf("ERRO");
    return NULL;
  }
  Grafo *novoGrafo = criarGrafo(5, 5, ponderado);
  return novoGrafo;
}

int inserirNoGrafo(Grafo *grafico)
{
  int saber = 0;
  printf("\n0 ==Grafo direcionado não-ponderado.");
  printf("\n1 ==Grafo não-direcionado não-ponderado.");
  printf("\n2 ==GGrafo não-direcionado ponderado.");
  printf("\n3 ==Grafo direcionado ponderado.");
  printf("\n\n");
  scanf("%d", &saber);
  if (saber == 0)
  {
    colocarValores(grafico, 0, 1, 0, 0);
    colocarValores(grafico, 1, 3, 0, 0);
    colocarValores(grafico, 1, 2, 0, 0);
    colocarValores(grafico, 2, 4, 0, 0);
    colocarValores(grafico, 3, 4, 0, 0);
    saber = colocarValores(grafico, 4, 1, 0, 0);
    imprimeGrafomatriz(grafico);
  }
  else if (saber == 2)
  {
    colocarValores(grafico, 0, 1, 0, 10);
    colocarValores(grafico, 1, 0, 0, 10);

    colocarValores(grafico, 1, 3, 0, 6);
    colocarValores(grafico, 3, 1, 0, 6);

    colocarValores(grafico, 1, 2, 0, 5);
    colocarValores(grafico, 2, 1, 0, 5);

    colocarValores(grafico, 2, 4, 0, 11);
    colocarValores(grafico, 4, 2, 0, 11);

    colocarValores(grafico, 3, 4, 0, 2.5);
    colocarValores(grafico, 4, 3, 0, 2.5);

    colocarValores(grafico, 4, 1, 0, 4);
    saber = colocarValores(grafico, 1, 4, 0, 4);
    imprimeGrafoLista(grafico);
  }
  else if (saber == 1)
  {
    colocarValores(grafico, 0, 1, 0, 0);
    colocarValores(grafico, 1, 3, 0, 0);
    colocarValores(grafico, 1, 2, 0, 0);
    colocarValores(grafico, 2, 4, 0, 0);
    colocarValores(grafico, 3, 4, 0, 0);
    saber = colocarValores(grafico, 4, 1, 0, 0);
    imprimeGrafomatriz(grafico);
  }
  else
  {
    colocarValores(grafico, 0, 1, 0, 10);
    colocarValores(grafico, 1, 3, 0, 6);
    colocarValores(grafico, 1, 2, 0, 5);
    colocarValores(grafico, 2, 4, 0, 11);
    colocarValores(grafico, 3, 4, 0, 2.5);
    saber = colocarValores(grafico, 4, 1, 0, 4);
    imprimeGrafoLista(grafico);
  }

  return saber;
}
