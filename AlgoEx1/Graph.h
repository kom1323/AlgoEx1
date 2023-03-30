#pragma once
#include "Edge.h"
#include "Vertex.h"
#include <vector>
class Graph
{
protected:
	static int counter;
	vector<Vertex> vertices;
public:
	Graph() = default;
	~Graph() = default;
	virtual void addEdge() = 0;
	virtual void addVertx();
	virtual int getNumOfVertices()const;
	virtual bool isConnected()=0;
	virtual bool isEulerGraph()= 0;
	virtual list<Edge*> findCircuit(Vertex & vertex) = 0;
};