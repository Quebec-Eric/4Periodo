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
  else
  {

  
      imprimeGrafoLista(grafo);
   
      //imprimeGrafomatriz(grafo);
    
    coletarLixo(grafo);
  }

  return 0;
}

void demonstracao()
{

  printf("Nosso modelo de grafo\n");
  printf("-----------------------\n");
  printf("Entrada para a criacao de nosso grafo == \n");
  printf("Entre com o numero de vertices seguido por grauMaximo e se ele e ponderado ou nao \n\n");
}

Grafo *criacaoDoGRafo()
{
  int vertices = 0;
  int grauMax = 0;
  int ponderado = 0;
  printf("Numero de Vertices = ");

  if (scanf("%d", &vertices) < 0)
  {
    printf("ERRO");
    return NULL;
  }
  printf("\nO grau Maximo = ");
  if (scanf("%d", &grauMax) < 0)
  {
    printf("ERRO");
    return NULL;
  }

  printf("\nSe for ponderado digite 1 se nao digite 0");
  if (scanf("%d", &ponderado) < 0)
  {
    printf("ERRO");
    return NULL;
  }
  Grafo *novoGrafo = criarGrafo(vertices, grauMax, ponderado);
  return novoGrafo;
}

int inserirNoGrafo(Grafo *grafico)
{
  int saber = 0;
  colocarValores(grafico, 0, 1, 1, 0);
  colocarValores(grafico, 1, 0, 0, 0);
  colocarValores(grafico, 1, 3, 0, 0);
  colocarValores(grafico, 1, 2, 0, 0);
  colocarValores(grafico, 2, 4, 1, 0);
  colocarValores(grafico, 3, 2, 0, 0);
  colocarValores(grafico, 3, 4, 0, 0);
  saber = colocarValores(grafico, 4, 1, 0, 0);

  return saber;
}
