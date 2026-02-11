#!/usr/bin/env python3
import sys


def interpret_args() -> None:
    arg_count = len(sys.argv)
    has_args = True
    print("=== Command Quest ===")
    if arg_count == 1:
        print("No arguments provided!")
        has_args = False
    else:
        arg_count -= 1
    print("Program name:", sys.argv[0])
    if has_args:
        print("Arguments received:", arg_count)
    for input in range(1, len(sys.argv)):
        print(f"Argument {input}: {sys.argv[input]}")
    print(f"Total Arguments: {len(sys.argv)}\n")


if __name__ == "__main__":
    interpret_args()
