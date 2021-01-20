#include <iostream>

#include "placer.hpp"

using namespace std;
using std::string;

Terminal::Terminal() {}

Terminal::Terminal(string label, int rel_x, int rel_y) : label(label), rel_x(rel_x), rel_y(rel_y) {}

void Terminal::compute_absolute_positions(int ref_x, int ref_y)
{
    this->x = ref_x + rel_x;
    this->y = ref_y + rel_y;
}

PlacementCell::PlacementCell() {}

PlacementCell::PlacementCell(string id, int x, int y, int x_span, int y_span, int spacing, vector<Terminal> ports)
    : id(id), x(x), y(y), x_span(x_span), y_span(y_span), component_spacing(spacing), ports(ports) {}

Net::Net() {}

Net::Net(string id, PlacementCell *source_cell, Terminal *source_terminal, vector<PlacementCell *> sink_cells, vector<Terminal *> sink_terminals) : id(id), source(source_cell), source_terminal(source_terminal), sinks(sink_cells), sink_terminals(sink_terminals) {}

Constraint::Constraint()
{
}

PositionConstraint::PositionConstraint(int x, int y, PlacementCell cell) : xpos(x), ypos(y), cell(cell)
{
    this->type = ConstraintType::POSITION;
}

RotationConstraint::RotationConstraint(int rotation, PlacementCell cell) : rotation(rotation), cell(cell)
{
    this->type = ConstraintType::ROTATION;
}

OrientationConstraint::OrientationConstraint(map<PlacementCell, Orientation> orientations) : orientations(orientations)
{
    this->type = ConstraintType::ORIENTATION;
}

LengthConstraint::LengthConstraint(Net net, string source_id, string sink_id, int length) : net(net), source_id(source_id), sink_id(sink_id), length(length)
{
    this->type = ConstraintType::LENGTH;
}

OrthogonalConstraint::OrthogonalConstraint(vector<PlacementCell> cells) : cells(cells)
{
    this->type = ConstraintType::ORTHOGONAL;
}

ArrayConstraint::ArrayConstraint(int xdim, int ydim, vector<PlacementCell> cells) : xdim(xdim), ydim(ydim), cells(cells)
{
    this->type = ConstraintType::ARRAY;
}

MirrorConstraint::MirrorConstraint(vector<vector<PlacementCell>> groups) : groups(groups)
{
    this->type = ConstraintType::MIRROR;
}

RadialConstraint::RadialConstraint(vector<vector<PlacementCell>> groups, PlacementCell center) : groups(groups), center(center)
{
    this->type = ConstraintType::RADIAL;
}

Placer::Placer(){};

Placer::Placer(vector<PlacementCell> cells, vector<Net> nets, vector<Constraint> constraints) : cells(cells), nets(nets), constraints(constraints)
{

    cout << "Firing Constructor for Placer" << endl;

    for (size_t i = 0; i < cells.size(); i++)
    {
        PlacementCell c_check = cells[i];
        cout << c_check.id << endl;
        for (size_t j = 0; j < c_check.ports.size(); j++)
        {
            Terminal t_check = c_check.ports[j];
            cout << "Terminal - " << t_check.label << "| Rel Position (" << t_check.x << ", " << t_check.y << ")" << endl;
        }
    }

    for (size_t i = 0; i < nets.size(); i++)
    {
        cout << nets[i].id << endl;
    }

    for (size_t i = 0; i < constraints.size(); i++)
    {
        cout << i;
        Constraint c_check = constraints[i];
        switch (c_check.type)
        {
        case ConstraintType::ROTATION:
            cout << " - Rotoation Constraint" << endl;
            break;
        case ConstraintType::POSITION:
            cout << " - Position Constraint" << endl;
            break;
        case ConstraintType::ORIENTATION:
            cout << " - Orientation Constraint" << endl;
            break;
        case ConstraintType::LENGTH:
            cout << " - Length Constraint" << endl;
            break;
        case ConstraintType::ORTHOGONAL:
            cout << " - Orthogonal Constraint" << endl;
            break;
        case ConstraintType::ARRAY:
            cout << " - Array Constraint" << endl;
            break;
        case ConstraintType::MIRROR:
            cout << " - Mirror Constraint" << endl;
            break;
        case ConstraintType::RADIAL:
            cout << " - Radial Constraint" << endl;
            break;
        default:
            break;
        }
    }
}

void Placer::place()
{
    cout << "Running place method" << endl;
}

void Placer::place_and_route()
{
    cout << "Running place and route method" << endl;
}
