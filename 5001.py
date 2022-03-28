# 5001.py
import turtle as T

class BoardGame(T.Turtle):
    def __init__(self, nW=3, nH=3, W= 512, H = 512, M = 50,
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
  
        self.nW  = nW  #  nW x nH board
        self.nH  = nH              
        self.M   = M   # 스크린 테두리 여백
        
        self.bW = (W-2*M)//nW  # 블록 크기계산
        self.bH = (H-2*M)//nH

        if self.bW < 0 or self.bH < 0:
            print("블럭크기가 작아요, 윈도우 크기(W, H)를 크게 해요!")
            T.bye()   # 윈도우 파괴
            import sys
            sys.exit() # 프로그램 종료 

        self.pen = T.Turtle()   #  터틀 생성 
        self.pen.ht()           #  터틀 감추기
        self.pen.pensize(pensize)
        self.drawBoard()

    def drawLine(self, x1, y1, x2, y2):
        self.pen.up()
        self.pen.setpos(x1, y1)
        self.pen.down()
        self.pen.setpos(x2, y2)
                        
    def drawBoard(self):
        x1 = self.M
        y1 = self.M
        x2 = x1 + self.nW*self.bW
        y2 = y1 + self.nH*self.bH

        T.tracer(0) # 에니메이션 끄기(turn off)        
        for nx in range(self.nW+1): # 세로 직선
            x = x1+self.bW*nx
            self.drawLine(x, y1, x, y2)

        for ny in range(self.nH+1): # 가로 직선
            y = y1+self.bH*ny
            self.drawLine(x1, y, x2, y)
            
        T.update() # T.tracer(1)

if __name__ == "__main__":
    game = BoardGame()  
    T.mainloop()
