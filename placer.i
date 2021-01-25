%module placer

%{
#define SWIG_PYTHON_EXTRA_NATIVE_CONTAINERS 
%}

%{
#include <memory>
%}

%include "std_string.i"
%include "typemaps.i"
%include "std_vector.i"
%include "std_map.i"
%include "std_shared_ptr.i"

%{
#include "placer.hpp"
%}

%template(PortVector) std::vector<Terminal>;
%template(PlacementCellVector) std::vector<PlacementCell>;
%template(PortPointerVector) std::vector<Terminal *>;
%template(PlacementCellPointerVector) std::vector<PlacementCell *>;
%template(NetPointerVector) std::vector<Net *>;
%template(ConstraintPointerVector) std::vector<Constraint *>;
%template(PlacementCellGroups) std::vector<vector<PlacementCell*>>;
%template(ConstraintVector) std::vector<Constraint>;
%template(NetVector) std::vector<Net>;
%template(OrientationMap) std::map<PlacementCell*, Orientation>;
%template(SinksVector) std::vector<std::string>;
%template(MirrorGroupsVector) std::vector<std::vector<PlacementCell>>;

%include "placer.hpp"