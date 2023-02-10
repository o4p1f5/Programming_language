# 1303.py
x, y=map(int, input('--->').split()) #문자열항목에 int(항목) 적용
print(x, y)

def f(x):  # 함수 f 정의
	if x.isnumeric():     # 문자열 x가 숫자이면
		return int(x) # 정수 반환
	return x  # 그대로(문자열) 반환

name, age=map(f, input('--->').split())#문자열항목에 f(항목)적용
print(name)
print(age)
