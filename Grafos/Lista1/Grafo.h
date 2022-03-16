typedef struct grafo Grafo;
Grafo* criarGrafo(int vertice, int grau, int ponderado);
void libera_Grafo(Grafo* gr);
int colocarValores(Grafo* grafo, int vertice1 , int verticd2, int retornoE,float peso );
void imprimeGrafoLista(Grafo *grafico);
void imprimeGrafomatriz(Grafo *grafico);
int *bolha(int *arrayDesordenado, int tamanho, int tamanhoGeral);
void coletarLixo(Grafo *grafico);