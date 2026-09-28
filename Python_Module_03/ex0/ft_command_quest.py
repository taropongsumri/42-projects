import sys

def main():
    argc = len(sys.argv)
    n = 1
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    if argc < 2:
        print("dont have arguments!")
    else:
        print(f"Arguments received: {argc-1}")
        while n < argc:
            print(f"Arguments {n} {sys.argv[n]}")
            n+=1

        print(f"Total arguments: {argc}")

if __name__ == "__main__":
    main()