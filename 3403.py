# 3403.py
import random

print(random.random())     # 범위 [0.0, 1.0)의 균등분포 랜덤실수
print(random.randrange(10)) # 범위 [0, 10]의 랜덤 정수, random.randrange(0, 10, 1) 
print(random.uniform(1, 10)) # 범위 [1, 10] 사이의 균등분포 랜덤실수
print(random.gauss(0, 1))    #평균 mu=0, 표준편차 sigma=1인 정규분포 랜덤실수

print(random.choice('abcdefg'))  # 문자열에서 임의로 선택

A = [1, 2, 3, 4, 5]
random.shuffle(A)  # 리스트를 무작위로 섞음
print(A)

print(random.sample([1, 2, 3, 4, 5],  3))
print([random.randint(1, 10)for x in range(5)]) # 5개의 균등분포 정수 난수 생성
