#include <algorithm>

#include "bfs-iterator.h"

constexpr auto FIRST_VERTEX = 0;

BFSIterator::BFSIterator(Graph graph) {
	known_vertices = std::vector<bool>(graph.getNumberOfVertices(), false);
}

void BFSIterator::reset() {
	std::fill(known_vertices.begin(), known_vertices.end(), false);
	known_vertices[FIRST_VERTEX] = true;
	queue.empty();
	queue.push(FIRST_VERTEX); 
}

void BFSIterator::next() {
	if ( !queue.empty() ) {
		int current = queue.front();
		queue.pop();

		for (int vertex : graph.getEdges(current)) {
			if (!known_vertices[vertex]) {
				queue.push(vertex);
				known_vertices[vertex] = true;
			}
		}
	} else {
		for (int vertex = 0; vertex < known_vertices.size(); ++vertex) {
			if ( !known_vertices[vertex] ) {
				queue.push(vertex);
				known_vertices[vertex] = true;
				break;
			}
		}
	}
}

int BFSIterator::currentKey() {
	return queue.front();
}

bool BFSIterator::isEnd() {
	return queue.empty() && std::all_of(
		std::begin(known_vertices),
		std::end(known_vertices),
		[](bool i) {
			return i;
		}
	);
}
