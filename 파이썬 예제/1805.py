# 1805.py
A = [] # 홀수 리스트
B = [] # 짝수 리스트
for i in [2, 3, 5, 4, 6]:
    if i%2: # 홀수
        A.append(i)
    else:   # 짝수
        B.append(i)
print("홀수 A= %s " % A)
print("짝수 B= %s " % B)
