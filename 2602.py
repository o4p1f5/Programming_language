# 2602.py
class Vec:
	def __init__(self, *args): # args: 가변 위치 매개변수 
		data = []
		for item in args:
			if type(item) == list:
				for x in item:
					data.append(x)
			else:
				data.append(item)
		self.data = data
	def __add__(self, other):
		assert len(self.data)==len(other.data),"not the same size Vec"	
		data = []
		for i in range(len(self.data)):
			data.append(self.data[i] + other.data[i])
		return Vec(data)		
	def __len__(self):     # len()
		return len(self.data)
	def __getitem__(self, key):
		return self.data[key]
	def __setitem__(self, key, value):
		self.data[key] = value
	def __delitem__(self, key):
		del self.data[key]
	def __contains__(self, item):
		return item in self.data
	def __iter__(self):
		return iter(self.data)

A = Vec(1, 2, 3, 4, 5, 6)
print(len(A))   
print(A[1])
print(A[1:4])

A[1] = 20
print(A.data)

del A[1]
print(A.data)

print( 3 in A )
for x in A:             # __iter__()
	print(x)

B = A + A
print(B.data)
#C = A + Vec(1, 2, 3)
