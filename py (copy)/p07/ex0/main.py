#!/usr/bin/env python3
from .CreatureCard import CreatureCard

if __name__ == "__main__":
    print("\n=== DataDeck Card Foundation ===")
    print("\nTesting Abstract Base Class Design:")
    mana = 6
    fire_dragon = CreatureCard("Fire Dragon", 5, "L", 7, 5)
    print(fire_dragon.get_card_info())
    print(f"\nPlaying {fire_dragon.name} with {mana} mana available:")
    print("Playable:", fire_dragon.is_playable(mana))
    print("Play result:", fire_dragon.play({"mana": {mana}}))
    goblin_warrior = CreatureCard("Goblin Warrior", 3, "R", 3, 3)
    print("\nFire Dragon attacks Goblin Warrior:")
    print(fire_dragon.attack_target(goblin_warrior))
    print("\nTesting insufficient mana (3 available):")
    mana = 3
    print("Playable:", fire_dragon.is_playable(mana))
    print("\nAbstract pattern successfully demonstrated!")
