#pragma once

//#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

template<typename T>
using GraphMap = std::map<T,std::vector<T>>;

template<typename T>
class Graph {
private:
    GraphMap<T> graph;
    void recDFS(const T&, const T&, std::vector<T>&, std::map<T,bool>&) const;
public:
    void addEdge(const T&, const T&);
    std::vector<T> DFS(const T&, const T&) const;
    std::vector<T> BFS(const T&, const T&) const;
};

template<typename T>
void Graph<T>::addEdge(const T& v1, const T& v2) {
    graph[v1].push_back(v2);
    graph[v2];
}

template<typename T>
std::vector<T> Graph<T>::DFS(const T& root, const T& target) const {
    std::vector<T> route{};
    std::map<T,bool> excluded{};
    if(graph.find(root) == graph.cend()) return route;
    recDFS(root, target, route, excluded);
    std::reverse(route.begin(),route.end());
    return route;
}

template<typename T>
void Graph<T>::recDFS(const T& root, const T& target, std::vector<T>& route, std::map<T,bool>& excluded) const{
    excluded[root] = true;
    if(root == target) route.push_back(root);
    else {
        typename std::vector<T>::const_iterator cit;
        for(cit = graph.at(root).cbegin(); cit != graph.at(root).cend(); cit++) {
            if(excluded[*cit]) continue;
            this->recDFS(*cit, target, route, excluded);
            if(!route.empty()) {
                route.push_back(root);
                break;
            }
        }
    }
}

template<typename T>
std::vector<T> Graph<T>::BFS(const T& root, const T& target) const {
    std::queue<T> searchQueue{};
    std::map<T, T> ancestors{};
    std::map<T, bool> excluded{};
    std::vector<T> route{};

    if(graph.find(root) == graph.cend()) return route;

    // graph traversal
    searchQueue.push(root);
    bool targetFound {false};
    while(!searchQueue.empty()) {
        const T& current {searchQueue.front()};
        searchQueue.pop();
        if(current == target) {
            targetFound = true;
            break;
        }
        else {
            std::for_each(graph.at(current).cbegin(), graph.at(current).cend(), [&searchQueue, &ancestors, &current, &excluded](const T& child){
                if(!excluded[child]) {
                    excluded[child] = true;
                    searchQueue.push(child);
                    ancestors[child] = current;
                }
            });
        }
    }

    // route restore
    if(targetFound) {
        T current {target};
        while(current != root) {
            route.push_back(current);
            current = ancestors[current];
        }
        route.push_back(root);
    }
    std::reverse(route.begin(), route.end());

    return route;
}