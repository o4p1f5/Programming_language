# 2002.py
def add(x, y=1): # y는 디폴트 매개변수
	print("x = %s, y = %s"%(x, y))
	return x + y
    
add(2)      # add(x= 2)
add(1, 2)
