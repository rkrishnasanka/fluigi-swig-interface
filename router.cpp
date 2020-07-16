#include "router.h"
#include <iostream>

using namespace std;


Router::Router(vector<Cell> obstacles, int channelWidth, int channelSpacing): 
    obstacles(obstacles), channelWidth(channelWidth), channelSpacing(channelSpacing){}

vector<Route> Router::route(vector<Vertex> sources, vector<Vertex> targets){
    std::cout << "Do some routing here" << std::endl;
    vector<Route> ans;
    ans.clear();
    std::cout << "Fill answer with a result here " << std::endl;            //Determine the final wiring result, which is stored in "paths"
    return ans;
}

void hello_world(vector<Cell> cells){
    for(size_t i=0; i<cells.size(); i++){
        cout << "x: " << cells[i].x << " y: " << cells[i].y << endl; 
    }
}
