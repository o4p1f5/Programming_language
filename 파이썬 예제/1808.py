# 1808.py
n = int(input('양의 정수---> '))
for i in range(2, n):      
    if not n % i:
        bPrime = False
        break
else:
    bPrime = True

if bPrime:
    print("{0}은 소수입니다.".format(n))
else:
    print("{0}은 소수가 아닙니다.".format(n))
