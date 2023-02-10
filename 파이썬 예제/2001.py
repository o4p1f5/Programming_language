# 2001.py
def add(x, y):
	print("x = %s, y = %s"%(x, y))
	return x + y
add(1, 2)      # 위치인수(positional argument)
add(y=2, x=3) # 키워드인수(keyword argument)
add("abc", "def")        # 문자열 위치인수
add([1, 2, 3], [4, 5, 6]) # 리스트 위치인수
