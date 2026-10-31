def input_temperature(temp_str: str) -> int:
    num = int(temp_str)
    if num > 40:
        raise ValueError(f"{num}°C is too hot for plants (max 40°C)")
    elif num < 0:
        raise ValueError(f"{num}°C is too cold for plants (min 0°C)")

    return num


def test_temperature() -> None:
    print("=== Garden Temperature Checker ===\n")
    for temp_str in ["25", "abc", "100", "-50"]:
        print(f"Input data is '{temp_str}'")
        try:
            temp = input_temperature(temp_str)
            print(f"Temperature is now {temp}°C")
        except ValueError as e:
            print(f"Caught input_temperature error: {e}")
        print("")
    print("All tests completed - program didn't crash!")


def main() -> None:
    test_temperature()


if __name__ == "__main__":
    main()
