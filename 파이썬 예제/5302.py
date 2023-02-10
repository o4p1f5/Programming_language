# 5302.py
import turtle as T
import random

HINT, RUNNING, STOP  = 0, 1, 2 # 게임 상태
HIDDEN, FLIP         = 0, 1      # 셀 상태
class BoardGame(T.Turtle):
    def __init__(self, nW=3, nH=3, bW=100, bH=100, M=20, gap=0,
                 pensize = 3, bgcolor="white"):
        self.imageList = []
        self.imageList.append("./image/shape0.gif")        
        self.imageList.append("./image/shape1.gif")
        self.imageList.append("./image/shape2.gif")
        self.imageList.append("./image/shape3.gif")
        self.imageList.append("./image/shape4.gif")
        self.imageList.append("./image/shape5.gif")
        self.imageList.append("./image/shape6.gif")
        self.imageList.append("./image/shape7.gif")
        self.imageList.append("./image/shape8.gif")           
        for image in self.imageList:            
            T.register_shape(image)  # 이미지 등록

        W = 2*M+(nW-1)*gap+(nW*bW) # 스크린 크기 계산
        H = 2*M+(nH-1)*gap+(nH*bH)

        screen = T.Screen()
        screen.bgcolor(bgcolor)        
        screen.setup(W, H)
        T.setworldcoordinates(0, 0, W, H)

        self.canvas = screen.getcanvas()
        self.canvas.master.resizable(0,0)
        self.canvas.master.wm_attributes("-topmost", 1)
        self.bW = bW   # 블록 크기
        self.bH = bH  
        self.nW = nW
        self.nH = nH              
        self.M  = M
        self.gap = gap

        # 터틀 생성
        self.turtle = [[ T.Turtle() for ix in range(nW)]
                                  for iy in range(nH)]        
        self.cell  = [[ 0 for ix in range(nW)] for iy  in range(nH)]
        self.status = [[ 0 for ix in range(nW)] for iy  in range(nH)]
        self.initGame(move=True) # 터틀 움직임
         
        # 마우스, 키보드 이벤트 설정
        T.onscreenclick(self.onMouseLeftDown) # 스크린 이벤트 설정
        # 터틀 클릭 이벤트 설정
##        for iy in range(self.nH):
##            for ix in range(self.nW):
##                self.turtle[iy][ix].onclick(self.onMouseLeftDown)
        T.onkey(self.onSpace, "space")
        T.onkey(T.bye, "Escape")
        T.listen()    
        
    def onSpace(self): # 키보드 이벤트 처리
        if self.gameSatus == STOP:
            self.initGame()# 터틀 움직임 필요없고, 모양변경

    def onGameStart(self): # 타이머 이벤트 처리
        title = "게임상태 : RUNNING"
        T.title(title)
        self.gameSatus = RUNNING
        self.drawBoard()

    def countHidden(self):
        remain = self.nH*self.nW
        for iy in range(self.nH):
            for ix in range(self.nW):
                if self.status[iy][ix] == FLIP:
                    remain -= 1
        return remain
                              
    def getClickCell2(self, x, y): # 블록(셀) 찾음
        for iy in range(self.nH):
            for ix in range(self.nW):
                x1 = self.M+(self.bW+self.gap)*ix
                y1 = self.M+(self.bH+self.gap)*iy
                x2 = x1 + self.bW
                y2 = y1 + self.bH
                if x1 <= x <=x2 and y1 <= y <= y2:
                    return ix, iy
        return -1, -1 # 보드 외부 클릭
    
    def onMouseLeftDown(self, x, y): # 마우스 이벤트 처리
        if self.gameSatus != RUNNING:
            return
        ix, iy = self.getClickCell2(x, y)
        if ix < 0 : # 선택 블록 없음 
            return        
        if self.status[iy][ix] != HIDDEN:
            return
        self.status[iy][ix] = FLIP
        self.drawBoard()
        count= self.countHidden()
        title = " HIDDEN 셀 = " + str(count)
        if count == 0:
            self.gameSatus = STOP
            title = "게임상태 : STOP"
        T.title(title)
                             
    def initGame(self, move=False):       
        self.gameSatus = HINT
        for iy in range(self.nH):
            for ix in range(self.nW):
                num = random.choice(list(range(1,len(self.imageList))))
                self.cell[iy][ix] = num
                self.status[iy][ix]= HIDDEN
        self.drawBoard(move)
        title = "게임상태 : HINT"
        T.title(title)
        T.ontimer(self.onGameStart, 3000) # 3초 타이머 이벤트 설정
                
    def drawBlock(self, ix, iy, num, move):
        if move:           
            x1 = self.M+(self.bW+self.gap)*ix
            y1 = self.M+(self.bH+self.gap)*iy
            x2 = x1 + self.bW/2 # 블록중심
            y2 = y1 + self.bH/2
            
            self.turtle[iy][ix].up()
            self.turtle[iy][ix].st()
            self.turtle[iy][ix].setpos(x2, y2) # 블록중앙에 위치
        self.turtle[iy][ix].shape(self.imageList[num])
               
    def drawBoard(self, move=False):
        T.tracer(0) # 에니메이션 끄기(turn off)     
        for iy in range(self.nH):
                for ix in range(self.nW):
                    if (self.gameSatus == HINT or
                       self.status[iy][ix] != HIDDEN ):
                        num = self.cell[iy][ix]
                    else:
                        num = 0
                    self.drawBlock(ix, iy, num, move)
        T.update() # T.tracer(1)
if __name__ == "__main__":
    game = BoardGame(4, 4)
    T.mainloop()
