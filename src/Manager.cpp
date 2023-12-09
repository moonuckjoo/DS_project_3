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
	if(load)	//if graph is loaded, delete graph
		delete graph;	
	if(fout.is_open())	//if fout is opened, close file
		fout.close();	//close log.txt File
}

void Manager::run(const char* command_txt){
	ifstream fin;	//Command File Input File Stream
	fin.open(command_txt, ios_base::in);//File open with read mode
		
	if(!fin) { //If command File cannot be read, Print error
		fout<<"command file open error"<<endl;
		return;	//Return
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
	string line ="";
	string size; //size
	bool type=true;
	getline(graph_file, line);
	string info_list;
	int idx=1; // to vertex
	int data;
	if (line == "") { //if file is null
		printErrorCode(100);
		return false;
	}
	getline(graph_file, size); //get size;
	int int_size = stoi(size); //string to int
	if (line == "M") { //Matrix type
		type = 1;
		graph = new MatrixGraph(type, int_size);
		for (int i = 0; i != graph_file.eof(); i++) {
			idx = 1;
			getline(graph_file, line);
			for (int j = 0; line[j] != NULL ; j++) { //vector size
				if (line[j] == ' ') {
					data = stoi(info_list); //data is weight
					info_list.clear();
					graph->insertEdge(i + 1, idx, data);
					idx++;
					continue;
				}
				else {
					info_list.push_back(line[j]);
				}
			}
			data = stoi(info_list); //data is weight
			info_list.clear();
			graph->insertEdge(i + 1, idx, data);
		}
	}
	else if(line == "L") { //List type
		type = 0;
		graph = new ListGraph(type, int_size);
		for (int i = 0; i != graph_file.eof(); i++) {
			getline(graph_file, line);

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

}

bool Manager::mBFS(char option, int vertex)	
{
	
}

bool Manager::mDFS(char option, int vertex)	
{
	
}

bool Manager::mDIJKSTRA(char option, int vertex)	
{
	
}

bool Manager::mKRUSKAL()
{
 	
}

bool Manager::mBELLMANFORD(char option, int s_vertex, int e_vertex) 
{
	
}

bool Manager::mFLOYD(char option)
{
	
}

bool Manager::mKwoonWoon(int vertex) {
	
}

void Manager::printErrorCode(int n)
{
	fout<<"========ERROR======="<<endl;
	fout<<n<<endl;
	fout<<"===================="<<endl << endl;
}


