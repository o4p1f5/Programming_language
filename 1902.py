# 1902.py
nPrime = int(input('소수의 개수---> '))
n = 2
L = []  # 결과 리스트 
while len(L) != nPrime:  #  len(L) < nPrime  
    for i in range(2, n):
        if not n % i: break
    else:
        L.append(n)
    n += 1
        
print("{0}개의 소수, L = {1}".format(k, L))
