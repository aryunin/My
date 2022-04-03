#pragma once
#include <string>
#include <vector>
#include "Graph.h"

struct Coord {
    int x, y;
    bool operator>(const Coord& c2){
        if(c2.y > y) {
            if(c2.x > x) return true;
            else return false;
        }
        else return false;
    }
};

class Maze {
private:
    std::vector<std::string> mazeArr;
    Coord startPoint, endPoint, treasurePos;
    std::vector<Coord> routeToTreasure;
    std::vector<Coord> routeToExit;
    Graph<Coord> graph;

    void readFile(const std::string&);
    void findInPoint();
    void findOutPoint();
    void recBuildGraph(const Coord&);
public:
    Maze(const std::string&);
    void setTreasureLocation(const Coord&);
    void buildGraph();
    void findRoute_stot();
    void findRoute_ttoe();
};