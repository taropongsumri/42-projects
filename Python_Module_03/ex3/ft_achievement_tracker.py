import random

ACHIEVEMENTS = [
    "Crafting Genius", "World Savior", "Master Explorer",
    "Collector Supreme", "Untouchable", "Boss Slayer",
    "Strategist", "Unstoppable", "Speed Runner", "Survivor",
    "Treasure Hunter", "First Steps", "Sharp Mind",
    "Hidden Path Finder",
]


def gen_player_achievements():
    count = random.randint(6, 11)
    return set(random.sample(ACHIEVEMENTS, count))


def main():
    print("=== Achievement Tracker System ===\n")

    names = ["Alice", "Bob", "Charlie", "Dylan"]
    players = []
    for name in names:
        players += [(name, gen_player_achievements())]

    for name, ach in players:
        print(f"Player {name}: {ach}")
    print()

    all_ach = set()
    for name, ach in players:
        all_ach = all_ach.union(ach)
    print(f"All distinct achievements: {all_ach}\n")

    common = players[0][1]
    for name, ach in players:
        common = common.intersection(ach)
    print(f"Common achievements: {common}\n")

    for name, ach in players:
        others = set()
        for other_name, other_ach in players:
            if other_name != name:
                others = others.union(other_ach)
        print(f"Only {name} has: {ach.difference(others)}")
    print()

    full = set(ACHIEVEMENTS)
    for name, ach in players:
        print(f"{name} is missing: {full.difference(ach)}")


if __name__ == "__main__":
    main()