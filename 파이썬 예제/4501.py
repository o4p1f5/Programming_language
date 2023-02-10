# 4501.py
from turtle import *
def move_turtle(x, y):
    g_pen.up()
    g_pen.setpos(x, y)
    g_pen.down()

def main():
    global g_pen    
    screen = Screen()
    screen.delay(0)
    g_pen = Turtle("circle")
    g_pen.color("blue", "red")
    g_pen.pensize(4)
    g_pen.speed(0)

    g_pen.ondrag(g_pen.setpos) # g_pen.ondrag(g_pen.goto)
    onscreenclick(move_turtle)  # screen.onclick(move_turtle)
  
if __name__ == "__main__" :
    main()
    mainloop()
