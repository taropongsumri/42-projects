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
    rose = Plant("Rose", 25, 30, 0.8)
    print("=== Garden Plant Growth ===")
    rose.show()
    start_height = rose.height
    for day in range(1, 8):
        print(f"=== Day {day} ===")
        rose.grow()
        rose.age()
        rose.show()
    growth = round(rose.height - start_height, 1)
    print(f"Growth this week: {growth}cm")


if __name__ == "__main__":
    main()