#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(int numOfVertices) :Graph(numOfVertices)
{
	this->ColorArray = nullptr;
}
DirectedGraph::~DirectedGraph()
{
	delete []ColorArray;
}
void DirectedGraph::addEdge(int vertex1, int vertex2)
{
	vector<Vertex>::iterator itr = vertices.begin();
	(itr + vertex1)->AddEdge(vertex2,DIRECTED_EDGE);
}
bool DirectedGraph::checkDegrees()
{
	int* indegree = new int[vertices.size()];
	int* outdegree = new int[vertices.size()];
	for (int i = 0; i < vertices.size(); i++)
	{
		indegree[i] = 0;
		outdegree[i] = 0;
	}

	for (int i =1; i<vertices.size(); i++)
	{
		list<Edge*>::iterator itrEdge = vertices[i].Edges.begin();
		list<Edge*>::iterator itrEdgeEnd = vertices[i].Edges.end();
		for (; itrEdge != itrEdgeEnd; ++itrEdge)
		{
			outdegree[i]++;
			indegree[(*itrEdge)->getEdge()]++;
		}
	}
	bool EQUAL = true;
	for (int i = 0; i <vertices.size() && EQUAL; i++)
	{
		if (indegree[i] != outdegree[i])
			EQUAL = false;
	}
	delete[]indegree;
	delete[]outdegree;
	return EQUAL;
}
void DirectedGraph::BuildTranspose(DirectedGraph& output)
{
	int numOfvertices = vertices.size();
	for (int i = 0; i< vertices.size(); i++)
	{
		list<Edge*>::iterator itrEdge = vertices[i].Edges.begin();
		list<Edge*>::iterator itrEdgeEnd = vertices[i].Edges.end();
		for (; itrEdge != itrEdgeEnd; ++itrEdge)
		{
			output.addEdge((*itrEdge)->getEdge(), i);
		}
	}
}
bool DirectedGraph::isConnected()
{
	DirectedGraph transposeGraph(vertices.size());
	vector<int> EndList;
	BuildTranspose(transposeGraph);
	DFS_Return_EndList(EndList);
	int numOfTrees = DFS_USE_MainLoop(EndList);
	return (numOfTrees==1);
}
void DirectedGraph::DFS_Return_EndList(vector<int>& EndList)
{
	this->ColorArray = new int[vertices.size()];
	for (int i = 0; i < vertices.size(); i++)
		ColorArray[i] = WHITE;
	for (int i = 1; i < vertices.size(); i++)
	{
		if (ColorArray[i] == WHITE)
			Visit_DFS__Return_EndList(i, EndList);
	}
}
void DirectedGraph::Visit_DFS__Return_EndList(int id, vector<int>& EndList)
{
	this->ColorArray[id] = GRAY;
	vector<Vertex>::iterator itrVertex = vertices.begin();
	list<Edge*>::iterator itrEdge = (itrVertex + id )->Edges.begin();
	list<Edge*>::iterator itrEdgeEnd = (itrVertex + id )->Edges.end();
	for (; itrEdge != itrEdgeEnd; ++itrEdge)
	{
		if (ColorArray[(*itrEdge)->getEdge()] == WHITE)
			Visit_DFS__Return_EndList((*itrEdge)->getEdge(), EndList);
	}
	this->ColorArray[id] = BLACK;
	EndList.push_back(id);
}
int DirectedGraph::DFS_USE_MainLoop(vector<int>& MainLoop)
{
	int Use_Vist_Func = 0;
	this->ColorArray = new int[vertices.size()];
	for (int i = 0; i < vertices.size(); i++)
		ColorArray[i] = WHITE;
	vector<int>::iterator itrLoop = MainLoop.end()-1;
	vector<int>::iterator itrLoopEnd = MainLoop.begin();
	for (; itrLoop != itrLoopEnd; --itrLoop)
	{
		if (ColorArray[(*itrLoop)] == WHITE)
		{
			++Use_Vist_Func;
			Visit_DFS__Use_MainLoop((*itrLoop));
		}	
	}
	return Use_Vist_Func;
}
void DirectedGraph::Visit_DFS__Use_MainLoop(int id)
{
	this->ColorArray[id - 1] = GRAY;
	vector<Vertex>::iterator itrVertex = vertices.begin();
	list<Edge*>::iterator itrEdge = (itrVertex + id)->Edges.begin();
	list<Edge*>::iterator itrEdgeEnd = (itrVertex + id)->Edges.end();
	for (; itrEdge != itrEdgeEnd; ++itrEdge)
	{
		if (ColorArray[(*itrEdge)->getEdge()] == WHITE)
			Visit_DFS__Use_MainLoop((*itrEdge)->getEdge());
	}
	this->ColorArray[id] = BLACK;
}
bool DirectedGraph::isEulerGraph()
{
	if (vertices.size() <= 2)//****************************************
		return false;
	return (checkDegrees() && isConnected());
}
list<int> DirectedGraph::findCircuit(int vertex)
{
	int currentVertex = vertex;
	int nextVertex;
	list<int> Circuit;
	Circuit.push_back(currentVertex);
	while(!vertices[currentVertex].checkPosAtEnd())
	{
		nextVertex = (*(vertices[currentVertex].pos))->getEdge();
		++((vertices[currentVertex].pos));
		Circuit.push_back(nextVertex);
		currentVertex = nextVertex;
	} 
	return Circuit;
}
