# CMakeList.txt : CMake project for graph-iterator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (graph-iterator "graph-iterator.cpp"  "model/graph.h" "model/graph.cpp" "logic/bfs-iterator.h" "logic/iterator.h" "logic/dfs-iterator.cpp" "logic/bfs-iterator.cpp" )

# TODO: Add tests and install targets if needed.
