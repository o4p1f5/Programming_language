# 2202.py
x = 1           # 전역변수
def func():
	global x     #  전역변수 x 설정
	x = 10      #  전역변수 x
	print("x = ", x)	
	print("locals() = ", locals())	

func()
print(x)
print(globals())
