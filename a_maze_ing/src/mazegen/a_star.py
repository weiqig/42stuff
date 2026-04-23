from typing_extensions import Generator
from .maze import Maze
from .algorithms import SolvingAlgorithm


class AStar(SolvingAlgorithm):
    """
    A* maze solver that yields each step and marks the shortest path.
    """

    def solve(self) -> Generator[Maze, None, None]:
        """
        Solve the maze and yield each step of the shortest path.
        """
        self._initialize_costs()
        yield from self._search()
        yield from self._reconstruct_path()

    def _initialize_costs(self) -> None:
        """
        Initialize all cells with cost info for A*.
        Manhattan distance used as heuristics to get shortest path
        """
        ex, ey = self.maze.exit.pos
        for y, row in enumerate(self.maze.grid[1::2]):
            for x, cell in enumerate(row[1::2]):
                cell._estimated_cost = abs(x - ex) + abs(y - ey)
                cell._from_entry_cost = 0
                cell._cost = -42
                cell.path = False

        start = self.maze.entry
        start._cost = start._estimated_cost
        start._from_entry_cost = 0

    def _search(self) -> Generator[Maze, None, None]:
        """
        Perform the A* search, yield each step during exploration.
        """
        open_list = [self.maze.entry]

        while open_list:

            # Pop the cell with the lowest total cost
            current = min(open_list, key=lambda c: c._cost)
            open_list.remove(current)

            # Mark the current cell as part of the explored path
            current.path = True
            yield self.maze

            # Check if we reached the exit
            if current.exit:
                return

            # Explore neighbors
            for dir in range(4):
                cells = self.maze._get_adjacent(dir, current)
                if cells is None:
                    continue
                sep, adj = cells
                if not (sep and adj) or sep.id == -1:
                    continue
                tentative_g = current._from_entry_cost + 1
                if tentative_g < adj._from_entry_cost or adj._parent is None:
                    adj._from_entry_cost = tentative_g
                    adj._cost = tentative_g + adj._estimated_cost
                    adj._parent = (sep, current)
                    if adj not in open_list:
                        open_list.append(adj)

    def _reconstruct_path(self) -> Generator[Maze, None, None]:
        """
        Follow parent pointers to mark the shortest path.
        """
        cell = self.maze.exit
        path_cells = []

        while cell._parent:
            sep, parent = cell._parent
            path_cells.append(sep)
            path_cells.append(cell)

            offset = (cell.pos[0] - parent.pos[0],
                      cell.pos[1] - parent.pos[1])
            if offset == (0, 2):
                self.maze.path += "S"
            elif offset == (2, 0):
                self.maze.path += "E"
            elif offset == (0, -2):
                self.maze.path += "N"
            elif offset == (-2, 0):
                self.maze.path += "W"
            else:
                self.maze.path += "\nFFS it didn't work\n"

            cell = parent
            if cell.entry:
                self.maze.path = self.maze.path[::-1]
                break

        # Include the entry cell
        path_cells.append(self.maze.entry)

        # Mark path in order
        for c in reversed(path_cells):
            c.shortest_path = True
            yield self.maze
