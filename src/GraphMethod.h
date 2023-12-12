#ifndef _GRAPHMETHOD_H_
#define _GRAPHMETHOD_H_

#include "ListGraph.h"
#include "MatrixGraph.h"

bool BFS(Graph* graph, char option, int vertex);     
bool DFS(Graph* graph, char option,  int vertex);     
bool KWANGWOON(Graph* graph, int vertex);  
bool Kruskal(Graph* graph);
bool Dijkstra(Graph* graph, char option, int vertex);    //Dijkstra
bool Bellmanford(Graph* graph, char option, int s_vertex, int e_vertex); //Bellman - Ford
bool FLOYD(Graph* graph, char option);   //FLoyd

void QuickSort(vector<pair<int, pair<int, int>>>* arr, const int low, const int high);
void InsertionSort(vector<pair<int, pair<int, int>>>* arr, int low, int high);
int find(int x);
void uni(int x, int y);
bool sameparent(int x, int y);
#endif
