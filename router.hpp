#ifndef ROUTER_H
#define ROUTER_H

#include <vector>
// #include "route.h"

using std::vector;

struct Vertex{
    int x;
    int y;
};


class Route{
    public:
        Route();
        Route(Vertex start, Vertex end);
        ~Route() {waypoints.clear();}
        Vertex start;
        Vertex end;
        vector<Vertex> waypoints;
};


struct Cell{
    int x;
    int y;
    int x_span;
    int y_span;
};


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