# 5301.py
import turtle as T
import random

class BoardGame(T.Turtle):
    def __init__(self, nW=3, nH=3, bW=100, bH=100, M=20, gap=10,
                 pensize = 3, bgcolor="white"):
        title = "Board size :" + str(nW) + "x" + str(nH)
        T.title(title)

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
        self.cell = [[ 0 for ix in range(nW)] for iy in range(nH)]
                        
        self.initGame(move=True) # 터틀을 움직임
        
        # 키보드 이벤트 설정
        T.onkey(self.onSpace, "space")
        T.onkey(T.bye, "Escape")
        T.listen()    
        
    def onSpace(self): # 키보드 이벤트 처리
        self.initGame() # move=False, 터틀움직임 필요없고, 모양변경
                   
    def initGame(self, move=False):                  
        for iy in range(self.nH):
            for ix in range(self.nW):
                num = random.choice(range(len(self.imageList)))
                self.cell[iy][ix]= num
        self.drawBoard(move)
                
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
               
    def drawBoard(self, move):
        T.tracer(0) # 에니메이션 끄기(turn off)     
        for iy in range(self.nH):
                for ix in range(self.nW):
                     self.drawBlock(ix, iy, self.cell[iy][ix], move)
        T.update() # T.tracer(1)

if __name__ == "__main__":
    game = BoardGame(5, 5)
    T.mainloop()
