# 4601.py
from turtle import *
def animate():
    global STEP
    try:
        ball_x, ball_y = ball.position()
        ball_y += STEP
        if (ball_y < min_y)  or  (ball_y > max_y):  STEP *= -1
        ball.setpos(ball_x, ball_y)
        update()
        ontimer(animate, 10)
    except:
        print('bye')
        return
    
def main():
    global ball, min_y, max_y, STEP
    max_y = 200; min_y = -max_y
    
    tracer(0)  # 에니메이션 해제
    ball = Turtle()
    ball.shape("circle")
    ball.color("blue", "red")
    ball.shapesize(3, 3, 4)
    ball.up()
    ball.setpos(0, min_y)
    ball.down()
    
    STEP = 10
    tracer(1, 10) # n= 1, delay = 10
    animate()

if __name__ == "__main__":
    main()
    mainloop()
