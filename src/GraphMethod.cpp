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
		vector<pair<int, int>>* nodes = new vector<pair<int, int>>[graph->getSize()];
		for (int i = 1; i < graph->getSize(); i++) {
			graph->getAdjacentEdgesDirect(i, s);

			auto iter = s[i].begin();
			while (iter != s[i].end()) {
				if (iter->second < 0) {
					delete[] s;
					delete[] nodes;
					fout.close();
					return false;
				}
				nodes[i].push_back({ iter->second,iter->first });
				iter++;
			}
		}
		int dist[10000]; //vertex ~to , cost
		priority_queue<pair<int, int>> pq; //cost, to
		for (int i = 0; i < 10000; i++) {
				dist[i] = INT_MAX;
		}
		

		pq.push({0, vertex});
		dist[vertex] = 0;
		fout << "======== Dijkstra ========" << endl;
		fout << "Directed Graph Dijkstra result " << endl;
		fout << "startvertex: " << vertex << endl;

		stack <int>* path = new stack<int>[graph->getSize()];
		int* result = new int[graph->getSize()];
		for (int i = 0; i < graph->getSize(); i++) {
			result[i] = 0;
		}
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int from = pq.top().second;
			pq.pop();

			for (int i = 0; i < nodes[from].size(); i++) {
				int via_cost = cost + nodes[from][i].first; //next cost
				int nxt_node = nodes[from][i].second;  //next node

				if (via_cost < dist[nxt_node]) {
					result[nxt_node] = 0;
					dist[nxt_node] = via_cost;
					pq.push({ -via_cost, nxt_node });
					path[nxt_node].push(from);
					result[nxt_node] = via_cost;
				}
			}
		}
		for (int i = 1; i < graph->getSize(); i++) {
			if (!path[i].empty()&&!(i==vertex)) {
				fout << "[" << i << "]" << "  " << vertex;
			}
			else {
				continue;
			}
			while(!path[i].empty()) {
				int num = path[i].top();
				path[i].pop();
				fout << "->" << num;
			}
			if (result != 0) {
				fout <<result[i] << endl;
			}
		}
		fout << "======================" << endl << endl;
		fout.close();
	}
	else if (option == 'N') {

		vector<vector<pair<int, int>>> nodes;
		for (int i = 1; i < graph->getSize(); i++) {
			graph->getAdjacentEdges(i, s);
			auto iter = s[i].begin();
			while (iter != s[i].end()) {
				nodes[i].push_back({ iter->second,iter->first });
				iter++;
			}
		}
		int result = 0;
		int dist[10000]; //vertex ~to , cost
		priority_queue<pair<int, int>> pq; //cost, to
		for (int i = 0; i < 10000; i++) {
			dist[i] = INT_MAX;
		}
		dist[vertex] = 0;

		pq.push({ 0, vertex });
		fout << "======== Dijkstra ========" << endl;
		fout << "Undirected Graph Dijkstra result " << endl;
		fout << "startvertex: " << vertex << endl;
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int to = pq.top().second;
			pq.pop();

			if (dist[to] < cost)
				continue;

			for (int i = 0; i < nodes[to].size(); i++) {
				int via_cost = cost + nodes[to][i].first;

				if (via_cost < dist[nodes[to][i].second]) {
					dist[nodes[to][i].second] = via_cost;
					pq.push({ -via_cost, nodes[to][i].second });
				}
			}
		}

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
int get_small_node(int ** dist, bool** visited, int size) {
	// 최소비용노드 탐색 함수
	int min = INT_MAX;
	int minpos = 0;
	for (int i = 0; i < size; i++) {
		if (*dist[i] < min && !visited[i]) {
			min = *dist[i];
			minpos = i;
		}
	}
	return minpos;
}
