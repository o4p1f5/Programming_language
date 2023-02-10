# 1807.py
year, month, day = map(int, input('년 월 일 ---> ').split())
nDays = 0

# 전년도 까지 날짜 계산
for y in range(1, year):    
    if y % 4 == 0 and y % 100 != 0 or y % 400 == 0:    
        nDays += 366  # 윤년
    else:
        nDays += 365  # 평년   

# 당해(year)년도 날짜 계산       
# 월 처리
mDays = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31) # 월별 날짜
for m in range(month-1):
    nDays += mDays[m]

# 당해(year)년도 윤년판단
if year % 4 == 0 and year % 100 != 0 or year % 400 == 0:    
    bLeapYear = True
else:
    bLeapYear = False    
if bLeapYear and month>2: # 윤년이고 2월보다 크면
        nDays += 1  # 2월이 29일
# 일 처리
nDays += day        

sWeek = "일월화수목금토"
k = nDays%7
print("{0}년 {1}월 {2}일은 {3}요일입니다.".format(year, month, day, sWeek[k]))
