#include "Maze.h"
#include <string>
#include <fstream>

void Maze::findStartPoint() {
    startPoint.y = 0;
    startPoint.x = (mazeArr[0]).find(' ');
}

void Maze::findEndPoint() {
    endPoint.y = mazeArr.size() - 1;
    endPoint.x = (mazeArr[mazeArr.size() - 1]).find(' ');
}

Maze::Maze(const std::string& fileName) : treasurePoint{-1, -1} {
    readFile(fileName);
    findStartPoint();
    findEndPoint();
}

void Maze::setTreasurePoint(const Coord& coords, const char symbol){
    treasurePoint = coords; // TODO exception (invalid treasure coords)
    mazeArr[treasurePoint.y][treasurePoint.x] = symbol;
}

void Maze::readFile(const std::string& fileName) {
    std::ifstream fin;
    fin.open(fileName);
    if(!fin) exit(1); // TODO exception (invalid filename)
    std::string str;
    while(getline(fin,str))
        mazeArr.push_back(str);
    fin.close();
}

void Maze::buildGraph() {
    for(int i {1}; i < mazeArr.size()-1; i++) {            //для всех кроме первой и последней строк
        for(int j{1}; j < mazeArr[i].length() - 1; j++) {  //для .. столбцов
            Coord current {j, i};
            // в mazeArr первый индекс это строчка
            if(mazeArr[i][j] != '#') {
                if(mazeArr[i][j-1] != '#') graph.addEdge(current, Coord{j-1,i});
                if(mazeArr[i][j+1] != '#') graph.addEdge(current, Coord{j+1,i});
                if(mazeArr[i-1][j] != '#') graph.addEdge(current, Coord{j,i-1});
                if(mazeArr[i+1][j] != '#') graph.addEdge(current, Coord{j,i+1});
            }
        }
    }
    graph.addEdge(startPoint, Coord{startPoint.x, startPoint.y+1});  //так как мы не проверяем первую и последнюю сторки то
    graph.addEdge(Coord{endPoint.x, endPoint.y-1}, endPoint);        //связываем точку старта с точкой ниже, точку выше выхода с точкой выхода
}

void Maze::findRoute_stot(std::vector<Coord>& route) {
    graph.DFS(startPoint, treasurePoint, route);
    if(!route.empty()) route.erase(route.end() - 1);  // получаем последнюю вершину и удаляем звездочку, если вектор не пустой
}

void Maze::findRoute_ttoe(std::vector<Coord>& route) {
    graph.BFS(treasurePoint, endPoint, route);
    route.erase(route.begin());
}

void Maze::printRoute(std::vector<Coord>& route, const char symbol) {
    for(const Coord& c : route)
        mazeArr[c.y][c.x] = symbol;
}

void Maze::printToFile(const std::string& fileName) const {
    std::ofstream fout;
    fout.open(fileName);
    for(const std::string& str : mazeArr)
        fout << str + '\n';
    fout.close();
}

