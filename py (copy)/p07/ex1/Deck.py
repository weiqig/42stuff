#!/usr/bin/env python3
import random
from ex0.Card import Card


class Deck:
    def __init__(self):
        self.decklist = []

    def add_card(self, card: Card) -> None:
        self.decklist += [card]

    def remove_card(self, card_name: str) -> bool:
        for card in self.decklist:
            if card.name == card_name:
                self.decklist.remove(card)
                return True
            return False

    def shuffle(self) -> None:
        random.shuffle(self.decklist)

    def draw_card(self) -> Card:
        if self.decklist:
            return self.decklist.pop(0)
        return None
    
    def get_deck_stats(self) -> dict:
        if self.decklist:
            return {cards for cards in self.decklist}
        return None

    def get_deck_stats(self) -> dict:
        total_cards = 0
        creature_count = 0
        spell_count = 0
        artifact_count = 0
        cost_total = 0
        for i, card in enumerate(self.decklist):
            total_cards += 1
            cost_total += card.cost
            if card.__class__.__name__ == "CreatureCard":
                creature_count += 1
            if card.__class__.__name__ == "SpellCard":
                spell_count += 1
            elif card.__class__.__name__ == "ArtifactCard":
                artifact_count += 1
        avg_cost = 0.0
        if total_cards > 0:
            avg_cost = float((cost_total + total_cards - 1) // total_cards)
        stats = {
            "total_cards": total_cards,
            "creatures": creature_count,
            "spells": spell_count,
            "artifacts": artifact_count,
            "avg_cost": avg_cost
        }
        return stats