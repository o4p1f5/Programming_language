# 3603.py
import turtle
folder = "C:/Users/Public/Pictures/Sample Pictures/"
turtle.bgpic(folder+"Desert.gif")
image = folder + "Koala.gif"
turtle.register_shape(image)  # turtle.addshape(image)
koala = turtle.Turtle()
koala.shape(image)
#turtle.bgpic("nopic")   # 배경영상 삭제
