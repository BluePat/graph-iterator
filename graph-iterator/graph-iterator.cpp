#include <iostream>

#include "logic/bfs-iterator.h"
#include "logic/dfs-iterator.h"

void iterate(DFSIterator iterator) {

	iterator.reset();

	while ( !iterator.isEnd() ) {
		std::cout << iterator.currentKey() << " ";
		iterator.next();
	}
}

int main(int argc, char* argv[]) {

	try {
		Graph graph{ "graph1.txt" };
		graph.printAdjacencyMatrix();

		DFSIterator dfs{ graph };
		std::cout << "Info: DFSIterator initialized.\n";
		iterate(dfs);

		BFSIterator bfs{ graph };
		//iterate(bfs);

	} catch (std::string msg) {
		std::cout << msg;
		return 1;
	}

	return 0;
}
