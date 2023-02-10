# 5701.py
def fact(n): # 예제 20.5, 반복문 사용
    nFact = 1
    for i in range(n, 0, -1):
        nFact *= i
    return nFact
    
def fact_r(n): # 예제 21.2, 재귀함수 
    if n == 0:
        return 1
    return n*fact_r(n-1)
   
def perm1(n, k):
    return fact(n)/fact(n-k)
    
def perm2(n, k):
    nP = 1
    for i in range(n, n-k, -1):
        nP *= i
    return nP

def comb1(n, k):
    return perm1(n, k)/fact(k)

def comb2(n, k):
    return fact(n)/(fact(n-k)*fact(k))

print(perm1(3, 2))
print(comb1(3, 2))
