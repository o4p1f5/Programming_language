# 4401.py
from turtle import *
def onRed(x, y):
    screen.bgcolor("red")   
def onGreen(x, y):
    screen.bgcolor("green")
def onBlue(x, y):
    screen.bgcolor("blue")
    
def main():
    global screen
    tracer(0) # 에니메이션 끄기
    
    screen = Screen()
    red = Turtle("square")
    red.color("black", "red")
    red.shapesize(5, 5, 4)
    red.up()
    red.bk(200)

    green = Turtle("square")
    green.color("black", "green")
    green.shapesize(5, 5, 4)

    blue = Turtle("square")
    blue.color("black", "blue")
    blue.shapesize(5, 5, 4)
    blue.up()
    blue.fd(200)

    red.onclick(onRed)
    green.onclick(onGreen)
    blue.onclick(onBlue)
    update()  # 스크린 갱신, 그림 보이기

if __name__ == "__main__" :
    main()
    mainloop()
