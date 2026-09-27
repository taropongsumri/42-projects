def input_temperature(temp_str):
    try:
        num = int(temp_str)
        if (num <= 0 and num >= 40 ):
            print(f"Input data is '{temp_str}'")
            print(f"Temperature is now {num}°C")
        elif(num < 0):
            print(f"Caught input_temperature error: {num}°C is too cold for plants (min 0°C)")
        elif(num > 40):
            print(f"Caught input_temperature error: {num}°C is too hot for plants (max 40°C)")
        
        return num
    except ValueError:
        print(f"Input data is '{temp_str}'")
        print(f"Caught input_temperature error: invalid literal for int() with base 10: '{temp_str}'")
        return ("error")