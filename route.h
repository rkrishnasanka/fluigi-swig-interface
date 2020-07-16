#ifndef ROUTE_H
#define ROUTE_H

#include <vector>

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


#endif