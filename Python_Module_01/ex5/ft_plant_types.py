class Plant:
    def __init__(self, name, height, age, growth_rate=0.8):
        self._name = name
        self._height = 0.0
        self._age = 0
        self._growth_rate = growth_rate
        if height < 0:
            print(f"{name}: Error, height can't be negative, set to 0")
        else:
            self._height = height
        if age < 0:
            print(f"{name}: Error, age can't be negative, set to 0")
        else:
            self._age = age

    def get_height(self):
        return self._height

    def get_age(self):
        return self._age

    def set_height(self, height):
        if height < 0:
            print(f"{self._name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = height
            print(f"Height updated: {height}cm")

    def set_age(self, age):
        if age < 0:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = age
            print(f"Age updated: {age} days")

    def grow(self):
        self._height = round(self._height + self._growth_rate, 1)

    def age(self):
        self._age += 1

    def show(self):
        print(f"{self._name}: {self._height}cm, {self._age} days old")


class Flower(Plant):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age)
        self._color = color
        self._bloomed = False

    def bloom(self):
        self._bloomed = True

    def show(self):
        super().show()
        print(f"Color: {self._color}")
        if self._bloomed:
            print(f"{self._name} is blooming beautifully!")
        else:
            print(f"{self._name} has not bloomed yet")


class Tree(Plant):
    def __init__(self, name, height, age, trunk_diameter):
        super().__init__(name, height, age, 0.2)
        self._trunk_diameter = trunk_diameter

    def produce_shade(self):
        print(f"Tree {self._name} now produces a shade of "
              f"{self._height}cm long and {self._trunk_diameter}cm wide.")

    def show(self):
        super().show()
        print(f"Trunk diameter: {self._trunk_diameter}cm")


class Vegetable(Plant):
    def __init__(self, name, height, age, harvest_season):
        super().__init__(name, height, age, 2.1)
        self._harvest_season = harvest_season
        self._nutritional_value = 0

    def grow(self):
        super().grow()
        self._nutritional_value += 0.5

    def age(self):
        super().age()
        self._nutritional_value += 0.5

    def show(self):
        super().show()
        print(f"Harvest season: {self._harvest_season}")
        print(f"Nutritional value: {round(self._nutritional_value)}")


def main():
    print("=== Garden Plant Types ===")

    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    print("[asking the rose to bloom]")
    rose.bloom()
    rose.show()

    print("=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    print("[asking the oak to produce shade]")
    oak.produce_shade()

    print("=== Vegetable")
    tomato = Vegetable("Tomato", 5.0, 10, "April")
    tomato.show()
    print("[make tomato grow and age for 20 days]")
    for _ in range(20):
        tomato.grow()
        tomato.age()
    tomato.show()


if __name__ == "__main__":
    main()