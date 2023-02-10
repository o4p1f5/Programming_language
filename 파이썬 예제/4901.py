# 4901.py
from turtle import *
screen = Screen()
screen.title("tkinter sample")  #  canvas.master.title("tkinter sample")

screen.setup(600, 400)
canvas = screen.getcanvas()
canvas.master.resizable(0,0)  # 윈도우 크기 고정
canvas.master.wm_attributes("-topmost", 1) 
