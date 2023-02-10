# 4801.py
from turtle import *
class MyTurtle(Turtle):
    def __init__(self, shape="classic", color1="black", color2="blue",
                     animate=None):
        super().__init__(shape) # self.shape(shape)
        self.color(color1, color2)    
        self.shapesize(2, 2, 3)
        self._animate = animate
        
    def animated(self, flag=None):
        if not flag is None:
            self._animate = flag
        return self._animate
               
    def line(self, x1, y1, x2, y2):
        if not self.animated():
            tracer(False) # tracer(0)
        self.up();   self.setpos(x1, y1)
        self.down(); self.setpos(x2, y2)
        #self.ht()
        if not self.animated():
            tracer(True)  # tracer(1)
    
    def rectangle(self, x1, y1, x2, y2, fill=None):
        if not self.animated():
            tracer(False) # tracer(0)
        if fill:
            self.begin_fill()            
        self.up()
        self.setpos(x1, y1)
        self.down()

        self.setpos(x2, y1)
        self.setpos(x2, y2)
        self.setpos(x1, y2)
        self.setpos(x1, y1)
        
        if fill:
            self.end_fill()        
        #self.ht()
        if not self.animated():
            tracer(True) # tracer(1)
def main():
    pen1 = MyTurtle()
    pen1.rectangle(-200, -200, 200, 200)

    pen1.animated(True)
    pen1.rectangle(-200, -200, 150, 150, True)

    pen2 = MyTurtle("turtle", "red", "green", True)
    pen2.line(-200, -200, 200, 200)

    pen2.animated(False)
    pen2.pensize(4)
    pen2.line(-200, 200, 200, -200)
    
if __name__ == "__main__" :
    main()
    mainloop()
