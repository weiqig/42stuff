#!/usr/bin/env python3
import math


def dist_magnitude(pos1: tuple, pos2: tuple) -> float:
    x1, y1, z1 = pos1
    x2, y2, z2 = pos2
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2 + (z2 - z1)**2)


def parse_coordinate(data: str) -> tuple:
    try:
        x, y, z = data.split(',')
        return (int(x), int(y), int(z))
    except Exception as e:
        print(f"Error parsing coordinates: {e}")
        print(f"Error details - Type: {type(e).__name__}, Args: {e.args}")


def init_coordinate_system(pos: tuple, origin: tuple) -> None:
    print("=== Game Coordinate System ===")
    print(f"\nPosition created: {pos}")
    print(f"Distance between {origin} and {pos}: "
          f"{dist_magnitude(origin, pos):.2f}")


def run_unpacking_demo(position: tuple) -> None:
    x, y, z = position
    print(f"Player at x={x}, y={y}, z={z}")
    print(f"Coordinates: X={x}, Y={y}, Z={z}")


if __name__ == "__main__":
    pos = (10, 20, 5)
    origin = (0, 0, 0)
    coord = "3,4,0"
    init_coordinate_system(pos, origin)
    print(f'\nParsing coordinates: "{coord}"')
    print(f"Parsed position: {parse_coordinate(coord)}")
    print(f"Distance between {origin} and {parse_coordinate(coord)}: "
          f"{dist_magnitude(origin, parse_coordinate(coord))}")
    invalid = "abc,def,ghi"
    print(f'\nParsing invalid coordinates: "{invalid}"')
    parse_coordinate(invalid)
    print("\nUnpacking demonstration:")
    final_pos = parse_coordinate(coord)
    run_unpacking_demo(final_pos)
