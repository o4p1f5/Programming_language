# 4803.py
from turtle import *
class CTurtle(Turtle):
    _RGB = [255, 255, 255]
    def __init__(self, shape="turtle", x=0, color="red"):        
        super().__init__(shape)     
        self.lt(90)
        self.color(color)
        self.shapesize(3, 3, 5)
        self.pensize(10)
        self.speed = 0
        self.up()
        self.setpos(x, 0)
        self.down()
        self.sety(255) 
        self.up()
        # 초기에 _RGB의 위치와 일치 
        if color == "red":
            y = CTurtle._RGB[0]
        elif  color == "green":
            y = CTurtle._RGB[1]
        else: # "blue"
            y = CTurtle._RGB[2]
        self.sety(y)
        bgcolor(CTurtle._RGB) # 초기 배경색 변경   
        self.pencolor("black")
        self.ondrag(self.move)

    def move(self, x, y):
        self.sety(max(0,min(y,255)))
        color = self.fillcolor()
        if color == "red":                      # int(x) ==  0
            CTurtle._RGB[0] = int(self.ycor())
        elif  color == "green":                 # int(x) == 100
            CTurtle._RGB[1] = int(self.ycor())
        else: # "blue"
            CTurtle._RGB[2] = int(self.ycor())
        bgcolor(CTurtle._RGB) # 배경색 변경          
      
def main():   
    screen = Screen()
    screen.delay(0)
    screen.setworldcoordinates(-50, -50, 250, 300)
    screen.colormode(255)
    red   = CTurtle(x=0)
    green = CTurtle(x=100, color="green")
    blue  = CTurtle(x=200, color="blue")
    return "Done"

if __name__ == "__main__":
    msg = main()
    mainloop()
    print(msg)
