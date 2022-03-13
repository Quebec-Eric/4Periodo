#include <stdlib.h>
#include <stdio.h>
#include "Grafo.h"




 int vertices = 0;
void demonstracao()
{

    printf("Nosso modelo de grafo\n");
    printf("-----------------------\n");
    printf("Entrada para a criacao de nosso grafo == \n");
    printf("Entre com o numero de vertices seguido por grauMaximo e se ele e ponderado ou nao \n\n");
}

Grafo *criacaoDoGRafo()
{
 
    int grauMax = 0;
    int ponderado = 0;
    printf("Numero de Vertices = ");
    scanf("%d", &vertices);
    printf("\nO grau Maximo = ");
    scanf("%d", &grauMax);
    printf("\nSe for ponderado digite 1 se nao digite 0");
    scanf("%d", &ponderado);
    ponderado = verificarEntrada(ponderado);
    Grafo *novoGrafo =criarGrafo(vertices, grauMax, ponderado);
    return novoGrafo;
}

int inserirNoGrafo(Grafo *grafico)
{
 int saber=0;
   colocarValores(grafico, 0, 1, 0, 0);
   colocarValores(grafico, 1, 3, 0, 0);
   colocarValores(grafico, 1, 2, 0, 0);
   colocarValores(grafico, 2, 4, 0, 0);
   colocarValores(grafico, 3, 2, 0, 0);
   colocarValores(grafico, 3, 4, 0, 0);
  saber= colocarValores(grafico, 4, 1, 0, 0);
  

    
  return saber;
}


int verificarEntrada(int ponderado)
{
    if(ponderado != 0 && ponderado != 1){
    printf("\nSomente os valores 0 e 1 sao tolerados, digite novamente");
    scanf("%d", &ponderado);
    verificarEntrada(ponderado);
    }
    else{
        return ponderado;
    }
}




// --- Main ---


int main()
{
    demonstracao();
    Grafo *grafo =criacaoDoGRafo();
  int retornarVerdade=inserirNoGrafo(grafo);
  if(retornarVerdade!=1){
    printf("\nErro ao incluir valor\n");
  }
  else{
    
    imprimeGrafomatriz(grafo);
    
  }
  
   

    return 0;
}




