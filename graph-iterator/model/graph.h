#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

using namespace std;

/** Simple undirected graph implementation using adjecency list representation. */
class Graph {

private:

    /** Number of graph's vertices. */
    int number_of_vertices;

    /** Representation of Graph as an adjecency list. */
    vector<vector<bool>> adjacency_matrix;

public:

    /** Constructs graph with no edges. */
    Graph(int number_of_vertices = 0);

    /** Reads graph from given input file. */
    Graph(string file_name);

    /** Getter, returns number of vertices. */
    int getNumberOfVertices();

    /** Returns vector representation of edges for a given vertex. */
    vector<int> getEdges(int vertex);

    /** Connects vertices u, v by an edge. */
    void addEdge(int u, int v);

    /** Prints the adjacency matrix representation of the graph. */
    void printAdjacencyMatrix();
};

#endif
