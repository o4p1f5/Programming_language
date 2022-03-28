# 3901.py
from turtle import *
t = Turtle()
t.pensize(5)
print(t.pencolor())
print(colormode())

t.pencolor("red")
t.fd(300)
t.lt(90)
t.pencolor("#0000ff")  # t.pencolor("blue")
t.fd(300)
t.pencolor(0, 1, 0)    # t.pencolor("green")
t.setpos(0,0)
