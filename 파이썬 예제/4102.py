#4102.py  
from turtle import *
import  time
max_y = 200; min_y = -200
ball = Turtle()
ball.shape("circle")
ball.color("blue", "red")
ball.shapesize(3, 3, 4)
ball.up()
ball.setpos(0, min_y)
ball.down()

STEP = 20      # 한번에 이동할 거리
tick = 50
delay_time = tick / 1000
print("{} sec".format(delay_time))

while True:
    try:
        #start = time.clock()
        start = time.perf_counter()
        ball_x, ball_y = ball.position()
        ball_y += STEP
        if (ball_y < min_y)  or  (ball_y > max_y):  STEP *= -1
        ball.setpos(ball_x, ball_y)

        #elapsed = time.clock() - start
        elapsed = time.perf_counter() - start
        delay_time2  = max(0, delay_time - elapsed)
        time.sleep(delay_time2)
#        print("elapsed = {}sec, delay_time2={}sec".format(elapsed, delay_time2))
    except:
        print('Good bye')
        break
