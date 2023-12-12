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
	string c_line= "";
	fin.open(command_txt, ios_base::in);//File open with read mode
	bool check = false; //check for graph exist
	if (!fin) { //If command File cannot be read, Print error
		fout << "command file open error" << endl;
		return;	//Return
	}
	string cmd;
	int cnt = 0;
	while (getline(fin, c_line)) {
		size_t len = c_line.find(' ');
		cmd = c_line.substr(0, len);
		if (cmd == "LOAD") {
			if (check == true) { //if already exist graph , reset graph
				delete graph;
			}
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
			check = true;
			LOAD(filename_Array);
			cnt++;
		}
		else if (cmd == "PRINT") {
			if (cnt ==0 ) { // no graph
				printErrorCode(200);
				continue;
			}
			PRINT();
		}
		else if (cmd == "DFS") {
			char type = NULL;
			type = c_line[len + 1];
			int num = 0;;
			string temp ="";
			for (int i = len + 3; c_line[i] != NULL; i++) {
				temp.push_back(c_line[i]);
			}
			if (temp == "") { // no vertex
				printErrorCode(400);
				continue;
			}
			num = stoi(temp);
			if (type == NULL) { //type error
				printErrorCode(400);
				continue;
			}
			if (graph->getSize() == 0 || cnt == 0) { // no graph
				printErrorCode(400);
				continue;
			}
			if ((graph->getSize() - 1) < num) { //no vertex
				printErrorCode(400);
				continue;
			}
			mDFS(type, num);
				
		}
		else if (cmd == "BFS") {
			if (graph->getSize() == 0 || cnt == 0) { // no graph
				printErrorCode(300);
				continue;
			}
			char type = NULL;
			type = c_line[len + 1];
			int num = 0;;
			string temp = "";
			for (int i = len + 3; c_line[i] != NULL; i++) {
				temp.push_back(c_line[i]);
			}
			if (temp == "") { // no vertex
				printErrorCode(400);
				continue;
			}
			num = stoi(temp);
			if (type == NULL) { //type error
				printErrorCode(300);
				continue;
			}
			if (graph->getSize() == 0 || cnt == 0) { // no graph
				printErrorCode(300);
				continue;
			}
			if ((graph->getSize() - 1) < num) { //no vertex
				printErrorCode(300);
				continue;
			}
			mBFS(type, num);

		}
		else if (cmd == "DIJKSTRA") {
			char type = NULL;
			type = c_line[len + 1];
			int num = 0;;
			string temp = "";
			for (int i = len + 3; c_line[i] != NULL; i++) {
				temp.push_back(c_line[i]);
			}
			if (temp == "") { // no vertex
				printErrorCode(700);
				continue;
			}
			num = stoi(temp);
			if (type == NULL) { //type error
				printErrorCode(700);
				continue;
			}
			if (graph->getSize() == 0 || cnt == 0) { // no graph AND no LOAD
				printErrorCode(700);
				continue;
			}
			if ((graph->getSize() - 1) < num) { //no vertex
				printErrorCode(700);
				continue;
			}
			mDIJKSTRA(type, num);
		}
		else if (cmd == "KRUSKAL") {;
		if (graph->getSize() == 0 || cnt == 0) { // no graph AND no LOAD
			printErrorCode(600);
			continue;
		}
		mKRUSKAL();
		}
		else if (cmd == "BELLMANFORD") {
		char type = NULL;
		type = c_line[len + 1];
		int space=0;
		int start = 0;;
		int end = 0;
		string temp = "";
		string temp2 = "";
		for (int i = len + 3; c_line[i] != NULL; i++) {
			if(space ==0)
				temp.push_back(c_line[i]);
			else if (space == 1) {
				temp2.push_back(c_line[i]);
			}
			else {
				printErrorCode(800);
				continue;
			}
		}
		if (temp == ""||temp2=="") { // no vertex
			printErrorCode(800);
			continue;
		}
		start = stoi(temp);
		end = stoi(temp2);
		if (type == NULL) { //type error
			printErrorCode(800);
			continue;
		}
		if (graph->getSize() == 0 || cnt == 0) { // no graph AND no LOAD
			printErrorCode(800);
			continue;
		}
		if (((graph->getSize() - 1) < start)|| (graph->getSize() - 1) < end) { //no vertex
			printErrorCode(800);
			continue;
		}
		mBELLMANFORD(type, start,end);
		}
		else if (cmd == "FLOYD") {
		char type = NULL;
		type = c_line[len + 1];
		if (type == NULL) { //type error
			printErrorCode(700);
			continue;
		}
		if (graph->getSize() == 0 || cnt == 0) { // no graph AND no LOAD
			printErrorCode(700);
			continue;
		}
		mFLOYD(type);
		}
		else if (cmd == "KWANGWOON") {
		if (graph->getType() == 1) { //its matrix graph case handling
			printErrorCode(700);
			continue;
		}
		if (graph->getSize() == 0 || cnt == 0) { // no graph AND no LOAD
			printErrorCode(700);
			continue;
		}
		mKwoonWoon(1);
		}
		else if (cmd == "EXIT") {
			return;
		}
		else {
			printErrorCode(1000);
		}
	}
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
	if (!BFS(graph, option, vertex)) {
		printErrorCode(300);
		return false;
	}
	return true;
}

bool Manager::mDFS(char option, int vertex)
{
	if (!DFS( graph, option, vertex)) {
		printErrorCode(400);
		return false;
	}
	return true;
}

bool Manager::mDIJKSTRA(char option, int vertex)
{
	if (!Dijkstra(graph, option, vertex)) {
		printErrorCode(700);
		return false;
	}
	return true;
}

bool Manager::mKRUSKAL()
{
	if (!Kruskal(graph)) {
		printErrorCode(600);
		return false;
	}

	return true;
}

bool Manager::mBELLMANFORD(char option, int s_vertex, int e_vertex)
{
	if (!Bellmanford(graph, option, s_vertex, e_vertex)) {
		printErrorCode(800);
		return false;
	}
	return true;
}

bool Manager::mFLOYD(char option)
{
	if (FLOYD(graph, option)) {
		printErrorCode(900);
		return false;
	}
	return true;
}

bool Manager::mKwoonWoon(int vertex) {
	if (!KWANGWOON( graph,  vertex)) {
		printErrorCode(500);
		return false;
	}
	return true;
}

void Manager::printErrorCode(int n)
{
	fout << "========ERROR=======" << endl;
	fout << n << endl;
	fout << "====================" << endl << endl;
}


