# 1702.py
n = int(input('양의 정수---> '))
i = 2
while i < n:
    if not n % i:
        bPrime = False
        break
    i += 1
else:
    bPrime = True
if bPrime:
    print("{0}은 소수이다.".format(n))
else:
    print("{0}은 소수가 아니다.".format(n))
