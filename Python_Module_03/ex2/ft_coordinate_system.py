import math

def split_coords(line):
    parts = []
    tok = ""
    pending = "" 
    for c in line:
        if c == ',':
            parts += [tok]
            tok = ""
            pending = ""
        elif c == ' ':
            if tok != "":
                pending += c
        else:
            tok += pending + c
            pending = ""
    parts += [tok]
    return parts


def get_player_pos():
    while True:
        line = input("Enter new coordinates as floats in format 'x,y,z': ")
        parts = split_coords(line)
        try:
            x, y, z = parts
        except ValueError:
            print("Invalid syntax")
            continue
        coords = []
        ok = True
        for p in (x, y, z):
            try:
                coords += [float(p)]
            except ValueError as e:
                print(f"Error on parameter '{p}': {e}")
                ok = False
                break
        if ok:
            return (coords[0], coords[1], coords[2])


def main():
    print("=== Game Coordinate System ===\n")

    print("Get a first set of coordinates")
    pos1 = get_player_pos()
    print(f"Got a first tuple: {pos1}")
    x1, y1, z1 = pos1
    print(f"It includes: X={x1}, Y={y1}, Z={z1}")
    dist_center = math.sqrt(x1 ** 2 + y1 ** 2 + z1 ** 2)
    print(f"Distance to center: {round(dist_center, 4)}\n")

    print("Get a second set of coordinates")
    pos2 = get_player_pos()
    x2, y2, z2 = pos2
    dist = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2 + (z2 - z1) ** 2)
    print(f"Distance between the 2 sets of coordinates: {round(dist, 4)}")


if __name__ == "__main__":
    main()