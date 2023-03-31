#include "Graph.h"

void Graph::addVertx()
{
	this->vertices.push_back(Vertex(++counter));
}
int Graph::getNumOfVertices()const
{
	return counter;
}
int Graph::counter = 0;
void Graph::Euler()
{
	if (!isEulerGraph())
		cout << "The graph is not aulerian";
	else
	{
		cout << "The graph is aulerian\n";
		list <int> Circle;
		Circle.splice(Circle.end(), findCircuit(*vertices.begin()));
		vector<Vertex>::iterator FirstVertex = vertices.begin();
		list<int>::iterator itrCurrentVerCircle = Circle.begin();
		list<int>::iterator itrEndCircle = Circle.end();
		while (itrCurrentVerCircle != itrEndCircle)
		{
			list <int> TempCircle= findCircuit(*vertices.begin());
			TempCircle.pop_front();
			Circle.splice(itrCurrentVerCircle, TempCircle);
			itrEndCircle = Circle.end();
			while (((FirstVertex + (*itrCurrentVerCircle) - 1)->checkPosAtEnd())&& itrCurrentVerCircle != itrEndCircle)
				++itrCurrentVerCircle;
		}
		cout << "(";
		for (auto i : Circle)
		{
			cout << i << ",";
		}
		cout << ")";
	}
}