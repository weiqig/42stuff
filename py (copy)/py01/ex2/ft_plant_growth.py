#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: int, plantAge: int) -> None:
        self.name = name.capitalize()
        self.height = height
        self.plantAge = plantAge

    def get_info(self):
        return (f"{self.name}: {self.height}cm, {self.plantAge} days old")

    def grow(self, cm):
        self.height += cm

    def age(self, days):
        self.plantAge += days


days = 6
plant1 = Plant("Rose", 25, 30)
print("=== Day 1 ===")
print(f"{plant1.get_info()}")
plant1.grow(days)
plant1.age(days)
print("=== Day 7 ===")
print(f"{plant1.get_info()}")
print(f"Growth this week: +{days}cm")
