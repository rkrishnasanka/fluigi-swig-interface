from place_and_route import *


terminals = []

t1 = Terminal("Terminal 1", 5, 5)

terminals.append(t1)

cell1 = PlacementCell("0", 0, 0, 10, 10, 10, terminals)

cell2 = PlacementCell("1", 25, 25, 10, 10, 10, terminals)

sinks = []
sinks.append("1")

net1 = Net("n0", "0", sinks)

cells = []
cells.append(cell1)
cells.append(cell2)
nets = []
nets.append(net1)

constriants = []
c1 = OrthogonalConstraint(cells)
constriants.append(c1)

placer = Placer(cells, nets, constriants)

placer.place()