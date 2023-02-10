# 3802.py
from turtle import *
from math import pi, sin, cos
def line(x1, y1, x2, y2):
    #global g_pen
    g_pen.up();    g_pen.setpos(x1, y1)
    g_pen.down(); g_pen.setpos(x2, y2)
def plot(f, min_x = -2*pi, max_x = 2*pi, dx = 0.1):
    #global g_pen
    x = min_x
    g_pen.up(); g_pen.setpos(x, f(x));g_pen.down()
    while x <= max_x:
        g_pen.setpos(x, f(x))
        x += dx

def main():
    global g_pen
    g_pen = Turtle()
    setworldcoordinates(-6.5, -2, 6.5, 2)
    line(-6.5, 0,  6.5, 0) # X-축
    line(0, -2, 0, 2)  # Y-축
    plot(sin)
    plot(cos)
if __name__ == "__main__":
    main()
    mainloop() 
