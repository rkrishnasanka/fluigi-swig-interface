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
     * @brief 
     * 
     */
    string id;

    /**
     * @brief 
     * 
     */
    Vertex start;

    /**
     * @brief 
     * 
     */
    Vertex end;

    /**
     * @brief 
     * 
     */
    int channelWidth;

    /**
     * @brief 
     * 
     */
    int channelSpacing;

    /**
     * @brief 
     * 
     */
    vector<Vertex> waypoints;
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
    void route(vector<Route> routes);
};

#endif