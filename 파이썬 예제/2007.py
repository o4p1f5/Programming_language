# 2007.py
def isPrime(n):
	for i in range(2, n):
		if not n % i:
			bPrime = False
			break
	else:
		bPrime = True
	return bPrime

print(isPrime(7))
print(isPrime(10))
