# 5201.py
import turtle as T
import random

colors = {0:"white", 1:"red", 2:"green", 3:"blue"} # 전역변수 
class BoardGame(T.Turtle):
##    colors  = {0:"white", 1:"red", 2:"green", 3:"blue"} # 클래스 변수
    def __init__(self, nW=3, nH=3, bW=100, bH=100, M=20, gap=10,
                 pensize = 3, bgcolor="white"):
        title = "Board size :" + str(nW) + "x" + str(nH)
        T.title(title)
        screen = T.Screen()
        screen.bgcolor(bgcolor)
             
        W = 2*M+(nW-1)*gap+(nW*bW) # 스크린 크기 계산
        H = 2*M+(nH-1)*gap+(nH*bH)        
        screen.setup(W, H)
        T.setworldcoordinates(0, 0, W, H)

        self.canvas = screen.getcanvas()
        self.canvas.master.resizable(0,0)
        self.canvas.master.wm_attributes("-topmost", 1)
        self.bW   = bW   # 블록 크기
        self.bH   = bH  
        self.nW  = nW
        self.nH  = nH              
        self.M   = M
        self.gap = gap
##     self.colors={0:"white",1:"red",2:"green", 3:"blue"}# 인스턴스 변수
        
        self.pen = T.Turtle()   #  터틀 생성 
        self.pen.ht()           #  터틀 감추기
        self.pen.pensize(pensize)
        
        self.cell  = [[ 0 for ix in range(nW)] for iy in range(nH)]
##        random.seed()
        self.initGame()
        
        # 키보드 이벤트 설정
        T.onkey(self.onSpace, "space")
        T.onkey(T.bye, "Escape")
        T.listen()
        
    def onSpace(self): # 키보드 이벤트 처리
        self.initGame()       
        
    def initGame(self):                  
        for iy in range(self.nH):
            for ix in range(self.nW):
                self.cell[iy][ix]=random.choice([0, 1, 2, 3])
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
##                     color=BoardGame.colors[self.cell[iy][ix]] #클래스변수
##                     color=self.colors[self.cell[iy][ix]] # 클래스, 인스턴스변수
                     color = colors[self.cell[iy][ix]] # 전역변수
                     self.drawBlock(ix, iy, fill_color=color)
        T.update() # T.tracer(1)

if __name__ == "__main__":
    game = BoardGame(5, 5)  
    T.mainloop()
