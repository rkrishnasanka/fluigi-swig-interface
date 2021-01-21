#ifndef ROUTER_H
#define ROUTER_H

#include <vector>
#include <string>
// #include "route.h"

using std::string;
using std::vector;

/**
 * @brief This the basic datastructure that is used for describing
 * the waypoints for the net
 * 
 */
struct Vertex
{
    int x;
    int y;
};

/**
 * @brief Captures the routing start and end point
 * 
 */
class Route
{
public:
    /**
     * @brief Construct a new Route object
     * 
     */
    Route();

    /**
     * @brief Construct a new Route object
     * 
     * @param id 
     * @param start 
     * @param end 
     * @param channelWidth 
     * @param channelSpacing 
     */
    Route(string id, Vertex start, Vertex end, int channelWidth, int channelSpacing);

    /**
     * @brief Destroy the Route object
     * 
     */
    ~Route() { this->waypoints.clear(); }

    /**
     * @brief Stores the id of the route so that we can map it back to the 
     * original connection
     * 
     */
    string id;

    /**
     * @brief Stores the start point coordinate
     * 
     */
    Vertex start;

    /**
     * @brief Stores the end point Coordinate
     * 
     */
    Vertex end;

    /**
     * @brief Stores the size of the channel
     * 
     */
    int channelWidth;

    /**
     * @brief Stores the channel spacing value
     * 
     */
    int channelSpacing;

    /**
     * @brief Stores the waypoints of the route
     * 
     */
    vector<Vertex> waypoints;

    /**
     * @brief Returns the set of the vertex waypoints
     * 
     * @return vector<Vertex> 
     */
    vector<Vertex> getWaypoints();
};

/**
 * @brief 
 * 
 */
struct Cell
{
    int x;
    int y;
    int x_span;
    int y_span;
};

/**
 * @brief 
 * 
 */
class Router
{
public:
    /**
     * @brief Construct a new Router object
     * 
     * @param obstacles 
     */
    Router(vector<Cell> obstacles);

    /**
     * @brief Destroy the Router object
     * 
     */
    ~Router()
    {
        this->obstacles.clear();
    }

    /**
     * @brief 
     * 
     */
    vector<Cell> obstacles;

    /**
     * @brief 
     * 
     * @param routes 
     */
    void route(vector<Route *> routes, int min_x, int min_y, int max_x, int max_y);
};

#endif