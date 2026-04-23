*This project has been created as part of the 42 curriculum by wgan, mmerican.*

# A-Maze-ing

## Description

The goal of this project is to create a maze generator library in **Python** and package it into a module that can then be installed via **pip**, Python's built-in package manager. In addition, we need to create a user interface that displays the maze and provides users with interactive features (re-generating the maze, changing colours, etc).

## Program features
Our maze display has these features:
- Animated maze generation
- Support for two maze generation algorithms (see the **"Maze Generation Algorithms"** section)
- User interactions, including:
  - Displaying the maze configuration
  - Reconfiguring the maze parameters and re-generating the maze
  - Changing wall colours
  - An alternate rendering mode, showing cell types
  - Showing/hiding the shortest path
  - Saving the maze to the file specified by the config file



## Instructions

The following `make` rules are available:

- `install` Install dependencies.
- `build` Build the `mazegen` package.
- `run` Execute the project's main script.
- `debug` Run the main script in debug mode using pdb.
- `clean` Remove temporary files or caches.
- `lint` Lint the project.
- `lint-strict` Lint the project in strict mode.

The program must be run with the following command:

```sh
python3 a_maze_ing.py <config file>
```

You can also use `make run` or just `make` to do the same thing. This method uses the `config.txt` that is supplied in the repository by default.

## Using the MazeGenerator package

Instantiate the MazeGenerator, with data configuration settings:
```sh
    mazegen = MazeGenerator.model_validate(config)
```
The pydantic model accepts a config argument of type Dict[str, Any] to be validated by the model; the config format should be written and passed as follows:

```sh
config = {
            'width': config.width,
            'height': config.height,
            'entry': config.entry_pos,
            'exit': config.exit_pos,
            'output_file': config.output_filename,
            'perfect': config.perfect,
            'seed': config.seed,
            'algorithm': config.algorithm
        }
```

Create a generator object:
```sh
    gen = mazegen.maze_generator()
```

Retrieve and display each step of the maze generation process:
```sh
maze = next(gen)
maze._display_grid(
    mode,
    colour,
    shortest_path
)
```
- mode = maze display mode: (0 = Colour, 1 = Cell Type)
- colour = ANSI color escape sequences for wall colours (41 - 47)
- shortest_path = boolean value to toggle show / hide path

Immediately generates a maze and show the maze solution:
```sh
maze = mazegen._build()
maze.run_pathfinder()
maze._display_grid(mode, colour, shortest_path)
```
refer to run_pathfinder() function in the Maze class for more details.

## Main classes
### Cell
A maze cell.

Attributes:
- id: Unique identifier of the cell.
- pos: x, y coordinates of the cell.
- path: Whether the cell is a path or not.
- ft_pattern: Whether or not the cell is part of the 42 pattern.
- shortest_path: Whether or not the cell is part of the shortest path.
- visited: Whether the cell has been visited or not.
- entry: Whether the cell is the entry or not.
- exit: Whether the cell is the exit or not.
- cost: The cost of the current cell.
- from_entry_cost: Cost of current cell from entry.
- estimated_cost: The distance from this cell to the exit.
- parent: If this cell is part of the shortest path: the previous cell in the path.

### Maze
A class handling mazes.

Attributes:
- grid: The maze as a grid of integers.
- width: Maze width.
- height: Maze height.
- entry: entry point represented as a cell.
- exit: exit point represented as a cell.
- output_file: file to save maze data.
- perfect: Whether the maze is perfect or not.
- seed: Seed ID.
- wall_colour: Maze wall colour.
- path: The maze route traversal as a string.

### MazeAlgorithm
An abstract class representing a maze-generating algorithm.

Abstract method:
generate()
- Generates the maze walls. This should be a Generator,
and each call should perform one step of the generation
process. (This way, it's possible to animate the maze
generation.)

Concrete (final) methods:
generator()
- The 'main' function of the MazeAlgorithm.
                Will repeatedly call the generate()
                function until that's
finished. Then, if the maze is set to be non-perfect,
it will repeatedly call break_up()
until that's finished.
Then it will exit.

break_up()
- Removes random walls, one per call, allowing the maze to be
non-perfect.

ft_pattern()
- Attempts to insert the 42 pattern into the maze.
                This is the first step in the maze generation process, as
the 42 pattern should NEVER be touched during mazegen.

### SolvingAlgorithm
An abstract class representing a maze-solving algorithm.

## Configuration

The configuration file consists of several options set as `KEY=VALUE` pairs. Each option must be on its own line, and you may write comments by starting a line with a hashtag `#`.

Supported options are shown below:

|   Option    |       Description       | Mandatory |
|------------ | ----------------------- | --------- |
| WIDTH       | Maze width              |    Yes    |
| HEIGHT      | Maze height             |    Yes    |
| ENTRY       | Entry coordinates (x,y) |    Yes    |
| EXIT        | Exit coordinates (x,y)  |    Yes    |
| OUTPUT_FILE | Output filename         |    Yes    |
| PERFECT     | Is the maze perfect ?   |    Yes    |
| SEED        | Unique seed for maze    |    No     |
| ALGORITHM   | The algorithm to run    |    No     |

## Maze Generation Algorithms

### Depth-First Search

- simple and efficient algorithm to generate a maze, usually consisting of long corridors and few branching corridors.

### Kruskal

- Popular algorithm for generating high connected and randomly branching perfect mazes using a disjoint data set structure, biased towards generating mazes with many dead ends.

## Maze Solving Algorithm (A*)

A* (A-star) Algorithm is a popular graph traversal and pathfinding algorithm used to find the shortest path between two points. It improves upon Dijkstra’s algorithm through the applicaton of heuristic search to attain better performance. ([Wikipedia](https://en.wikipedia.org/wiki/A*_search_algorithm))

This algorithm was selected due to its fast and optimal path finding capabilities through heuristics, albeit the higher memory cost needed to keep track of cells.

## Code reusability

The Cell and Maze classes are reused througout the project, with the Maze initialized and created using the Cell class every time a new maze is generated. The same goes for the MazeAlgorithm and SolvingAlgorithm Abstract Base Classes being reused as a blueprint template for the rdfs, kruskal and A* algorithms.

## Project Management

### Task delegation

Our original plan was to delegate the tasks like this:

| Name     | Contribution                   |
| -------- | ------------------------------ |
| wgan     | Maze generation & solving      |
| mmerican | Config parsing, UI & rendering |

We didn't adhere strictly to this plan. `wgan` ended up doing more of the heavy lifting, while `mmerican` focused on small improvements, optimisation, and bugfixing. We also helped each other with our respective parts on a few occasions. In the end, the final task delegation ended up being something like this:

| Name     | Contribution                                                                  |
| -------- | ----------------------------------------------------------------------------- |
| wgan     | Maze generation & solving, documentation, UI & rendering                      |
| mmerican | Config parsing, bugfixing & optimisation, refactoring, rendering improvements |

There were also some shared tasks, such as writing the README and version control.

### What worked well, and what could be improved upon
 Overall we made sure to have a deadline for the delegated tasks and minimized version control conflicts as much as possible, with emphasis on pair programming to quickly solve problems as they came up. One thing that could be improved on would be during the planning phase of the project, where a draft and planning of the code structure would cut down on a lot of trial and error when working on the project, as well as having better communication early on regarding project updates and progress. For the project itself, possible future improvements could include the addition of more algorithms for example Wilson's algorithm for a more uniform and unbiased maze generation, as well as an overhaul to the main a_maze_ing.py file to be optimized by moving the functions over to a different folder to make the code structure more readable.

### Tools used
- pydantic - validation for the MazeGenerator class
- setuptools - build backend used with pip / build in python project packaging
- build - building the reusable module
- pip - installation of dependencies
- flake8 - linting
- mypy - type safety checking

## Resources

- Python official documentation: [Python](https://docs.python.org/3)
- README documentation and structuring guide: [Medium](https://medium.com/@fulton_shaun/readme-rules-structure-style-and-pro-tips-faea5eb5d252)
- Examples of maze generation algorithms: [Wikipedia](https://en.wikipedia.org/wiki/Maze_generation_algorithm)
- Maze generator: [by dqwertyc](https://dqwertyc.github.io/unity-maze-generator)
- Recursive backtracking: [Medium](https://medium.com/@that-software-PM/depth-first-search-dfs-algorithm-201dc95e524)
- Iterative backtracking: [Medium](https://david9dragon9.medium.com/depth-first-search-without-recursion-b8827065d2b6)
- A* Pathfinding algorithm video and explanation: [Sebastian Lague](https://www.youtube.com/watch?v=-L-WgKMFuhE)


### Notes on AI Usage
AI was used to explain and provide examples on existing maze generation and solving algorithms and how they work, and also in debugging and refining the Makefile, .gitignore, and README.md documentation.

## 📄 License

MIT License  
See the `LICENSE` file for more details.