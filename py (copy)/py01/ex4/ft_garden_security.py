#!/usr/bin/env python3
class SecurePlant:
    def __init__(self, name: str, height: int, plantAge: int) -> None:
        self.name = name.capitalize()
        self.height = height
        self.plantAge = plantAge
        print(f"Plant created: {self.name}")

    def get_info(self):
        return (f"{self.name} ({self.height}cm, {self.plantAge} days)")

    def get_height(self):
        return (self.height)

    def set_height(self, cm):
        if (cm < 0):
            print(f"\nInvalid operation attempted: height {cm}cm [REJECTED]")
            print("Security: Negative height rejected")
        else:
            self.height = cm
            print(f"Height updated: {cm}cm [OK]")

    def get_age(self):
        return (self.plantAge)

    def set_age(self, days):
        if (days < 0):
            print(f"\nInvalid operation attempted: age {days} days [REJECTED]")
            print("Security: Negative age rejected")
        else:
            self.plantAge = days
            print(f"Age updated: {days}cm [OK]")


print("=== Garden Security System ===")
plant = SecurePlant("rose", 5, 10)
plant.set_height(25)
plant.set_age(30)
plant.set_height(-5)
print(f"\nCurrent plant: {plant.get_info()}")
