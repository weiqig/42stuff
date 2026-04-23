# Maze Algorithm classes. Allows for maze generation and pathfinding.
import math
import random
from abc import ABC, abstractmethod
from collections.abc import Generator
from typing import final
from .maze import Maze, Cell


class MazeAlgorithm(ABC):
    """
    An abstract class representing a maze-generating algorithm.

    Abstract method:
    generate() - Generates the maze walls. This should be a Generator,
                 ...and each call should perform one step of the generation
                 ...process. (This way, it's possible to animate the maze
                 ...generation.)

    Concrete (final) methods:
    generator() - The 'main' function of the MazeAlgorithm.
                  Will repeatedly call the generate() function until that's
                  ...finished. Then, if the maze is set to be non-perfect,
                  ...it will repeatedly call break_up() until that's finished.
                  ...Then it will exit.

    break_up() - Removes random walls, one per call, allowing the maze to be
                 ...non-perfect.

    ft_pattern() - Attempts to insert the 42 pattern into the maze.
                   This is the first step in the maze generation process, as
                   ...the 42 pattern should NEVER be touched during mazegen.
    """

    def __init__(self, maze: Maze, seed: random.Random, perfect: bool) -> None:
        """
        Construct and initialize the MazeAlgorithm class.

        Args:
            maze: New maze to generate in.
            perfect: Condition to check if maze is perfect.
        """
        self.maze = maze
        self.rng = seed
        self.perfect = perfect

    @abstractmethod
    def generate(self) -> Generator[Maze]:
        """
        Generate the maze walls.
        """
        pass

    @final
    def generator(self) -> Generator[Maze]:
        """
        Generate the maze.

        Yields:
            Each step of the maze generation.
        """
        self.ft_pattern()
        yield from self.generate()
        if not self.perfect:
            yield from self.break_up()
        yield self.maze

    @final
    def break_up(self) -> Generator[Maze]:
        """
        Break random walls after maze generation to make it un-perfect.

        Yields:
            Each step of the break-ups.
        """
        direction = [0, 1, 2, 3]
        cells = [cell for row in self.maze.grid[1::2] for cell in row[1::2]]
        self.rng.shuffle(cells)
        limit = math.sqrt(self.maze.width * self.maze.height) / 2
        for cell in cells:
            if cell.ft_pattern:
                continue
            self.rng.shuffle(direction)
            for dir in direction:
                sep, _ = self.maze._get_adjacent(dir, cell)
                if (sep and sep.id != 0
                   and not sep.ft_pattern):
                    limit -= 1
                    sep.id = 0
                    sep.path = True
                    yield self.maze
                    break
            if limit <= 0:
                break

    @final
    def ft_pattern(self) -> bool:
        """
        Attempts to draw the 42 pattern onto the center of the maze.
        If the maze is too small (smaller than 9x7), this function
        ...will fail and return False.

        NOTE: The size of the 42 pattern is only 7x5. This function
        ...still fails even on a 8x7 or 9x6 grid because it would
        ...be nearly infeasible to generate an interesting maze
        ...in those cases.

        Returns:
        True if the 42 pattern was successfully added, false otherwise.
        """
        width = self.maze.width
        height = self.maze.height
        # Check if the maze is too small to put the 42 pattern
        # (The pattern itself is 7x5, but yea)
        if width < 9 or height < 7:
            return False

        positions: list[tuple[int, int]] = [
            # The '4'
            (0, 0),
            (0, 1),
            (0, 2),
            (1, 2),
            (2, 2),
            (2, 3),
            (2, 4),

            # The '2'
            (4, 0),
            (5, 0),
            (6, 0),
            (6, 1),
            (6, 2),
            (5, 2),
            (4, 2),
            (4, 3),
            (4, 4),
            (5, 4),
            (6, 4),
        ]

        adjacents: list[tuple[int, int]] = [
            (-1, -1),
            (0, -1),
            (1, -1),
            (1, 0),
            (1, 1),
            (0, 1),
            (-1, 1),
            (-1, 0),
        ]

        def cell_at_pos(x: int, y: int) -> Cell:
            """Helper function: Returns the cell at this position."""
            return self.maze.grid[x][y]

        off_x = int(width / 2 - 3) * 2
        off_y = int(height / 2 - 2) * 2
        for i, p in enumerate(positions):
            pos_x = p[1] * 2 + 1 + off_y
            pos_y = p[0] * 2 + 1 + off_x
            cell = cell_at_pos(pos_x, pos_y)
            cell.ft_pattern = True
            cell.visited = True

            # Ask that the adjacent cells be walls
            for adj in adjacents:
                adjpos_x = pos_x + adj[0]
                adjpos_y = pos_y + adj[1]
                adj_cell = cell_at_pos(adjpos_x, adjpos_y)
                adj_cell.visited = True
                adj_cell.ft_pattern = True
        return True


class SolvingAlgorithm(ABC):
    """An abstract class representing a maze-solving algorithm."""
    def __init__(self, maze: Maze) -> None:
        """
        Construct and initialize the SolvingAlgorithm class.

        Args:
            maze: The maze to solve.
        """
        self.maze: Maze = maze

    @abstractmethod
    def solve(self) -> Generator[Maze, None, None]:
        """
        Find The shortest path in the maze.

        Yields:
            Each step of the maze solving.
        """
        pass
