#!/usr/bin/env python3
import alchemy
from alchemy.elements import create_water
from alchemy.potions import healing_potion as heal, strength_potion as stronk
from alchemy.elements import create_earth, create_fire


def brew_potion(type: str, recipe) -> None:
    try:
        print(f"{type}(): {recipe()}")
    except Exception:
        print("Potion go kaboom")


if __name__ == "__main__":
    print("=== Import Transmutation Mastery ===")
    try:
        print("\nMethod 1 - Full module import:")
        print("alchemy.elements.create_fire():", alchemy.create_fire())
        print("\nMethod 2 - Specific module import:")
        print("create_water():", create_water())
        print("\nMethod 3 - Aliased import:")
        brew_potion("heal", heal)
        print("\nMethod 4 - Multiple imports:")
        print("create_earth():", create_earth())
        print("create_fire():", create_fire())
        brew_potion("strength_potion", stronk)
    except Exception:
        print("Error occured during transmutation")
    finally:
        print("\nAll import transmutation methods mastered!")
