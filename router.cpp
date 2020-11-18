#include "router.hpp"
#include <iostream>
#include <string>

using namespace std;

Route::Route(){};

Route::Route(string id, Vertex start, Vertex end, int channelWidth, int channelSpacing) : id(id), start(start), end(end), channelWidth(channelWidth), channelSpacing(channelSpacing){};

Router::Router(vector<Cell> obstacles) : obstacles(obstacles)
{

    //TODO Delete all this
    cout << "Obstacles: " << endl;

    for (size_t i = 0; i < this->obstacles.size(); i++)
    {
        Cell cell = obstacles[i];
        cout << "Cell{" << i << "}- (" << cell.x << ", " << cell.y << ", " << cell.x_span << ", " << cell.y_span << ")" << endl;
    }
}

vector<Route> Router::route(vector<Route> routes)
{
    cout << "Do some routing here" << std::endl;
    cout << "Sources:" << endl;
    for (size_t i = 0; i < routes.size(); i++)
    {
        cout << "Route - " << routes[i].id << endl;
        cout << "(" << routes[i].start.x << ", " << routes[i].start.y << ")" << endl;
        cout << "(" << routes[i].end.x << ", " << routes[i].end.y << ")" << endl;
        cout << "Channel Width -" << routes[i].channelWidth << endl;
        cout << "Channel Spacing -" << routes[i].channelSpacing << endl;
        cout << endl;
    }

    vector<Route> ans;
    ans.clear();
    cout << "Fill answer with a result here " << std::endl; //Determine the final wiring result, which is stored in "paths"
    return ans;
}
