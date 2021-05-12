// graph-iterator.cpp : Defines the entry point for the application.

#include "graph.h"
#include "graph-iterator.h"

int main(int argc, char* argv[]) {
	Graph graph = Graph("graph1.txt");
	graph.printGraph();
	return 0;
}
