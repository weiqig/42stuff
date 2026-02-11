#!/usr/bin/env python3
"""
    Relative import works inside packages
    and only when the file is run as a module, not as a script
    running this file directly will result in an import error
"""
from .elements import create_fire, create_water, create_earth, create_air


def healing_potion():
    return f"Healing potion brewed with {create_fire()} and {create_water()}"


def strength_potion():
    return f"Strength potion brewed with {create_earth()} and {create_fire()}"


def invisibility_potion():
    msg = "Invisibility potion brewed with"
    return f"{msg} {create_air()} and {create_water()}"


def wisdom_potion():
    msg = "Wisdom potion brewed with"
    elements = (f"{create_fire()} and {create_water()}"
                f" and {create_earth()} and {create_air()}")
    return f"{msg} {elements}"
