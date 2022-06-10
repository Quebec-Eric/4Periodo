#include <iostream>
#include <list>
#include <stack>
using namespace std;

class GrafoQuestao1
{

	list<int> *ArestaDeAdjacencia;
	int quantidadeVertices;

protected:
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

public:
	GrafoQuestao1(int quantidadeDeVertices)
	{
		this->quantidadeVertices = quantidadeDeVertices;
		ArestaDeAdjacencia = new list<int>[quantidadeDeVertices];
	}
	void AdicionandoAresta(int verticeDeSaida, int VerticeDeChegada)
	{
		ArestaDeAdjacencia[verticeDeSaida].push_back(VerticeDeChegada);
	}

	GrafoQuestao1 FazerGrafoTransposto()
	{
		GrafoQuestao1 g(quantidadeVertices);
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

	bool *NegarVesticesVisitados(bool visitado[])
	{
		for (int i = 0; i < quantidadeVertices; i++)
		{
			visitado[i] = false;
		}
		return visitado;
	}

	void MostrarComponentes()
	{
		stack<int> Pilha;

		bool *visited = new bool[quantidadeVertices];

		visited = NegarVesticesVisitados(visited);

		for (int i = 0; i < quantidadeVertices; i++)
		{
			if (visited[i] == false)
			{
				EmpilhandoAPilha(i, visited, Pilha);
			}
		}

		GrafoQuestao1 gr = FazerGrafoTransposto();

		visited = NegarVesticesVisitados(visited);

		while (Pilha.empty() == NULL)
		{

			int v = Pilha.top();
			Pilha.pop();

			if (visited[v] == false)
			{
				gr.BuscaPorProfundidade(v, visited);
				cout << endl;
			}
		}
	}
};

void MatrizParaArestaSimple(int matriz[][15], int tamanho)
{
	GrafoQuestao1 g(tamanho);
	for (int i = 0; i < tamanho; i++)
	{
		for (int z = 0; z < tamanho; z++)
		{
			if (matriz[i][z] != 0)
			{

				g.AdicionandoAresta(i, z);
			}
		}
	}

	g.MostrarComponentes();
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

			  


	MatrizParaArestaSimple(matriz, 15);

	return 0;
}