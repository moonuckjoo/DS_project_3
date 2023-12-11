#include <iostream>
#include <vector>
#include "GraphMethod.h"
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <utility>

using namespace std;
const int segment_size = 6;
int parent[10000];
bool BFS(Graph* graph, char option, int vertex)
{
	ofstream fout; // print to log.txt
	fout.open("log.txt", ios::app);
	queue<int> q;
	if (option == 'Y') {
		q.push(vertex);
		bool* visited_Y = new bool[graph->getSize()]; // for check visit
		for (int i = 0; i < graph->getSize(); i++) // initilize false
			visited_Y[i] = false;
		visited_Y[vertex] = true; // start vertex is visit
		map<int, int>* m = new map<int, int>[graph->getSize()]; // m is (to, weight)
		fout << "======== BFS ========" << endl;
		fout << "Directed Graph BFS result " << endl;
		fout << "startvertex: " << vertex << endl;
		fout << vertex;
		while (!q.empty()) // loop while stack is emtpy
		{
			int current_vertex = q.front(); // current vertex is stack's pop
			q.pop();
			graph->getAdjacentEdgesDirect(current_vertex, m);  // get adjacent edges to m
			auto iter = m[current_vertex].begin();
			while (iter != m[current_vertex].end()) {
				int to = iter->first;
				if (visited_Y[to] == false) {
					fout << " -> " << to;
					visited_Y[to] = true;
					q.push(to);
				}
				iter++;
			}

		}
		delete[] visited_Y;
		delete[] m;

		fout << endl << "======================" << endl << endl;
		fout.close();
		return true;
	}
	else if (option == 'N') {
		q.push(vertex);
		bool* visited_N = new bool[graph->getSize()]; // for check visit
		for (int i = 0; i < graph->getSize(); i++) // initilize false
			visited_N[i] = false;
		visited_N[vertex] = true; // start vertex is visit
		map<int, int>* m = new map<int, int>[graph->getSize()]; // m is (to, weight)
		fout << "======== BFS ========" << endl;
		fout << "Undirected Graph BFS result " << endl;
		fout << "startvertex: " << vertex << endl;
		fout << vertex;
		while (!q.empty()) // loop while stack is emtpy
		{
			int current_vertex = q.front(); // current vertex is stack's pop
			q.pop();
			graph->getAdjacentEdges(current_vertex, m);  // get adjacent edges to m
			auto iter = m[current_vertex].begin();
			while (iter != m[current_vertex].end()) {
				int to = iter->first;
				if (visited_N[to] == false) {
					fout << " -> " << to;
					visited_N[to] = true;
					q.push(to);
				}
				iter++;
			}

		}
		delete[] visited_N;
		delete[] m;

		fout << endl << "======================" << endl << endl;
		fout.close();
		return true;
	}
	else {
		fout.close();
		return false;
	}
	return true;
}

bool DFS(Graph* graph, char option, int vertex)
{

	ofstream fout; // print to log.txt
	fout.open("log.txt", ios::app);

	if (option == 'Y') { //case of direction
		bool* visited_Y = new bool[graph->getSize()]; // for check visit
		map<int, int>* m = new map<int, int>[graph->getSize()]; // m is (to, weight)
		for (int i = 0; i < graph->getSize(); i++) // initilize false
			visited_Y[i] = false;
		visited_Y[vertex] = true; // start vertex is visit

		stack<int> s; // use stack
		s.push(vertex); // push vertex to stack
		fout << "======== DFS ========" << endl;
		fout << "Directed Graph DFS result " << endl;
		fout << "startvertex: " << vertex << endl;
		if (graph->getSize() == 1) // if graph has only one vertex
		{
			fout << vertex << endl;
			delete[] visited_Y;
			delete[] m;
			fout << "======================" << endl << endl;
			fout.close();
			return true;
		}
		else {
			fout << vertex;
			while (!s.empty()) // loop while stack is emtpy
			{
				int current_vertex = s.top(); // current vertex is stack's pop
				graph->getAdjacentEdgesDirect(current_vertex, m);  // get adjacent edges to m
				auto iter = m[current_vertex].begin();
				while (iter != m[current_vertex].end()) {
					int to = iter->first;
					if (!visited_Y[to]) {
						fout << " -> " << to;
						visited_Y[to] = true;
						s.push(to);
						break;
					}
					iter++;
				}
				if (iter == m[current_vertex].end()) {
					s.pop();
				}
			}
			delete[] visited_Y;

		}

		fout << endl << "======================" << endl << endl;
		fout.close();
		delete[] m;

		return true;
	}
	else if (option == 'N') { //case of undirection
		bool* visited_N = new bool[graph->getSize()]; // for check visit
		map<int, int>* m = new map<int, int>[graph->getSize()]; // m is (to, weight)
		for (int i = 0; i < graph->getSize(); i++) // initilize false
			visited_N[i] = false;
		visited_N[vertex] = true; // start vertex is visit

		stack<int> s; // use stack
		s.push(vertex); // push vertex to stack
		fout << "======== DFS ========" << endl;
		fout << "Undirected Graph DFS result " << endl;
		fout << "startvertex: " << vertex << endl;
		if (graph->getSize() == 1) // if graph has only one vertex
		{
			fout << vertex << endl;
			delete[] visited_N;
			delete[] m;
			fout << "======================" << endl << endl;
			fout.close();
			return true;
		}
		else {
			fout << vertex;
			while (!s.empty()) // loop while stack is emtpy
			{
				int current_vertex = s.top(); // current vertex is stack's pop
				graph->getAdjacentEdges(current_vertex, m);  // get adjacent edges to m
				auto iter = m[current_vertex].begin();
				while (iter != m[current_vertex].end()) {
					int to = iter->first;
					if (!visited_N[to]) {
						fout << " -> " << to;
						visited_N[to] = true;
						s.push(to);
						break;
					}
					iter++;
				}
				if (iter == m[current_vertex].end()) {
					s.pop();
				}
			}
			delete[] visited_N;
			delete[] m;
		}

		fout << endl << "======================" << endl << endl;
		fout.close();


		return true;
	}
	else
		fout.close();
	return false;
}

bool Kruskal(Graph* graph)
{
	ofstream fout; // print to log.txt
	fout.open("log.txt", ios::app);

	map<int, int>* m = new map<int, int>[graph->getSize()]; // m is (to, weight)
	vector<pair<int, pair<int, int>>>* edges = new vector<pair<int, pair<int, int>>>; // weight, <from, to>

	for (int i = 1; i < graph->getSize(); i++) {
		parent[i] = i;
	}

	fout << "====== Kruskal =======" << endl; // print edge
	for (int i = 1; i < graph->getSize(); i++) {
		graph->getAdjacentEdgesDirect(i, m);
		auto iter = m[i].begin();
		while (iter != m[i].end()) {
			edges->push_back({ iter->second,{i,iter->first} });
			iter++;
		}
	}

	for (int i = 1; i < graph->getSize(); i++) {
		fout << "[" << i << "]" << "   ";
		for (auto iter = m[i].begin(); iter != m[i].end(); iter++) {
			fout << iter->first << "(" << iter->second << ")";
		}
		fout << endl;
	}

	QuickSort(edges, 0, edges->size() - 1);
	int result = 0;
	for (auto iter = edges->begin(); iter != edges->end(); iter++) {
		if (!sameparent(iter->second.first, iter->second.second)) {
			uni(iter->second.first, iter->second.second);
			result += iter->first;
		}
	}
	fout << "cost: " << result << endl;
	fout << "======================" << endl << endl;
	delete[] m;
	return true;
}

bool Dijkstra(Graph* graph, char option, int vertex)
{
	ofstream fout; // print to log.txt
	fout.open("log.txt", ios::app);
	map<int, int>* s = new map<int, int>[graph->getSize()];

	if (option == 'Y') {
		vector<pair<int, pair<int, int>>> w;
		for (int i = 1; i < graph->getSize(); i++) {
			graph->getAdjacentEdgesDirect(i, s);
			auto iter = s[i].begin();
			while (iter != s[i].end()) {
				w.push_back({ iter->second,{i,iter->first} });
				iter++;
			}
		}
		QuickSort(&w, 0, w.size() - 1);
		int result = 0;
		int i = 0;
		for (int i = 0; i < w.size(); i++) {
			if (w[i].first < 0) {
				fout.close();
				delete[] s;
				return false;
			}
		}
		fout << "======== Dijkstra ========" << endl;
		fout << "Directed Graph Dijkstra result " << endl;
		fout << "startvertex: " << vertex << endl;
		int* dist = new int[graph->getSize()];
		bool* visited = new bool[graph->getSize()];
		
		for (int i = 0; i < graph->getSize(); i++) {
			int length = INT_MAX;
			visited[i] = false;
			for (int j = 0; j < graph->getSize(); j++) {
				if ((w[j].second.first == vertex) && w[j].second.second == i)
					length = w[j].first;
			}
			dist[i] = length; //from vertex to i;
		}
		visited[0] = true;
		dist[0] = INT_MAX;
		visited[vertex] = true;
		dist[vertex] = 0;
		stack<int> path;
		for (int i = 0; i < graph->getSize()-2; i++) { //number of edge
			int minDist = INT_MAX;
			int minIndex = -1;

			for (int j = 0; j < graph->getSize(); j++) {
				if (!visited[j] && dist[j] < minDist) {
					minDist = dist[j];
					minIndex = j;
				}
			}
			
			visited[minIndex] = true;
			path.push(minIndex);
			// 최단 거리를 갖는 정점을 기준으로 인접한 정점들의 거리 갱신
			for (int j = 0; j < graph->getSize(); j++) {
				if (!visited[j] && graph->isAdjacent(minIndex, j) && dist[minIndex] + graph->getWeight(minIndex, j) < dist[j]) {
					dist[j] = dist[minIndex] + graph->getWeight(minIndex, j);
				}
			}
		}

		delete[] dist;
		delete[] visited;

		fout.close();
	}
	else if (option == 'N') {

		graph->getAdjacentEdges(vertex, s);
		fout << "======== Dijkstra ========" << endl;
		fout << "Undirected Graph Dijkstra result " << endl;
		fout << "startvertex: " << vertex << endl;

		fout.close();
	}
	else {

		fout.close();
	}
	return true;
}

bool Bellmanford(Graph* graph, char option, int s_vertex, int e_vertex)
{
	return true;
}

bool FLOYD(Graph* graph, char option)
{
	return true;
}

bool KWANGWOON(Graph* graph, int vertex) {
	return true;
}

void QuickSort(vector<pair<int, pair<int, int>>>* arr, const int left, const int right) // quick sort
{
	int i, j, pivot;
	if (left < right) {
		if (right - left + 1 <= segment_size) // if segment_size <= 6, insertion sort
			InsertionSort(arr, left, right); // insertion sort
		else { //quick sort
			int pivot = arr->at(left).first;
			pair<int, pair<int, int>> forSwap; // for sawp element
			i = left; // set i value
			j = right + 1; // set j value
			do {
				do i++; while (arr->at(i).first < pivot); // increase i to find bigger than pivot
				do j--; while (arr->at(j).first > pivot); // decrease j to find smaller than pivot
				if (i < j) {// swap(arr[i], arr[j])
					forSwap = arr->at(i);
					arr->at(i) = arr->at(j);
					arr->at(j) = forSwap;
				}
			} while (i < j);
			forSwap = arr->at(left); // swap
			arr->at(left) = arr->at(j);
			arr->at(j) = forSwap;

			QuickSort(arr, left, j - 1); // recursive
			QuickSort(arr, j + 1, right); // recursive
		}
	}
}

void InsertionSort(vector<pair<int, pair<int, int>>>* arr, int left, int right) { // insertion sort algorithm
	int j;
	pair<int, pair<int, int>> forSwap; // variable to use swap
	for (int i = left + 1; i <= right; i++) { // set loop range
		forSwap = arr->at(i); // set forSwap
		for (j = i - 1; j >= left; j--) {  // set loop range
			if (arr->at(j).first > forSwap.first)
				arr->at(j + 1) = arr->at(j); // change j+1 with j
			else
				break;
		}
		arr->at(j + 1) = forSwap; // set forSwap to arr->at(j+1)
	}
}

int find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
	x = find(x);
	y = find(y);
	parent[y] = x;
}
bool sameparent(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	else return false;
}

