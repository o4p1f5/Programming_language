# 4902.py
from turtle import *
screen = Screen()
max_x = screen.window_width()//2  - 50
max_y = screen.window_height()//2 - 50

canvas = screen.getcanvas()
canvas.create_line(-max_x, 0, max_x, 0)
canvas.create_line(0, -max_y, 0, max_y, fill="blue", width=4)

canvas.create_text(20, max_y, text="Y", font=("굴림", 20))
canvas.create_text(20, -max_y, text="-Y", font=("굴림", 20))
canvas.create_text(max_x, -20, text="X", font=("굴림", 20))
canvas.create_text(-max_x, -20, text="-X", font=("굴림", 20))

canvas.create_rectangle(0, 0, 300, 300)
canvas.create_rectangle(0, 0, -300, -300, fill="blue", outline = "red")

#canvas.delete(9) # 9번 그리기 객체 삭제
