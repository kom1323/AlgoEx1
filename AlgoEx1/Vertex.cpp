#include "Vertex.h"

void Vertex::AddEdge(int vertex,int type)
{
	Edge* newEdge;
	switch (type)
	{
	case DIRECTED_EDGE:
		newEdge = new DirectedEdge(vertex);
		break;
	case UNDIRECTED_EDGE:
		//undirected
		break;
	}
	Edges.push_back(newEdge);
	if (this->Edges.empty())
		this->pos = this->Edges.begin();
}
void Vertex::posToNextUnMarked()//need to implement
{
	++this->pos;
}

bool Vertex::checkPosAtEnd()
{
	return (this->pos == this->Edges.end());
}


int Vertex::getId() { return id; }

Vertex::~Vertex()
{
	for(auto&& edge : this->Edges) {
		delete edge;
	}
}

