#include <stdlib.h>
#include <stdio.h>
#include "Grafo.h"

void demonstracao();
Grafo *criacaoDoGRafo();
int inserirNoGrafo(Grafo *grafico);

int ponderado = 0;


//Inicio  int mais 
int main()
{
 //demostracao de como deve ser a entrada do programa
  demonstracao();
  
   
  Grafo *grafo = criacaoDoGRafo();//criacao da alocacao dinamica do nosso Grafo


  int retornarVerdade = inserirNoGrafo(grafo);//Fazer a isercao das aretas no rafico
  
  //vericiar erro
  if (retornarVerdade != 1)
  {
    printf("\nErro ao incluir valor\n");
  }
 
 //desalocar lixo da memorai
  coletarLixo(grafo);

  return 0;
}
//fim int mai


//inicio demostacao
//Passgem de parametro Void
//retur void
void demonstracao()
{

  printf("Nosso modelo de grafo\n");
  printf("-----------------------\n");
  printf("Entrada para a criacao de nosso grafo == \n");
  printf("Entre  se ele e ponderado ou nao \n\n");
}
//fim demostracao


//Inicio fucao criacaoDoGrafico
//Passagem de parametro Void
//Return um ponteiro de Grafo 
Grafo *criacaoDoGRafo()
{
  int ponderado = 0;
  printf("\nSe for ponderado digite 1 se nao digite 0");
  if (scanf("%d", &ponderado) < 0)
  {
    printf("ERRO");
    return NULL;
  }
  Grafo *novoGrafo = criarGrafo(5, 5, ponderado);//Criar o grafico com o numero 4 de vertices , com o grau maximo 4
  return novoGrafo;
}
//fim criacaoDoGrafo


//Iicio iserirNografo/Mostraar
//Passagem de parametro Um ponteiro de Grafico
//return um valor Int
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
    //Inicio Incerssao grafo  direcioado e nao ponderado
    colocarValores(grafico, 0, 1, 0, 0);
    colocarValores(grafico, 1, 3, 0, 0);
    colocarValores(grafico, 1, 2, 0, 0);
    colocarValores(grafico, 2, 4, 0, 0);
    colocarValores(grafico, 3, 4, 0, 0);
    saber = colocarValores(grafico, 4, 1, 0, 0); // retornar saber para saber se foi possivel incluir
    imprimeGrafomatriz(grafico);// primtar na tela a matriz do grafo
  } 
  else if (saber == 2)
  {
    //Inicio grafo nao direcionado e ponderado
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
    saber = colocarValores(grafico, 1, 4, 0, 4);//retur de confirmacao
    imprimeGrafoLista(grafico);//pritar na tela a lista de adjacecia
  }
  else if (saber == 1)
  {
    //Inciio Grafo não-direcionado não-ponderado
    colocarValores(grafico, 0, 1, 0, 0);
    colocarValores(grafico, 1, 3, 0, 0);
    colocarValores(grafico, 1, 2, 0, 0);
    colocarValores(grafico, 2, 4, 0, 0);
    colocarValores(grafico, 3, 4, 0, 0);
    saber = colocarValores(grafico, 4, 1, 0, 0);//retur de confirmacao
    imprimeGrafoLista(grafico);//imprimir a lista a tela
  }
  else
  {
    //Grafo direcionado ponderado
    colocarValores(grafico, 0, 1, 0, 10);
    colocarValores(grafico, 1, 3, 0, 6);
    colocarValores(grafico, 1, 2, 0, 5);
    colocarValores(grafico, 2, 4, 0, 11);
    colocarValores(grafico, 3, 4, 0, 2.5);
    saber = colocarValores(grafico, 4, 1, 0, 4);
    imprimeGrafoLista(grafico);//imprimir lista na tela 
  }

  return saber;
}
//Fim iserirNografo/Mostraars