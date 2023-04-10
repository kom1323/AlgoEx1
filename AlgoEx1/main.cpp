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
	cin >> n >> m;
	switch (choice)
	{
	case 'y':
		graph = new DirectedGraph(n);
		break;
	case 'n':
		graph = new DirectedGraph(n);
		break;
	default:
		exit(1);
		break;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> edgeFrom >> edgeTo;
		graph->addEdge(edgeFrom, edgeTo);
	}
	graph->Euler();
	
}