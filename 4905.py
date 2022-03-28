# 4905.py
import turtle  as T
import tkinter as tk

screen = T.Screen()
canvas = screen.getcanvas()
max_x = screen.window_width()//2
max_y = screen.window_height()//2

myImage = tk.PhotoImage(file=
                  "C:/Users/Public/Pictures/Sample Pictures/Tulips.png")
canvas.create_image(-max_x, -max_y, anchor=tk.CENTER, image=myImage)
