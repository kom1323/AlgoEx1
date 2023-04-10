#include "Graph.h"
Graph::Graph(int numOfVertices)
{
	for (int i = 0; i <= numOfVertices; i++)
	{
		this->vertices.push_back(Vertex(i));
	}
	
}

void Graph::Euler()
{
	if (!isEulerGraph())
		cout << "The graph is not aulerian";
	else
	{
		cout << "The graph is aulerian\n";
		list <int> Circle;
		Circle.splice(Circle.end(), findCircuit(vertices[1].getId()));
		list<int>::iterator itrCurrentVerCircle = Circle.begin();
		list<int>::iterator itrEndCircle = Circle.end();
		while (itrCurrentVerCircle != itrEndCircle)
		{
			list <int> TempCircle= findCircuit(*itrCurrentVerCircle);
			TempCircle.pop_front();
			Circle.splice(itrCurrentVerCircle, TempCircle);
			itrEndCircle = Circle.end();
			if((vertices[*itrCurrentVerCircle].checkPosAtEnd()))
				++itrCurrentVerCircle;
				
		}
		cout << "(";
		int count=0;
		for (auto i : Circle)
		{
			
			cout << i;
			if(Circle.size()-1!=count)
				cout << ",";
			count++;
		}
		cout << ")";
	}
}