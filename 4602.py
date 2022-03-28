# 4602.py
from turtle import *
from datetime import datetime
def make_arrow_shape(name, length, tside):  # 4001.py 사용자 정의 화살표
	pen = Turtle()
	if pen.screen.mode()  == "standard":
		pen.lt(90)
	pen.begin_poly()
	pen.fd(length)
	pen.lt(90)
	pen.fd(tside/2)
	pen.rt(120)
	pen.fd(tside)
	pen.rt(120)    
	pen.fd(tside)
	pen.rt(120) 
	pen.fd(tside/2)
	pen.end_poly()

	p = pen.get_poly()   
	register_shape(name, p) 
	pen.reset()
	#pen.ht() 
	pen.shape(name)   
	return pen 

def jump(pen, dist):
    pen.up(); pen.fd(dist); pen.down()
    
def clock_face(R):
        pen = Turtle()
        pen.pensize(7)       
        for i in range(60):
                jump(pen, R)
                if i % 5 == 0:
                        pen.fd(20)
                        jump(pen,-(R+20))
                else:
                        pen.dot(5)
                        jump(pen,-R)
                pen.rt(6)
        pen.ht()

def run_clock():
        t = datetime.today()
        sec = t.second + t.microsecond*0.000001
        minute = t.minute + sec/60.0
        hour = t.hour + minute/60.0
        screen.title(t.strftime("%Y-%m-%d, %I:%M%p"))
        try:
            #tracer(0)
            second_hand.seth(6*sec)
            minute_hand.seth(6*minute)
            hour_hand.seth(30*hour)
            update() #tracer(1)
            ontimer(run_clock, 100)
        except Terminator:
            pass  # STOP

def main():
    global screen, second_hand, minute_hand, hour_hand
    screen = Screen()
    screen.mode("logo")
    R = 200  # clock radius

    tracer(0) # 에니메이션 해제 
    second_hand = make_arrow_shape("clock_hand", R-30, 20)
    second_hand.color("red")
    second_hand.shapesize(1, 1, 3)

    minute_hand = Turtle("clock_hand")
    minute_hand.color("gray50")
    minute_hand.shapesize(1, 0.9, 4)

    hour_hand = Turtle("clock_hand")
    hour_hand.color("gray20")
    hour_hand.shapesize(1, 0.7, 5)

    clock_face(R)
    run_clock()

if __name__ == "__main__":
    main()
    mainloop()
