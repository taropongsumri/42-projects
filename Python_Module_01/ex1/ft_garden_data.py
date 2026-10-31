class Plant:
    def __init__(self, name: str, age: int, height: int) -> None:
        self.name = name  # Instance attribute
        self.age = age  # Instance attribute
        self.height = height  # Instance attribute

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")


def main() -> None:
    print("=== Garden Plant Registry ===")
    rose = Plant("Rose", 30, 25)
    rose.show()
    sunf = Plant("Sunflower", 45, 80)
    sunf.show()
    cac = Plant("Cactus", 120, 15)
    cac.show()


if __name__ == "__main__":
    main()
