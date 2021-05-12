#include <vector>
#include <string>

/** Simple undirected graph implementation using adjecency list representation */
class Graph {

private:
    int V;
    std::vector<int> *adjacency_list;

public:

    /** Constructs V-vertex graph with no edges */
    Graph(int V);

    /** Reads graph from given input file */
    Graph(std::string file_name);

    /** Connects vertices u, v by an edge */
    void addEdge(int u, int w);

    /** Prints the adjacency list representation of the graph */
    void printGraph();
};
