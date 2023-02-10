# 2005.py
def fact(n):
	nFact = 1
	for i in range(n, 0, -1):
		nFact *= i
	return nFact

print(fact(4))
