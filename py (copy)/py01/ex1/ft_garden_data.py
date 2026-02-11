#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: int, plantAge: int) -> None:
        self.name = name.capitalize()
        self.height = height
        self.plantAge = plantAge

    def displayInfo(self):
        print(f"{self.name}: {self.height}cm, {self.plantAge} days old")


plant1 = Plant("Rose", 25, 30)
plant2 = Plant("Sunflower", 80, 45)
plant3 = Plant("Cactus", 15, 120)
print("=== Garden Plant Registry ===")
plant1.displayInfo()
plant2.displayInfo()
plant3.displayInfo()
