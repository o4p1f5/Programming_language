# 4904.py
import turtle as T
def onMouseLeftDown(event):
    x =  canvas.canvasx(event.x)
    y = -canvas.canvasy(event.y)
    T.penup()
    T.setpos(x, y)
    T.pendown()
def onMouseMove(event):
    x = canvas.canvasx(event.x)
    y = -canvas.canvasy(event.y)   
    T.setpos(x, y)
def onMouseLeftUp(event):
    T.penup()
def onClear(event):
    T.clear() 
def onExit(event):
    T.bye()
def main():
    global canvas
    screen = T.Screen()
    screen.delay(0)
    canvas = screen.getcanvas()
    T.listen()
      
    T.speed(0)
    T.pensize(4)
    T.ht()
    canvas.bind("<Button-1>", onMouseLeftDown)
    canvas.bind("<B1-Motion>", onMouseMove)
    canvas.bind("<ButtonRelease-1>", onMouseLeftUp)
    canvas.bind("<space>", onClear)
    canvas.bind("<Escape>", onExit)
    canvas.mainloop()  # screen.mainloop()
        
if __name__ == '__main__':
    main()
