#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "DirectedGraph.h"
int main(void)
{
	char choice;
	Graph* graph;
	int n, m,edgeFrom,edgeTo;
	cout << "Is the graph directed: y/n\n";
	cin >> choice;
	if (choice != 'y' && choice != 'n')
	{
		cout << "invalid error";
		exit(1);
	}
	cin >> n >> m;
	if (n <= 0 || m < 0)
	{
		cout << "invalid error";
		exit(1);
	}
	switch (choice)
	{
	case 'y':
		graph = new DirectedGraph(n);
		break;
	case 'n':
		graph = new DirectedGraph(n);
		break;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> edgeFrom >> edgeTo;
		if ((edgeFrom<0 && edgeFrom>n) || (edgeTo<0 && edgeTo>n))
		{
			cout << "invalid error";
			exit(1);
		}	
		graph->addEdge(edgeFrom, edgeTo);
	}
	graph->Euler();
	
}