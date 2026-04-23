# Maze building blocks. Contains Cell and Maze class.
class Cell:
    """
    A maze cell.

    Attributes:
        id: Unique identifier of the cell.
        pos: x, y coordinates of the cell.
        path: Whether the cell is a path or not.
        ft_pattern: Whether or not the cell is part of the 42 pattern.
        shortest_path: Whether or not the cell is part of the shortest path.
        visited: Whether the cell has been visited or not.
        entry: Whether the cell is the entry or not.
        exit: Whether the cell is the exit or not.
        cost: The cost of the current cell.
        from_entry_cost: Cost of current cell from entry.
        estimated_cost: The distance from this cell to the exit.
        parent: If this cell is part of the shortest path: the previous cell
        ...in the path.
    """

    def __init__(self, pos: tuple[int, int]) -> None:
        """
        Initializes the Cell with a position and default data.
        """
        self.id: int = -1
        self.pos = pos
        self.path: bool = False
        self.ft_pattern: bool = False
        self.shortest_path: bool = False
        self.visited: bool = False
        self.entry: bool = False
        self.exit: bool = False
        self._cost: int = -1
        self._from_entry_cost: int = 0
        self._estimated_cost: int = 0
        self._parent: tuple[Cell, Cell] | None = None


class Maze:
    """
    A class handling mazes.

    Attributes:
        grid: The maze as a grid of integers.
        width: Maze width.
        height: Maze height.
        entry: entry point represented as a cell.
        exit: exit point represented as a cell.
        output_file: file to save maze data.
        perfect: Whether the maze is perfect or not.
        seed: Seed ID.
        wall_colour: Maze wall colour.
        path: The maze route traversal as a string.
    """
    def __init__(
        self,
        width: int,
        height: int,
        entry: tuple[int, int],
        exit: tuple[int, int],
        output_file: str,
        perfect: bool,
        seed: str | int | None = None
    ) -> None:
        """
        Initializes the Maze with the data passed in as parameters.
        """
        self.grid: list[list[Cell]] = []
        self.width = width
        self.height = height
        self.entry: Cell
        self.exit: Cell
        self.output_file: str = output_file
        self.perfect = perfect
        self.seed = seed
        self.wall_colour = 42
        self.path: str = ""

        cell_id = 0
        exp_entry = tuple(2 * i + 1 for i in entry)
        exp_exit = tuple(2 * i + 1 for i in exit)
        for row in range((self.height * 2) + 1):
            current_row: list[Cell] = []
            for col in range((self.width * 2) + 1):
                pos = (col, row)
                cell = Cell(pos)
                if row % 2 and col % 2:
                    cell.path = True
                    cell.id = cell_id
                    cell_id += 1
                    if pos == exp_entry:
                        self.entry = cell
                        cell.entry = True
                    elif pos == exp_exit:
                        self.exit = cell
                        cell.exit = True
                current_row.append(cell)
            self.grid.append(current_row)
        if self.entry is None or self.exit is None:
            raise ValueError("Entry or Exit is not set")

    def display_info(self) -> None:
        """Displays the maze configuration to the standard output."""
        print("Current maze configuration:")
        print(f"Dimensions : {self.width} x {self.height}")
        print("Entry cell :", tuple((i - 1) // 2 for i in self.entry.pos))
        print("Exit cell  :", tuple((i - 1) // 2 for i in self.exit.pos))
        print("Seed       :", self.seed)
        print("Perfect?   :", self.perfect)
        print(f"Path       : {self.path} ({len(self.path)})")

    def _display_grid(self,
                      mode: int,
                      colour: int,
                      show_shortest_path: bool) -> None:
        """
        display the maze as a grid;
        get the pos (x, y) with y = cell index of the row,
        where x = row index | row = cells in the list.

        mode: accepts an integer value or None if empty.
        Toggle display modes:
        0 - Maze Visual (X = wall, C = cell, S = entry, E = exit, . = path)
        1 - Colour grid (Blue = entry, Red = exit)
        2 - Cell id (id to differentiate between cell sets)
        """
        # helper function for printing cells
        def colour_block(bg: int) -> str:
            """Returns a string representing a coloured block rendered
            ...on the terminalwith ANSI escape codes."""
            return f"\033[1;30;{bg}m  \033[0m"
        print()
        for r, row in enumerate(self.grid):
            match mode:
                case 0:
                    for c, cell in enumerate(row):
                        if r % 2 == 0 or c % 2 == 0:
                            if show_shortest_path and cell.shortest_path:
                                print(colour_block(105), end='')
                            elif cell.path:
                                print(colour_block(34), end='')
                            else:
                                print(colour_block(colour), end='')
                        elif (c, r) == self.entry.pos:
                            print(colour_block(104), end='')
                        elif (c, r) == self.exit.pos:
                            print(colour_block(101), end='')
                        elif cell.ft_pattern:
                            print(colour_block(colour + 60), end='')
                        elif show_shortest_path and cell.shortest_path:
                            print(colour_block(105), end='')
                        else:
                            print(colour_block(40), end='')
                    print()
                case 1:
                    for c, cell in enumerate(row):
                        if r % 2 == 0 or c % 2 == 0:
                            if show_shortest_path and cell.shortest_path:
                                print("\033[105m. \033[0m", end='')
                            elif cell.path:
                                print("\033[1m.\033[0m", end=' ')
                            else:
                                print(colour_block(colour), end='')
                        else:
                            if show_shortest_path and cell.shortest_path:
                                print("\033[105m", end='')
                            match (c, r):
                                case self.entry.pos:
                                    print('S', end=' ')
                                case self.exit.pos:
                                    print('E', end=' ')
                                case _:
                                    if cell.ft_pattern:
                                        print(f"\033[{colour + 60}mFT", end='')
                                    else:
                                        print('C', end=' ')
                            if show_shortest_path and cell.shortest_path:
                                print("\033[0m", end='')
                    print()
                case 2:
                    for c, cell in enumerate(row):
                        if r % 2 == 0 or c % 2 == 0:
                            if cell.path:
                                # Breakable wall / path
                                print(f"\033[1m{cell.id:2}\033[0m", end=' ')
                            else:
                                # Wall
                                print(f"\033[1m{cell.id}\033[0m", end=' ')
                        else:
                            # Cell
                            print(f"{cell.id:2}", end=' ')
                    print()
                case _:
                    raise ValueError("Invalid display mode")
        print()

    def _get_adjacent(
        self, direction: int, cell: Cell
    ) -> tuple[Cell, Cell] | tuple[None, None]:
        """Get the adjacent cell in one direction.

        If there is no adjacent cell, the separator wall should not be changed.
        Thus the method returning either a complete tuple or an empty tuple.

        Args:
            direction: The direction of the adjacent cell.
            x: The x coordinate of the cell.
            y: The y coordinate of the cell.

        Directions:
        0 - up N
        1 - down S
        2 - left W
        3 - right E
        Returns:
            the cell or None
        """
        col, row = cell.pos
        sep, adj = None, None
        try:
            match direction:
                case 0:  # up
                    if row >= 2:
                        return self.grid[row - 1][col], self.grid[row - 2][col]
                case 1:  # right
                    if col <= len(self.grid[0]) - 3:
                        return self.grid[row][col + 1], self.grid[row][col + 2]
                case 2:  # down
                    if row <= len(self.grid) - 3:
                        return self.grid[row + 1][col], self.grid[row + 2][col]
                case 3:  # left
                    if col >= 2:
                        return self.grid[row][col - 1], self.grid[row][col - 2]
                case _:
                    pass
        except IndexError:
            return (None, None)
        if sep and adj:
            return (sep, adj)
        return (None, None)

    def run_pathfinder(self) -> None:
        from .a_star import AStar
        solver = AStar(self)
        for step in solver.solve():
            pass

    def _save(self, file: str) -> None:
        """
        Save the maze output.
        """
        maze_output: str = ""
        for row in self.grid[1::2]:
            hex_row = ""
            for cell in row[1::2]:
                hex = 0
                for dir in range(4):
                    sep, adj = self._get_adjacent(dir, cell)
                    if not adj or (sep and sep.id == -1):
                        hex |= 1 << dir
                hex_row += f"{hex:X}"
            maze_output += f"{hex_row}\n"
        maze_output += "\n"
        x, y = [int((i - 1) / 2) for i in self.entry.pos]
        maze_output += f"{x},{y}\n"
        x, y = [int((i - 1) / 2) for i in self.exit.pos]
        maze_output += f"{x},{y}\n"
        if self.path != "":
            maze_output += self.path + "\n"
        else:
            print("\033[31mMissing maze path!\033[0m")

        with open(file, 'w') as f:
            f.write(maze_output)
