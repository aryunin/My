#include <iostream>
#include "Graph.h"
#include "Maze.h"

void simpleGraphTest();

int main() {
    Maze maze{"Maze.txt"};

    return 0;
}

void simpleGraphTest() {
    Graph<int> graph;
    graph.addEdge(1, 2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(2,5);
    graph.addEdge(3,6);
    graph.addEdge(3,7);
    graph.addEdge(4,8);
    graph.addEdge(5,2);
    graph.addEdge(5,6);
    graph.addEdge(5,9);
    graph.addEdge(5,10);

    std::vector<int> v1{graph.DFS(1, 6)};
    std::cout << "DFS: ";
    for(int x : v1) std::cout << x << ' ';
    std::cout << std::endl;

    std::vector<int> v2{graph.BFS(1, 6)};
    std::cout << "BFS: ";
    for(int x : v2) std::cout << x << ' ';
    std::cout << std::endl;
}