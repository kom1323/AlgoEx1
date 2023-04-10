#pragma once
#include "Edge.h"
#include "Vertex.h"
#include <vector>
#include <iostream>
#define WHITE 0
#define GRAY 1
#define BLACK 2
class Graph
{
protected:
	vector<Vertex> vertices;
public:
	Graph(int numOfVertices);
	~Graph() = default;
	virtual void addEdge(int vertex1,int vertex2) = 0;
	virtual bool isConnected()=0;
	virtual bool checkDegrees() = 0;
	virtual bool isEulerGraph()= 0;
	virtual void Euler();
	virtual list<int> findCircuit(int vertex) = 0;
	
};