# 3903.py
from turtle import *
def draw_rect(pen, x, y, w, h, fill_color= "white", pen_color="black", psize=4):
    pen.pensize(psize)
    pen.color(pen_color, fill_color)
    pen.setheading(0)
    pen.up()
    pen.setpos(x, y)
    pen.down()

    pen.begin_fill()
    pen.setpos(x+w, y)
    pen.setpos(x+w,y+h)
    pen.setpos(x,y+h)
    pen.setpos(x,y)
    pen.end_fill()

def main():
    t = Turtle()
    draw_rect(t, -300, -300, 600, 600)
    draw_rect(t, -200, -200, 400, 400, "red", "blue")
    draw_rect(t, -100, -100, 200, 200, "yellow", "green")
    draw_rect(t, -50, -50, 100, 100, "pink", "purple", 10)

if __name__ == "__main__":
    main()
    mainloop()
