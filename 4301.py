# 4301.py
from turtle import *
def key_left():
    g_pen.lt(90)
def key_right():
    g_pen.rt(90)
def key_up():
    g_pen.fd(10)
def key_down():
    g_pen.bk(10)
def key_home():
    g_pen.up()
    g_pen.home()
def key_space():
    if g_pen.isdown():
        g_pen.up()
        g_pen.shape( "classic")
    else:
        g_pen.down()
        g_pen.shape("turtle")
def key_clear():
    g_pen.clear()
 	
def main():
    global g_pen
    screen = Screen()
    screen.title("Turtle Key Event processing")

    g_pen = Turtle()
    g_pen.up() #  "classic"에서는 이동
    g_pen.pensize(5)
    g_pen.shapesize(3, 3)

    onkey(screen.bye, "Escape")
    onkey(key_up,    "Up")
    onkey(key_down,  "Down")
    onkey(key_left,  "Left")
    onkey(key_right, "Right")
    onkey(key_home, "Home")
    onkey(key_space, "space")
    onkey(key_clear, "c")
    screen.listen()
#   screen.mainloop()
if __name__ == "__main__" :
    main()
    mainloop()
