#!/usr/bin/env python3
import alchemy
from alchemy import create_fire, create_water
from alchemy.elements import create_earth, create_air


def run_sacred_scroll():
    print("\n=== Sacred Scroll Mastery ===")
    print("\nTesting direct module access:")
    print("alchemy.elements.create_fire():", create_fire())
    print("alchemy.elements.create_water():", create_water())
    print("alchemy.elements.create_earth():", create_earth())
    print("alchemy.elements.create_air():", create_air())
    print("\nTesting package-level access (controlled by __init__.py):")
    print("alchemy.elements.create_fire():", alchemy.create_fire())
    print("alchemy.elements.create_water():", alchemy.create_water())
    try:
        print("alchemy.elements.create_earth():", alchemy.create_earth())
    except Exception:
        print("alchemy.elements.create_earth(): AttributeError - not exposed")
    try:
        print("alchemy.elements.create_air():", alchemy.create_air())
    except Exception:
        print("alchemy.elements.create_air(): AttributeError - not exposed")

    print("\nPackage metadata:")
    print("Version:", alchemy.__version__)
    print("Author:", alchemy.__author__)


run_sacred_scroll()
