#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Grafo
{

public:
    list<int> *ArestaDeAdjacencia;
    int quantidadeVertices;
    void AdicionandoAresta(int verticeDeSaida, int VerticeDeChegada)
    {
        ArestaDeAdjacencia[verticeDeSaida].push_back(VerticeDeChegada);
    }
    Grafo(int quantidadeDeVertices)
    {
        this->quantidadeVertices = quantidadeDeVertices;
        ArestaDeAdjacencia = new list<int>[quantidadeDeVertices];
    }

    void EmpilhandoAPilha(int v, bool visitado[], stack<int> &Pilha)
    {
        visitado[v] = true;
        list<int>::iterator i;
        for (i = ArestaDeAdjacencia[v].begin(); i != ArestaDeAdjacencia[v].end(); ++i)
            if (!visitado[*i])
            {
                EmpilhandoAPilha(*i, visitado, Pilha);
            }

        Pilha.push(v);
    }

    void BuscaPorProfundidade(int v, bool visitado[])
    {
        visitado[v] = true;
        cout << v << " ";
        list<int>::iterator i;
        for (i = ArestaDeAdjacencia[v].begin(); i != ArestaDeAdjacencia[v].end(); ++i)
            if (!visitado[*i])
            {
                BuscaPorProfundidade(*i, visitado);
            }
    }

    Grafo FazerGrafoTransposto()
    {
        Grafo g(quantidadeVertices);
        for (int v = 0; v < quantidadeVertices; v++)
        {
            list<int>::iterator i;
            for (i = ArestaDeAdjacencia[v].begin(); i != ArestaDeAdjacencia[v].end(); ++i)
            {
                g.ArestaDeAdjacencia[*i].push_back(v);
            }
        }
        return g;
    }
};

void MostrarMatriz(int matriz[15][15])
{
    std::cout << "Matriz :" << endl;
    for (int i = 0; i < 15; i++)
    {
        cout << i << ": ";
        for (int z = 0; z < 15; z++)
        {
            cout << matriz[i][z] << " ";
        }

        cout << endl;
    }
}

Grafo MatrizParaAresta(int matriz[15][15], int tamanho, Grafo grafo)
{

    for (int i = 0; i < tamanho; i++)
    {
        for (int z = 0; z < tamanho; z++)
        {
            if (matriz[i][z] != 0)
            {

                grafo.AdicionandoAresta(i, z);
            }
        }
    }

    return grafo;
}
bool *NegarVesticesVisitados(bool visitado[], Grafo grafo)
{
    for (int i = 0; i < grafo.quantidadeVertices; i++)
    {
        visitado[i] = false;
    }
    return visitado;
}

void MostrarNaTela(Grafo grafo, Grafo tranposto, stack<int> &Pilha, bool visitado[])
{
    while (Pilha.empty() == NULL)
    {
        int valor = Pilha.top();
        Pilha.pop();
        if (visitado[valor] == false)
        {
            tranposto.BuscaPorProfundidade(valor, visitado);
            cout << endl;
        }
    }
}

void Empilhar(Grafo grafo)
{
    bool *visitados = new bool[grafo.quantidadeVertices];
    visitados = NegarVesticesVisitados(visitados, grafo);
    stack<int> Pilha;
    for (int i = 0; i < grafo.quantidadeVertices; i++)
    {
        if (visitados[i] == false)
        {
            grafo.EmpilhandoAPilha(i, visitados, Pilha);
        }
    }

    Grafo transposto = grafo.FazerGrafoTransposto();
    visitados = NegarVesticesVisitados(visitados, grafo);
    MostrarNaTela(grafo, transposto, Pilha, visitados);
}

void Fazerex(int matriz[15][15], int tamanho)
{
    Grafo grafo(tamanho);
    grafo = MatrizParaAresta(matriz, tamanho, grafo);
    Empilhar(grafo);
}

int main()
{
    /*
int matriz[5][5] = {{0, 1, 0, 0, 0},
                    {0, 0, 1, 1, 0},
                    {1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 0}};
                    */
    int matriz[15][15] = {{0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};

    MostrarMatriz(matriz);
    Fazerex(matriz, 15);
    
}