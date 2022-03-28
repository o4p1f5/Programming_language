# 4903.py
from turtle import *
def onMouseLeftDown(event):
    print('event.x={}, event.y={}'.format(event.x, event.y))  
    x =  canvas.canvasx(event.x)
    y = -canvas.canvasy(event.y)      
    print('x={}, y={}'.format(x, y))  
    setpos(x, y)  
canvas = getcanvas()
canvas.bind("<Button-1>", onMouseLeftDown)
