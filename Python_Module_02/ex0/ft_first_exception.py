def input_temperature(temp_str):
    try:
        num = int(temp_str)
        print(f"Input data is '{temp_str}'")
        print(f"Temperature is now {num}°C")
        return num
    except ValueError:
        print(f"Input data is '{temp_str}'")
        print(f"Caught input_temperature error: invalid literal for int() with base 10: '{temp_str}'")
        return ("error")