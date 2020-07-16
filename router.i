%module aarf

%{
#include <memory>
%}

%include "typemaps.i"
%include "std_vector.i"
%include "std_shared_ptr.i"

%{
#include "router.h"
%}

%template(VertexVector) std::vector<Vertex>;
%template(RouteVector) std::vector<Route>;
%template(CellVector) std::vector<Cell>;

%include "router.h"