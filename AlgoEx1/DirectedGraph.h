#pragma once
#include "Graph.h"
class DirectedGraph : public Graph
{
private:
	int* ColorArray;
public:
	DirectedGraph();
	~DirectedGraph();
	virtual void addEdge(int vertex1, int vertex2)override;
	virtual bool checkDegrees()override;
	virtual bool isConnected()override;
	virtual bool isEulerGraph()override;
	virtual list<int> findCircuit(Vertex& vertex) override;
	void BuildTranspose(DirectedGraph& output);
	void DFS_Return_EndList(vector<int>& EndList);
	int DFS_USE_MainLoop(vector<int>& MainLoop);
	void Visit_DFS__Return_EndList(int id, vector<int>& EndList);
	void Visit_DFS__Use_MainLoop(int id);
};