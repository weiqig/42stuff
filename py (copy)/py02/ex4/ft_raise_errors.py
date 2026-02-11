#!/usr/bin/env python3
class PlantError(Exception):
    def __init__(self, message: str) -> None:
        self.message = message

    def __str__(self) -> None:
        return (f"Error: {self.message}")


def check_plant_health(plant_name: str, water_level: int, sunlight_hours: int):
    try:
        if plant_name is None:
            raise PlantError("Plant name cannot be empty!")
        if water_level < 1:
            raise PlantError(f"Water level {water_level}"
                             f" is too low (min 1)")
        elif water_level > 10:
            raise PlantError(f"Water level {water_level}"
                             f" is too high (max 10)")
        if sunlight_hours < 2:
            raise PlantError(f"Sunlight hours {sunlight_hours}"
                             f" is too low (min 2)")
        elif sunlight_hours > 12:
            raise PlantError(f"Sunlight hours {sunlight_hours}"
                             f" is too high (max 12)")
        print(f"Plant '{plant_name}' is healthy!")
    except PlantError as e:
        print(e)


def test_plant_checks() -> None:
    try:
        print("\nTesting good values...")
        check_plant_health("tomato", 3, 8)
        print("\nTesting empty plant name...")
        check_plant_health(None, 5, 8)
        print("\nTesting bad water level...")
        check_plant_health("tomato", 15, 8)
        print("\nTesting bad sunlight hours...")
        check_plant_health("tomato", 5, 0)
    except (TypeError, ValueError) as e:
        print(e)
    finally:
        print("\nAll error raising tests completed!")


if __name__ == "__main__":
    print("=== Garden Plant Health Checker ===")
    test_plant_checks()
