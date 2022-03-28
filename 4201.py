# 4201.py
from turtle import *
import random
def make_ball(size=30):
    x = random.randint(min_x, max_x)
    y = random.randint(min_y, max_y)
    color = random.choice(["red", "green", "blue", "yellow", "pink", "purple"])
    while True:
        dx = random.randint(-4, 4)  # 이동벡터
        dy = random.randint(-4, 4)  # 이동벡터
        if dx != 0 or dy != 0:
            break
    return [x, y, size, color, dx, dy]
 
def animate_ball(pen, ball_list):
    tracer(0)  # 에니메이션 끄기(turn off)
    while True:
        try:
            pen.clear()  # 원을 지음
            for i in range( len(ball_list) ): # 모든 원을 움직임
                ball_x, ball_y, size, color, dx, dy =  ball_list[i]
                ball_x += dx
                ball_y += dy
                ball_list[i][0] = ball_x
                ball_list[i][1] = ball_y
                if (ball_x<min_x) or (ball_x > max_x): ball_list[i][4] *= -1
                if (ball_y<min_y) or (ball_y > max_y): ball_list[i][5] *= -1
                pen.setpos(ball_x, ball_y)
                pen.dot(size, color)
            update() # 스크린 갱신
        except:
            print('Good bye')
            break
def main():
    global min_x, max_x, min_y, max_y
    max_x = 400; min_x=  -max_x
    max_y = 300; min_y = -max_y
    setup(max_x*2, max_y*2)

    my_pen = Turtle()
    my_pen.up()
    my_pen.ht()
    ball_list = []
    for i in range(50):
        ball = make_ball(random.randint(30, 50))
        ball_list.append(ball)
    animate_ball(my_pen, ball_list) # 에니메이션
    
if __name__ == "__main__":
    main()
