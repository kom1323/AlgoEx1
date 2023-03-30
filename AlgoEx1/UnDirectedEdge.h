#pragma once
#include "Edge.h"

class UndirectedEdge : protected Edge
{
private:
	
	bool mark;
	UndirectedEdge* twinCopy;

public:
	UndirectedEdge(int toVertex);
	void setTwinCopy(UndirectedEdge* twin);
	void markEdge();

	


};