class plant:
    def __init__(self, name, age, height):
        self.name = name  # Instance attribute
        self.age = age  # Instance attribute
        self.height = height  # Instance attribute

    def show(self):
        print(f"{self.name}: {self.height}cm, {self.age} days old")

def main():
    rose = plant("Rose", 30, 25)
    rose.show()
    sunf = plant("Sunflower", 45, 80)
    sunf.show()
    cac = plant("Cactus", 120, 15)
    cac.show()

if __name__=="__main__":
    main()