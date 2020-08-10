#include <iostream>

#include "placer.hpp"

using namespace std;

Terminal::Terminal(){}

Terminal::Terminal(string label, int x, int y): label(label), x(x), y(y) {}

PlacementCell::PlacementCell(){}

PlacementCell::PlacementCell(string id, int x, int y, int x_span, int y_span, int spacing, vector<Terminal> ports)
    : id(id), x(x), y(y), x_span(x_span), y_span(y_span), component_spacing(spacing), ports(ports) {}

Net::Net(){}

Net::Net(string id, string source, vector<string> sinks): id(id), source(source), sinks(sinks){}

Constraint::Constraint(){}

PositionConstraint::PositionConstraint(int x, int y): xpos(x), ypos(y){
    this->type = ConstraintType::POSITION;
}

RotationConstraint::RotationConstraint(int rotation): rotation(rotation){
    this->type = ConstraintType::ROTATION;
}

OrientationConstraint::OrientationConstraint(map<string, Orientation> orientations): orientations(orientations){
    this->type = ConstraintType::ORIENTATION;
}

LengthConstraint::LengthConstraint(Net net, string source_id, string sink_id, int length): net(net), source_id(source_id), sink_id(sink_id), length(length){
    this->type = ConstraintType::LENGTH;
}

OrthogonalConstraint::OrthogonalConstraint(vector<PlacementCell> cells): cells(cells){
    this->type = ConstraintType::ORTHOGONAL;
}

ArrayConstraint::ArrayConstraint(int xdim, int ydim, vector<PlacementCell> cells): xdim(xdim), ydim(ydim), cells(cells){
    this->type = ConstraintType::ARRAY;
}

MirrorConstraint::MirrorConstraint(vector<vector<PlacementCell>> groups): groups(groups){
    this->type = ConstraintType::MIRROR;
}

RadialConstraint::RadialConstraint(vector<vector<PlacementCell>> groups, PlacementCell center): groups(groups), center(center){
    this->type = ConstraintType::RADIAL;
}

Placer::Placer(){};

Placer::Placer(vector<PlacementCell> cells, vector<Net> nets, vector<Constraint> constraints): cells(cells), nets(nets), constraints(constraints){
    
    cout<<"Firing Constructor for Placer" << endl;
    
    for(size_t i = 0; i<cells.size(); i++){ 
    	cout<<cells[i].id << endl; 
    }

    for(size_t i = 0; i < nets.size(); i++){
        cout<<nets[i].id << endl;
    }

    for(size_t i = 0; i < constraints.size(); i++){
        cout<<i << endl;
    }
}

void Placer::place(){
    cout << "Running place method" << endl;
}