# 5601.py
def Kaprekar_number(numstr):
    count = 0
    print("count=%s, numstr=%s"%(count, numstr))
    while int(numstr) != 6174:
        numstr = '0' * (4 - len(numstr)) + numstr # 공백 0 채우기
        maxS = ''.join(sorted(numstr, reverse=True))
        minS = ''.join(sorted(numstr))
        numstr = str(int(maxS) - int(minS))
        count += 1
        print("count=%s: %s - %s = %s"%(count, maxS, minS, numstr))

Kaprekar_number("1234")    
