#ifndef ROUTER_H
#define ROUTER_H

#include <vector>
#include "route.h"

using std::vector;

struct Cell{
    int x;
    int y;
    int x_span;
    int y_span;
};


void hello_world(vector<Cell> cells);

class Router{
    public:
        Router(vector<Cell> obstacles, int channelWidth, int channelSpacing);
        ~Router() {obstacles.clear();}
        vector<Cell> obstacles;
        int channelWidth;
        int channelSpacing;
        vector<Route> route(vector<Vertex> sources, vector<Vertex> targets);
};

#endif