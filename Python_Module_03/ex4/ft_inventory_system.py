import sys

def ft_split(line):
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

def main():
    argc = len(sys.argv)
    print("=== Inventory System Analysis ===")
    inv = {}

    for arg in sys.argv[1:]:
        parts = split_colon(arg)

        if len(parts) != 2:
            print(f"Error - invalid parameter '{arg}'")
            continue

        name = parts[0]
        qty_text = parts[1]

        try:
            qty = int(qty_text)
        except ValueError as e:
            print(f"Quantity error for '{name}': {e}")
            continue

        if name in inv:
            print(f"Redundant item '{name}' - discarding")
            continue

        inv[name] = qt
    print(f"Redundant item ")
    print(f"Item list: {sys.argv[1:]}")


if __name__ == '__main__':
    main()