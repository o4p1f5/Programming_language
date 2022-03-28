# 2004.py
def mySum(n):
	nSum = 0
	for i in range(1, n+1):   # nSum = sum(range(1, n+1))
		nSum += i;
	return nSum

print(mySum(10))
