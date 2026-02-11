#!/usr/bin/env python3
def get_list_comprehension(list_players: list) -> None:
    print("\n=== List Comprehension Examples ===")
    highscorers = [name for name, score, _ in list_players if score > 2000]
    print(f"High scorers (>2000): {highscorers}")
    double_scores = [score * 2 for _, score, _ in list_players]
    print(f"Scores doubled: {double_scores}")
    active_players = [name for name, _, active in list_players if active]
    print(f"Active players: {active_players}")


def get_dict_comprehension(dict_players: dict, achievements: dict) -> None:
    print("\n=== Dict Comprehension Examples ===")
    print(f"Player scores: {dict_players}")
    score_counts = {
        category: sum(
            1 for score in dict_players.values()
            if (score < 2500 and category == "high")
            or (score <= 2200 and category == "medium")
            or (score < 1900 and category == "low")
        )
        for category in ("high", "medium", "low")
    }
    print(f"Score categories: {score_counts}")
    achievement_count = {
        player: len(achievements[player])
        for player in dict_players
    }
    print(f"Achievement counts: {achievement_count}")


def get_set_comprehension(set_player: set, achievements: dict,
                          player_regions: dict) -> None:
    print("\n=== Set Comprehension Examples ===")
    unique_players = {player for player in set_player}
    print(f"Unique players: {unique_players}")
    all_achievements = [
        ach
        for player in achievements
        for ach in achievements[player]
    ]
    all_achievements = sorted(all_achievements)
    unique = {
        ach
        for ach in all_achievements
        if sum(a == ach for a in all_achievements) == 1
    }
    print(f"Unique Achievements: {unique}")
    active_regions = {region for region in player_regions.values()}
    print(f"Active regions: {active_regions}")


def get_comb_analysis(set_players: set, achievements: dict,
                      dict_players: dict, list_players: list) -> None:
    print("\n=== Combined Analysis ===")
    total_players = len(set_players)
    unique_achievements = {
        ach
        for ach_list in achievements.values()
        for ach in ach_list
    }
    total_unique_achievements = len(unique_achievements)
    player_total = len(list_players)
    average_score = sum(score
                        for _, score, _ in list_players) / player_total
    top_player = max(dict_players, key=dict_players.get)
    top_score = dict_players[top_player]
    top_achievements = len(achievements.get(top_player, []))
    print(f"Total players: {total_players}")
    print(f"Total unique achievements: {total_unique_achievements}")
    print(f"Average score: {average_score}")
    print(
        f"Top performer: {top_player} "
        f"({top_score} points, {top_achievements} achievements)"
    )


if __name__ == "__main__":
    print("=== Game Analytics Dashboard ===")
    list_players: list = [
        ("alice", 2300, True),
        ("bob", 1800, True),
        ("charlie", 2150, True),
        ("diana", 2050, False)
    ]
    dict_players: dict = {
        "alice": 2300,
        "bob": 1800,
        "charlie": 2150
    }
    achievements: dict[str, set[str]] = {
        "alice": {"first_kill", "boss_slayer", "level_10", "speed_runner",
                  "collector"},
        "bob": {"first_kill", "level_10", "collector"},
        "charlie": {"first_kill", "boss_slayer", "level_10", "strategist",
                    "sharpshooter", "collector", "veteran"},
        "diana": {"first_kill", "level_10", "veteran", "afkchamp"}
    }
    set_players: set = {
        "alice",
        "bob",
        "charlie",
        "diana"
    }
    player_regions: dict = {
        "alice": "north",
        "bob": "east",
        "charlie": "central",
        "diana": "east"
    }
    get_list_comprehension(list_players)
    get_dict_comprehension(dict_players, achievements)
    get_set_comprehension(set_players, achievements, player_regions)
    get_comb_analysis(set_players, achievements, dict_players, list_players)
