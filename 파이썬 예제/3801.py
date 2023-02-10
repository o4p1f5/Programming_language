# 3801.py
from turtle import *
t = Turtle()
setworldcoordinates(-2.0, -2.0, 2.0, 2.0) # t.screen.setworldcoordinates()
t.up()                  # t.penup()
t.setpos(-1, -1)        # t.goto(-1, -1)
t.down()               # t.pendown()
for i in range(4):
	t.fd(2)         # t.forward(2)
	t.lt(90)        # t.left(90)

#setworldcoordinates(-1.2, -1.2, 1.2, 1.2)
