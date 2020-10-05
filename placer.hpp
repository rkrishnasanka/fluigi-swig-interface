#ifndef PLACER_H
#define PLACER_H

#include <vector>
#include <string>
#include <map>
// #include "router.hpp"

using std::map;
using std::string;
using std::vector;

enum class ConstraintType
{
    POSITION = 0,
    ROTATION = 1,
    ORIENTATION = 2,
    LENGTH = 3,
    ORTHOGONAL = 4,
    ARRAY = 5,
    MIRROR = 6,
    RADIAL = 7
};

enum class Orientation
{
    HORIZONTAL,
    VERTICAL
};

class Terminal
{
public:
    Terminal();
    Terminal(string label, int x, int y);
    ~Terminal(){};
    //This is relative to the Placement Cell position
    string label;
    int x;
    int y;
};

class PlacementCell
{
public:
    PlacementCell();
    PlacementCell(string id, int x, int y, int x_span, int y_span, int spacing, vector<Terminal> ports);
    ~PlacementCell()
    {
        this->ports.clear();
    }
    string id;
    int x;
    int y;
    int x_span;
    int y_span;
    int component_spacing;
    vector<Terminal> ports;
};

class Net
{
public:
    Net();
    Net(string id, string source, vector<string> sinks);
    ~Net()
    {
        this->sinks.clear();
    }
    string id;
    string source;
    vector<string> sinks;
};

class Constraint
{
public:
    Constraint();
    ~Constraint(){};
    ConstraintType type;
};

class PositionConstraint : public Constraint
{
public:
    PositionConstraint(int x, int y, PlacementCell cell);
    ~PositionConstraint(){};
    int xpos;
    int ypos;
    PlacementCell cell;
};

class RotationConstraint : public Constraint
{
public:
    RotationConstraint(int rotation, PlacementCell cell);
    ~RotationConstraint(){};
    int rotation;
    PlacementCell cell;
};

class OrientationConstraint : public Constraint
{
public:
    OrientationConstraint(map<string, Orientation> orientations);
    ~OrientationConstraint()
    {
        this->orientations.clear();
    };
    map<string, Orientation> orientations;
};

class LengthConstraint : public Constraint
{
public:
    LengthConstraint(Net net, string source_id, string sink_id, int length);
    ~LengthConstraint(){};
    Net net;
    string source_id;
    string sink_id;
    int length;
};

class OrthogonalConstraint : public Constraint
{
public:
    OrthogonalConstraint(vector<PlacementCell> cells);
    ~OrthogonalConstraint()
    {
        cells.clear();
    };
    vector<PlacementCell> cells;
};

class ArrayConstraint : public Constraint
{
public:
    ArrayConstraint(int xdim, int ydim, vector<PlacementCell> cells);
    ~ArrayConstraint()
    {
        cells.clear();
    };
    int xdim;
    int ydim;
    vector<PlacementCell> cells;
};

class MirrorConstraint : public Constraint
{
public:
    MirrorConstraint(vector<vector<PlacementCell>> groups);
    ~MirrorConstraint()
    {
        for (std::size_t i = 0; i < groups.size(); i++)
        {
            groups[i].clear();
        }
        groups.clear();
    }
    vector<vector<PlacementCell>> groups;
};

class RadialConstraint : public Constraint
{
public:
    RadialConstraint(vector<vector<PlacementCell>> groups, PlacementCell center);
    ~RadialConstraint()
    {
        for (std::size_t i = 0; i < groups.size(); i++)
        {
            groups[i].clear();
        }
        groups.clear();
    }
    vector<vector<PlacementCell>> groups;
    PlacementCell center;
};

class Placer
{
public:
    Placer();
    Placer(vector<PlacementCell> cells, vector<Net> nets, vector<Constraint> constraints);
    ~Placer()
    {
        cells.clear();
        nets.clear();
    }
    vector<PlacementCell> cells;
    vector<Net> nets;
    vector<Constraint> constraints;

    void place();
};

#endif