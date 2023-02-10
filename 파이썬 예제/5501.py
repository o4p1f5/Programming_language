# 5501.py
import turtle as T
import random
import winsound

EMPTY, BLACK, WHITE = 0, 1, 2
colors = {BLACK:"black", WHITE:"white"}    
class BoardGame(T.Turtle):
    def __init__(self, game="TicTacToe", nW=3, nH=3, 
                 bW= 100, bH= 100,
                 M = 20, gap=0, pensize = 3, bgcolor="gold"):      
        T.title(game)
        screen = T.Screen()
        screen.bgcolor(bgcolor)

        W = 2*M+(nW-1)*gap+(bW*nW)  # 스크린 크기 계산
        H = 2*M+(nH-1)*gap+(bH*nH)

        screen.screensize(100, 100) # 스크롤바가 나타나는 크기 설정
        screen.setup(W, H)          # 윈도우 크기 변경
        T.setworldcoordinates(0, 0, W, H) # 좌표계 설정
 
        self.canvas = screen.getcanvas()
        self.canvas.master.resizable(0,0)
        self.canvas.master.wm_attributes("-topmost", 1)

        self.game = game
        if self.game == "TicTacToe":
            self.COUNT = 3
        else:     # "Omok"   
            self.COUNT = 5         
        
        self.sound = "C:/Windows/Media/notify.wav" # 사운드 파일

        self.bW = bW 
        self.bH = bH  
        self.nW = nW
        self.nH = nH              
        self.M  = M
        self.gap= gap
        self.pensize = pensize
        
        self.cell  = [[ EMPTY for ix in range(nW)]
                               for iy in range(nH)]
        self.pen = T.Turtle()
        self.pen.ht()
        self.pen.pensize(pensize)

        self.initGame()
        T.onscreenclick(self.onMouseLeftDown)
        T.onkey(self.onSpace, "space")
        T.onkey(T.bye, "Escape")
        T.listen()

    def initGame(self):                  
        for iy in range(self.nH):
            for ix in range(self.nW):
                self.cell[iy][ix] = EMPTY
                
        T.title(self.game)
        self.nextPlayer=random.choice([BLACK, WHITE]) # 랜덤선택
        T.title("{} : {} turn!".format(self.game, colors[self.nextPlayer]))

        self.pen.pensize(self.pensize)         
        self.currPlayer = None
        self.gameOver   = False
        self.drawBoard()

    def drawCircle(self, ix, iy,
                  fill="white", outline="black", width = 3):
        x1 = self.M+(self.bW+self.gap)*ix
        y1 = self.M+(self.bH+self.gap)*iy
        x2 = x1 + self.bW
        y2 = y1 + self.bH

        self.pen.pensize(width)
        self.pen.up()
        self.pen.setpos((x1+x2)//2, y1+5) # +r
        self.pen.down()
        r = (x2-x1-10)//2
        self.pen.color(outline, fill)

        self.pen.begin_fill()
        self.pen.circle(r)
        self.pen.end_fill()

    def drawBlock(self, ix, iy,
                  fill="white", outline="black"):
        x1 = self.M+(self.bW+self.gap)*ix
        y1 = self.M+(self.bH+self.gap)*iy
        x2 = x1 + self.bW
        y2 = y1 + self.bH
        
        self.pen.color(outline, fill)
        self.pen.begin_fill()            
        self.pen.up()
        self.pen.setpos(x1, y1)
        self.pen.down()
        
        self.pen.setpos(x2, y1)
        self.pen.setpos(x2, y2)
        self.pen.setpos(x1, y2)
        self.pen.setpos(x1, y1)    
        self.pen.end_fill()

        if self.cell[iy][ix] != EMPTY:
            fill_color = colors[self.cell[iy][ix]]
            self.drawCircle(ix, iy, fill_color)
                                    
    def drawBoard(self):
        T.tracer(0) # 에니메이션 끄기(turn off)

        for iy in range(self.nH):
            for ix in range(self.nW):
                self.drawBlock(ix, iy)

        T.update() # T.tracer(1)

    def getNextPlayer(self):
        player = self.nextPlayer
        if player == BLACK:
            self.nextPlayer = WHITE
        else:
            self.nextPlayer = BLACK
        return player

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
        if self.gameOver:
            winsound.MessageBeep(winsound.MB_ICONHAND)
            return
        ix, iy = self.getClickCell2(x, y)
        if ix < 0: # 선택 블록 없음
            return
          
        if self.cell[iy][ix] != EMPTY:
            winsound.MessageBeep(winsound.MB_ICONHAND)
        else:
            self.currPlayer   = self.getNextPlayer()
            self.cell[iy][ix] = self.currPlayer
            self.drawBoard()

            self.gameOver = self.getGameOver(ix, iy)
            if self.gameOver:
                winsound.PlaySound(self.sound,
                     winsound.SND_FILENAME+winsound.SND_ASYNC)
                # 승자 표시
                T.title("{} : {} Won!".format(self.game,
                                            colors[self.currPlayer]))
                T.tracer(0)
                for ix, iy in self.winnerList:
                    self.drawCircle(ix, iy,
                                fill=colors[self.currPlayer],
                                outline="red", width = 4)
                T.update()
            elif self.noEmptyCell():
                T.title("{} : Draw!".format(self.game))
                self.gameOver = True
                winsound.PlaySound(self.sound,
                      winsound.SND_FILENAME+winsound.SND_ASYNC)
            else:
                T.title("{} : {} turn!".format(self.game,
                                           colors[self.nextPlayer]))   
        T.update()
                                   
    def onSpace(self): # 게임 다시하기
        if self.gameOver:
            self.initGame()
 
#   self.winnerList는 연속된 셀 번호 (ix, iy)를 리스트에  저장
    def countH(self, ix, iy):# 가로 검사
        self.winnerList = []
        tx = ix; count = 0
        while(tx < self.nW and self.cell[iy][tx]==self.currPlayer):
            self.winnerList.append((tx, iy))
            count += 1; tx+=1         
        tx = ix-1
        while(tx >=0 and self.cell[iy][tx]==self.currPlayer):
            self.winnerList.append((tx, iy))
            count += 1; tx-=1 
        return count
    
    def countV(self, ix, iy):# 가로 검사
        self.winnerList = []
        ty = iy; count = 0
        while(ty < self.nW and self.cell[ty][ix]==self.currPlayer):
            self.winnerList.append((ix, ty))
            count += 1; ty+=1 
            
        ty = iy-1
        while(ty >=0 and self.cell[ty][ix]==self.currPlayer):
            self.winnerList.append((ix, ty))
            count += 1; ty-=1 
        return count
    
    def countD1(self, ix, iy):# 대각선 검사1
        self.winnerList = []
        tx = ix; ty = iy; count = 0
        while(tx < self.nW and ty < self.nH and
                    self.cell[ty][tx]==self.currPlayer):
            self.winnerList.append((tx, ty))
            count += 1; tx += 1; ty += 1
            
        tx = ix-1; ty = iy-1
        while(tx >=0 and ty >=0 and 
               self.cell[ty][tx]==self.currPlayer):
            self.winnerList.append((tx, ty))
            count += 1; tx -= 1; ty -= 1
        return count
    
    def countD2(self, ix, iy):# 대각선 검사2
        self.winnerList = []
        tx = ix; ty = iy; count = 0
        while(tx < self.nW and ty >=0 and 
              self.cell[ty][tx]==self.currPlayer):
            self.winnerList.append((tx, ty))
            count += 1; tx += 1; ty -= 1
            
        tx = ix-1; ty = iy+1
        while(tx >=0 and ty  < self.nH and 
               self.cell[ty][tx]==self.currPlayer):
            self.winnerList.append((tx, ty))
            count += 1; tx -= 1; ty += 1
        return count
    
    def noEmptyCell(self): # EMPTY: 셀이 없으면 True
        for iy in range(self.nH):
            for ix in range(self.nW):
                if self.cell[iy][ix]== EMPTY:
                    return False
        return True
    
    def getGameOver(self, ix, iy):
        if self.countH(ix, iy) == self.COUNT:
           return True
        elif self.countV(ix, iy) == self.COUNT:
           return True
        elif self.countD1(ix,iy) == self.COUNT:
           return True
        elif self.countD2(ix, iy) == self.COUNT:
           return True
        else:
            return False
        
if __name__ == "__main__":
    game = BoardGame()
##    game = BoardGame(game="Omok", nW=8, nH=8)
    T.mainloop()
