#include <algorithm>
#include <iostream>

#include "dfs-iterator.h"

constexpr auto FIRST_VERTEX = 0;

DFSIterator::DFSIterator(Graph graph) {
	known_vertices = std::vector<bool>(graph.getNumberOfVertices(), false);
}

void DFSIterator::reset() {
	std::fill(known_vertices.begin(), known_vertices.end(), false);
	known_vertices[FIRST_VERTEX] = true;
	stack.empty();
	stack.push(FIRST_VERTEX);
}

void DFSIterator::next() {
	if ( !stack.empty() ) {
		int current = stack.top();
		stack.pop();

		for ( int vertex : graph.getEdges(current) ) {
			if ( !known_vertices[vertex] ) {
				known_vertices[vertex] = true;
				stack.push(vertex);
			}
		}
	} else {
		for (int vertex = 0; vertex < known_vertices.size(); ++vertex) {
			if ( !known_vertices[vertex] ) {
				known_vertices[vertex] = true;
				stack.push(vertex);
				break;
			}
		}
	}
}

int DFSIterator::currentKey() {
	return stack.top();
}

bool DFSIterator::isEnd() {
	return stack.empty() && std::all_of(
		std::begin(known_vertices),
		std::end(known_vertices),
		[](bool i) {
			return i;
		}
	);
}
