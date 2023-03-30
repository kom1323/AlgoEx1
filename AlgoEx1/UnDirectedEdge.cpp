#include "UnDirectedEdge.h"



UndirectedEdge::UndirectedEdge(int toVertex): Edge(toVertex), mark(false), twinCopy(nullptr)
{
}

void UndirectedEdge::setTwinCopy(UndirectedEdge* twin)
{
	this->twinCopy = twin;
	twin->twinCopy = this->twinCopy;
}

void UndirectedEdge::markEdge(){

	this->mark = true;
	this->twinCopy->mark = true;
}
