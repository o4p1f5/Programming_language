# 1803.py
n = int(input('---> '))
nFact = 1
for i in range(n, 0, -1):
    nFact *= i
   
print("%d! =%d" % (n, nFact))
