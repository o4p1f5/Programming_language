# 4906.py
import turtle as T
import tkinter as tk
def main():
    root = tk.Tk()
    cv1 = tk.Canvas(root, width=400, height=300)
    cv2 = tk.Canvas(root, width=400, height=300)
    cv1.pack() 
    cv2.pack()

##    cv1.pack(side="right")
##    cv2.pack(side="right")
  
    s1 = T.TurtleScreen(cv1)
    s1.bgcolor("white")
    
    s2 = T.TurtleScreen(cv2)
    s2.colormode(255)
    s2.bgcolor(128, 128, 128)

    
    t1 = T.RawTurtle(s1)  # 스크린 s1에 터틀 t1 생성
    t2 = T.RawTurtle(s2)  # 스크린 s2에 터틀 t2 생성
#   t3 = T.Turtle()       # 새로운 독립된 스크린 생성, 터틀생성 

    t2.shape("turtle")
    t2.pencolor("red")
    t2.pensize(5)
    for i in range(4):       
        t1.fd(100)
        t1.lt(90)

        t2.fd(100)
        t2.lt(90)
    root.mainloop() 
       
if __name__ == '__main__':
    main()
#   tk.mainloop() 
