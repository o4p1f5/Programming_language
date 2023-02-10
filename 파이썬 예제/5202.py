# 5202.py
import turtle as T

colors = {0:"white", 1:"red", 2:"green", 3:"blue"}
class BoardGame(T.Turtle):      
    def __init__(self, nW=3, nH=3, bW= 100, bH= 100,M = 20, gap = 0,
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

        self.bW  = bW   # 블록 크기
        self.bH  = bH
        self.nW  = nW
        self.nH  = nH              
        self.M   = M
        self.gap = gap
        
        self.pen = T.Turtle()   #  터틀 생성 
        self.pen.ht()            #  터틀 감추기
        self.pen.pensize(pensize)
        
        self.cell = [[ 0 for ix in range(nW)] for iy in range(nH)]
        self.initGame()
        
        # 키보드 마우스 이벤트 설정
        T.onscreenclick(self.onMouseLeftDown)
        T.onkey(self.onSpace, "space")
        T.onkey(self.onSaveTxt, "s")
##        T.onkey(self.onSaveBin, "s")
        T.onkey(self.onLoadTxt, "l")
##        T.onkey(self.onLoadBin, "l")
        T.onkey(T.bye, "Escape")
        T.listen()
        
    def onSpace(self): # 키보드 처리
        self.initGame()

    def onSaveTxt(self): # 키보드 처리, 텍스트 파일저장
        strBoard = ""
##        for y in range(self.nH-1,-1,-1): # 위->아래(보이는) 순서저장
        for y in range(self.nH): # 아래->위 순서저장     
            for x in range(self.nW):
                strBoard += str(self.cell[y][x])
            strBoard +="\n"

        f = open('map.txt', 'w')
        f.write(strBoard)
        f.close()
        
    def onLoadTxt(self): # 키보드 처리, 텍스트 파일읽기
        f = open('map.txt', 'r')
        lines=f.readlines()
        f.close()
        
        for iy in range(self.nH):
            # 아래-> 위 순서 
            self.cell[iy]=list(map(int, list(lines[iy])[:-1]))
            
            #위->아래(보이는) 순서
            #self.cell[self.nH-1-iy]=list(map(int,list(lines[iy])[:-1]))
        self.drawBoard()

    def onSaveBin(self): # 키보드 처리, 이진파일 저장
        import pickle
        f = open('map.bin', 'wb')
        pickle.dump(self.cell, f)
        f.close()
        
    def onLoadBin(self): # 키보드 처리, 이진파일 읽기
        import pickle
        f = open('map.bin', 'rb')
        self.cell = pickle.load(f)
        f.close()
        self.drawBoard()
            
    def getClickCell2(self, x, y): # 블록(셀) 찾음
        for iy in range(self.nH):
            for ix in range(self.nW):
                x1 = self.M+(self.bW+self.gap)*ix
                y1 = self.M+(self.bH+self.gap)*iy
                x2 = x1 + self.bW
                y2 = y1 + self.bH
                if x1 <= x <=x2 and y1 <= y <= y2:
                    return ix, iy
        return -1, -1 # 외부 클릭
    
    def onMouseLeftDown(self, x, y):
        ix, iy = self.getClickCell2(x, y)
        if ix >= 0: # 선택 블록 있음
            self.cell[iy][ix] += 1  # 색상 변경
            if self.cell[iy][ix] == 4:
                self.cell[iy][ix] = 0
            self.drawBoard()
        
    def initGame(self):                  
        for y in range(self.nH):
            for x in range(self.nW):
                self.cell[y][x]= 0
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
                     color = colors[self.cell[iy][ix]]
                     self.drawBlock(ix, iy, fill_color=color)
        T.update() # T.tracer(1)

if __name__ == "__main__":
    game = BoardGame(5, 5)  
    T.mainloop()
