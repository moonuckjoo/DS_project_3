#include "ListGraph.h"
#include <iostream>
#include <utility>

ListGraph::ListGraph(bool type, int size) : Graph(type, size)
{
	m_Type = type;
	m_List = new map<int,int>[size];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m_List[i][j] = 0;
		}
	}
}

ListGraph::~ListGraph()	
{
	delete[] m_List;
}

void ListGraph::getAdjacentEdges(int vertex, map<int, int>* m)	 //Definition of getAdjacentEdges(No Direction == Undirected)
{
	for (int i = 0; i < getSize(); i++) {
		for (auto& iter : m_List[i]) {
			if (iter.second != 0) {
				m[i].insert({ iter.first, iter.second });
				m[iter.first].insert({ i, iter.second });
			}
		}
	}
	return;
}

void ListGraph::getAdjacentEdgesDirect(int vertex, map<int, int>* m)	//Definition of getAdjacentEdges(Directed graph)
{
	for (auto& iter : m_List[vertex]) {
		if (iter.second != 0) {
		m[vertex].insert({ iter.first, iter.second});
		}
	}
	return;
}

void ListGraph::insertEdge(int from, int to, int weight) //Definition of insertEdge
{
	if (from >= 1 && from < (getSize()) && to >= 1 && to < (getSize())) {
		m_List[from].insert({ to, weight });
	}
}

bool ListGraph::printGraph(ofstream *fout)	//Definition of print Graph
{
	*fout << "======== PRINT========" << endl;
	
	for (int i = 1; i < getSize(); i++) {
		auto iter = m_List[i].begin();
		*fout << "[" << i << "]";
		for (int j = 1; j < getSize(); j++) {
			if (iter->second == 0) {
				continue;
			}
			else {
				*fout << "-> " << "(" << iter->first << "," <<iter->second << ")";
			}
			iter++;
			if (iter == m_List[i].end())
				break;
		}
		*fout << endl;
	}
	*fout << "======================" << endl << endl;
	return true;
}