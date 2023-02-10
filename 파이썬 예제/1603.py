# 1603.py
year = int(input('--->'))
if not year % 400:  # year % 400 == 0
    bLeapYear = True
elif not year % 100:
    bLeapYear = False
elif not year % 4:
    bLeapYear = True
else:
    bLeapYear = False    

if bLeapYear:    
    print(" 윤년 : %d"% year)
else:
    print(" 평년 : %d"% year)
