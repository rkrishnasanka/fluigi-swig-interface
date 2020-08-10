#ifndef PLACER_H
#define PLACER_H

#include <vector>
#include <string>
#include <map>
// #include "router.hpp"

using std::vector;
using std::string;
using std::map;

enum class ConstraintType { 
    POSITION = 0, 
    ROATATION = 1, 
    ORIENTATION = 2, 
    LENGTH = 3, 
    ORTHOGONAL = 4, 
    ARRAY = 5, 
    MIRROR = 6 
};

enum class Orientation{
    HORIZONTAL,
    VERTICAL
}

class Terminal{
    public:
        Terminal();
        Terminal(string label, int x, int y);
        ~Placment();
        //This is relative to the Placement Cell position
        int x;
        int y;
        string label;
}

class PlacementCell{
    public:
        PlacementCell();
        PlacementCell(string id, int x, int y, int x_span, int y_span, int spacing, vector<Port> ports);
        ~PlacementCell(){
            ports.clear();
        }
        string id;
        int x;
        int y;
        int x_span;
        int y_span;
        int component_spacing;
        vector<Port> ports;
}

class Net{
    public:
        Net();
        Net(string source, vector<string> sinks);
        ~Net(){
            sinks.clear();
        }
        string source;
        vector<string> sinks;
}

class Constraint{
    public:
        Constraint();
        ~Constraint(){
            cells.clear();
        }
        ConstraintType type;
        vector<PlacementCell> cells;
}

class PositionConstraint : public Constraint{
    public:
        PositionConstraint(int x, int y);
        ~PositionConstraint();
        int xpos;
        int ypos;
}

class RoationConstraint : public Constraint{
    public:
        RoationConstraint(int rotation);
        ~RoationConstraint();
        int rotation;
}

class OrientationConstraint: public Constraint{
    public:
        OrientationConstraint(map<string, Orientation> orientations);
        ~OrientationConstraint();
        map<string, Orientation> orientations;
}

class LengthConstraint: public Constraint{
    public:
        LengthConstraint();
        ~LengthConstraint();
        int length;
}

class OrthogonalConstraint: public Constraint{
    public:
        OrientationConstraint();
        ~OrthogonalConstraint();
}

class ArrayConstraint: public Constraint{
    public:
        ArrayConstraint(int xdim, int ydim);
        ~ArrayConstraint();
        int xdim;
        int ydim;
}

class MirrorConstraint: public Constraint{
    public:
        MirrorConstraint(vector<vector<PlacementCell>> groups);
        ~MirrorConstraint(){
            for(std::size_t i=0; i <groups.size(); i++){
                groups[i].clear();
            }
            groups.clear();
        }
        vector<vector<PlacementCell>> groups;
}

class RadialConstraint: public Constraint{
    public:
        RadialConstraint(vector<vector<PlacementCell>> groups, PlacementCell center);
        ~RadialConstraint(){
            for(std::size_t i=0; i <groups.size(); i++){
                groups[i].clear();
            }
            groups.clear();
        }
        vector<vector<PlacementCell>> groups;
        PlacementCell center;
}

class Placer{
    public:
        Placer();
        Placer(vector<PlacementCell> cells, vector<Net> nets, vector<Constraint> constraints);
        ~Placer(){
            cells.clear();
            nets.clear();
        }
        vector<PlacementCell> cells;
        vector<Constraint> constraints;
        vector<Net> nets;
        void place();

}


