# 6001.py
from turtle import *
def lineFit(P): # data: list of (x, y) tuple
  xSum  = 0
  ySum  = 0
  xySum = 0 
  x2Sum = 0
  n  = len(P)
  for x, y in P:
    xSum  += x
    ySum  += y    
    xySum += x*y
    x2Sum  += x*x

  a = (n*xySum - xSum*ySum)/(n*x2Sum-xSum*xSum)
  b = (ySum - a*xSum)/n
  return a, b

def Error(a, b, P): # a:기울기, b: y-절편
  eSum = 0
  n  = len(P)
  for x, y in P:
    e = y - ( a *x + b)
    eSum  += e*e
  return eSum/n

def line(x1, y1, x2, y2):
    g_pen.up();    g_pen.setpos(x1, y1)
    g_pen.down(); g_pen.setpos(x2, y2)

def drawPoints(P):
    g_pen.up()
    for x, y in P:
        g_pen.setpos(x, y)
        g_pen.dot(10, "red")
    
def main():
    global g_pen
    g_pen = Turtle()
    setworldcoordinates(-1, -1, 6, 6)
    line(-1, 0,  5, 0) # X-축
    line(0, -1, 0, 5)  # Y-축

    P = [(1, 2), (2, 4), (3, 5), (4, 4), (5, 5)]
    drawPoints(P)
    a, b = lineFit(P)
    error = Error(a, b, P)
    print("y = %sx + %s"%(a, b))
    print("E(a, b) = %s"%error)
        
    x1 = 0
    y1 = a*x1 + b
    x2 = 5
    y2 = a*x2 + b
    
    g_pen.pensize(4)
    g_pen.pencolor("blue")
    line(x1, y1, x2, y2)
    
if __name__ == "__main__":
    main()
    mainloop() 
