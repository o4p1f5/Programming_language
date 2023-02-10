# 5802.py
from turtle import *
from math import pi, sin, cos

def diff1(f, x): # 전방차분
    h = 0.001    
    return (f(x+h)-f(x))/h

def diff2(f, x): # 중심차분
    h = 0.001    
    return (f(x+h)-f(x-h))/(2*h)

def line(x1, y1, x2, y2):
    g_pen.up();    g_pen.setpos(x1, y1)
    g_pen.down(); g_pen.setpos(x2, y2)

def plot(f, min_x = -2*pi, max_x = 2*pi, dx = 0.1):
    x = min_x
    g_pen.up(); g_pen.setpos(x, f(x));g_pen.down()
    while x <= max_x:
        g_pen.setpos(x, f(x))
        x += dx
        
def diff_plot(f, min_x = -2*pi, max_x = 2*pi, dx = 0.1):
    x = min_x
    g_pen.up(); g_pen.setpos(x,diff2(f,x));g_pen.down() # diff1(f,x)
    while x <= max_x:
        g_pen.setpos(x, diff2(f,x))  # diff1(f,x)
        x += dx
        
def main():
    global g_pen
    g_pen = Turtle()
    setworldcoordinates(-6.5, -2, 6.5, 2)
    line(-6.5, 0,  6.5, 0) # X-축
    line(0, -2, 0, 2)      # Y-축

    g_pen.pensize(4)
    plot(lambda x: sin(x))

    g_pen.pencolor("blue")
    plot(lambda x: cos(x))
    
    g_pen.pensize(2)    
    g_pen.pencolor("red")
    diff_plot(lambda x: sin(x))
    
if __name__ == "__main__":
    main()
    mainloop() 
