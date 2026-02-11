#!/usr/bin/env python3
class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name.capitalize()
        self.height = height
        self.age = age

    def plantInfo(self):
        print(f"Created: {self.name} ({self.height}cm, {self.age} days)")


class Flower(Plant):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age)
        self.type = self.__class__.__name__
        self.color = color

    def displayInfo(self):
        info = f"({self.type}): {self.height}cm, {self.age} days"
        print(f"\n{self.name} {info}, {self.color} color")

    def bloom(self):
        print(f"{self.name} is blooming beautifully!")


class Tree(Plant):
    def __init__(self, name, height, plantAge, trunk_diameter):
        super().__init__(name, height, plantAge)
        self.type = self.__class__.__name__
        self.trunk_diameter = trunk_diameter

    def displayInfo(self):
        info = f"({self.type}): {self.height}cm, {self.age} days"
        print(f"\n{self.name} {info}, {self.trunk_diameter}cm diameter")

    def produce_shade(self):
        shade = int(self.trunk_diameter * 3.14 / 2)
        print(f"{self.name} provides {shade} square meters of shade")


class Vegetable(Plant):
    def __init__(self, name, height, age, harvest_season, nutritional_value):
        super().__init__(name, height, age)
        self.type = self.__class__.__name__
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def displayInfo(self):
        info = f"({self.type}): {self.height}cm, {self.age} days"
        print(f"\n{self.name} {info}, {self.harvest_season} harvest")
        print(f"{self.name} is rich in {self.nutritional_value}")


f1 = Flower("Rose", 25, 30, "red")
f2 = Flower("Magnolia", 15, 10, "white")
t1 = Tree("oak", 500, 1825, 50)
t2 = Tree("birch", 500, 1825, 50)
v1 = Vegetable("tomato", 80, 90, "summer", "vitamin C")
v2 = Vegetable("Carrot", 30, 60, "summer", "vitamin A")
print("=== Garden Plant Types ===")
f1.displayInfo()
f1.bloom()
t1.displayInfo()
t1.produce_shade()
v1.displayInfo()
