#!/usr/bin/env python3
def check_temperature(temp_str: str) -> None:
    print(f"\nTesting temperature: {temp_str}")
    try:
        temp = int(temp_str)
        if (temp == 25):
            print(f"Temperature {temp}°C is perfect for plants!")
        elif (temp < 0):
            print(f"Error: {temp_str}°C is too cold for plants (min 0°C)")
        elif (temp > 40):
            print(f"Error: {temp}°C is too hot for plants (max 40°C)")
    except ValueError:
        print(f"Error: {temp_str} is not a valid number")


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===")
    check_temperature("25")
    check_temperature("abc")
    check_temperature("100")
    check_temperature("-50")
    print("\nAll tests completed - program didn't crash!")
