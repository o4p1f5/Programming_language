# 1809.py
strInput= input('숫자를 포함한 문자열 ---> ')
nSum = 0
for s in strInput:      
    if not s.isnumeric():
        continue
    nSum += int(s)
print("nSum = ", nSum)
