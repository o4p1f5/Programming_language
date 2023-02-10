# 2402.py
def frange(start, stop=None, step = 1.0):
	assert step != 0, "need step nonzero"

	if stop == None:  # step is None
		x = 0.0
		y = float(start)
	else:
		x = float(start)
		y = float(stop)
	n = int((y - x)/step) # 개수

	k = 0
	while k <= n:  # k < n과 비교
		yield x
		x += step
		k += 1

print(list(frange(5)))
print(list(frange(0, 5, 0.5)))
print(list(frange(5, 0, -0.5)))
