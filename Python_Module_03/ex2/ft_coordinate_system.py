import math

def split(input , split):
    print(f"Old Input :{input}")
    print(f"{split}")
    x = 0
    value = []
    while x < input:
        if input[x] != split:
            value += float(input[x])
            x+=1
        else:
            x+=1

    print(f"New Input : {value}")

    return

def get_player_pos():
    print("Get a first set of coordinates")
    try:
        x = input("Enter new coordinates as floats in format 'x,y,z': ")
        split(x, ', ')        
    except:
        print("e")
    # finally:

def main():
    print("=== Game Coordinate System ===\n")

    get_player_pos()

if __name__ == "__main__":
    main()