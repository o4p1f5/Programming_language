# 4502.py
from turtle import *
from random import choice

def change_color(x, y):
    colors = ("red", "green", "blue", "purple", "orange")
    g_pen.color(choice(colors))

def main():
    global g_pen
    g_pen = Turtle("circle")
    g_pen.color("blue")
    g_pen.pensize(4)
    g_pen.speed(0)

    onscreenclick(g_pen.setpos)   # btn = 1
    onscreenclick(change_color, btn = 3)
  
if __name__ == "__main__" :
    main()
    mainloop()
