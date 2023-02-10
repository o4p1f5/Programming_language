# 3402.py
import random
random.seed()

N = 5  # 히스토그램 bin(방)의 개수
hist = [0 for x in range(N)]

M = 10  # 샘플의 개수
sample = [random.randint(0, N-1)for x in range(M)]

for k in sample:
    hist[k] += 1
print("hist = ", hist)
