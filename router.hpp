#ifndef ROUTER_H
#define ROUTER_H

#include <vector>
#include <string>
// #include "route.h"

using std::string;
using std::vector;

struct Vertex
{
    int x;
    int y;
};

class Route
{
public:
    Route();
    Route(string id, Vertex start, Vertex end, int channelWidth, int channelSpacing);
    ~Route() { waypoints.clear(); }
    string id;
    Vertex start;
    Vertex end;
    int channelWidth;
    int channelSpacing;
    vector<Vertex> waypoints;
};

struct Cell
{
    int x;
    int y;
    int x_span;
    int y_span;
};

class Router
{
public:
    Router(vector<Cell> obstacles);
    ~Router() { obstacles.clear(); }
    vector<Cell> obstacles;
    vector<Route> route(vector<Route> routes);
};

#endif