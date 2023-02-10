#4001.py
from turtle import *
def make_arrow_shape(name, length, tside):
	pen = Turtle()
	if pen.screen.mode()  == "standard":
		pen.lt(90)  # heading 일치
	pen.begin_poly()  # 기록 시작
	pen.fd(length)
	pen.lt(90)
	pen.fd(tside/2) # 한변의 길이/2
	pen.rt(120)     # 120도 오른쪽으로 회전
	pen.fd(tside)   # 한 변의 길이
	pen.rt(120)    
	pen.fd(tside)
	pen.rt(120) 
	pen.fd(tside/2)
	pen.end_poly() # 기록 끝

	p = pen.get_poly()   # 기록한 다각형을 반환    
	register_shape(name, p)  # name으로 모양 p를 등록
	pen.reset()
	#pen.ht()         # 펜 감추기
	pen.shape(name) # name으로 등록된 모양으로 펜 변경
	return pen        # 펜을 반환
def main():
         arrow1 = make_arrow_shape("my_arrow", 100, 20) #[그림 40.1]
         arrow1.screen.mode("logo")  # [그림 40.2]
         arrow2 = Turtle("my_arrow") 
         arrow2.rt(90)                # [그림 40.3]
if __name__ == "__main__":
    main()
    mainloop()
