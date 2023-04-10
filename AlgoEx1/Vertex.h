#pragma once
#include "DirectedEdge.h"
#include "UnDirectedEdge.h"
#include <list>
#define DIRECTED_EDGE 1
#define UNDIRECTED_EDGE 2
using namespace std;

class Vertex
{
private:
	int id;
	list<Edge*>::iterator pos;
	list<Edge *> Edges;

public:
	Vertex(int id):id(id){}
	~Vertex();
	void AddEdge(int vertex,int type);
	void posToNextUnMarked();
	bool checkPosAtEnd();
	int getId();
	friend class DirectedGraph;
	friend class UnDirectedGraph;
};	