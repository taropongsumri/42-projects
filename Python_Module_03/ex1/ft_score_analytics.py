import sys

def main():
    print("=== Player Score Analytics ===")
    argc = len(sys.argv)
    scores = []
    x = 1

    while x < argc:
        try:
            scores += [int(sys.argv[x])]
            x+=1
        except ValueError:
            print(f"Invalid parameter: '{sys.argv[x]}'")
            x+=1

    if not scores:
        print(f"No scores provided. Usage: python3 {sys.argv[0]} <score1> <score2> ...")
        return

    print(f"Scores processed: {scores}")
    print(f"Total players: {len(scores)}")
    print(f"Total score: {sum(scores)}")
    print(f"Average score: {sum(scores)/len(scores)}")
    print(f"High score: {max(scores)}")
    print(f"Low score: {min(scores)}")
    print(f"Score range: {max(scores) - min(scores)}")


if __name__ == "__main__":
    main()