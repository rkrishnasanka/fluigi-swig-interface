#ifndef PLACER_H
#define PLACER_H

#include <vector>
#include <string>
#include <map>
#include "router.hpp"

using std::map;
using std::string;
using std::vector;

/**
 * @brief The constraint type dictates the various kinds of 
 * layout constraints that can be applied to various components
 * 
 */
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

/**
 * @brief Represents the relative orientation of the component
 * 
 */
enum class Orientation
{
    HORIZONTAL,
    VERTICAL
};

/**
 * @brief Class is used to represent the locations on the components / device
 * where the connection can point to
 * 
 */
class Terminal
{
public:
    /**
     * @brief Construct a new Terminal object with no initial data
     * 
     */
    Terminal();

    /**
     * @brief Construct a new Terminal object
     * 
     * @param label 
     * @param x 
     * @param y 
     */
    Terminal(string label, int rel_x, int rel_y);

    /**
     * @brief Destroy the Terminal object
     * 
     */
    ~Terminal(){};

    /**
     * @brief Identifier used to for the terminal within the cell
     * 
     */
    string label;

    /**
     * @brief Absolute x-position
     * 
     */
    int x;

    /**
     * @brief Absolute y-position
     * 
     */
    int y;

    /**
     * @brief Relative x-position
     * 
     */
    int rel_x;

    /**
     * @brief Relative y-position
     * 
     */
    int rel_y;

    /**
     * @brief Computes the relative positions
     * 
     * @param x 
     * @param y 
     */
    void compute_absolute_positions(int ref_x, int ref_y);
};

/**
 * @brief Represents the component or any other object that needs to 
 * be placed on the canvas
 * 
 */
class PlacementCell
{
public:
    PlacementCell();

    /**
     * @brief Construct a new Placement Cell object
     * 
     * @param id 
     * @param x 
     * @param y 
     * @param x_span 
     * @param y_span 
     * @param spacing 
     * @param ports 
     */
    PlacementCell(string id, int x, int y, int x_span, int y_span, int spacing, vector<Terminal> ports);

    /**
     * @brief Destroy the Placement Cell object
     * 
     */
    ~PlacementCell()
    {
        this->ports.clear();
    }

    /**
     * @brief Unique identifier for the placement cell
     * 
     */
    string id;

    /**
     * @brief X Coordinate position for the placement cell
     * 
     */
    int x;

    /**
     * @brief Y coordinate position for the placement cell
     * 
     */
    int y;

    /**
     * @brief rotation of the placement cell
     * 
     */
    int rotation;

    /**
     * @brief Width of the placement cell
     * 
     */
    int x_span;

    /**
     * @brief Length of the placement cell
     * 
     */
    int y_span;

    /**
     * @brief The minimus spacing necessary around the component
     * 
     */
    int component_spacing;

    /**
     * @brief Contains the references for the terminal objects 
     * associated with the placement cell
     * 
     */
    vector<Terminal> ports;

    /**
     * @brief Tells the placer to not move the placement cell
     * in the x-coordinate
     * 
     */
    bool lock_x = false;

    /**
     * @brief Tells the placer to not move the placement cell
     * in the y-coordinate
     * 
     */
    bool lock_y = false;

    /**
     * @brief Tells the placer to not rotate the placement
     * cell
     * 
     */
    bool lock_rotation = false;

    bool operator<(const PlacementCell &ob) const
    {
        return this->id < ob.id || (this->id == ob.id);
    }
};

/**
 * @brief Represents the connections/channels that need to be routed
 * on the device
 * 
 */
class Net
{
public:
    /**
     * @brief Construct a new Net object
     * 
     */
    Net();

    /**
     * @brief Construct a new Net object
     * 
     * @param id 
     * @param source_cell 
     * @param source_terminal 
     * @param sink_cells 
     * @param sink_terminals 
     */
    Net(string id, PlacementCell *source_cell, Terminal *source_terminal, vector<PlacementCell *> sink_cells, vector<Terminal *> sink_terminals);

    /**
     * @brief Destroy the Net object
     * 
     */
    ~Net()
    {
        this->sinks.clear();
        this->routes.clear();
        this->sink_terminals.clear();
    }

    /**
     * @brief Unique identifier for the net
     * 
     */
    string id;

    /**
     * @brief Stores the source placment cell
     * 
     */
    PlacementCell *source;

    /**
     * @brief Stores the referene of the terminal where the net starts
     * 
     */
    Terminal *source_terminal;

    /**
     * @brief Stores the spacing around the channel where no
     * routing is supposed to occur
     * 
     */
    int channelSpacing;

    /**
     * @brief Stores the channel width
     * 
     */
    int channelWidth;

    /**
     * @brief Stores the references of the sink placementcells
     * 
     */
    vector<PlacementCell *> sinks;

    /**
     * @brief Stores the references of the terminal where the net
     * ends
     * 
     */
    vector<Terminal *> sink_terminals;

    /**
     * @brief Stores the final routing results as the route objects
     * 
     */
    vector<Route *> routes;
};

/**
 * @brief Captures the constraint object base class
 * 
 */
class Constraint
{
public:
    /**
     * @brief Construct a new Constraint object
     * 
     */
    Constraint();

    /**
     * @brief Destroy the Constraint object
     * 
     */
    ~Constraint(){};

    /**
     * @brief Stores the type of the constraint
     * 
     */
    ConstraintType type;
};

/**
 * @brief Represents the Position Constraints
 * that specifies the x and y coordinates of component
 * 
 */
class PositionConstraint : public Constraint
{
public:
    /**
     * @brief Construct a new Position Constraint object
     * 
     * @param x 
     * @param y 
     * @param cell 
     */
    PositionConstraint(int x, int y, PlacementCell *cell);

    /**
     * @brief Destroy the Position Constraint object
     * 
     */
    ~PositionConstraint(){};

    /**
     * @brief x-coordinates
     * 
     */
    int xpos = -1;

    /**
     * @brief y-coordinates
     * 
     */
    int ypos = -1;

    /**
     * @brief Reference to the Placement cell object the constraint applies to
     * 
     */
    PlacementCell *cell;
};

/**
 * @brief Represents a rotation constriant (allows the user to specify exact 
 * rotation angle) that for a single components
 * 
 */
class RotationConstraint : public Constraint
{
public:
    /**
     * @brief Construct a new Rotation Constraint object
     * 
     * @param rotation 
     * @param cell 
     */
    RotationConstraint(int rotation, PlacementCell *cell);

    /**
     * @brief Destroy the Rotation Constraint object
     * 
     */
    ~RotationConstraint(){};

    /**
     * @brief stores the exact rotation angle
     * 
     */
    int rotation;

    /**
     * @brief Stores the reference placement cell to which this 
     * constraint applies to
     * 
     */
    PlacementCell *cell;
};

class OrientationConstraint : public Constraint
{
public:
    /**
     * @brief Construct a new Orientation Constraint object
     * 
     * @param orientations 
     */
    OrientationConstraint(map<PlacementCell *, Orientation> orientations);

    /**
     * @brief Destroy the Orientation Constraint object
     * 
     */
    ~OrientationConstraint()
    {
        this->orientations.clear();
    };

    /**
     * @brief Map of all the orientations, where the 
     * key is a reference to placement cell and the 
     * stored value is the orientation (vertical | horizontal)
     * 
     */
    map<PlacementCell *, Orientation> orientations;
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
    OrthogonalConstraint(vector<PlacementCell *> cells);
    ~OrthogonalConstraint()
    {
        cells.clear();
    };
    vector<PlacementCell *> cells;
};

class ArrayConstraint : public Constraint
{
public:
    ArrayConstraint(int xdim, int ydim, vector<PlacementCell *> cells);
    ~ArrayConstraint()
    {
        cells.clear();
    };
    int xdim;
    int ydim;
    vector<PlacementCell *> cells;
};

class MirrorConstraint : public Constraint
{
public:
    MirrorConstraint(vector<vector<PlacementCell *>> groups);
    ~MirrorConstraint()
    {
        for (std::size_t i = 0; i < groups.size(); i++)
        {
            groups[i].clear();
        }
        groups.clear();
    }
    vector<vector<PlacementCell *>> groups;
};

class RadialConstraint : public Constraint
{
public:
    RadialConstraint(vector<vector<PlacementCell *>> groups, PlacementCell *center);
    ~RadialConstraint()
    {
        for (std::size_t i = 0; i < groups.size(); i++)
        {
            groups[i].clear();
        }
        groups.clear();
    }
    vector<vector<PlacementCell *>> groups;
    PlacementCell *center;
};

class Placer
{
public:
    Placer();
    Placer(vector<PlacementCell *> cells, vector<Net *> nets, vector<Constraint *> constraints);
    ~Placer()
    {
        this->cells.clear();
        this->nets.clear();
        this->constraints.clear();
    }
    vector<PlacementCell *> cells;
    vector<Net *> nets;
    vector<Constraint *> constraints;

    void place(int max_x, int max_y);

    void place_and_route();
};

#endif