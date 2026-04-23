#!/usr/bin/env python3
import sys
import os
import time
from typing_extensions import Callable, Tuple, Dict, Any
from pydantic import ValidationError
from src.mazegen import Maze, MazeGenerator
from src.input_parsing import Config, ConfigError, InputParser


def display_help() -> None:
    """
    Display help information.
    """
    print(f"usage: python3 {os.path.basename(sys.argv[0])} <config-file>")


def display_options() -> Tuple[int, int]:
    """
    Display options list.
    """
    cols = 2
    border_length = 35 * cols
    title = "A-maze-ing"
    print("="*border_length)
    print(f"{title:^{border_length}}")
    print("="*border_length)

    option_list = [
        "Regenerate and display new maze",
        # "Display maze configuration",
        "Show / display path",
        "Toggle maze wall colour",
        "Toggle display mode",
        "Change maze parameters",
        "Save maze data",
        "Exit"
    ]
    rows = (len(option_list) + cols - 1) // cols
    count = 1
    for i in range(rows):
        for j in range(cols):
            idx = i * cols + j
            if idx < len(option_list):
                option = f"{count}. {option_list[idx]}"
                print(f"{option:<35}", end=' ')
                count += 1
        print()
    return (border_length, len(option_list))


def init_generator(config: Dict[str, Any]) -> MazeGenerator:
    """
    Initializes and returns a MazeGenerator class.
    """
    try:
        mazegen = MazeGenerator.model_validate(config)
    except ValidationError as e:
        err = e.errors()[0]
        field = err["loc"][0] if err["loc"] else "input"
        msg = err.get("ctx", {}).get("error")
        print(f"Invalid {field}: {msg}")
    except Exception as e:
        print(e)
    return mazegen


def parse_int(prompt: str,
              err_message: str,
              default: int,
              validation: Callable[[int], bool]) -> int | None:
    """
    Parses an integer from the standard input.
    Has customizable validation and error messages.
    """
    while True:
        user_input = input(prompt)
        try:
            new_value: int
            if user_input == "":
                new_value = default
            else:
                new_value = int(user_input)
            if not validation(new_value):
                raise ValueError()
            return new_value
        except ValueError:
            print(err_message)


def change_config(config: Dict[str, Any]) -> None:
    """
    Allows the user to change the configuration during program runtime.
    """

    print("Tip: If you want to use the previous value, "
          "leave the field empty.")
    user_input: str

    # Width
    new_width = parse_int("Enter new width: ",
                          "Invalid input. (Must be an integer, at least 2)",
                          config['width'],
                          lambda i: i >= 2)
    config['width'] = new_width

    # Height
    new_height = parse_int("Enter new height: ",
                           "Invalid input. (Must be an integer, at least 2)",
                           config['height'],
                           lambda i: i >= 2)
    config['height'] = new_height

    while True:
        # Start position
        new_start_x = parse_int("Enter new start position (X): ",
                                "Invalid input. (Must be a non-negative "
                                "integer less than the maze width)",
                                config['entry'][0],
                                lambda i: i >= 0 and i < config['width'])
        new_start_y = parse_int("Enter new start position (Y): ",
                                "Invalid input. (Must be a non-negative "
                                "integer less than the maze height)",
                                config['entry'][1],
                                lambda i: i >= 0 and i < config['height'])

        # End position
        new_end_x = parse_int("Enter new end position (X): ",
                              "Invalid input. (Must be a non-negative integer "
                              "less than the maze width)",
                              config['exit'][0],
                              lambda i: i >= 0 and i < config['width'])
        new_end_y = parse_int("Enter new end position (Y): ",
                              "Invalid input. (Must be a non-negative integer "
                              "less than the maze height)",
                              config['exit'][1],
                              lambda i: i >= 0 and i < config['height'])

        new_start = (new_start_x, new_start_y)
        new_end = (new_end_x, new_end_y)

        if new_start == new_end:
            print("Invalid input: Start and end cannot be the same!")
            continue
        config['entry'] = new_start
        config['exit'] = new_end
        break

    # Algorithm
    new_algorithm: str
    while True:
        new_algorithm = input("Enter algorithm name: ").lower()
        if new_algorithm == "":
            new_algorithm = config['algorithm']
        if new_algorithm == "rdfs" or new_algorithm == "kruskal":
            break
        print("Invalid algorithm. (Must be rdfs or kruskal.)")
    config['algorithm'] = new_algorithm

    # Perfect
    perfect: bool
    while True:
        user_input = input("Is maze perfect? (y/n): ").lower()
        if user_input == "":
            perfect = config['perfect']
            break
        elif user_input == "y":
            perfect = True
            break
        elif user_input == "n":
            perfect = False
            break
        else:
            print("Invalid input. (Must be y/n)")
    config['perfect'] = perfect

    # Seed
    seed: str = input("Enter a new seed: ")
    if seed == "":
        pass
    elif seed == 'none':
        config['seed'] = None
    else:
        config['seed'] = seed
    print("New configuration complete.")


def maze_loop(config: Dict[str, Any]) -> Maze | None:
    """
    Loops the program until user exits the program.
    """
    active = True
    mode = 0
    colour = 42
    display_mode = ["Colour", "Cell Type"]
    print("\nStarting program...")
    print("Creating maze generator...")
    mazegen = init_generator(config)
    print("Generator created.")
    if mazegen:
        print("\nBuilding maze...")
        maze = mazegen._build()
        print("Done!")
        if maze.width < 9 or maze.height < 7:
            print("Couldn't add the 42 pattern - maze too small")
        print("\nDefault display mode:", display_mode[mode])
    else:
        maze = None
        active = False

    shortest_path = True

    is_first_loop = True
    while active:
        try:
            if maze:
                if is_first_loop:
                    is_first_loop = False
                    maze.run_pathfinder()
                maze._display_grid(mode, colour, shortest_path)
            else:
                print("Maze not found.")
                active = False
                break
            maze.display_info()
            border_length, count = display_options()
            if maze:
                option = input(f"Select options (1-{count}): ")
                print("\033[H\033[J", end="")
                print("="*border_length)
                match option.lower():
                    case '1':
                        option = input("Show animation? (Y/N): ")
                        print("="*border_length)
                        gen = mazegen.maze_generator()
                        match option.upper():
                            case 'Y':
                                try:
                                    while True:
                                        print("\033[H", end="")
                                        print("="*border_length)
                                        print("Generating new maze.....")
                                        print("="*border_length)
                                        maze = next(gen)
                                        maze._display_grid(
                                            mode,
                                            colour,
                                            shortest_path
                                        )
                                        time.sleep(0.05)
                                except KeyboardInterrupt:
                                    # return final maze if interrupted
                                    try:
                                        while True:
                                            next(gen)
                                    except StopIteration:
                                        pass
                                except StopIteration:
                                    pass
                                maze.run_pathfinder()
                            case 'N' | _:
                                maze = mazegen._build()
                                maze.run_pathfinder()
                        print("\033[H\033[J", end="")
                        print("="*border_length)
                        print("New maze generated.")
                        if maze.width < 9 or maze.height < 7:
                            print("Couldn't add the 42 pattern "
                                  "- maze too small")
                        # Set the new maze to have the same col as the old one
                    case '2':
                        shortest_path = not shortest_path
                        print("Shortest path:",
                              "SHOWN" if shortest_path else "HIDDEN")
                    case '3':
                        colour = (colour + 1) % 48
                        if colour == 0:
                            colour = 41
                        print("Wall colour changed.")
                    case '4':
                        mode = (mode + 1) % 2
                        print("Current display mode:", display_mode[mode])
                    case '5':
                        print("\033[H\033[J", end="")
                        change_config(config)
                        mazegen = init_generator(config)
                    case '6':
                        maze._save(config["output_file"])
                        print("Saved maze data to:", maze.output_file)
                    case '7':
                        print("\033[H\033[J", end="")
                        active = False
                    case _:
                        print("Invalid user input, try again")
            else:
                raise Exception("Maze not found.")
        except Exception as e:
            print(type(e), e)
        except KeyboardInterrupt:
            print("\033[H\033[J", end="")
            active = False
        finally:
            if active:
                print("="*border_length)
    print("Terminating program...")
    print()
    return maze


def main() -> None:
    """
    Execute the program.
    """
    if len(sys.argv) != 2:
        display_help()
        return
    else:
        # config = get data from the parser
        # parse and validate maze configuration file
        # handle any errors
        # sample data to be replaced with parser to get config from config.txt
        config: Config
        try:
            with open(sys.argv[1], 'r') as f:
                config = InputParser.parse_input(f)
        except FileNotFoundError:
            print("Error: The config file doesn't exist!")
            return
        except PermissionError:
            print("Error: Couldn't open the config file: Permission denied")
            return
        except IsADirectoryError:
            print("Error: Invalid config file (that's a directory)")
            return
        except ConfigError as e:
            print(e)
            return
        except Exception as e:
            print("Oops... an unexpected error occurred.")
            print(f"{type(e)}: {e}")
            return

        config_data = {
            'width': config.width,
            'height': config.height,
            'entry': config.entry_pos,
            'exit': config.exit_pos,
            'output_file': config.output_filename,
            'perfect': config.perfect,
            'seed': config.seed,
            'algorithm': config.algorithm
        }
        try:
            maze = maze_loop(config_data)
        except KeyboardInterrupt:
            pass
        except Exception as e:
            print(e)
        # save maze data at the end of program
        output_file = config.output_filename
        try:
            if maze:
                print(f"Saving maze data to {output_file}...")
                maze._save(output_file)
            else:
                print("No maze data found.")
        except Exception as e:
            print("Exception occurred while saving maze data:", e)
        finally:
            print("Session terminated.")


if __name__ == "__main__":
    main()
