# 2502.py
class A:
	def __init__(self, value = 0):   # 재정의 메서드
		self.value = value	
	def set(self, value):             # 인스턴스 메서드
		self.value = value
	def get(self):                    # 인스턴스 메서드
		return self.value

a = A()    # __init__() 메서드 호출
print(a.get())

b = A(10) # __init__() 메서드 호출
print(b.get())
