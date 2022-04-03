#include "Maze.h"
#include <string>
#include <fstream>
//#include <vector>
#include <algorithm>

void Maze::findInPoint() {
    startPoint.y = 0;
    startPoint.x = (mazeArr[0]).find(' ');
}

void Maze::findOutPoint() {
    endPoint.y = mazeArr.size() - 1;
    endPoint.x = (mazeArr[mazeArr.size() - 1]).find(' ');
}

Maze::Maze(const std::string& fileName) : treasurePos{-1,-1} {
    readFile(fileName);
    findInPoint();
    findOutPoint();
}

void Maze::setTreasureLocation(const Coord& coords){
    mazeArr[coords.y][coords.x] = '*';
}


void Maze::readFile(const std::string& fileName) {
    std::ifstream fin;
    fin.open(fileName);
    if(!fin) exit(1); // TODO exception
    std::string str;
    while(getline(fin,str))
        mazeArr.push_back(str);
    fin.close();
}

void Maze::recBuildGraph(const Coord& root) {

}


void Maze::buildGraph() {
    recBuildGraph(startPoint);
}

void Maze::findRoute_stot() {

}

void Maze::findRoute_ttoe() {

}

