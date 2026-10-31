class Plant:
    def __init__(self, name: str, height: float, days: int,
                 growth_rate: float) -> None:
        self.name = name
        self.height = height
        self.days = days
        self.growth_rate = growth_rate

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days} days old")

    def grow(self) -> None:
        self.height = round(self.height + self.growth_rate, 1)

    def age(self) -> None:
        self.days += 1


def main() -> None:
    plants = [
        Plant("Rose", 25.0, 30, 0.8),
        Plant("Oak", 200.0, 365, 0.2),
        Plant("Cactus", 5.0, 90, 0.1),
        Plant("Sunflower", 80.0, 45, 2.0),
        Plant("Fern", 15.0, 120, 0.5),
    ]
    print("=== Plant Factory Output ===")
    for plant in plants:
        print("Created: ", end="")
        plant.show()


if __name__ == "__main__":
    main()
