#!/usr/bin/env python3
# from time import perf_counter as timer
from typing import Generator


def gen_fib(n: int) -> Generator[int, int, None]:
    a, b = 0, 1
    for _ in range(n):
        yield a
        a, b = b, a + b


def gen_prime(n: int) -> Generator[int, int, None]:
    count = 0
    num = 2
    while count < n:
        prime = True
        for i in range(2, int(num ** (1/2)) + 1):
            if num % i == 0:
                prime = False
                break
        if prime:
            yield num
            count += 1
        num += 1


def game_start(event_count: int) -> Generator[str, None, None]:
    print("=== Game Data Stream Processor ===\n")
    print(f"Processing {event_count} game events...\n")
    names = [
        "alice", "bob", "charlie", "david",
        "ellie", "fred", "george"
    ]
    low_level = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    high_level = [12, 14, 21, 26, 33, 38, 42, 67, 84]
    events = [
        "killed a goblin",
        "killed a dragon",
        "found a treasure chest!",
        "leveled up!",
        "has died",
        "hit the jackpot!",
        "has been kicked out from the casino",
        "defeated the elite four!",
        "tried to cross the border",
        "touched grass"
    ]
    high_count = 0
    treasure_count = 0
    lvl_count = 0
    # start = timer()
    for i in range(1, event_count + 1):
        player = names[i % len(names)]
        level = low_level[i % len(low_level)] + high_level[i % len(high_level)]
        action = events[i % len(events)]
        if level >= 20:
            high_count += 1
        if action == "found a treasure chest!":
            treasure_count += 1
        if action == "leveled up!":
            lvl_count += 1
        yield f"Event {i}: Player {player} (level {level}) {action}"
    # end = timer()
    print("")
    print("=== Stream Analytics ===")
    print(f"Total events processed: {event_count}")
    print(f"High-level players (10+): {high_count}")
    print(f"Treasure events: {treasure_count}")
    print(f"Level-up events: {lvl_count}\n")
    # print("Memory usage: Constant (streaming)")
    # print(f"Processing time: {end - start:.3f} seconds\n")
    fib = 10
    pnum = 5
    print("=== Generator Demonstration ===")
    print(f"Fibonacci sequence (first {fib}):", end=" ")
    fib_count = 0
    for num in gen_fib(fib):
        fib_count += 1
        if fib_count == fib:
            print(num)
        else:
            print(num, end=", ")
    print(f"Prime numbers (first {pnum}):", end=" ")
    prime_count = 0
    for num in gen_prime(pnum):
        prime_count += 1
        if prime_count == pnum:
            print(num)
        else:
            print(num, end=", ")


if __name__ == "__main__":
    for event in game_start(1000):
        print(event)
