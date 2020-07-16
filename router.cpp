#include "router.h"
#include <iostream>

using namespace std;

Route::Route(){};

Route::Route(Vertex start, Vertex end): start(start), end(end){};

Router::Router(vector<Cell> obstacles, int channelWidth, int channelSpacing): 
    obstacles(obstacles), channelWidth(channelWidth), channelSpacing(channelSpacing){

        //TODO Delete all this

        cout << "Channel Width: " << this->channelWidth << endl;
        cout << "Channel Spacing: " << this->channelSpacing << endl;

        cout << "Obstacles: " << endl;

        for(size_t i = 0 ; i < this->obstacles.size(); i++ ){
            Cell cell = obstacles[i]; 
            cout << "Cell{" << i <<  "}- (" << cell.x << ", " << cell.y << ", " << cell.x_span << ", " << cell.y_span << ")" << endl; 
        }
}

vector<Route> Router::route(vector<Vertex> sources, vector<Vertex> targets){
    cout << "Do some routing here" << std::endl;
    cout << "Sources:" << endl;
    for(size_t i = 0; i < sources.size(); i++){
        cout << "(" << sources[i].x  << ", " << sources[i].y <<")" << endl;
    }

    cout << "Targets:" << endl;
    for(size_t i = 0; i < targets.size(); i++){
        cout << "(" << targets[i].x  << ", " << targets[i].y <<")" << endl;
    }

    vector<Route> ans;
    ans.clear();
    cout << "Fill answer with a result here " << std::endl;            //Determine the final wiring result, which is stored in "paths"
    return ans;
}
