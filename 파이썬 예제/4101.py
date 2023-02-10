#4101.py  
from turtle import *
max_y = 200
min_y = -200
ball = Turtle()
ball.speed(1) # 1, 3, 5, 10, 0
#delay(100)
ball.shape("circle")
ball.color("blue", "red")
ball.shapesize(3, 3, 4)
ball.up()
ball.setpos(0, min_y)
ball.down()

##while True:
##    ball.setpos(0, max_y)
##    ball.setpos(0, min_y)
    
while True:
    try:
        ball.setpos(0, max_y)
        ball.setpos(0, min_y)
    except:
        print('Good bye')
        break
