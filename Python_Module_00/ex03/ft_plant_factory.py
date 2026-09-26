class Plant:
    def __init__(self, name, height, days, growth_rate):
        self.name = name
        self.height = float(height)
        self.days = days
        self.growth_rate = growth_rate

    def show(self):
        print(f"{self.name}: {self.height}cm, {self.days} days old")

    def grow(self):
        self.height = round(self.height + self.growth_rate, 1)

    def age(self):
        self.days += 1


def main():
    plants = [
        Plant("Rose", 25, 30, 0.8),
        Plant("Oak", 200, 365, 0.2),
        Plant("Cactus", 5, 90, 0.1),
        Plant("Sunflower", 80, 45, 2.0),
        Plant("Fern", 15, 120, 0.5),
    ]
    print("=== Plant Factory Output ===")
    for plant in plants:
        print("Created: ", end="")
        plant.show()
    print(f"Total plants created: {len(plants)}")


if __name__ == "__main__":
    main()