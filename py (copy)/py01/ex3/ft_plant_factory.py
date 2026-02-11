#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: int, plantAge: int) -> None:
        self.name = name.capitalize()
        self.height = height
        self.plantAge = plantAge

    def get_info(self):
        print(f"Created: {self.name} ({self.height}cm, {self.plantAge} days)")

    def grow(self, cm):
        self.height += cm

    def age(self, days):
        self.plantAge += days


plants = [Plant("Rose", 25, 30),
          Plant("Oak", 200, 365),
          Plant("Cactus", 5, 90),
          Plant("Sunflower", 80, 45),
          Plant("Fern", 15, 120)]
print("=== Plant Factory Output ===")
count = 0
for plant in plants:
    plant.get_info()
    count += 1
print(f"\nTotal plants created: {count}")
