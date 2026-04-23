# MazeGenerator class. Uses pydantic model for type hinting and validation
import random
from pydantic import (
    BaseModel,
    Field,
    model_validator
    )
from collections.abc import Generator
from typing_extensions import Self
from .maze import Maze


class MazeGenerator(BaseModel):
    '''
    MazeGenerator Class that inherits from BaseModel;
    allows for automatic and custom validation of config data.
    '''
    width: int = Field(ge=1, le=1000)
    height: int = Field(ge=1, le=1000)
    entry: tuple[int, int]
    exit: tuple[int, int]
    output_file: str
    perfect: bool = False
    seed: str | int | None = None

    algorithm: str

    @model_validator(mode="after")
    def validate_maze(self) -> Self:
        """
        Validates the maze.

        Checks for any of these possible error cases:
        - Maze dimensions are too small (1*Y or X*1)
        - Entry and exit are the same
        - Entry and/or exit out of bounds in any direction
        """
        # Validate maze dimensions
        if self.width < 2 or self.height < 2:
            raise ValueError("Invalid maze dimensions provided!")

        # Validate same entry and exit coordinates
        if self.entry == self.exit:
            raise ValueError("Entry and exit cannot be the same")

        # Validate entry/exit coordinates
        coords = [("entry", self.entry), ("exit", self.exit)]
        for name, (row, col) in coords:
            if not (0 <= row < self.width):
                msg = f"{name} row out of bounds (max {self.width-1})"
                raise ValueError(msg)
            if not (0 <= col < self.height):
                msg = f"{name} col out of bounds (max {self.height-1})"
                raise ValueError(msg)
        return self

    def _get_algorithm(self, algorithm: str) -> type:
        """
        Maps algorithm name to its class.
        Lazy-imports the class when needed.
        """
        # import specified algorithm
        match algorithm.lower():
            case "rdfs":
                from .rdfs import RandomizedDFS
                return RandomizedDFS
            case "kruskal":
                from .kruskal import Kruskal
                return Kruskal
            case _:
                raise ValueError(f"Unknown algorithm: {algorithm}")

    def get_maze_template(self) -> Maze:
        """
        Creates a new Maze using the data stored in the MazeGenerator itself.
        """
        maze = Maze(
            width=self.width,
            height=self.height,
            entry=self.entry,
            exit=self.exit,
            output_file=self.output_file,
            perfect=self.perfect,
            seed=self.seed,
        )
        return maze

    def maze_generator(self) -> Generator[Maze]:
        """
        Generate a maze.

        :param self: Description
        :returns a maze generator object
        :rtype: Generator[Maze, None, None]
        """
        if self.seed is not None:
            seedgen = random.Random(self.seed)
        else:
            seedgen = random.Random()
        maze = self.get_maze_template()

        # get algorithm class and iterate through generator
        algorithm = self._get_algorithm(self.algorithm)
        maze_algorithm = algorithm(maze, seedgen, perfect=self.perfect)
        for state in maze_algorithm.generator():
            yield state
        yield maze

    def _build(self) -> Maze:
        """
        Build and return the generated maze.
        """
        gen = self.maze_generator()
        maze_state: Maze
        try:
            while True:
                maze_state = next(gen)
        except StopIteration:
            if not isinstance(maze_state, Maze):
                raise Exception(f"what. ({type(maze_state)})")
            return maze_state
