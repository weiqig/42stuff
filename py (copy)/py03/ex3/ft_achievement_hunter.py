#!/usr/bin/env python3
def compare_achievements(player1: set, player2: set) -> None:
    common = player1.intersection(player2)
    print("\nAlice vs Bob common:", common)
    print("Alice unique: ", a.difference(common))
    print("Bob unique: ", b.difference(common))


def display_achievements(achievements: list, name: str) -> None:
    print(f"Player {name} achievements: {achievements}")


if __name__ == "__main__":
    a = {"first_kill", "level_10", "treasure_hunter", "speed_demon"}
    b = {"first_kill", "level_10", "boss_slayer", "collector"}
    c = {"level_10", "treasure_hunter", "boss_slayer", "speed_demon",
         "perfectionist"}
    unique = set(["boss_slayer", "collector", "first_kill", "level_10",
                 "perfectionist", "speed_demon", "treasure_hunter"])
    print("=== Achievement Tracker System ===\n")
    display_achievements(a, "alice")
    display_achievements(b, "bob")
    display_achievements(c, "charlie")
    print("\n=== Achievement Analytics ===")
    print(f"All unique achievements: {unique}")
    print(f"Total unique achievements: {len(unique)}")
    print("\nCommon to all players:", a.intersection(b, c))
    ab = a.difference(b).union(b.difference(a))
    abc = ab.difference(c).union(c.difference(ab))
    rare = abc.difference(a.intersection(b, c))
    print("Rare achievements (1 player):", rare)
    compare_achievements(a, b)
