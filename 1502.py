# 1502.py
x, y = map(int, input('--->').split())
if x > y:
    Max = x
    Min = y
else:
    Max = y
    Min = x
print("Max = %d, Min = %d"%(Max, Min))
