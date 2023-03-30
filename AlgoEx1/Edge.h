#pragma once
class Edge
{
protected:
	int edgeToVertex;
	Edge(int Vertex) :edgeToVertex(Vertex){}

public:
	Edge(const Edge& other)=delete;
	virtual ~Edge() = default;
	int getEdge() { return edgeToVertex; }
};