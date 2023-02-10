# 5101.py
import turtle as T
colors = {0:"white", 1:"red", 2:"green", 3:"blue"} # 전역변수 
class BoardGame(T.Turtle):
    def __init__(self, nW=3, nH=3, bW= 100, bH= 100, M = 20, gap=0,
                 pensize = 3, bgcolor="white"):
        title = "Board size :" + str(nW) + "x" + str(nH)
        T.title(title)
        screen = T.Screen()
        screen.bgcolor(bgcolor)
        
        W = 2*M+(nW-1)*gap+(bW*nW) # 스크린 크기 계산
        H = 2*M+(nH-1)*gap+(bH*nH)
        
        screen.screensize(100, 100) # 스크롤바가 나타나는 크기 설정
        screen.setup(W, H)          # 윈도우 크기 변경
        T.setworldcoordinates(0, 0, W, H) # 좌표계 설정

        self.canvas = screen.getcanvas()
        self.canvas.master.resizable(0,0)
        self.canvas.master.wm_attributes("-topmost", 1)

        self.bW = bW 
        self.bH = bH  
        self.nW = nW
        self.nH = nH              
        self.M  = M
        self.gap= gap

        self.nx = -1  # 현재 마우스 클릭 위치
        self.ny = -1
        self.nfill = 0
        self.colors = {0:"white", 1:"red", 2:"green", 3:"blue"}

        if self.bW < 0 or self.bH < 0:
            print("블럭크기가 작아요, 윈도우 크기(W, H)를 크게 해요!")
            T.bye()   # 윈도우 파괴
            import sys
            sys.exit() # 프로그램 종료 

        self.pen = T.Turtle()   #  터틀 생성 
        self.pen.ht()           #  터틀 감추기
        self.pen.pensize(pensize)
        self.drawBoard()

        # 키보드 마우스 이벤트 설정
        T.onscreenclick(self.onMouseLeftDown)
        T.onkey(self.onSpaceDown, "space")
        T.onkey(T.bye, "Escape")
        T.listen()

    def onSpaceDown(self): # 키보드 이벤트 처리
        self.nfill += 1
        if self.nfill == 4:
            self.nfill = 0
        self.drawBoard()
        
    def getClickCell(self, x, y): # gap=0, (x, y) 위치 블록(셀) 찾음
        ix = int((x - self.M)//self.bW)
        iy = int((y - self.M)//self.bH)
        if (0 <= ix < self.nW) and (0 <= iy <self.nH):
            return ix, iy
        return -1, -1 # 보드 외부 클릭
         
    def getClickCell2(self, x, y):  # (x, y) 위치 블록(셀) 찾음
        for iy in range(self.nH):
            for ix in range(self.nW):
                x1 = self.M+(self.bW+self.gap)*ix
                y1 = self.M+(self.bH+self.gap)*iy
                x2 = x1 + self.bW
                y2 = y1 + self.bH
                if x1 <= x <=x2 and y1 <= y <= y2:
                    return ix, iy
        return -1, -1 # 보드 외부 클릭
    
    def onMouseLeftDown(self, x, y):
##        ix, iy = self.getClickCell(x, y) # gap = 0 경우
        ix, iy = self.getClickCell2(x, y)                
##        print("ix = %s, iy = %s"%(ix, iy))
        if ix >= 0: # 선택 블록 있음, ix만 비교해도 됨
            self.nx = ix  # 현재 클릭 셀 저장
            self.ny = iy
            self.drawBoard()
                       
    def drawCircle(self, ix, iy,
                  fill="white", outline="black"):
        x1 = self.M+(self.bW+self.gap)*ix
        y1 = self.M+(self.bH+self.gap)*iy
        x2 = x1 + self.bW
        y2 = y1 + self.bH
        
        self.pen.up()
        self.pen.setpos((x1+x2)//2, y1+5) # +r
        self.pen.down()
        r = (x2-x1-10)//2
        self.pen.color(outline, fill)

        self.pen.begin_fill()
        self.pen.circle(r)
        self.pen.end_fill()  

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
                        
        # 마우스 클랙 위치 원 그리기 
        if 0 <= self.nx and 0 <= self.nx:
            self.drawCircle(self.nx, self.ny,
                        fill=colors[self.nfill])            
        T.update() # T.tracer(1)
if __name__ == "__main__":
    game = BoardGame(5, 5) 
##    game = BoardGame(5, 5, gap=20)
    T.mainloop()
