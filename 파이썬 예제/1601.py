# 1601.py
x, y = map(int, input('--->').split())
if x == y:
    print("%d is equal to %d"%(x, y)) 
elif x < y:
    print("%d is less than %d"%(x, y))
else:
    print("%d is greater than %d"%(x, y))
