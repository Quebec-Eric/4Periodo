#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
int variavelglobal = 0;
bool BuscaEmLargura(int grafoResifual[6][6], int tamanho, int valores[], int saberCaminho[])
{
    bool saberQuemFoiVisitado[tamanho];

    for (int i = 0; i < 6; i++)
    {
        saberQuemFoiVisitado[i] = 0;
    }

    queue<int> fila;
    fila.push(valores[0]);
    saberQuemFoiVisitado[valores[0]] = true;
    saberCaminho[valores[0]] = -1;

    while (!fila.empty())
    {
        int pegarPrimeiro = fila.front();
        fila.pop();

        for (int i = 0; i < tamanho; i += 1)
        {
            if (saberQuemFoiVisitado[i] == false && grafoResifual[pegarPrimeiro][i] > 0)
            {

                if (i == valores[1])
                {
                    saberCaminho[i] = pegarPrimeiro;
                    return true;
                }
                fila.push(i);
                saberCaminho[i] = pegarPrimeiro;
                saberQuemFoiVisitado[i] = true;
            }
        }
    }

    return false;
}

int FordFulkeson(int matriz[6][6], int valores[], int tamanho)
{
    int grafoResidual[6][6];

    for (int i = 0; i < tamanho; i++)
    {
        for (int z = 0; z < tamanho; z++)
        {
            grafoResidual[i][z] = matriz[i][z];
        }
    }

    int saberCaminho[6];
    int quantidadeMaxima = 0;

    while (BuscaEmLargura(grafoResidual, tamanho, valores, saberCaminho))
    {
        int path_flow = INT_MAX;

        for (int i = valores[1]; i != valores[0]; i = saberCaminho[i])
        {
            int u = saberCaminho[i];
            path_flow = min(path_flow, grafoResidual[u][i]);
        }

        for (int i = valores[1]; i != valores[0]; i = saberCaminho[i])
        {
            int u = saberCaminho[i];
            grafoResidual[u][i] -= path_flow;
            grafoResidual[i][u] += path_flow;
            variavelglobal++;
        }
    	int somador=0;
        for (int i = 0; i < tamanho; i++)
        {
            for (int z = 0; z < tamanho; z++)
            {
                if(i==5&& grafoResidual[i][z]==1){
                    somador++;
                }   
            }
        }
        std::cout<<"Passou por "<<somador<<" Vertices"<<endl;
        quantidadeMaxima += path_flow;
    }
    variavelglobal += 1;
    return quantidadeMaxima;
}

int Pegarvalores(string fala)
{
    int resposta = 0;
    cout << fala << endl;
    std::cin >> resposta;
    return resposta;
}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    std::cout << "\n Lista de Adjacencia " << endl;

    for (int v = 0; v < V; ++v)
    {
        for (auto x : adj[v])
        {
            std::cout << x << "-> ";
        }
        std::cout << endl;
    }
}

void MatrizParaArestaSimple(int matriz[6][6], int tamanho)
{
    vector<int> adj[tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        for (int z = 0; z < tamanho; z++)
        {
            if (matriz[i][z] != 0)
            {

                addEdge(adj, i, z);
            }
        }
    }
    printGraph(adj, 6);
}

void Mostrartela(int matriz[6][6])
{
    std::cout << "No Grafo \n"
              << endl;
    MatrizParaArestaSimple(matriz, 6);
    std::cout << endl;
    int valores[2];
    valores[0] = Pegarvalores(" Qual o Vertice Inicial ");
    valores[1] = Pegarvalores(" Qual o Vertice final ");
    int quantidadeMaxima = FordFulkeson(matriz, valores, 6);
    std::cout << "A Quantidade maxima de caminhos Dijuntos e " << quantidadeMaxima << endl;
    cout <<"Numero de arestas utilizadas e "<< variavelglobal << endl;
}

int main()
{
    int matriz[6][6] = {{0, 1, 1, 1, 0, 1},
                        {0, 0, 0, 1, 1, 1},
                        {0, 1, 0, 1, 1, 1},
                        {0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0, 1},
                        {0, 0, 0, 0, 0, 0}};

    Mostrartela(matriz);
}