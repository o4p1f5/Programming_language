# 3301.py
import time

print(time.time())
print(time.clock())

t = time.localtime()
print(t[0]) # t.tm_year

start = time.clock()
for y in range(5):
	print(y)

stop = time.clock()
ellapse  =  stop - start
print(ellapse)

