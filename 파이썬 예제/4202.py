# 4202.py
from turtle import *
import random
def make_ball(size=2):
    tracer(0) # 에니메이션 끄기(turn off)
    ball = Turtle()
    ball.up()
    ball.shape("circle")
    ball.shapesize(size, size)

    x = random.randint(min_x, max_x)
    y = random.randint(min_y, max_y)
    ball.setpos(x, y)

    color=random.choice(["red","green","blue","yellow","pink","purple"])
    ball.color(color)

    while True:
        dx = random.randint(-4, 4)
        dy = random.randint(-4, 4)
        if dx != 0 or dy != 0:
            break
    return [ball, dx, dy]

def animate_ball(ball_list):
    tracer(0)  # 에니메이션 끄기(turn off)
    while True:
        try:
            for i in range( len(ball_list) ):
                ball, dx, dy =  ball_list[i]
                ball_x, ball_y = ball.position()
                ball_x += dx
                ball_y += dy
                if (ball_x<min_x) or (ball_x>max_x): ball_list[i][1] *= -1
                if (ball_y<min_y) or (ball_y>max_y): ball_list[i][2] *= -1
                ball.setpos(ball_x, ball_y)
            update()
        except:
            print('Good bye')
            break

def main():
    global min_x, max_x, min_y, max_y
    max_x = 400; min_x=  -max_x
    max_y = 300; min_y = -max_y
    setup(max_x*2, max_y*2)
    
    ball_list = []
    for i in range(50):
        ball = make_ball() # ball = make_ball(random.randint(1, 3))
        ball_list.append(ball)
    animate_ball(ball_list) 
if __name__ == "__main__":
    main()
