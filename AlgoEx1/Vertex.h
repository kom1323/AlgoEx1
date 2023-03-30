#pragma once
#include "Edge.h"
#include <list>

using namespace std;

class Vertex
{
private:
	int id;
	list<Edge*>::iterator pos;
	list<Edge *> Edges;

public:
	Vertex(int id):id(id){}
	Vertex(const Vertex& other)=delete;
	~Vertex();
	void AddEdge(int vertex);
	void posToNextUnMarked();
	bool checkPosAtEnd();
	bool isPosAtEnd();
	int getId() { return id; }
};	