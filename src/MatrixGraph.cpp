#include "MatrixGraph.h"
#include <iostream>
#include <vector>
#include <string>

MatrixGraph::MatrixGraph(bool type, int size) : Graph(type, size)
{
	m_Type = type;
	m_Mat = new int* [size]; //matrix graph
	for (int i = 1; i < size; i++) {
		m_Mat[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m_Mat[i][j] = 0;
		}
	}
}

MatrixGraph::~MatrixGraph()
{	//delete memory
	for (int i = 1; i < getSize(); i++) {
		delete[] m_Mat[i];
	}
	delete[] m_Mat;
}

void MatrixGraph::getAdjacentEdges(int vertex, map<int, int>* m)
{
	for (int j = 1; j < getSize(); j++) {
		for (int i = 1; i < getSize(); i++) {
			if (m_Mat[j][i] != 0) {
				m[j].insert({ i,m_Mat[j][i] }); //first is weight
				m[i].insert({ j,m_Mat[j][i] });
			}
		}
	}
}

void MatrixGraph::getAdjacentEdgesDirect(int vertex, map<int, int>* m)
{
	for (int i = 1; i < getSize(); i++){
			if (m_Mat[vertex][i] != 0) {
				m[vertex].insert({i,m_Mat[vertex][i]});
			}
	}
}

void MatrixGraph::insertEdge(int from, int to, int weight)
{
	if (from >= 1 && from < (getSize()) && to >= 1 && to < (getSize())) {
		m_Mat[from][to] = weight;
	}
}

bool MatrixGraph::printGraph(ofstream* fout)
{
	*fout << "======== PRINT========" << endl;
	*fout << "     ";
	for (int i = 1; i < getSize(); i++) {
		*fout << "[" << i << "]" << "   ";
	}
	*fout << endl;
	for (int i = 1; i < getSize(); i++) {
		*fout << "[" << i << "]" << "  ";
		for (int j = 1; j < getSize(); j++) {
			*fout << m_Mat[i][j] << "     ";
		}
		*fout << endl;
	}
	*fout << "======================" << endl << endl;
	return true;

}

