#include "Vertex.h"

void Vertex::AddEdge(int vertex)
{
	Edge* newEdge = new Edge(vertex);
	Edges.push_back(newEdge);
	if (this->Edges.empty())
		this->pos = this->Edges.begin();
}
void Vertex::posToNextUnMarked()//need to implement
{
	++this->pos;
}

bool Vertex::isPosAtEnd()
{
	return (this->pos == this->Edges.end())
}


int Vertex::getId() { return id; }

Vertex::~Vertex()
{
	for(auto&& edge : this->Edges) {
		delete edge;
	}
}

