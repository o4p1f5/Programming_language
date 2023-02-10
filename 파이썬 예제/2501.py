# 2501.py
class A:
	value = 10          # 클래스 데이터 속성
	def set(self, value): # 인스턴스 메서드
		self.value = value

a = A() # 인스턴스 a 생성
a.set(20) 
print(a.value)

b = A() # 인스턴스 b 생성 	
b.set(30)
print(b.value)
print(A.value)
