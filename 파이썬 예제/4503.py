# 4503.py
from turtle import *
def move_red(x, y):
    global R
    red.sety(max(0,min(y,255)))
    R = int(red.ycor())
    screen.bgcolor(R, G, B)
def move_green(x, y):
    global G
    green.sety(max(0,min(y,255)))
    G = int(green.ycor())
    screen.bgcolor(R, G, B)
def move_blue(x, y):
    global B
    blue.sety(max(0,min(y,255)))
    B = int(blue.ycor())
    screen.bgcolor(R, G, B)

def make_turtle_and_bar(x, y, color):
    t = Turtle("turtle")
    t.lt(90)
    t.color(color)
    t.shapesize(3, 3, 5)
    t.pensize(10)
    
    t.up()
    t.setpos(x, 0)
    t.down()
    t.sety(255)
    t.up()
    t.sety(y)
    t.pencolor("black")
    return t

def main():
    global screen, red, green, blue
    global R, G, B
    R = G = B = 255
    
    screen = Screen()
    screen.delay(0)
    screen.setworldcoordinates(-50, -50, 250, 300)
    screen.colormode(255)

    red = make_turtle_and_bar(0,  R, "red")
    green = make_turtle_and_bar(100, G, "green")
    blue = make_turtle_and_bar(200,  B, "blue")

    red.ondrag(move_red)
    green.ondrag(move_green)
    blue.ondrag(move_blue)

if __name__ == "__main__" : 
    main() 
    mainloop()
