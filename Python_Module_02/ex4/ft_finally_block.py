class GardenError(Exception):
    def __init__(self, message="Unknown garden error"):
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message="Unknown plant error"):
        super().__init__(message)


def water_plant(plant_name):
    if plant_name != plant_name.capitalize():
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")
    print(f"Watering {plant_name}: [OK]")


def test_watering_system():
    try:
        water_plant("Tomato")
        water_plant("Lettuce")
        water_plant("Carrots")
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    finally:
        print("Closing watering system")


# def main():
#     print("=== Garden Watering System ===")
#     print()
#     print("Testing valid plants...")
#     test_watering_system()
#     print()
#     print("Testing invalid plants...")
#     test_watering_system()
#     print()
#     print("Cleanup always happens, even with errors!")

# if __name__ == "__main__":
#     main()