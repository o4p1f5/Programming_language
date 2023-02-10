# 3702.py
from turtle import *
def line(x1, y1, x2, y2):
    # global g_pen  생략가능
    g_pen.up()
    g_pen.setpos(x1, y1)
    g_pen.down()
    g_pen.setpos(x2, y2)

def main():
    global g_pen
    max_x = window_width()/2 -10
    max_y = window_height()/2 - 10
    min_x = -max_x
    min_y = -max_y
    g_pen = Turtle()
    g_pen.write(str(g_pen.position()), font=("Times", 20))
    line(min_x, 0, max_x, 0)  # X축
    g_pen.write("X", font=("Times", 20))
    line(0, min_y, 0, max_y)  # Y축
    g_pen.write("Y", font=("Times", 20))

if __name__ == "__main__":
    main()
    mainloop()
