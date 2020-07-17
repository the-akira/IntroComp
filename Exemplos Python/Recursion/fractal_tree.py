import turtle

WIDTH = 11
BRANCH_LENGTH = 145
ROTATION_LENGTH = 26

class FractalTree(turtle.Turtle):
    def __init__(self, level):
        super(FractalTree, self).__init__()
        self.level = level
        self.hideturtle()
        self.speed('fastest')
        self.color('#3d2506')
        self.left(90)
        self.width(WIDTH)
        self.penup()
        self.back(BRANCH_LENGTH * 1.5)
        self.pendown()
        self.forward(BRANCH_LENGTH)
        self.draw_tree(BRANCH_LENGTH, level)

    def draw_tree(self, branch_length, level):
        self.color('green')
        width = self.width()
        self.width(width * 3.0 / 3.6)
        branch_length *= 3.0 / 3.6
        self.left(ROTATION_LENGTH)
        self.forward(branch_length)

        if level > 0:
            self.draw_tree(branch_length, level - 1)
        self.back(branch_length)
        self.right(2 * ROTATION_LENGTH)
        self.forward(branch_length)

        if level > 0:
            self.draw_tree(branch_length, level - 1)
        self.back(branch_length)
        self.left(ROTATION_LENGTH)

        self.width(width)

if __name__ == '__main__':
    tree_level = 8
    tree = FractalTree(tree_level)
    turtle.done()