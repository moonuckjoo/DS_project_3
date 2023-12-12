#include "Manager.h"
#include "GraphMethod.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Manager::Manager()
{
	graph = nullptr;
	fout.open("log.txt", ios::app);
	load = 0;	//Anything is not loaded
}

Manager::~Manager()
{
	if (load)	//if graph is loaded, delete graph
		delete graph;
	if (fout.is_open())	//if fout is opened, close file
		fout.close();	//close log.txt File
}

void Manager::run(const char* command_txt) {
	ifstream fin;	//Command File Input File Stream
	string c_line;
	fin.open(command_txt, ios_base::in);//File open with read mode

	if (!fin) { //If command File cannot be read, Print error
		fout << "command file open error" << endl;
		return;	//Return
	}
	string cmd;
	while (getline(fin, c_line)) {
		size_t len = c_line.find(' ');
		cmd = c_line.substr(0, len);
		if (cmd == "LOAD") {
			string filename;
			if (c_line[len + 1] == NULL) { //The number of factors does not match
				printErrorCode(100);
				return;
			}
			for (int i = len + 1; i < c_line.length(); i++) {
				if (c_line[i] == ' ') {
					printErrorCode(100); //The number of factors does not match
					return;
				}
				else {
					filename.push_back(c_line[i]);
				}
			}
			const char* filename_Array = filename.c_str();
			LOAD(filename_Array);
		}
		else if (cmd == "PRINT") {
			PRINT();
		}
		else if (cmd == "DFS") {
			char type;
			type = c_line[len + 1];
			int num = 0;;
			string temp;
			for (int i = len + 3; c_line[i] != NULL; i++) {
				temp.push_back(c_line[i]);
			}
			num = stoi(temp);
			if (!DFS(graph, type, num)) {
				printErrorCode(400);
			}
		}
		else if (cmd == "BFS") {
			char type;
			type = c_line[len + 1];
			int num = 0;;
			string temp;
			for (int i = len + 3; c_line[i] != NULL; i++) {
				temp.push_back(c_line[i]);
			}
			num = stoi(temp);
			if (!BFS(graph, type, num)) {
				printErrorCode(300);
			}

		}
	}
	Kruskal(graph);
	Dijkstra(graph, 'Y', 1);
	fin.close();
	return;
}

bool Manager::LOAD(const char* filename)
{
	ifstream graph_file;
	graph_file.open(filename);
	if (!graph_file.is_open()) { //if file is not exist
		printErrorCode(100);
		return false;
	}
	string line = "";
	string size; //size
	bool type = true;
	getline(graph_file, line);
	string info_list;
	int to = 1; // to vertex
	int from = 1;
	int weight;
	if (line == "") { //if file is null
		printErrorCode(100);
		return false;
	}
	getline(graph_file, size); //get size;
	int int_size = stoi(size); //string to int
	if (line == "M") { //Matrix type
		type = 1;
		graph = new MatrixGraph(type, int_size + 1);

		while (getline(graph_file, line)) {
			to = 1;
			for (int j = 0; line[j] != NULL; j++) { //line size
				if (line[j] == ' ') {
					weight = stoi(info_list); //weight is weight
					info_list.clear();
					graph->insertEdge(from, to, weight);
					to++;
					continue;
				}
				else {
					info_list.push_back(line[j]);
				}
			}
			weight = stoi(info_list); //weight is weight
			info_list.clear();
			graph->insertEdge(from, to, weight);
			from++;
		}
	}
	else if (line == "L") { //List type
		type = 0;
		int cnt = 0;

		graph = new ListGraph(type, int_size + 1);
		while (getline(graph_file, line)) {
			cnt = 0;
			for (int i = 0; i < line.length(); i++) { // from type or to type
				if (line[i] == ' ')
					cnt++;
			}

			if (cnt == 0) { // from case
				from = stoi(line);
				line.clear();
			}
			else if (cnt == 1) { //to type
				for (int j = 0; line[j] != NULL; j++) {
					if (line[j] == ' ') {
						to = stoi(info_list); //weight is weight
						info_list.clear();
						continue;
					}
					else {
						info_list.push_back(line[j]);
					}
				}
				weight = stoi(info_list); // weight case
				info_list.clear();
				graph->insertEdge(from, to, weight);
			}
			else { //three or more factors
				printErrorCode(100);
				return false;
			}

		}
	}
	else { //Handling unexpected case of exceptions
		printErrorCode(100);
		return false;
	}
	graph_file.close();
}

bool Manager::PRINT()
{
	if (graph->getType() == 1) {
		graph->printGraph(&fout);
		return true;
	}
	else if(graph->getType() == 0) {
		graph->printGraph(&fout);
		return true;
	}
	else {
	printErrorCode(200);
	return false;
}
}

bool Manager::mBFS(char option, int vertex)
{
	return true;
}

bool Manager::mDFS(char option, int vertex)
{
	return true;
}

bool Manager::mDIJKSTRA(char option, int vertex)
{
	return true;
}

bool Manager::mKRUSKAL()
{
	return true;
}

bool Manager::mBELLMANFORD(char option, int s_vertex, int e_vertex)
{
	return true;
}

bool Manager::mFLOYD(char option)
{
	return true;
}

bool Manager::mKwoonWoon(int vertex) {

	return true;
}

void Manager::printErrorCode(int n)
{
	fout << "========ERROR=======" << endl;
	fout << n << endl;
	fout << "====================" << endl << endl;
}


