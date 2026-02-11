#!/usr/bin/env python3
class PlantError(Exception):
    def __init__(self, message: str) -> None:
        self.message = message

    def __str__(self) -> None:
        return (f"Error: {self.message}")


def water_plants(control: list, plant_list: list) -> None:
    error = False
    print("Opening watering system")
    try:
        for plant in plant_list:
            if plant is None or plant is int:
                raise PlantError(f"Cannot water {plant} - invalid plant!")
            else:
                print(f"Watering {plant}")
    except PlantError as e:
        error = True
        print(e)
    finally:
        print("Closing watering system (cleanup)")
    if not error:
        print("Watering completed successfully!")
    return error


def test_watering_system(control: list, plant_list: list) -> None:
    error = False
    try:
        error = water_plants(control, plant_list)
    except PlantError as e:
        print(e)
    finally:
        if error:
            print("\nCleanup always happens, even with errors!")


if __name__ == "__main__":
    list = ["tomato", "lettuce", "carrots"]
    list2 = ["tomato", None, 67]
    print("=== Garden Watering System ===")
    print("\nTesting normal watering...")
    test_watering_system(list, list)
    print("\nTesting with error...")
    test_watering_system(list, list2)
