#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

#include "graph.h"

Graph::Graph(int number_of_vertices) {
    V = number_of_vertices;
    adjacency_list = new std::vector<int>[V];
}

Graph::Graph(std::string file_name) {

    std::ifstream input_file(file_name);
    std::string line;

    if ( !getline(input_file, line) ) {
        throw "ERR: Input file empty!";
    }
    std::istringstream iss(line);

    int number_of_vertices;
    if ( !(iss >> number_of_vertices) ) {
        return;
    };

    Graph graph = Graph(number_of_vertices);

    while ( getline(input_file, line) ) {
        std::istringstream iss(line);

        int vertex, neighbour;
        if ( !(iss >> vertex >> neighbour) ) {
            break;
        }

        graph.addEdge(vertex, neighbour);
    }

    V = number_of_vertices;
    adjacency_list = new std::vector<int>[V];
    for (int i = 0; i < V; ++i) {
        adjacency_list[i] = graph.adjacency_list[i];
    }
}

void Graph::addEdge(int u, int w) {
    
    if ( u >= V || w >= V ) {
        throw "ERR: Invalid vertex!";
    }

    if ( std::find(adjacency_list[u].begin(), adjacency_list[u].end(), w) == adjacency_list[u].end() ) {
        adjacency_list[u].push_back(w);
        adjacency_list[w].push_back(u);
    } else {
        std::cout << "edge " << u << " - " << w << " already exists!\n";
    }
}

void Graph::printGraph() {
    for (int i = 0; i < V; ++i) {
        std::cout << "Adjacency list of node " << i << ": ";

        for (int j = 0; j < adjacency_list[i].size(); ++j) {
            std::cout << adjacency_list[i].at(j) << (j == adjacency_list[i].size() - 1 ? "\n" : " -> ");
        }
    }
}
