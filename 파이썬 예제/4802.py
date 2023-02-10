# 4802.py
from turtle import *
import random
class AnimateTurtle(Turtle):
    _turtles = []
    def __init__(self, shape="circle", xPos=0, yPos=0, heading = 0,
                 size=2, fillColor="black", step = 4):        
        super().__init__(shape, visible=False)
        self.speed = 0
        self.color(fillColor)
        self.up()
        self.setpos(xPos, yPos)
        self.seth(heading)
        self.shapesize(size, size)
        self._step = step
        self.st()
        AnimateTurtle._turtles.append(self) # 클래스 속성_turtles에 인스턴스 저장 
        #self.animate_each() #터틀 수가 많아지면, 너무 느림
        
    def move(self):
        self.fd(self._step)
        if  max_x <= abs(self.xcor()) or max_y <= abs(self.ycor()) :
            self.left(180)
                
    @staticmethod
    def animate_all():
        try:
            tracer(False) # tracer(0)
            for t in AnimateTurtle._turtles:
                t.move()
            tracer(True)  # update(), # tracer(1) 
            ontimer(AnimateTurtle.animate_all, 1)
        except Terminator:
            pass  # STOP
               
    # 터틀 수가 많아지면, 너무 느림     
    def animate_each(self):
        try:
            tracer(False) # tracer(0)
            self.move()
            tracer(True)  # update(), # tracer(1) 
            ontimer(self.animate_each, 1)
        except Terminator:
            pass # STOP         
def main():
    global max_x, max_y
    screen = Screen()
    max_x = screen.window_width()//2  - 10    
    max_y = screen.window_height()//2 - 10
    
    tracer(False)  # tracer(0)
    for i in range(100):
        x = random.randint(-max_x, max_x)
        y = random.randint(-max_y, max_y)
        angle = random.randint(0, 360)
        color = random.choice(["red", "green", "blue", "yellow", "pink", "purple"])
        STEP  = random.randint(1, 20)
        if i% 2:
            SHAPE = "circle"
        else:
            SHAPE = "turtle"
        AnimateTurtle(shape = SHAPE, xPos = x, yPos = y,
                   heading=angle, fillColor=color, step = STEP)
    tracer(True) # update(), # tracer(1) 
    AnimateTurtle.animate_all()
    return "Done"

if __name__ == "__main__":
    msg = main()
    mainloop()
    print(msg)
