#!/usr/bin/env python3
from .basic import lead_to_gold
from ..potions import healing_potion


def philosophers_stone() -> None:
    transmute = lead_to_gold()
    potion = healing_potion()
    return f"Philosopher’s stone created using {transmute} and {potion}"


def elixir_of_life() -> None:
    return "Elixir of life: eternal youth achieved!"
