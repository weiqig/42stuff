# Randomized Depth-First Search (DFS) Algorithm.
from typing_extensions import Generator, override
from .algorithms import MazeAlgorithm
from .maze import Cell, Maze


class RandomizedDFS(MazeAlgorithm):
    """
    Maze generation using randomized depth-first search.
    """

    @override
    def generate(self) -> Generator[Maze]:
        """Generate a random maze using randomized DFS.

        Yields:
            Each step of the maze.
        """
        yield self.maze

        start = self.maze.entry
        if start.ft_pattern:
            start = self.maze.grid[1][1]
        start.visited = True
        stack: list[Cell] = [start]
        while stack:
            current = stack[-1]
            next_step = self._check_unvisited(current)
            if next_step is None:
                stack.pop()
                continue
            sep, adj = next_step
            sep.id = 0
            sep.path = True
            adj.visited = True
            stack.append(adj)
            yield self.maze
        yield self.maze

    def _reset_cells(self) -> None:
        """Reset traversal state before generation."""
        for row in self.maze.grid[1::2]:
            for cell in row[1::2]:
                cell.visited = False
        for row in self.maze.grid:
            for cell in row:
                if cell.id == -1:
                    cell.path = False

    def _check_unvisited(
        self, cell: Cell
    ) -> tuple[Cell, Cell] | None:
        """
        Return a random unvisited adjacent cell and its separator.

        Args:
            cell: Current cell.

        Returns:
            A tuple of (sep, adj), or None if no unvisited
            adjacent cell exists.
        """
        directions = [0, 1, 2, 3]
        self.rng.shuffle(directions)

        for dir in directions:
            sep, adj = self.maze._get_adjacent(dir, cell)
            if sep and adj and not adj.visited:
                return sep, adj
        return None
