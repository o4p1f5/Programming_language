#4002.py
from turtle import *
def make_arrow_poly(pen, length, tside):
    pen.reset()
    if pen.screen.mode()  == "standard":
        pen.lt(90)  # heading 일치
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
    return pen.get_poly()

def make_circle_poly(pen, radius):
    pen.reset()
    pen.up()
    pen.setpos(0, -radius)
    pen.begin_poly()
    pen.down()
    pen.circle(radius)
    pen.end_poly()
    return pen.get_poly()

def main():
    arrow1 = Turtle()
    p = make_arrow_poly(arrow1, 100, 20)
    my_shape = Shape("compound")
    my_shape.addcomponent(p, "red", "blue")
     
    p2 = make_circle_poly(arrow1, 10)
    my_shape.addcomponent(p2, "green", "purple")
    register_shape( "my_arrow", my_shape)

    arrow1.reset()
    arrow1.shape( "my_arrow")
    arrow1.shapesize(1, 1, 5)   # [그림 40.4]
    arrow2 = Turtle("my_arrow")
    arrow2.shapesize(1, 1, 5)
    arrow2.seth(90)             # [그림 40.5]
if __name__ == "__main__":
    main()
    mainloop()
