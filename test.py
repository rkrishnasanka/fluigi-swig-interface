#!/usr/bin/env python3

from aarf import *


cell1 = Cell()
cell2 = Cell()

cell1.x = 6
cell1.y = 9


print(cell1)

cells = [cell1, cell2]

route = Route()

v1 = Vertex()
v1.x = 0
v1.y = 99

v2 = Vertex()
v2.x = 999
v2.y = 8989

print(route.waypoints)
route.waypoints.append(v1)


print('waypoints:')
for w in route.waypoints:
    print('({}, {})'.format(w.x, w.y))

router = Router(cells, 80, 90)


router.route([v1], [v2])