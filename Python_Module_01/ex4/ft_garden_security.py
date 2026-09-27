class Plant:
    def __init__(self, name, height, age):
        self._name = name
        self._height = 0.0
        self._age = 0
        if height < 0:
            print(f"{name}: Error, height can't be negative, set to 0")
        else:
            self._height = float(height)
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
            self._height = float(height)
            print(f"Height updated: {height}cm")

    def set_age(self, age):
        if age < 0:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = age
            print(f"Age updated: {age} days")

    def show(self):
        print(f"{self._name}: {self._height}cm, {self._age} days old")


def main():
    print("=== Garden Security System ===")
    rose = Plant("Rose", 15, 10)
    print("Plant created: ", end="")
    rose.show()
    rose.set_height(25)
    rose.set_age(30)
    rose.set_height(-5)
    rose.set_age(-3)
    print("Current state: ", end="")
    rose.show()


if __name__ == "__main__":
    main()