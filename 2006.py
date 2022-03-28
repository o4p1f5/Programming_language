# 2006.py
def countString(sArg):
	nAlphabet = nHanGul = nOthers = 0
	for s in sArg:
		if 'A' <= s <= 'Z' or 'a' <= s <= 'z':
		    nAlphabet += 1                
		elif '가' <= s <= '힣':
		    nHanGul += 1
		else:
		    nOthers += 1
	return nAlphabet, nHanGul, nOthers

alphabet, hangul, other = countString("Python?파이썬!")
print(alphabet, hangul, other)
