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