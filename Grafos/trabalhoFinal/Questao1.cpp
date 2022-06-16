#include <iostream>
#include <list>
#include <stack>
using namespace std;
int comunidade=0;
//inicio Classe Grafo
class Grafo
{

public:
    //lista onde iremos colocar as arestas
    list<int> *ArestaDeAdjacencia;
    int quantidadeVertices;

    // funcao para adicionar as arestas na lista
    void AdicionandoAresta(int verticeDeSaida, int VerticeDeChegada)
    {
        ArestaDeAdjacencia[verticeDeSaida].push_back(VerticeDeChegada);
    }

    //Construtor 
    Grafo(int quantidadeDeVertices)
    {
        this->quantidadeVertices = quantidadeDeVertices;
        ArestaDeAdjacencia = new list<int>[quantidadeDeVertices];
    }

    //Funcao de empilihar o vertice onde ainda nao foi visitado
    void EmpilhandoAPilha(int vertice, bool visitado[], stack<int> &Pilha)
    {
        visitado[vertice] = true;
        list<int>::iterator i;
        for (i = ArestaDeAdjacencia[vertice].begin(); i != ArestaDeAdjacencia[vertice].end(); ++i)
            if (!visitado[*i])
            {
                EmpilhandoAPilha(*i, visitado, Pilha);
            }

        Pilha.push(vertice);
    }

    // Fazer a busca em profundidade
    void BuscaPorProfundidade(int vertice, bool visitado[])
    {
        visitado[vertice] = true;
        cout << "Comunidade ("<< comunidade<<") "<< "Pessoa ("<<vertice+1 << ")  "<< endl;
        list<int>::iterator i;
        for (i = ArestaDeAdjacencia[vertice].begin(); i != ArestaDeAdjacencia[vertice].end(); ++i)
            if (!visitado[*i])
            {
                BuscaPorProfundidade(*i, visitado);
            }
           
    }

    //Funcao para fazer o grafico transposto
    // que e o grafo onde mudamos a direcao das arestas
    Grafo FazerGrafoTransposto()
    {
        Grafo graficoTran(quantidadeVertices);
        for (int v = 0; v < quantidadeVertices; v++)
        {
            list<int>::iterator i;
            for (i = ArestaDeAdjacencia[v].begin(); i != ArestaDeAdjacencia[v].end(); ++i)
            {
                graficoTran.ArestaDeAdjacencia[*i].push_back(v);
            }
        }
        return graficoTran;
    }
};

//Funcao para mostrarmos a matriz
void MostrarMatriz(int matriz[15][15])
{
    std::cout << "Matriz :" << endl;
    for (int i = 0; i < 15; i++)
    {
        cout << i << ": ";
        for (int z = 0; z < 15; z++)
        {
            cout << matriz[i][z] <<",";
        }

        cout << endl;
    }
}

//Funcao que utilizamos para mudar a matriz para uma aresta simples
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

//Funcao para negar todos os vertices visitados
bool *NegarVesticesVisitados(bool visitado[], Grafo grafo)
{
    for (int i = 0; i < grafo.quantidadeVertices; i++)
    {
        visitado[i] = false;
    }
    return visitado;
}

//Funcao para mostrar na tela os componentres 
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
             comunidade++;
        }
    }
}


//funcao que ira empilhar a pilha e chamar a funcao de fazer o grafo tranposto
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

//Funcao que chama as funcao
void Fazerex(int matriz[15][15], int tamanho)
{
    Grafo grafo(tamanho);
    grafo = MatrizParaAresta(matriz, tamanho, grafo);
    Empilhar(grafo);
}

//entrada do programa funcao main
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