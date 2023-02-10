# 5003.py
import turtle as T

class BoardGame(T.Turtle):
    def __init__(self, nW=3, nH=3, W= 512, H = 512, M = 50, gap = 10,
                 pensize = 3, bgcolor="white"):
        title = "Board size :" + str(nW) + "x" + str(nH)
        T.title(title)
        screen = T.Screen()
        screen.bgcolor(bgcolor)
        screen.screensize(100, 100)   # 스크롤바가 나타나는 크기 설정
        screen.setup(W, H)          # 윈도우 크기 변경
        T.setworldcoordinates(0, 0, W, H) # 좌표계 설정

        self.canvas = screen.getcanvas()
        self.canvas.master.resizable(0,0)
        self.canvas.master.wm_attributes("-topmost", 1)
  
        self.nW  = nW
        self.nH  = nH              
        self.M   = M
        self.gap = gap
       
        self.bW = (W-2*M-(nW-1)*gap)//nW  # 블록 크기 계산
        self.bH = (H-2*M-(nH-1)*gap)//nH

        if self.bW < 0 or self.bH < 0:
            print("블럭크기가 작아요, 윈도우 크기(W, H)를 크게 해요!")
            T.bye()   # 윈도우 파괴
            import sys
            sys.exit() # 프로그램 종료 

        self.pen = T.Turtle()   #  터틀 생성 
        self.pen.ht()            #  터틀 감추기
        self.pen.pensize(pensize)
        self.drawBoard()

    def drawBlock(self, ix, iy,
                  fill_color="white", outline_color="black"):
        x1 = self.M+(self.bW+self.gap)*ix
        y1 = self.M+(self.bH+self.gap)*iy
        x2 = x1 + self.bW
        y2 = y1 + self.bH
        
        self.pen.color(outline_color, fill_color)
        self.pen.begin_fill()            
        self.pen.up()
        self.pen.setpos(x1, y1)
        self.pen.down()
        
        self.pen.setpos(x2, y1)
        self.pen.setpos(x2, y2)
        self.pen.setpos(x1, y2)
        self.pen.setpos(x1, y1)    
        self.pen.end_fill()        
                       
    def drawBoard(self):
        T.tracer(0) # 에니메이션 끄기(turn off)     
        for iy in range(self.nH):
                for ix in range(self.nW):
                        self.drawBlock(ix, iy)           
        T.update() # T.tracer(1)

if __name__ == "__main__":
    game = BoardGame(5, 3, gap=0)  # BoardGame(5, 3, gap=0) 
    T.mainloop()
