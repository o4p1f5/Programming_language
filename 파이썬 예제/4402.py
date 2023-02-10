# 4402.py
from turtle import *
screen = Screen()
screen.delay(0)

pen = Turtle("circle")
pen.color("blue", "red")
pen.pensize(4)
pen.speed(0)

pen.ondrag(pen.setpos)
mainloop()
