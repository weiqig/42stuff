#!/usr/bin/env python3
from abc import ABC


class Card(ABC):
    def __init__(self, name: str, cost: int, rarity: str) -> None:
        self.name = name
        self.cost = cost
        match rarity:
            case "C":
                self.rarity = "Common"
            case "U":
                self.rarity = "Uncommon"
            case "R":
                self.rarity = "Rare"
            case "E":
                self.rarity = "Epic"
            case "L":
                self.rarity = "Legendary"

    def play(self, game_state: dict) -> dict:
        pass

    def get_card_info(self) -> dict:
        print(f"\n{self.__class__.__name__} Info:")
        info = {
                "name": self.name,
                "cost": self.cost,
                "rarity": self.rarity,
                "type": self.type,
                "attack": self.attack,
                "health": self.health
               }
        return info

    def is_playable(self, available_mana: int) -> bool:
        if self.cost <= available_mana:
            return True
        else:
            return False
