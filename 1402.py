# 1402.py
x, y = map(int, input('--->').split())
if x > y :   # if x > y: t = x; x = y; y = t
	t = x
	x = y
        y = t
print('x = %s, y = %s'%(x, y))
