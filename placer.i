%module placer

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

%template(PortVector) std::vector<Port>;
%template(PlacementCellVector) std::vector<PlacementCell>;
%template(ConstraintVector) std::vector<Constraint>;
%template(NetVector) std::vector<Net>;
%template(OrientationMap) std::map<std::string, Orientation>;
%template(SinksVector) std::vector<std::string>;
%template(MirrorGroupsVector) std::vector<PlacementCellVector>;

%include "placer.hpp"