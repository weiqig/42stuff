from typing import IO


class Config:
    """
    Stores a configuration for the maze generator.

    Properties:
    width           - The width of the maze.
    height          - The height of the maze.
    entry_pos       - The start position of the maze.
    exit_pos        - The end position of the maze.
                      ...Must not be the same as the starting position.
    output_filename - The file to write the maze to.
    perfect         - Whether or not the maze is perfect
                      ...(meaning it has only one path from start to finish).
    seed            - The seed given to the algorithm.
    algorithm       - The algorithm used.

    Methods:
    to_string() - Converts the configuration to a string for easy viewing.
    """

    def __init__(self,
                 width: int | None,
                 height: int | None,
                 entry_pos: tuple[int, int] | None,
                 exit_pos: tuple[int, int] | None,
                 perfect: bool | None,
                 output_filename: str | None,
                 seed: str | None,
                 algorithm: str,
                 line_numbers: dict[str, int | None]) -> None:
        """
        Initializes and validates the Config with the input parameters.

        Initializes a new Config using the data passed in as parameters.
        At the same time, performs a few simple error checks.
        This constructor only checks for errors that must be checked
        ...once the whole file has been parsed. Specifically, it checks for:
        - Missing keys
        - Entry/exit out of bounds in the positive direction
        - Entry and exit are the same position
        It does not check for anything else.

        Parameters:
        width - Self-explanatory
        height - Self-explanatory
        entry_pos - Self-explanatory
        exit_pos - Self-explanatory
        perfect - Self-explanatory
        output_filename - Self-explanatory
        seed - Self-explanatory
        algoritm - Self-explanatory
        line_numbers - The line numbers that each part of the config came from.

        Errors:
        ConfigError - If the input configuration is invalid or incomplete.

        Returns:
        Config - A configuration for the maze.
        """

        if width is None:
            raise ConfigError("Missing WIDTH key!", None)
        if height is None:
            raise ConfigError("Missing HEIGHT key!", None)
        if entry_pos is None:
            raise ConfigError("Missing ENTRY_POS key!", None)
        if exit_pos is None:
            raise ConfigError("Missing EXIT_POS key!", None)
        if perfect is None:
            raise ConfigError("Missing PERFECT key!", None)
        if output_filename is None:
            raise ConfigError("Missing OUTPUT_FILE key!", None)

        if entry_pos[0] >= width or entry_pos[1] >= height:
            raise ConfigError("ENTRY_POS out of bounds",
                              line_numbers.get('entry_pos'))
        if exit_pos[0] >= width or exit_pos[1] >= height:
            raise ConfigError("EXIT_POS out of bounds",
                              line_numbers.get('exit_pos'))
        if entry_pos == exit_pos:
            raise ConfigError("Start and end cannot be the same!", None)
        self.width: int = width
        self.height: int = height
        self.entry_pos: tuple[int, int] = entry_pos
        self.exit_pos: tuple[int, int] = exit_pos
        self.perfect: bool = perfect
        self.output_filename: str = output_filename
        self.seed: str | None = seed
        self.algorithm: str = algorithm

    def to_string(self) -> str:
        """Converts the configuration to a string for easy viewing."""

        result = ""
        result += f"Width            = {self.width}\n"
        result += f"Height           = {self.height}\n"
        result += f"Entry Position   = {self.entry_pos}\n"
        result += f"Exit Position    = {self.exit_pos}\n"
        result += f"Output File Name = {self.output_filename}\n"
        result += f"Perfect          = {self.perfect}\n"
        return result


# =========================================================================== #


class ConfigError(Exception):
    """
    Thrown when there is an issue with a configuration file.

    Instance variables:
    message     - The error message
    line_number - The line number on which the error was found,
                  ...if the program is aware of it. (May be null.)
    """

    def __str__(self) -> str:
        """Converts this ConfigError to a string for easy viewing."""
        if self.line_number is None:
            return f"Configuration error: {super().__str__()}"
        return (f"Configuration error on Line {self.line_number}: "
                + super().__str__())

    def __init__(self, message: str, line_number: int | None) -> None:
        """Initializes the ConfigError with the data passed as input."""
        super().__init__(message)
        self.line_number: int | None = line_number


# =========================================================================== #


class InputParser:
    """
    A static class with methods related to input parsing.

    Main method:
    parse_input() - Takes in a stream as input, interprets it as a
                    ...configuration file, and parses it.

    Internally-used methods:
    _parse_width_height() - Parses a positive integer
    _parse_position()     - Parses a coordinate
                           ...(a tuple of two non-negative integers)

    Both of these methods have the same job - take in a string, parse that
    ...string, and return the parsed data (or throw a ConfigError if something
    ...is wrong).
    """

    @staticmethod
    def _parse_width_height(valstr: str, line_number: int) -> int:
        """
        Parses and validates inputs for the width and height of the maze.

        Takes in a string (representing an integer) and a line number,
        ...and attempts to convert it into a positive integer.
        A line number is needed so that it can be given in case an error
        ...occurs.

        Errors:
        ConfigError - If the string doesn't represent a valid positive integer.

        Returns:
        The integer parsed.
        """

        n = 0
        try:
            n = int(valstr)
            if n <= 0:
                raise ValueError("must be positive.")
        except ValueError:
            raise ConfigError(
                "Value must be a positive integer!",
                line_number
            )
        return n

    @staticmethod
    def _parse_position(valstr: str, line_number: int) -> tuple[int, int]:
        """
        Parses and validates inputs for a position inside the maze.

        Takes in a string (representing two non-negative integers) and converts
        ...it into a tuple of integers.

        Errors:
        ConfigError - If the string is malformed (invalid format,
                      ...negative integers, etc.)

        Returns:
        A tuple representing a position inside the maze.
        """

        split = valstr.split(',')
        if len(split) != 2:
            raise ConfigError(
                "Incorrectly-formatted coordinates (must be x,y) "
                "for two non-negative integers x, y",
                line_number
            )

        try:
            result = (int(split[0]), int(split[1]))
        except ValueError:
            raise ConfigError(
                "Incorrectly-formatted coordinates (must be x,y) "
                "for two non-negative integers x, y",
                line_number
            )
        if result[0] < 0 or result[1] < 0:
            raise ConfigError(
                "Invalid coordinates (must be non-negative)",
                line_number
            )
        return result

    @staticmethod
    def parse_input(filestream: IO[str]) -> Config:
        """
        Parses a configuration file and returns the Config obtained.

        Takes in a stream as input, representing the file to parse. Then parses
        ...the file, generating a Config.

        Errors:
        ConfigError - When something is wrong with the configuration file.

        Returns:
        Config - The maze configuration data obtained from the file.
        """

        width: int | None = None
        height: int | None = None
        entry_pos: tuple[int, int] | None = None
        exit_pos: tuple[int, int] | None = None
        output_filename: str | None = None
        perfect: bool | None = None
        seed: str | None = None
        algorithm: str = "kruskal"

        line_numbers: dict[str, int | None] = {
            'width': None,
            'height': None,
            'entry_pos': None,
            'exit_pos': None,
            'output_file': None,
            'perfect': None
        }

        line_number = 0
        for line in filestream:
            line_number += 1

            # Ignore comments and empty lines
            if line.startswith("#"):
                continue
            if line == "":
                continue

            # Check for width and height
            if line.startswith("WIDTH="):
                if width is not None:
                    raise ConfigError("Duplicate WIDTH keys!", line_number)
                width = InputParser._parse_width_height(line[6:], line_number)
                line_numbers['width'] = line_number
                continue

            if line.startswith("HEIGHT="):
                if height is not None:
                    raise ConfigError("Duplicate HEIGHT keys!", line_number)
                height = InputParser._parse_width_height(line[7:], line_number)
                line_numbers['height'] = line_number
                continue

            # Check for entry/exit coordinates
            if line.startswith("ENTRY="):
                if entry_pos is not None:
                    raise ConfigError("Duplicate ENTRY keys!", line_number)
                entry_pos = InputParser._parse_position(line[6:], line_number)
                line_numbers['entry_pos'] = line_number
                continue

            if line.startswith("EXIT="):
                if exit_pos is not None:
                    raise ConfigError("Duplicate EXIT keys!", line_number)
                exit_pos = InputParser._parse_position(line[5:], line_number)
                line_numbers['exit_pos'] = line_number
                continue

            # Check for the output file
            if line.startswith("OUTPUT_FILE="):
                if output_filename is not None:
                    raise ConfigError(
                        "Duplicate OUTPUT_FILE keys!",
                        line_number
                    )
                output_filename = line[12:].rstrip()
                if output_filename == "":
                    raise ConfigError(
                        "Output filename cannot be empty!",
                        line_number
                    )
                line_numbers['output_file'] = line_number
                continue

            # Check for the 'perfect' flag
            if line.startswith("PERFECT="):
                try:
                    if perfect is not None:
                        raise ConfigError(
                            "Duplicate PERFECT keys!",
                            line_number
                        )
                    if line[8:].rstrip() == "True":
                        perfect = True
                    elif line[8:].rstrip() == "False":
                        perfect = False
                    else:
                        print(line[8:], end='')
                        raise ValueError("invalid boolean literal:", line[8:])
                except ValueError:
                    raise ConfigError(
                        "Incorrectly formatted PERFECT key "
                        + "(must be either 'True' or 'False', no quotes)",
                        line_number
                    )
                line_numbers['perfect'] = line_number
                continue

            if line.startswith("SEED="):
                seed = line[5:].rstrip()
                if seed == "":
                    seed = None
                continue

            if line.startswith("ALGORITHM="):
                algorithm = line[10:].rstrip().lower()
                line_numbers['algorithm'] = line_number
                if algorithm != "rdfs" and algorithm != "kruskal":
                    raise ConfigError(
                        "Invalid algorithm (must be either rdfs or kruskal)",
                        line_number
                    )
                continue

            raise ConfigError("Invalid syntax", line_number)

        config = Config(width, height, entry_pos,
                        exit_pos, perfect, output_filename,
                        seed, algorithm, line_numbers)

        return config
