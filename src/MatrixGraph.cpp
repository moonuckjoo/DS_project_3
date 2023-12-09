#include "MatrixGraph.h"
#include <iostream>
#include <vector>
#include <string>

MatrixGraph::MatrixGraph(bool type, int size) : Graph(type, size)
{
	m_Mat = new int* [size+1]; //matrix graph
	for (int i = 0; i < size+1; i++) {
		m_Mat[i] = new int[size+1];
	}
	
}

MatrixGraph::~MatrixGraph()
{

}

void MatrixGraph::getAdjacentEdges(int vertex, map<int, int>* m)
{	
	
}

void MatrixGraph::getAdjacentEdgesDirect(int vertex, map<int, int>* m)
{
	
}

void MatrixGraph::insertEdge(int from, int to, int weight)	
{
	m_Mat[from][to] = weight;
}

bool MatrixGraph::printGraph(ofstream *fout)	
{

	*fout << "======== PRINT========" << endl;
	while () {
		*fout<< "[" << i << "]"
	}

	*fout << "======================" <<endl << endl;
}

