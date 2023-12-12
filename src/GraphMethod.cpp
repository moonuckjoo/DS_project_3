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
int parent[10000] = {};

bool BFS(Graph* graph, char option, int vertex)
{
	ofstream fout; // print to log.txt
	fout.open("log.txt", ios::app);
	queue<int> q;
	if (option == 'Y') {
		q.push(vertex);
		bool visited_Y[10000] = {}; // for check visit
		for (int i = 0; i < 10000; i++) {
			visited_Y[i] = true;
		}
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
		delete[] m;

		fout << endl << "======================" << endl << endl;
		fout.close();
		return true;
	}
	else if (option == 'N') {
		q.push(vertex);
		bool visited_N[10000] = {}; // for check visit
		for (int i = 0; i < 10000; i++) {
			visited_N[i] = true;
		}
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
		bool visited_Y[10000] = {}; // for check visit
		for (int i = 0; i < 10000; i++) {
			visited_Y[i] = true;
		}
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

		}

		fout << endl << "======================" << endl << endl;
		fout.close();
		delete[] m;

		return true;
	}
	else if (option == 'N') { //case of undirection
		bool visited_N[10000] = {}; // for check visit
		for (int i = 0; i < 10000; i++) {
			visited_N[i] = true;
		}
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
			delete[] m;
		}

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
	int cnt = 0; //always number of edge is n-1
	for (auto iter = edges->begin(); iter != edges->end(); iter++) {
		if (!sameparent(iter->second.first, iter->second.second)) {
			uni(iter->second.first, iter->second.second);
			result += iter->first;
			cnt++;
		}
	}

	if (cnt != graph->getSize()-2) { //edge is n-1;
		delete[] m;
		delete edges;
		return false;
	}
	fout << "cost: " << result << endl;
	fout << "======================" << endl << endl;
	delete[] m;
	delete edges;
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
			while (iter != s[i].end()) {  //minus case handling
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
		int dist[10000] = {}; //vertex ~to , cost
		priority_queue<pair<int, int>> pq; //cost, to
		for (int i = 0; i < 10000; i++) {
			dist[i] = INT_MAX;
		}


		pq.push({ 0, vertex });
		dist[vertex] = 0;
		fout << "======== Dijkstra ========" << endl;
		fout << "Directed Graph Dijkstra result " << endl;
		fout << "startvertex: " << vertex << endl;

		stack <int>* path = new stack<int>[graph->getSize()];
		int prev[10000] = {};
		for (int i = 0; i < 1000; i++) {
			prev[i] = INT_MAX;
		}
		prev[vertex] = vertex;
		int result[10000] = {};
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
					prev[nxt_node] = from;
					pq.push({ -via_cost, nxt_node });
					result[nxt_node] = via_cost;
				}
			}
		}
		for (int i = 1; i < graph->getSize(); i++) {
			if (i == vertex) continue;
			path[i].push(i);
			for (int j = i; vertex != prev[j]; j = prev[j]) {
				path[i].push(prev[j]);
			}

		}

		for (int i = 1; i < graph->getSize(); i++) {
			if (!(i == vertex)) {
				fout << "[" << i << "]" << "  " << vertex;
			}
			else {
				continue;
			}
			if (path[i].empty()) { //case of no distance handling
				fout << "x " << endl;
				continue;
			}
			while (!path[i].empty()) {
				int num = path[i].top();
				path[i].pop();
				fout << "->" << num;
			}
			if (result[i] != 0) {
				fout << "(" << result[i] << ")" << endl;
			}
		}
		fout << "======================" << endl << endl;
		delete[] nodes;
		delete[] path;
		delete[] s;
		fout.close();
	}
	else if (option == 'N') {

		vector<pair<int, int>>* nodes = new vector<pair<int, int>>[graph->getSize()];
		for (int i = 1; i < graph->getSize(); i++) {
			graph->getAdjacentEdges(i, s);

			auto iter = s[i].begin();
			while (iter != s[i].end()) {
				if (iter->second < 0) { //minus case handling
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


		pq.push({ 0, vertex });
		dist[vertex] = 0;
		fout << "======== Dijkstra ========" << endl;
		fout << "Undirected Graph Dijkstra result " << endl;
		fout << "startvertex: " << vertex << endl;

		stack <int>* path = new stack<int>[graph->getSize()];
		int prev[10000];
		for (int i = 0; i < 1000; i++) {
			prev[i] = INT_MAX;
		}
		prev[vertex] = vertex;
		int result[10000];
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
					prev[nxt_node] = from;
					pq.push({ -via_cost, nxt_node });
					result[nxt_node] = via_cost;
				}
			}
		}
		for (int i = 1; i < graph->getSize(); i++) {
			if (i == vertex) continue;
			path[i].push(i);
			for (int j = i; vertex != prev[j]; j = prev[j]) {
				path[i].push(prev[j]);
			}

		}

		for (int i = 1; i < graph->getSize(); i++) {
			if (!(i == vertex)) {
				fout << "[" << i << "]" << "  " << vertex;
			}
			else {
				continue;
			}
			if (path[i].empty()) { //case of no distance handling
				fout << "x" << endl;
				continue;
			}
			while (!path[i].empty()) {
				int num = path[i].top();
				path[i].pop();
				fout << "->" << num;
			}
			if (result[i] != 0) {
				fout << "(" << result[i] << ")" << endl;
			}
		}
		fout << "======================" << endl << endl;
		delete[] nodes;
		delete[] path;
		delete[] s;
		fout.close();
	}
	else {
		delete[] s;
		fout.close();
		return false;
	}
	return true;
}

bool Bellmanford(Graph* graph, char option, int s_vertex, int e_vertex)
{
	ofstream fout; // print to log.txt
	fout.open("log.txt", ios::app);

	if (option == 'Y') {
		map<int, int>* s = new map<int, int>[graph->getSize()];
		int size = graph->getSize();
		vector<int> dist(size, INT_MAX); //initialize
		vector<int> prev(size, INT_MAX); //initialize
		vector <pair<int, int>>* edge = new vector<pair<int, int>>[size];
		dist[s_vertex] = 0;
		prev[s_vertex] = s_vertex;
		queue <int> path;
		int result[10000];
		for (int i = 0; i < 10000; i++) {
			result[i] = 0;
		}
		for (int i = 1; i < size; i++)
			graph->getAdjacentEdgesDirect(i, s); //s[from](to.weight)

		for (int from = 1; from < size; from++) {
			auto iter = s[from].begin();
			while (iter != s[from].end()) {
				edge[from].push_back({ iter->first,iter->second });
				iter++;
			}
		}
		for (int k = 0; k <= size - 2; k++) { //max edge to middle
			for (int from = 1; from < size; from++) { //i is from
				for (int j = 0; j < edge[from].size(); j++) { //j.first is to, j.second is weight
					int to = edge[from][j].first;
					int cost = edge[from][j].second;
					if (dist[from] != INT_MAX && dist[to] > dist[from] + cost) {
						result[to] = 0;
						dist[to] = dist[from] + cost;
						prev[to] = from;
						result[to] = dist[to];
					}
				}

			}
		}
		for (int from = 1; from < size; from++)
		{
			for (int j = 0; j < edge[from].size(); j++)
			{
				int to = edge[from][j].first;
				int cost = edge[from][j].second;

				// case of negaive cycle check
				if (dist[from] != INT_MAX && dist[to] > dist[from] + cost)
				{
					delete[] s;
					delete[] edge;
					return false;
				}
			}
		}
		//print
		if (dist[e_vertex] == INT_MAX) { //no distance
			fout << "========Bellman-Ford========" << endl;
			fout << "Directed Graph Bellman - Ford result" << endl;
			fout << s_vertex << endl;
			fout << "x" << endl;
			fout << "========================" << endl << endl;
			delete[] s;
			delete[] edge;
			fout.close();
			return true;
		}
		for (int i = e_vertex; i != prev[i]; i = prev[i]) {
			if (prev[i] == INT_MAX) { //case of no dist;
				fout << "========Bellman-Ford========" << endl;
				fout << "Directed Graph Bellman - Ford result" << endl;
				fout << s_vertex << endl;
				fout << "x" << endl;
				fout << "========================" << endl << endl;
				delete[] s;
				delete[] edge;
				fout.close();
				return true;
			}
			else {
				path.push(prev[i]);
			}

		}
		fout << "========Bellman-Ford========" << endl;
		fout << "Directed Graph Bellman - Ford result" << endl;
		fout << s_vertex;
		while (path.size() > 1) {
			int num = path.front();
			path.pop();
			fout << "->" << num;
		}
		fout << "->" << e_vertex;
		if (result[e_vertex] != 0) {
			fout << "(" << result[e_vertex] << ")" << endl;
		}

		fout << "========================" << endl << endl;

		delete[] s;
		delete[] edge;
		fout.close();
	}

	else if (option == 'N') {
		map<int, int>* s = new map<int, int>[graph->getSize()];
		int size = graph->getSize();
		vector<int> dist(size, INT_MAX); //initialize
		vector<int> prev(size, INT_MAX); //initialize
		vector <pair<int, int>>* edge = new vector<pair<int, int>>[size];
		dist[s_vertex] = 0;
		prev[s_vertex] = s_vertex;
		queue <int> path;
		int result[10000];
		for (int i = 0; i < 10000; i++) {
			result[i] = 0;
		}
		for (int i = 1; i < size; i++)
			graph->getAdjacentEdges(i, s); //s[from](to.weight)

		for (int from = 1; from < size; from++) {
			auto iter = s[from].begin();
			while (iter != s[from].end()) {
				edge[from].push_back({ iter->first,iter->second });
				iter++;
			}
		}
		for (int k = 0; k <= size - 2; k++) { //max edge to middle
			for (int from = 1; from < size; from++) { //i is from
				for (int j = 0; j < edge[from].size(); j++) { //j.first is to, j.second is weight
					int to = edge[from][j].first;
					int cost = edge[from][j].second;
					if (dist[from] != INT_MAX && dist[to] > dist[from] + cost) {
						result[to] = 0;
						dist[to] = dist[from] + cost;
						prev[to] = from;
						result[to] = dist[to];
					}
				}

			}
		}
		for (int from = 1; from < size; from++)
		{
			for (int j = 0; j < edge[from].size(); j++)
			{
				int to = edge[from][j].first;
				int cost = edge[from][j].second;

				// case of negaive cycle check
				if (dist[from] != INT_MAX && dist[to] > dist[from] + cost)
				{
					delete[] s;
					delete[] edge;
					return false;
				}
			}
		}
		//print
		if (dist[e_vertex] == INT_MAX) { //no distance
			fout << "========Bellman-Ford========" << endl;
			fout << "Directed Graph Bellman - Ford result" << endl;
			fout << s_vertex << endl;
			fout << "x" << endl;
			fout << "========================" << endl << endl;
			delete[] s;
			delete[] edge;
			fout.close();
			return true;
		}
		for (int i = e_vertex; i != prev[i]; i = prev[i]) {
			if (prev[i] == INT_MAX) { //case of no dist;
				fout << "========Bellman-Ford========" << endl;
				fout << "Directed Graph Bellman - Ford result" << endl;
				fout << s_vertex << endl;
				fout << "x" << endl;
				fout << "========================" << endl << endl;
				delete[] s;
				delete[] edge;
				fout.close();
				return true;
			}
			else {
				path.push(prev[i]);
			}

		}
		fout << "========Bellman-Ford========" << endl;
		fout << "Undirected Graph Bellman - Ford result" << endl;
		fout << s_vertex;
		while (path.size() > 1) {
			int num = path.front();
			path.pop();
			fout << "->" << num;
		}
		fout << "->" << e_vertex;
		if (result[e_vertex] != 0) {
			fout << "(" << result[e_vertex] << ")" << endl;
		}

		fout << "========================" << endl << endl;

		delete[] s;
		delete[] edge;
		fout.close();
	}
	else {
		fout.close();
		return false;
	}
}

bool FLOYD(Graph* graph, char option)
{
	ofstream fout; // print to log.txt
	fout.open("log.txt", ios::app);
	int size = graph->getSize();
	map<int, int>* m = new map<int, int>[size]; // m is (to, weight)
	if (option == 'Y') {
		int dist[100][100];
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				dist[i][j] = 99999;
			}
		}

		for (int from = 1; from < size; from++) {
			graph->getAdjacentEdgesDirect(from, m);
		}

		for (int i = 1; i < size; i++) {
			auto iter = m[i].begin();
			while (iter != m[i].end()) {
				dist[i][iter->first] = iter->second;
				iter++;
			}
		}
		for (int i = 1; i < size; i++) {
			for (int j = 1; j < size; j++) {
				if (i == j) dist[i][j] = 0;
			}
		}
		for (int k = 1; k < size; k++) {
			for (int from = 1; from < size; from++) {
				for (int to = 1; to < size; to++) {
					if (dist[from][k] + dist[k][to] < dist[from][to]) {
						dist[from][to] = dist[from][k] + dist[k][to];
					}
				}
			}
		}

		for (int k = 1; k < size; k++) { //case of minus cycle
			for (int from = 1; from < size; from++) {
				for (int to = 1; to < size; to++) {
					if (dist[from][k] + dist[k][to] < dist[from][to]) {
						delete[] m;
						fout.close();
						return false;
					}
				}
			}
		}



		fout << "========FLOYD========" << endl;
		fout << "Directed Graph FLOYD result" << endl;
		fout << "    ";
		for (int i = 1; i < size; i++) {
			fout << "[" << i << "]  ";
		}
		fout << endl;
		for (int i = 1; i < size; i++)
		{
			fout << "[" << i << "]  ";
			for (int j = 1; j < size; j++)
			{
				if (dist[i][j] == 99999) { //if no change, infinite == no distance
					fout << "x   ";
				}
				else {
					fout << dist[i][j] << "   ";
				}
			}
			fout << endl;
		}
		fout << endl << "========================" << endl << endl;
	}


	else if (option == 'N') {

		int dist[100][100];
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				dist[i][j] = 99999;
			}
		}

		for (int from = 1; from < size; from++) {
			graph->getAdjacentEdges(from, m);
		}

		for (int i = 1; i < size; i++) {
			auto iter = m[i].begin();
			while (iter != m[i].end()) {
				dist[i][iter->first] = iter->second;
				iter++;
			}
		}
		for (int i = 1; i < size; i++) {
			for (int j = 1; j < size; j++) {
				if (i == j) dist[i][j] = 0;
			}
		}
		for (int k = 1; k < size; k++) {
			for (int from = 1; from < size; from++) {
				for (int to = 1; to < size; to++) {
					if (dist[from][k] + dist[k][to] < dist[from][to]) {
						dist[from][to] = dist[from][k] + dist[k][to];
					}
				}
			}
		}

		for (int k = 1; k < size; k++) { //case of minus cycle
			for (int from = 1; from < size; from++) {
				for (int to = 1; to < size; to++) {
					if (dist[from][k] + dist[k][to] < dist[from][to]) {
						delete[] m;
						fout.close();
						return false;
					}
				}
			}
		}



		fout << "========FLOYD========" << endl;
		fout << "Undirected Graph FLOYD result" << endl;
		fout << "    ";
		for (int i = 1; i < size; i++) {
			fout << "[" << i << "]  ";
		}
		fout << endl;
		for (int i = 1; i < size; i++)
		{
			fout << "[" << i << "]  ";
			for (int j = 1; j < size; j++)
			{
				if (dist[i][j] == 99999) { //if no change, infinite == no distance
					fout << "x   ";
				}
				else {
					fout << dist[i][j] << "   ";
				}
			}
			fout << endl;
		}
		fout << endl << "========================" << endl << endl;

	}
	else {
	delete[] m;
	fout.close();
	return false;
	}
	delete[] m;
	fout.close();
	return true;
}

bool KWANGWOON(Graph* graph, int vertex) {
	ofstream fout; // print to log.txt
	fout.open("log.txt", ios::app);
	int size = graph->getSize();
	if (size == 0) { // ndone have 1 error
		fout.close();
		return false;
	}
	map<int, int>* s = new map<int, int>[graph->getSize()];
	vector<bool> visited(size, false);
	queue<int> path;
	for (int from = 1; from < size; from++) {
		graph->getAdjacentEdges(from, s);
	}
	visited[vertex] = true;
	int cnt = 1; //count
	int next = 0;
	for (int from = vertex; cnt != (size - 1); from = next) {
		if (s[from].size() % 2 == 0) { //even
			auto iter = s[from].begin();
			while (iter != s[from].end()) {
				if (!visited[iter->first]) {
					next = iter->first; //next is low vertex
					cnt++;
					visited[next] = true;
					path.push(next);
					break;
				}
				else
					iter++;
			}
		}
		else { //odd
			auto iter = s[from].rbegin();
			while (iter != s[from].rend()) {
				if (!visited[iter->first]) {
					next = iter->first; //next is low vertex
					cnt++;
					visited[next] = true;
					path.push(next);
					break;
				}
				else
					iter++;
			}
		}

	}
	fout << "========KWANGWOON========" << endl;
	fout << "startvertex: 1" << endl << vertex;
	while (!path.empty()) {
		int num = path.front();
		path.pop();
		fout << " -> " << num;
	}
	fout << endl << "========================" << endl << endl;

	delete[] s;
	fout.close();
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

