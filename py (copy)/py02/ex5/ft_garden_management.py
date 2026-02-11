#!/usr/bin/python3.10
class EmptyNameError(Exception):
    def __init__(self, val: str) -> None:
        self.val = val

    def __str__(self) -> str:
        return f"Error adding plant: {self.val} cannot be empty!"


class InvalidTypeError(Exception):
    def __init__(self, val: str) -> None:
        self.val = val

    def __str__(self) -> str:
        return f"Error adding plant: Invalid input for {self.val}"


class HealthError(Exception):
    def __init__(self, name: str, message: str) -> None:
        self.name = name
        self.message = message

    def __str__(self) -> str:
        return f"Error checking {self.name}: {self.message}"


class NegativeWater(Exception):
    pass

    def __str__(self) -> str:
        return "Water level cannot be negative"


class EmptyTankError(Exception):
    pass

    def __str__(self) -> str:
        return "Not enough water in tank"


class Plant:
    def __init__(self, name: str, water: int, sunlight: int) -> None:
        self.name = name
        self.water = water
        self.sunlight = sunlight

    def check_health(self) -> None:
        if self.water < 1:
            raise HealthError(f"{self.name}", "Water level "
                              f"{self.water} is too low (min 1)"
                              )
        elif self.water > 10:
            raise HealthError(f"{self.name}", "Water level "
                              f"{self.water} is too high (max 10)"
                              )
        if self.sunlight < 2:
            raise HealthError(f"{self.name}", "Sunlight level "
                              f"{self.sunlight} is too low (min 2)"
                              )
        if self.sunlight > 12:
            raise HealthError(f"{self.name}", "Sunlight level "
                              f"{self.sunlight} is too high (max 12)"
                              )
        else:
            print(f"{self.name}: healthy "
                  f"(water: {self.water}, sun: {self.sunlight})")


class GardenManager:
    def __init__(self) -> None:
        self.__plants = []

    def add_plant(self, plant: str) -> None:
        try:
            if not plant.name:
                raise EmptyNameError("Plant name")
            elif not plant.water:
                raise EmptyNameError("Water level")
            elif not plant.sunlight:
                raise EmptyNameError("Sunlight level")
            if not isinstance(plant.name, str):
                raise InvalidTypeError("Plant name")
            elif not isinstance(plant.water, int):
                raise InvalidTypeError("Water level")
            elif not isinstance(plant.sunlight, int):
                raise InvalidTypeError("Sunlight level")
            else:
                print(f"Added {plant.name} successfully")
                self.__plants = self.__plants + [plant]
        except Exception as e:
            print(e)

    def water_plants(self, amount: int, water_level: int) -> None:
        print("Opening watering system")
        try:
            if amount < 0:
                raise NegativeWater()
            else:
                for plant in self.__plants:
                    if amount > water_level:
                        raise EmptyTankError()
                    plant.water += amount
                    water_level -= amount
                    print(f"Watering {plant.name} - success")
        except Exception as e:
            print(f"Caught GardenError: {e}")
        finally:
            print("Closing watering system (cleanup)")

    def check_health(self) -> None:
        print("\nChecking plant health...")
        if len(self.__plants) == 0:
            print("List of plants is empty.")
        else:
            try:
                for plant in self.__plants:
                    plant.check_health()
            except Exception as e:
                print(e)


def test_garden_management() -> None:
    print("=== Garden Management System ===")
    manager = GardenManager()
    print("\nAdding plants to garden...")
    manager.add_plant(Plant("tomato", 2, 8))
    manager.add_plant(Plant("lettuce", 12, 2))
    manager.add_plant(Plant("", water=5, sunlight=5))
    print("\nWatering plants...")
    manager.water_plants(amount=3, water_level=10)
    manager.check_health()
    print("\nTesting error recovery...")
    try:
        manager.water_plants(amount=5, water_level=2)
    except Exception as e:
        print(f"Caught GardenError: {e}")
    finally:
        print("System recovered and continuing...")
    print("\nGarden management system test complete!")


if __name__ == "__main__":
    test_garden_management()
