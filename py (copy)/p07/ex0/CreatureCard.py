#!/usr/bin/env python3
from .Card import Card


# CreatureCard (Concrete Implementation)
class CreatureCard(Card):
    def __init__(self, name: str, cost: int, rarity: str,
                 attack: int, health: int) -> None:
        super().__init__(name, cost, rarity)
        self.type = "Creature"
        try:
            if (attack < 0):
                raise Exception("cannot set attack below 0")
            self.attack = attack
            if (health < 0):
                raise Exception("cannot set health below 0")
            self.health = health
        except Exception:
            print("invalid attack / health")

    def play(self, game_state: dict) -> dict:
        result = {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": "Creature summoned to battlefield" 
        }
        return result

    def attack_target(self, target: dict) -> dict:
        result = {
            "attacker": self.name,
            "target": target.name,
            "damage_dealt": self.attack,
            "combat_resolved": True
        }
        return result
