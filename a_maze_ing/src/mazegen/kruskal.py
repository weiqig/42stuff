# Iterative randomized Kruskal's algorithm.
# Uses disjoint-set data structure.
from collections.abc import Generator
from typing_extensions import override
from .algorithms import MazeAlgorithm
from .maze import Cell, Maze


class Kruskal(MazeAlgorithm):
    """
    Maze generation using the Kruskal algorithm.
    """

    @override
    def generate(self) -> Generator[Maze]:
        """Generate a random maze using the Kruskal algorithm.

        Yields:
            Each step of the maze.
        """
        yield self.maze

        # cells = [
        #     cell
        #     for row in self.maze.grid[1::2]
        #     for cell in row[1::2]
        #     if not cell.ft_pattern
        # ]

        # self.rng.shuffle(cells)

        for cell in self._shuffled_cells():
            if cell.ft_pattern:
                continue
            self._carve_path(cell)
            yield self.maze

        yield from self._merge_sets()
        yield self.maze

    def _shuffled_cells(self) -> list[Cell]:
        """Return all logical maze cells in random order."""
        cells = [
            cell
            for row in self.maze.grid[1::2]
            for cell in row[1::2]
            if not cell.ft_pattern
        ]
        self.rng.shuffle(cells)
        return cells

    def _get_directions(self) -> list[int]:
        """Return directions in random order."""
        dir = [0, 1, 2, 3]
        self.rng.shuffle(dir)
        return dir

    def _carve_path(self, cell: Cell) -> bool:
        """
        remove a wall between twos cells from different sets.

        Args:
            cell: The main cell.

        Returns:
            True if a connection was made, otherwise False.
        """
        if cell.ft_pattern:
            return False
        for dir in self._get_directions():
            if self._try_merge_through_direction(cell, dir):
                return True

        return False

    def _try_merge_through_direction(self, cell: Cell, dir: int) -> bool:
        """Attempt to merge the cell with its neighbor in one direction.

        Args:
            cell: The main cell.
            direction: The direction to inspect.

        Returns:
            True if the merge happened, otherwise False.
        """
        sep, adj = self.maze._get_adjacent(dir, cell)

        if cell.ft_pattern:
            return False

        if not sep or not adj:
            return False

        if sep.ft_pattern or adj.ft_pattern:
            return False

        if adj.id == cell.id:
            return False

        self._update_set(adj, cell.id)
        sep.id = 0
        sep.path = True
        return True

    def _update_set(self, start: Cell, target_id: int) -> None:
        """
        Replace the entire connected set containing start with target_id.

        Args:
            start: A cell from the set to be replaced.
            target_id: The id to assign for the newly combined set.
        """
        original_id = start.id
        stack: list[Cell] = [start]

        if start.ft_pattern:
            return

        while stack:
            cell = stack.pop()
            cell.id = target_id

            for dir in (0, 1, 2, 3):
                sep, adj = self.maze._get_adjacent(dir, cell)
                if sep is None or adj is None:
                    continue
                pattern = sep.ft_pattern or adj.ft_pattern
                if adj and adj.id == original_id and not pattern:
                    stack.append(adj)

    def _merge_sets(self) -> Generator[Maze]:
        """Merge any remaining disconnected sets."""
        for cell in self._shuffled_cells():
            if cell.ft_pattern:
                continue

            for dir in self._get_directions():
                sep, adj = self.maze._get_adjacent(dir, cell)

                if not sep or not adj:
                    continue

                if sep.ft_pattern or adj.ft_pattern:
                    continue

                if adj.id == cell.id:
                    continue

                self._update_set(adj, cell.id)
                sep.id = 0
                sep.path = True
                yield self.maze


# class Kruskal(MazeAlgorithm):
#     """
#     Maze generation using a true Kruskal algorithm with Union-Find.
#     """

#     @override
#     def generate(self) -> Generator[Maze]:
#         yield self.maze

#         # Initialize Union-Find
#         parent: dict[Cell, Cell] = {}
#         rank: dict[Cell, int] = {}

#         def find(cell: Cell) -> Cell:
#             """
#             Finds the root representative of the set that cell belongs to.

#             Attributes:
#                 cell: The cell to find.
#                 ...
#             """
#             if parent[cell] != cell:
#                 parent[cell] = find(parent[cell])  # path compression
#             return parent[cell]

#         def union(a: Cell, b: Cell) -> bool:
#             """
#             Merges two sets if they are different.

#             Attributes:
#                 a, b: The cells/ sets to be merged.
#                 ...

#             Returns:
#                 A boolean value.
#                 False if both cells are in the same set; True otherwise.
#             """
#             root_a = find(a)
#             root_b = find(b)

#             if root_a == root_b:
#                 return False

#             # union by rank
#             if rank[root_a] < rank[root_b]:
#                 parent[root_a] = root_b
#             elif rank[root_a] > rank[root_b]:
#                 parent[root_b] = root_a
#             else:
#                 parent[root_a] = root_b
#                 rank[root_b] += 1
#             return True

#         cells = [
#             cell
#             for row in self.maze.grid[1::2]
#             for cell in row[1::2]
#             if not cell.ft_pattern
#         ]

#         for cell in cells:
#             parent[cell] = cell
#             rank[cell] = 0

#         edges: list[tuple[Cell, Cell, Cell]] = []
#         for cell in cells:
#             for direction in (0, 1):
#                 sep, adj = self.maze._get_adjacent(direction, cell)
#                 if not sep or not adj:
#                     continue
#                 if sep.ft_pattern or adj.ft_pattern:
#                     continue
#                 edges.append((cell, adj, sep))

#         self.rng.shuffle(edges)

#         for cell_a, cell_b, wall in edges:
#             if union(cell_a, cell_b):
#                 wall.id = 0
#                 wall.path = True
#                 yield self.maze

#         yield self.maze
