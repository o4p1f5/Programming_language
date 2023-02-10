# 2401.py
def Range(n):
	i = 0
	while i < n:
		yield i   # return i와 비교
		i += 1
for i in Range(5):
	print(i)

print(list(Range(10)))
