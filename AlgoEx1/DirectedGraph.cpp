#include "DirectedGraph.h"

DirectedGraph::DirectedGraph() :Graph()
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
	int* indegree = new int[counter];
	int* outdegree = new int[counter];
	for (int i = 0; i < counter; i++)
	{
		indegree[i] = 0;
		outdegree[i] = 0;
	}
	vector<Vertex>::iterator itrVertex = vertices.begin();
	vector<Vertex>::iterator itrVertexEnd = vertices.begin();
	for (int i = 0; itrVertex != itrVertexEnd; ++itrVertex)
	{
		list<Edge*>::iterator itrEdge = itrVertex->Edges.begin();
		list<Edge*>::iterator itrEdgeEnd = itrVertex->Edges.end();
		for (int j = 0; itrEdge != itrEdgeEnd; ++itrEdge)
		{
			outdegree[i];
			indegree[(*itrEdge)->getEdge()]++;
			j++;
		}
		i++;
	}
	bool EQUAL = true;
	for (int i = 0; i < counter && EQUAL; i++)
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
	int numOfvertices = counter;
	counter = 0;
	for (int i = 0; i < numOfvertices; i++)
		output.addVertx();
	vector<Vertex>::iterator itrVertex = vertices.begin();
	vector<Vertex>::iterator itrVertexEnd = vertices.begin();
	for (int i = 0; itrVertex != itrVertexEnd; ++itrVertex)
	{
		list<Edge*>::iterator itrEdge = itrVertex->Edges.begin();
		list<Edge*>::iterator itrEdgeEnd = itrVertex->Edges.end();
		for (int j = 0; itrEdge != itrEdgeEnd; ++itrEdge)
		{
			output.addEdge((*itrEdge)->getEdge(), i);
			j++;
		}
		i++;
	}
}
bool DirectedGraph::isConnected()
{
	DirectedGraph transposeGraph;
	vector<int> EndList;
	BuildTranspose(transposeGraph);
	DFS_Return_EndList(EndList);
	int numOfTrees = DFS_USE_MainLoop(EndList);
	return (numOfTrees==1);
}
void DirectedGraph::DFS_Return_EndList(vector<int>& EndList)
{
	this->ColorArray = new int[counter];
	for (int i = 0; i < counter; i++)
		ColorArray[i] = WHITE;
	vector<Vertex>::iterator itrVertex = vertices.begin();
	vector<Vertex>::iterator itrVertexEnd = vertices.begin();
	for (; itrVertex != itrVertexEnd; ++itrVertex)
	{
		if (ColorArray[itrVertex->getId()-1] == WHITE)
			Visit_DFS__Return_EndList(itrVertex->getId(), EndList);
	}
}
void DirectedGraph::Visit_DFS__Return_EndList(int id, vector<int>& EndList)
{
	this->ColorArray[id - 1] = GRAY;
	vector<Vertex>::iterator itrVertex = vertices.begin();
	list<Edge*>::iterator itrEdge = (itrVertex + id - 1)->Edges.begin();
	list<Edge*>::iterator itrEdgeEnd = (itrVertex + id - 1)->Edges.end();
	for (; itrEdge != itrEdgeEnd; ++itrEdge)
	{
		if (ColorArray[(*itrEdge)->getEdge()-1] == WHITE)
			Visit_DFS__Return_EndList((*itrEdge)->getEdge(), EndList);
	}
	this->ColorArray[id - 1] = BLACK;
	EndList.push_back(id - 1);
}
int DirectedGraph::DFS_USE_MainLoop(vector<int>& MainLoop)
{
	int Use_Vist_Func = 0;
	this->ColorArray = new int[counter];
	for (int i = 0; i < counter; i++)
		ColorArray[i] = WHITE;
	vector<int>::iterator itrLoop = MainLoop.end();
	vector<int>::iterator itrLoopEnd = MainLoop.begin();
	for (; itrLoop != itrLoopEnd; --itrLoop)
	{
		if (ColorArray[(*itrLoop)-1] == WHITE)
		{
			++Use_Vist_Func;
			Visit_DFS__Use_MainLoop((*itrLoop) - 1);
		}	
	}
	return Use_Vist_Func;
}
void DirectedGraph::Visit_DFS__Use_MainLoop(int id)
{
	this->ColorArray[id - 1] = GRAY;
	vector<Vertex>::iterator itrVertex = vertices.begin();
	list<Edge*>::iterator itrEdge = (itrVertex + id - 1)->Edges.begin();
	list<Edge*>::iterator itrEdgeEnd = (itrVertex + id - 1)->Edges.end();
	for (; itrEdge != itrEdgeEnd; ++itrEdge)
	{
		if (ColorArray[(*itrEdge)->getEdge() - 1] == WHITE)
			Visit_DFS__Use_MainLoop((*itrEdge)->getEdge());
	}
	this->ColorArray[id - 1] = BLACK;
}
bool DirectedGraph::isEulerGraph()
{
	if (counter <= 2)
		return false;
	return (checkDegrees() && isConnected());
}
list<int> DirectedGraph::findCircuit(Vertex& vertex)
{
	vector<Vertex>::iterator itrVertex = vertices.begin();
	int currentVertex = vertex.getId();
	int nextVertex;
	list<int> Circuit;
	Circuit.push_back(currentVertex);
	do
	{
		nextVertex = (*((itrVertex + currentVertex - 1)->pos))->getEdge();
		++(*((itrVertex + currentVertex - 1)->pos));
		Circuit.push_back(nextVertex);
		currentVertex = nextVertex;
	} while (!(itrVertex + currentVertex - 1)->isPosAtEnd());
	return Circuit;
}
