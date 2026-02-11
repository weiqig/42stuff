#!/usr/bin/env python3
from .Deck import Deck
from ex0.CreatureCard import CreatureCard
from .SpellCard import SpellCard
from .ArtifactCard import ArtifactCard
from tools.card_generator import CardGenerator


def draw(deck: Deck) -> dict:
    card = deck.draw_card()
    if (card):
        print(f"\nDrew: {card.name} ({card.type})")
        return card
    else:
        print("\nNo more cards left in deck")
    return None

if __name__ == "__main__":
    generator = CardGenerator()
    print("\n=== DataDeck Deck Builder ===")
    print("\nBuilding deck with different card types...")
    deck = Deck()
    mana = 42
    lightning = SpellCard("Lightning Bolt", 3, "R", "damage")
    mana_crystal = ArtifactCard("Mana Crystal", 2, "L", 3, "Permanent: +1 mana per turn")
    fire_dragon = CreatureCard("Fire Dragon", 5, "L", 7, 5)
    deck.add_card(lightning)
    deck.add_card(mana_crystal)
    deck.add_card(fire_dragon)
    print(deck.get_deck_stats())
    print("\nDrawing and playing cards:")
    card = draw(deck)
    print(card.play(mana))
    card = draw(deck)
    print(card.play(mana))
    card = draw(deck)
    print(card.play(mana))
    print("\nPolymorphism in action: Same interface, different card behaviors!")