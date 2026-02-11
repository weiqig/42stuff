#!/usr/bin/env python3
class GardenError(Exception):
    def __init__(self, message: str) -> None:
        self.message = message

    def __str__(self) -> None:
        return f"Caught a garden error: {self.message}"


class PlantError(GardenError):
    def __str__(self) -> None:
        return f"Caught PlantError: {self.message}"


class WaterError(GardenError):
    def __str__(self) -> None:
        return f"Caught WaterError: {self.message}"


def garden_error(plant: str) -> None:
    print("\nTesting catching all garden errors...")
    try:
        raise GardenError(f"The {plant} plant is wilting!")
    except GardenError as e:
        print(e)
    try:
        raise GardenError("Not enough water in the tank!")
    except GardenError as e:
        print(e)


def plant_error(plant: str) -> None:
    print("\nTesting PlantError...")
    try:
        raise PlantError(f"The {plant} plant is wilting!")
    except PlantError as e:
        print(e)


def water_error() -> None:
    print("\nTesting WaterError...")
    try:
        raise WaterError("Not enough water in the tank!")
    except WaterError as e:
        print(e)


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===")
    plant_error("tomato")
    water_error()
    garden_error("tomato")
    print("\nAll custom error types work correctly!")
