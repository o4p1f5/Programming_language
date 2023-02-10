# 2008.py
def sumNum(strInput):
	nSum = 0
	for s in strInput:
		if not s.isnumeric():
			continue
		nSum += int(s)
	return nSum

print(sumNum('123abc45'))
