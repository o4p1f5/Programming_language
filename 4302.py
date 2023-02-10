# 4302.py
from turtle import *
def key_left():
    g_sprite.seth(180)
def key_right():
    g_sprite.seth(0)
def key_up():
    g_sprite.seth(90)
def key_down():
    g_sprite.seth(270)
def key_space():
    if g_sprite.isdown():
        g_sprite.up()
    else:
        g_sprite.down()      
def main(): 
    global g_sprite
    onkey(key_right, "Right")
    onkey(key_left,  "Left")
    onkey(key_up,    "Up")
    onkey(key_down,  "Down")
    onkey(key_space,  "space")       
    listen()

    g_sprite = Turtle("arrow")
    g_sprite.speed(0)
    g_sprite.color("blue", "red")
    g_sprite.shapesize(3, 3, 4)
    g_sprite.pensize(3)
    g_sprite.up()
    
    STEP = 4
    max_x = window_width()/2 - 10
    max_y = window_height()/2 - 10
    min_x = -max_x
    min_y = -max_y

    while True:
        try:            
            g_sprite.fd(STEP)
            x, y = g_sprite.position()
            if (x < min_x)  or  (x > max_x):  g_sprite.lt(180)
            if (y < min_y)  or  (y > max_y):  g_sprite.lt(180)
        except:
            break              
if __name__ == "__main__":
    main()
