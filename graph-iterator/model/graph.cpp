#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>

#include "graph.h"

using namespace std;

Graph::Graph(int n) {
    number_of_vertices = n;
    adjacency_matrix = vector<vector<bool>>(n, vector<bool>(n, false));
}

Graph::Graph(std::string file_name) {

    ifstream input_file{ file_name };
    string line;

    if ( !getline(input_file, line) ) {
        throw "ERR: Input file empty!";
    }
    istringstream iss(line);

    int n;
    if ( !(iss >> n) ) {
        throw "ERR: Invalid input from file!";
    };

    Graph graph = Graph(n);

    while ( getline(input_file, line) ) {
        istringstream iss(line);

        int vertex, neighbour;
        if ( !(iss >> vertex >> neighbour) ) {
            break;
        }

        graph.addEdge(vertex, neighbour);
    }

    number_of_vertices = n;
    adjacency_matrix = graph.adjacency_matrix;
}

int Graph::getNumberOfVertices() {
    return number_of_vertices;
}

std::vector<int> Graph::getEdges(int vertex) {
    vector<int> edges;
    vector<bool> connections{ adjacency_matrix[vertex] };

    for (int i = 0; i < getNumberOfVertices(); ++i) {
        if ( connections[i] ) {
            edges.push_back(i);
        }
    }

    return edges;
}

void Graph::addEdge(int u, int v) {
    
    if ( u >= number_of_vertices || v >= number_of_vertices) {
        throw "ERR: Invalid vertex!";
    }

    this->adjacency_matrix[u][v] = true;
    this->adjacency_matrix[v][u] = true;
}

void Graph::printAdjacencyMatrix() {
    for (int i = 0; i < number_of_vertices; i++)
    {
        for (int j = 0; j < number_of_vertices; j++)
        {
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << std::endl;
    }
}
